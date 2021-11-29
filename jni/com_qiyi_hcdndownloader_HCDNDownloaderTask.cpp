#include "com_qiyi_hcdndownloader_HCDNDownloaderTask.h"

        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return JNI_FALSE;
        }

        bool brt = task->Start();

        return brt?JNI_TRUE:JNI_FALSE;

        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return JNI_FALSE;
        }
        int stop_t = stop_type;
        bool brt = task->Stop(stop_t);
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return JNI_FALSE;
        }
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return JNI_FALSE;
        }
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

            brt = task->SetAddtionalInfo(info,infolen);
        }
        env->ReleaseByteArrayElements(barr, ba, 0);


        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return 0;
        }

        task->GetSpeed(&mean_speed,&realtime_speed);
        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return 0;
        }

        long long filssize = static_cast<long long>(task->GetFileSize());
        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return 0;
        }

        long long filssize = static_cast<long long>(task->GetDownloadSize());
        if(NULL == task)
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_TASKEX,psl::logger::_Fatal, "%s %d: NULL == taskptr\r\n",__FUNCTION__,__LINE__);
            return;
        }

        task->SetSpeedLimit(jspeed);