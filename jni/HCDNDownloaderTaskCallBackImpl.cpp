#include "HCDNDownloaderTaskCallBackImpl.h"
#include "com_qiyi_hcdndownloader_HCDNDownloaderCreator.h"
#include <logger/include/InterfaceLogger.h>
#include "CubeTaskCallBackImpl.h"

CHCDNDownloaderTaskCallBackImpl::CHCDNDownloaderTaskCallBackImpl()
{
	m_task = NULL;
	breset = true;
	m_bcallfunc = false;
	m_preretryerrorcode = 0;
    attached_ = false;
	//m_jmidOnComplete = NULL;
	//m_jmidOnError = NULL;
	//m_jmidOnProcess = NULL;
	//m_jmidOnStartTaskSuccess = NULL;
}

CHCDNDownloaderTaskCallBackImpl::~CHCDNDownloaderTaskCallBackImpl()
{
	ResetJavaCallBack();
}

void CHCDNDownloaderTaskCallBackImpl::SetJavaCallBack(JavaVM * jvm,jobject cb,jobject jtask)
{
	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: SetJavaCallBack start\r\n",__FUNCTION__,__LINE__);	m_pVm = jvm;
	if(NULL == m_pVm)
		return;
	
	if (m_pVm->GetEnv((void **) &m_pEnv, JNI_VERSION_1_1) != JNI_OK) {
		m_pVm = NULL;
		psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal,"ConStruct DownloadCallback Failed");
		return;
	}
		m_objInterface = m_pEnv->NewGlobalRef(cb);
	m_task = m_pEnv->NewGlobalRef(jtask);
	breset = false;
	//m_jclsProcess = m_pEnv->GetObjectClass(m_objInterface);

	//if (m_jclsProcess == NULL)	//{
	//	psl::logger::CLogger::PrintA("IHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal, "%s %d: m_jclsProcess == null\r\n",__FUNCTION__,__LINE__);
	//	m_pEnv->DeleteGlobalRef(m_objInterface);
	//	m_pEnv->DeleteGlobalRef(m_task);	//}
	//else
	//{
	//	psl::logger::CLogger::PrintA("IHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: m_jclsProcess != null\r\n",__FUNCTION__,__LINE__);
	//	breset = false;
	//}


	//m_jmidOnComplete = m_pEnv->GetMethodID(m_jclsProcess,"OnComplete","(Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;)V");
	//m_jmidOnError = m_pEnv->GetMethodID(m_jclsProcess,"OnError","(Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;I)V");
	//m_jmidOnProcess = m_pEnv->GetMethodID(m_jclsProcess,"OnProcess","(Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;JJ)V");
	//m_jmidOnStartTaskSuccess = m_pEnv->GetMethodID(m_jclsProcess,"OnStartTaskSuccess","(Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;)V");

	//if((NULL == m_jmidOnComplete)||(NULL == m_jmidOnError)||(NULL == m_jmidOnProcess)||(NULL == m_jmidOnStartTaskSuccess))
	//{
	//	psl::logger::CLogger::PrintA("IHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal, "%s %d: get callback function failed\r\n",__FUNCTION__,__LINE__);
	//}
	//else
	//{
	//	psl::logger::CLogger::PrintA("IHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: get callback function succeed\r\n",__FUNCTION__,__LINE__);
	//}
}

void CHCDNDownloaderTaskCallBackImpl::ResetJavaCallBack()
{
	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: ResetJavaCallBack start\r\n",__FUNCTION__,__LINE__);
	if(breset)
		return;
		
	if(NULL == m_pVm)
		return;	
		
	m_pVm->GetEnv((void**) &m_pEnv, JNI_VERSION_1_1);
		
	if(NULL != m_pEnv)	
	{
	m_pEnv->DeleteGlobalRef(m_objInterface);
	m_pEnv->DeleteGlobalRef(m_task);	
	}
	
	breset = true;
}

//
bool CHCDNDownloaderTaskCallBackImpl::Check() {
	if (m_pVm == NULL)
		return false;

	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: Check() start\r\n",__FUNCTION__,__LINE__);

	int ret = m_pVm->GetEnv((void**) &m_pEnv, JNI_VERSION_1_1);

	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: Check()  ret = %d,attached_ = %d",__FUNCTION__,__LINE__, ret, attached_);

	if (ret == JNI_EDETACHED) {
		psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: Check() AttachCurrentThread",__FUNCTION__,__LINE__);
		m_pVm->AttachCurrentThread(&m_pEnv, NULL);
		attached_ = true;
	} else if (ret != JNI_OK) {
		psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: Check() Java VM Get Env Failed",__FUNCTION__,__LINE__);
		return false;
	}
	if (m_pEnv != NULL) {

		m_jclsProcess = m_pEnv->GetObjectClass(m_objInterface);
		if (m_jclsProcess == NULL) {
			psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: Check() Get Java Handler Failed",__FUNCTION__,__LINE__);
			m_pEnv = NULL;
			attached_ = false;
			return false;
		}
	}

	if(m_pEnv == NULL)
		return false;

	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: Check()  2 attached_ = %d",__FUNCTION__,__LINE__, attached_);
	return true;
}

