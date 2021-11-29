#include "stdafx.h"
#include <string>
#include "com_qiyi_hcdndownloader_CheckQSV.h"
#include "CubeCheckQSVCallBackImpl.h"
#include "../CubeError.h"

CCubeCheckQSVCallBackImpl* gCubeCheckQSVCallBack = NULL;

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jint JNICALL Java_com_qiyi_hcdndownloader_CheckQSV_StartCheckQSVNative(JNIEnv * env, jobject jCheckQSV, jint iAction, jstring jstrFilePath)
{
    int iRetValue = 0;
    do 
    {
        if((NULL == env)||(NULL == jstrFilePath))        {            psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV,psl::logger::_Fatal, "%s %d: param not enough\r\n",__FUNCTION__,__LINE__);            iRetValue = cube::CUCQ_JNI_PARAM_ERROR;            break;        }

        if(2 != iAction)
        {
            if(NULL == gCubeCheckQSVCallBack)
            {
                psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV,psl::logger::_Fatal, "%s %d: asynchronous check without callback\r\n",__FUNCTION__,__LINE__);                iRetValue = cube::CUCQ_JNI_ASYNC_WITHOUT_CB;                break;
            }
        }

        const char *szFilePath = env->GetStringUTFChars(jstrFilePath,NULL);
        std::string strFilePath = szFilePath;
        env->ReleaseStringUTFChars(jstrFilePath,szFilePath);

        iRetValue = CheckQsv(iAction, (void *)strFilePath.c_str());

    } while (false);

    return iRetValue;

}

JNIEXPORT jint JNICALL Java_com_qiyi_hcdndownloader_CheckQSV_StopCheckQSVNative(JNIEnv * env, jobject jCheckQSV, jint iAction, jstring jstrFilePath)
{
    int iRetValue = 0;
    do 
    {
        if((NULL == env)||(NULL == jstrFilePath))        {            psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV,psl::logger::_Fatal, "%s %d: param not enough\r\n",__FUNCTION__,__LINE__);            iRetValue = cube::CUCQ_JNI_PARAM_ERROR;            break;        }

        if(2 != iAction)
        {
            if(NULL == gCubeCheckQSVCallBack)
            {
                psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV,psl::logger::_Fatal, "%s %d: asynchronous check without callback\r\n",__FUNCTION__,__LINE__);                iRetValue = cube::CUCQ_JNI_ASYNC_WITHOUT_CB;                break;
            }
        }

        const char *szFilePath = env->GetStringUTFChars(jstrFilePath,NULL);
        std::string strFilePath = szFilePath;
        env->ReleaseStringUTFChars(jstrFilePath,szFilePath);

        iRetValue = CheckQsv(iAction, (void *)strFilePath.c_str());

    } while (false);

    return iRetValue;
}

JNIEXPORT jint JNICALL Java_com_qiyi_hcdndownloader_CheckQSV_RegisterCheckCallbackNative(JNIEnv * env, jobject jCheckQSV, jobject jCallBack)
{
    int iRetValue = 0;

    do 
    {
        if((NULL == env)||(NULL == jCallBack))        {            psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV,psl::logger::_Fatal, "%s %d: param not enough\r\n",__FUNCTION__,__LINE__);            iRetValue = cube::CUCQ_JNI_PARAM_ERROR;            break;        }

        if(NULL == gCubeCheckQSVCallBack)
            gCubeCheckQSVCallBack = new CCubeCheckQSVCallBackImpl();

        if(NULL == gCubeCheckQSVCallBack)
        {
            psl::logger::CLogger::PrintA(LOG_CUBE_CHECKQSV,psl::logger::_Fatal, "%s %d: gCubeCheckQSVCallBack create failed\r\n",__FUNCTION__,__LINE__);            iRetValue = cube::CUCQ_JNI_CB_CREATE_FAIL;            break;
        }

        JavaVM *jvm;        env->GetJavaVM(&jvm);
        bool bRet = gCubeCheckQSVCallBack->SetJavaCallBack(jvm,jCallBack);
        if(!bRet)
        {
            delete gCubeCheckQSVCallBack;
            gCubeCheckQSVCallBack = NULL;
            iRetValue = cube::CUCQ_JNI_SETJAVACB_FAIL;            break;
        }
        int iAction = 1;
        iRetValue = CheckQsv(iAction, (void *)&funcCheckQSVCallBack);
    } while (false);

    return iRetValue;
}

#ifdef __cplusplus
}
#endif
