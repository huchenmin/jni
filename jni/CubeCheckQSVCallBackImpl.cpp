#include "stdafx.h"
#include "CubeCheckQSVCallBackImpl.h"

CCubeCheckQSVCallBackImpl::CCubeCheckQSVCallBackImpl()
{
    m_bSetCallBack = false;
    m_bcallfunc = false;
    attached_ = false;
}

CCubeCheckQSVCallBackImpl::~CCubeCheckQSVCallBackImpl()
{
    ResetJavaCallBack();
}

bool CCubeCheckQSVCallBackImpl::SetJavaCallBack(JavaVM * jvm,jobject cb)
{
    psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: SetJavaCallBack start\r\n",__FUNCTION__,__LINE__);

    bool bRet = true;

    do 
    {
        if(m_bSetCallBack)            ResetJavaCallBack();        m_pVm = jvm;
        if(NULL == m_pVm)
        {
            bRet = false;
            break;
        }

        if (m_pVm->GetEnv((void **) &m_pEnv, JNI_VERSION_1_1) != JNI_OK)
        {
            m_pVm = NULL;

            psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Fatal,"ConStruct DownloadCallback Failed");

            bRet = false;
            break;
        }
        m_objInterface = m_pEnv->NewGlobalRef(cb);

        m_bSetCallBack = true;
    } while (false);    return bRet;
}

void CCubeCheckQSVCallBackImpl::ResetJavaCallBack()
{
    psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: ResetJavaCallBack start\r\n",__FUNCTION__,__LINE__);

    if(!m_bSetCallBack)
        return;

    if(NULL == m_pVm)
        return;	

    m_pVm->GetEnv((void**) &m_pEnv, JNI_VERSION_1_1);

    if(NULL != m_pEnv)	
    {
        m_pEnv->DeleteGlobalRef(m_objInterface);	
    }

    m_bSetCallBack = false;
}

bool CCubeCheckQSVCallBackImpl::Check()
{
    if (m_pVm == NULL)
        return false;

    psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: Check() start\r\n",__FUNCTION__,__LINE__);

    int ret = m_pVm->GetEnv((void**) &m_pEnv, JNI_VERSION_1_1);

    psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: Check()  ret = %d,attached_ = %d",__FUNCTION__,__LINE__, ret, attached_);

    if (ret == JNI_EDETACHED) {
        psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: Check() AttachCurrentThread",__FUNCTION__,__LINE__);
        m_pVm->AttachCurrentThread(&m_pEnv, NULL);
        attached_ = true;
    } else if (ret != JNI_OK) {
        psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: Check() Java VM Get Env Failed",__FUNCTION__,__LINE__);
        return false;
    }
    if (m_pEnv != NULL) {

        m_jclsProcess = m_pEnv->GetObjectClass(m_objInterface);
        if (m_jclsProcess == NULL) {
            psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: Check() Get Java Handler Failed",__FUNCTION__,__LINE__);
            m_pEnv = NULL;
            attached_ = false;
            return false;
        }
    }

    if(m_pEnv == NULL)
        return false;

    psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: Check()  2 attached_ = %d",__FUNCTION__,__LINE__, attached_);
    return true;
}

void CCubeCheckQSVCallBackImpl::detachJNI()
{
    if (!m_pVm)
        return;
    int ret = m_pVm->GetEnv((void**) &m_pEnv, JNI_VERSION_1_1);

    psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: detachJNI()  ret = %d,attached_ = %d",__FUNCTION__,__LINE__, ret, attached_);

    if (ret == JNI_EDETACHED || !attached_) {

        psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: detachJNI() thread not attached",__FUNCTION__,__LINE__);
        m_pEnv = NULL;
        return;
    }

    psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: detachJNI() thread detaching",__FUNCTION__,__LINE__);
    int result = JNI_OK;
    if(m_bcallfunc)
        result = m_pVm->DetachCurrentThread();

    psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: detachJNI() thread detached ",__FUNCTION__,__LINE__);


    if (result != JNI_OK) {
        psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: thread detach failed: %#x",__FUNCTION__,__LINE__, result);
    }

    m_pEnv = NULL;
    attached_ = false;
}

int CCubeCheckQSVCallBackImpl::OnCheckStatus(const char* szFilePath,int iState,int iValue)
{
    psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Fatal, "%s %d: OnCheckStatus start\r\n",__FUNCTION__,__LINE__);
    int iRetValue = 0;
    do 
    {
        if((NULL == szFilePath)||('\0' == szFilePath[0]))
        {
            iRetValue = -1;
            break;
        }

        if (!Check())
        {
            iRetValue = -1;
            break;
        }

        jmethodID jmidOnCheckStatus = m_pEnv->GetMethodID(m_jclsProcess,"OnCheckStatus","(Ljava/lang/String;II)I");

        jstring jFilePath = m_pEnv->NewStringUTF(szFilePath);

        if (NULL == jmidOnCheckStatus)        {
            psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Fatal, "%s %d: jmidOnCheckStatus is null\r\n",__FUNCTION__,__LINE__);
            iRetValue = -1;
            break;
        }

        iRetValue = m_pEnv->CallIntMethod (m_objInterface,jmidOnCheckStatus,jFilePath,iState,iValue);
        psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV_CALLBACK,psl::logger::_Debug, "%s %d: CallVoidMethod iRetValue = %d",__FUNCTION__,__LINE__,iRetValue);
        m_bcallfunc = true;

        detachJNI();
    } while (false);
    
    return iRetValue;
}

int funcCheckQSVCallBack(const char *szFilePath, int iState, int iValue)
{
    int iRetValue = -1;
    if(gCubeCheckQSVCallBack)
    {
        iRetValue = gCubeCheckQSVCallBack->OnCheckStatus(szFilePath,iState,iValue);
    }

    return iRetValue;
}