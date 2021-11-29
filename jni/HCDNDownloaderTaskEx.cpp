#include "com_qiyi_hcdndownloader_HCDNDownloaderTaskEx.h"#include "com_qiyi_hcdndownloader_HCDNDownloaderCreator.h"#include "CubeTaskCallBackImpl.h"#include <stdlib.h>#include "PublicMethod.h"#include "stdafx.h"#ifdef __cplusplusextern "C" {  #endif    JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_Start(JNIEnv *env, jobject jtask)    {        if(NULL == env)            return JNI_FALSE;        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);

        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return JNI_FALSE;
        }
		psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p\r\n",__FUNCTION__,__LINE__,task);		
        bool brt = task->Start();

        return brt?JNI_TRUE:JNI_FALSE;    }    JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_Stop(JNIEnv *env, jobject jtask,jint stop_type)    {        if(NULL == env)            return JNI_FALSE;			        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);

        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return JNI_FALSE;
        }				psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p\r\n",__FUNCTION__,__LINE__,task);		
        int stop_t = stop_type;
        bool brt = task->Stop(stop_t);        return brt?JNI_TRUE:JNI_FALSE;    }    JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_RegisterTaskCallback(JNIEnv * env, jobject jtask,jobject jcb)    {        if((NULL == env)||(NULL == jcb)||(NULL == gCubeTaskCallBackImpl))            return JNI_FALSE;        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return JNI_FALSE;
        }		psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p\r\n",__FUNCTION__,__LINE__,task);		            JavaVM *jvm;            env->GetJavaVM(&jvm);					gCubeTaskCallBackImpl->AdviseJavaCallBack(jvm,jcb,jtask,task);        bool brt = task->RegisterTaskCallback(gCubeTaskCallBackImpl);        if(!brt)        {			gCubeTaskCallBackImpl->UnAdviseJavaCallBack(task);            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: RegisterTaskCallback failed\r\n",__FUNCTION__,__LINE__);        }        return brt?JNI_TRUE:JNI_FALSE;    }    JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_SetAddtionalInfo(JNIEnv *env, jobject jtask,jstring jinfo)    {        if((NULL == env)||(NULL == jinfo))            return JNI_FALSE;        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return JNI_FALSE;
        }		psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p\r\n",__FUNCTION__,__LINE__,task);		        bool brt = false;        unsigned char* info = NULL;
        jclass clsstring = env->FindClass("java/lang/String");
        jstring strencode = env->NewStringUTF("utf-8");
        jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
        jbyteArray barr= (jbyteArray)env->CallObjectMethod(jinfo, mid, strencode);
        jsize jlen = env->GetArrayLength(barr); 
        jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
        if (jlen > 0)
        {
            info = (unsigned char*)malloc(jlen + 1);
            memcpy(info, ba, jlen);
            info[jlen] = 0;

            unsigned int infolen = jlen + 1;

            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Debug, "%s %d: info = %s,jlen = %d\r\n",__FUNCTION__,__LINE__,info,infolen);

            brt = task->SetAddtionalInfo(info,infolen);            free(info);
        }
        env->ReleaseByteArrayElements(barr, ba, 0);
        return brt?JNI_TRUE:JNI_FALSE;    }    JNIEXPORT jlong JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_GetSpeed(JNIEnv *env, jobject jtask,jint speed_type)    {        if(NULL == env)            return 0;        unsigned int realtime_speed = 0;        unsigned int mean_speed = 0;        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);

        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return 0;
        }		psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p\r\n",__FUNCTION__,__LINE__,task);

        task->GetSpeed(&mean_speed,&realtime_speed);        long long speed = 0;        if (0 == speed_type)        {            speed = static_cast<long long>(realtime_speed);        }        else        {            speed = static_cast<long long>(mean_speed);        }				psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Debug, "%s %d: speed = %llu\r\n",__FUNCTION__,__LINE__,speed);		        return speed;    }    JNIEXPORT jlong JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_GetFileSize(JNIEnv *env, jobject jtask)    {        if(NULL == env)            return 0;        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);
        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return 0;
        }		psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p\r\n",__FUNCTION__,__LINE__,task);

        long long filssize = static_cast<long long>(task->GetFileSize());        return filssize;    }    JNIEXPORT jlong JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_GetDownloadSize(JNIEnv *env, jobject jtask)    {        if(NULL == env)            return 0;        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);
        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return 0;
        }		psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p\r\n",__FUNCTION__,__LINE__,task);

        long long filssize = static_cast<long long>(task->GetDownloadSize());        return filssize;    }    JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_SetSpeedLimit(JNIEnv *env, jobject jtask ,jint jspeed)    {        if(NULL == env)            return;        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);
        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return;
        }		psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p\r\n",__FUNCTION__,__LINE__,task);

        task->SetSpeedLimit(jspeed);    }    JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_IsFilerExist(JNIEnv *env, jobject jtask)    {        if(NULL == env)            return JNI_FALSE;        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);        if(NULL == task)        {            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);            return JNI_FALSE;        }		psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p\r\n",__FUNCTION__,__LINE__,task);        bool brt = task->IsFileExist();        return brt?JNI_TRUE:JNI_FALSE;    }    JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_DeleteDownloaderFile(JNIEnv *env, jobject jtask)    {        if(NULL == env)		{            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == env\r\n",__FUNCTION__,__LINE__);            return;		}        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);        if(NULL == task)        {            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);            return;        }		psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p\r\n",__FUNCTION__,__LINE__,task);        task->DeleteDownloaderFile();    }		JNIEXPORT jstring JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_GetParam(JNIEnv *env, jobject jtask,jstring jparamname)	{		std::string strparamvalue;				if((NULL == env)||(NULL == jparamname))		{			psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: jparamname is not enough or env is null\r\n",__FUNCTION__,__LINE__);            return env->NewStringUTF(strparamvalue.c_str());		}		const char *szparamname = env->GetStringUTFChars(jparamname,NULL);        IHCDNDownloaderTask* task = gettaskptrbyjava(env,jtask);				if(NULL == task)        {            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);        }		else		{			psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p,szparamname = %s\r\n",__FUNCTION__,__LINE__,task,szparamname);			int parambufflen = CUBE_GETPARAM_PRIMELEN;			char* parambuff = NULL;			parambuff = new char[parambufflen];			memset(parambuff,0,parambufflen);			int gtpresult = task->GetParam(szparamname,parambuff,&parambufflen);			if(0 != gtpresult)			{				if(parambufflen > CUBE_GETPARAM_PRIMELEN)				{					if(parambuff)					{						delete[] parambuff;						parambuff = NULL;					}					parambufflen += 1024;					parambuff = new char[parambufflen];                    if(parambuff)                    {					    memset(parambuff,0,parambufflen);					    int gtpresult = task->GetParam(szparamname,parambuff,&parambufflen);					    psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: parambuff = %s\r\n",__FUNCTION__,__LINE__,parambuff);					    if(0 == gtpresult)						    strparamvalue = parambuff;                    }				}			}			else			{				strparamvalue = parambuff;			}			if(parambuff)			{				delete[] parambuff;				parambuff = NULL;			}		}		env->ReleaseStringUTFChars(jparamname,szparamname);		return env->NewStringUTF(strparamvalue.c_str());	}	JNIEXPORT jint JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderTask_SetParam(JNIEnv * env, jobject jtask, jstring jparamname, jstring jparamvalue)	{		int setresult = 0;		if((NULL == env)||(NULL == jparamname)||(NULL == jparamvalue))		{			setresult = -1;            return setresult;		}					const char *szparamname = env->GetStringUTFChars(jparamname,NULL);		const char *szparamvalue = env->GetStringUTFChars(jparamvalue,NULL);        IHCDNDownloaderTask* taskptr = gettaskptrbyjava(env,jtask);				if(NULL == taskptr)        {			setresult = -2;            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);			return setresult;        }		else		{			psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: taskptr = %p,szparamname = %s,szparamvalue = %s\r\n",__FUNCTION__,__LINE__,taskptr,szparamname,szparamvalue);		}				taskptr->SetParam(szparamname,szparamvalue,strlen(szparamvalue));				env->ReleaseStringUTFChars(jparamname,szparamname);		env->ReleaseStringUTFChars(jparamvalue,szparamvalue);				return setresult;	}#ifdef __cplusplus  }  #endif  