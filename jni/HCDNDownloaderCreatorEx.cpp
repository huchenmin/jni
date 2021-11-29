#include "com_qiyi_hcdndownloader_HCDNDownloaderCreator.h"
        psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_CREATOREX,psl::logger::_Fatal, "%s %d: albumid = %s,tvid = %s,vid = %s,file_path = %s,user_uuid = %s,qypid = %s,\r\n"
        jclass cls = env->FindClass("com/qiyi/hcdndownloader/HCDNDownloaderTask");

        if (NULL == cls) 
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_CREATOREX,psl::logger::_Fatal, "%s %d: NULL == localRefCls\r\n",__FUNCTION__,__LINE__);

            gIHCDNDownloaderCreator->DestroryTask(hcdntask);
            env->DeleteLocalRef(cls);
            return NULL;
        }
            if (fid != 0)
            {
                jlong taskptr = (jlong)hcdntask;
                env->SetLongField( jtask, fid, taskptr); 
            }
        jclass cls = env->FindClass("com/qiyi/hcdndownloader/HCDNDownloaderTask");

        if (NULL == cls) 
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_CREATOREX,psl::logger::_Fatal, "%s %d: NULL == localRefCls\r\n",__FUNCTION__,__LINE__);

            gIHCDNDownloaderCreator->DestroryTask(hcdntask);
            env->DeleteLocalRef(cls);
            return NULL;
        }
            if (fid != 0)
            {
                jlong taskptr = (jlong)hcdntask;
                env->SetLongField( jtask, fid, taskptr); 
            }
    JNIEXPORT jobject JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_CreateTaskWithAD(JNIEnv * env
        , jobject creator
        , jint jpage_type
        , jint jplayback_scene
        , jint juser_type
        , jboolean jis_offline_video
        , jboolean jis_downloading
        , jint jdefinition
        , jint jnet_status
        , jint juser_vip_type)
    {
        if(NULL == gIHCDNDownloaderCreator)
        psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_CREATOREX,psl::logger::_Fatal, "%s %d: albumid = %s,tvid = %s,vid = %s,file_path = %s,user_uuid = %s,qypid = %s,\r\n"
																						, jplayback_scene
																						, juser_type
																						, jis_offline_video
																						, jis_downloading
																						, jdefinition
																						, jnet_status
            , jplayback_scene
            , juser_type
            , jis_offline_video
            , jis_downloading
            , jdefinition
            , jnet_status
        jclass cls = env->FindClass("com/qiyi/hcdndownloader/HCDNDownloaderTask");

        if (NULL == cls) 
        {
            psl::logger::CLogger::PrintA(LOG_HCDNDOWNLOADER_CREATOREX,psl::logger::_Fatal, "%s %d: NULL == localRefCls\r\n",__FUNCTION__,__LINE__);

            gIHCDNDownloaderCreator->DestroryTask(hcdntask);
            env->DeleteLocalRef(cls);
            return NULL;
        }
            if (fid != 0)
            {
                jlong taskptr = (jlong)hcdntask;
                env->SetLongField( jtask, fid, taskptr); 
            }
    }
        , jobject creator
        , jstring jparamname)
    {
    }

    JNIEXPORT jint JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_SetParam(JNIEnv * env
        , jobject creator
        , jstring jparamname
        , jstring jparamvalue)
    {

        const char *szparamname = env->GetStringUTFChars(jparamname,NULL);

        int setresult = 0;

    }

    JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_SetCubeParam(JNIEnv * env