void CHCDNDownloaderTaskCallBackImpl::detachJNI() {
	//JavaVM* vm = AndroidRuntime::getJavaVM();
	if (!m_pVm)
		return;
	int ret = m_pVm->GetEnv((void**) &m_pEnv, JNI_VERSION_1_1);

	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: detachJNI()  ret = %d,attached_ = %d",__FUNCTION__,__LINE__, ret, attached_);

	if (ret == JNI_EDETACHED || !attached_) {

		psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: detachJNI() thread not attached",__FUNCTION__,__LINE__);
		m_pEnv = NULL;
		return;
	}

	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: detachJNI() thread detaching",__FUNCTION__,__LINE__);
	int result = JNI_OK;
	if(m_bcallfunc)
		result = m_pVm->DetachCurrentThread();

	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: detachJNI() thread detached ",__FUNCTION__,__LINE__);


	if (result != JNI_OK) {
		psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: thread detach failed: %#x",__FUNCTION__,__LINE__, result);
	}

	m_pEnv = NULL;
	attached_ = false;
}

void CHCDNDownloaderTaskCallBackImpl::OnComplete(IHCDNDownloaderTask *task)
{
	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal, "%s %d: OnComplete start\r\n",__FUNCTION__,__LINE__);
	
	if (!Check())
	{
		return;
	}
	
	jmethodID jmidOnComplete = m_pEnv->GetMethodID(m_jclsProcess,"OnComplete","(Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;)V");
	if (NULL == jmidOnComplete)	{
		psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal, "%s %d: jmidOnComplete is null\r\n",__FUNCTION__,__LINE__);
		return;
	}

	m_pEnv->CallVoidMethod (m_objInterface,jmidOnComplete,m_task);
	m_bcallfunc = true;
	detachJNI();
}

void CHCDNDownloaderTaskCallBackImpl::OnError(IHCDNDownloaderTask *task,int error)
{
	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal, "%s %d: OnError start error = %d\r\n",__FUNCTION__,__LINE__,error);
	
	if (!Check())
	{
		return;
	}
	
	jmethodID jmidOnError = m_pEnv->GetMethodID(m_jclsProcess,"OnError","(Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;I)V");
	if (jmidOnError == NULL)	{
		psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal, "%s %d: jmidOnError is null\r\n",__FUNCTION__,__LINE__);
		return;
	}

	if(0 != m_preretryerrorcode)
	{
		m_pEnv->CallVoidMethod (m_objInterface,jmidOnError,m_task,m_preretryerrorcode);
		m_preretryerrorcode = 0;
	}
	else
		m_pEnv->CallVoidMethod (m_objInterface,jmidOnError,m_task,error);
	m_bcallfunc = true;
	detachJNI();
}

void CHCDNDownloaderTaskCallBackImpl::OnProcess(IHCDNDownloaderTask *task,unsigned long long & total, unsigned long long & pos)
{
	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Debug, "%s %d: OnProcess start! total = %llu pos = %llu\r\n",__FUNCTION__,__LINE__,total,pos);
	
	if (!Check())
	{
		return;
	}
	
	jmethodID jmidOnProcess = m_pEnv->GetMethodID(m_jclsProcess,"OnProcess","(Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;JJ)V");
	
	if (jmidOnProcess == NULL)	{
		psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal, "%s %d: jmidOnProcess is null\r\n",__FUNCTION__,__LINE__);
		return;
	}
	
	jlong jtotal = total;
	jlong jpos = pos;

	m_pEnv->CallVoidMethod (m_objInterface,jmidOnProcess,m_task,jtotal,jpos);
	m_bcallfunc = true;
	detachJNI();
	
}

void CHCDNDownloaderTaskCallBackImpl::OnStartTaskSuccess(IHCDNDownloaderTask *task)
{
	psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal, "%s %d: OnStartTaskSuccess start\r\n",__FUNCTION__,__LINE__);
	
	if (!Check())
	{
		return;
	}
	
	jmethodID jmidOnStartTaskSuccess = m_pEnv->GetMethodID(m_jclsProcess,"OnStartTaskSuccess","(Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;)V");
	
	if (jmidOnStartTaskSuccess == NULL)	{
		psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal, "%s %d: jmidOnStartTaskSuccess is null\r\n",__FUNCTION__,__LINE__);
		return;
	}

	m_pEnv->CallVoidMethod (m_objInterface,jmidOnStartTaskSuccess,m_task);
	m_bcallfunc = true;
	detachJNI();
}
