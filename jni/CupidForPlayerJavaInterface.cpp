#include "com_qiyi_hcdndownloader_CupidForPlayer.h"
#include <logger/InterfaceLogger.h>
#include "HCDNDownloaderTaskCallBackImpl.h"
#include "stdafx.h"

JNIEXPORT jobject JNICALL Java_com_qiyi_hcdndownloader_CupidForPlayer_GetAdPath(JNIEnv * env, jobject jcupidforplayer,jlong jQpid, jint jDefinition, jstring JUrl, jint JDesDefinition)
{
	if(NULL == gHCDNAdForPlay)
		return NULL;
		
	if((NULL == env)||(NULL == JUrl))
	{
		psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Fatal, "%s %d: param not enough\r\n",__FUNCTION__,__LINE__);
		return NULL;
	}
				
	const char *szurl = env->GetStringUTFChars(JUrl,NULL);
	
	psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Debug, "%s %d: jQpid = %llu,jDefinition = %d,JUrl = %s,JDesDefinition = %d\r\n",__FUNCTION__,__LINE__,jQpid,jDefinition,szurl,JDesDefinition);
	
	int desdefinition = JDesDefinition;
	
		
	std::string strpath = gHCDNAdForPlay->GetAdPath(jQpid,jDefinition,szurl,desdefinition);
	
	/*jclass strClass = env->FindClass("Ljava/lang/String;");   
	jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");   
	jbyteArray bytes = env->NewByteArray(strpath.length());   
	env->SetByteArrayRegion(bytes, 0, strpath.length(), (jbyte*)strpath.c_str());   
	jstring encoding = env->NewStringUTF("utf-8");   
	jstring jstrpath =(jstring) env->NewObject(strClass, ctorID, bytes, encoding);*/
	jstring jstrpath = env->NewStringUTF(strpath.c_str());
	
	jobject jresult= NULL;
	jclass cls = env->FindClass("com/qiyi/hcdndownloader/PlayerGetAdPathResult");

	if (NULL == cls) 
	{
		psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Fatal, "%s %d: NULL == localRefCls\r\n",__FUNCTION__,__LINE__);

		env->DeleteLocalRef(cls);
		return NULL;
	}

	jmethodID mid = env->GetMethodID(cls,"<init>","()V");

	if(NULL == mid)
	{
		psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Fatal, "%s %d: NULL == mid\r\n",__FUNCTION__,__LINE__);
		return NULL;
	}

	jresult=env->NewObject(cls,mid);
	
	if(NULL == jresult)
	{
		psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Fatal, "%s %d: NULL == jresult\r\n",__FUNCTION__,__LINE__);
		env->DeleteLocalRef(cls);
		return NULL;
	}
	else
	{
		jfieldID fid_desdefinition = env->GetFieldID( cls, "DesDefinition", "I");
		if (fid_desdefinition != 0)
		{
			jint jdesdefinition = (jint)desdefinition;
			env->SetIntField( jresult, fid_desdefinition, jdesdefinition); 
		}
		else
		{
			return NULL;
		}
		
		jfieldID fid_AdPath = env->GetFieldID( cls, "AdPath", "Ljava/lang/String;");
		if (fid_AdPath != 0)
		{
			env->SetObjectField( jresult, fid_AdPath, jstrpath); 
		}
		else
		{
			return NULL;
		}
		
	}
	
	env->ReleaseStringUTFChars(JUrl,szurl);
	
	return jresult;
}

JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_CupidForPlayer_SetSavePathAd(JNIEnv * env, jobject jcupidforplayer, jstring jTvid, jlong jQpid, jint jDefinition, jstring jUrl, jstring jAbsolutePath, jlong jFileLen)
{
	if(NULL == gHCDNAdForPlay)
		return;
		
	if((NULL == env)||(NULL == jTvid)||(NULL == jUrl)||(NULL == jAbsolutePath))
	{
		psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Fatal, "%s %d: param not enough\r\n",__FUNCTION__,__LINE__);
		return;
	}
		
	const char *sztvid = env->GetStringUTFChars(jTvid,NULL);
    const char *szurl = env->GetStringUTFChars(jUrl,NULL);
	const char *szabsolutepath = env->GetStringUTFChars(jAbsolutePath,NULL);
	
	psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Debug, "%s %d: jTvid = %s,jQpid = %llu,jDefinition = %d,jUrl = %s,jAbsolutePath = %s,jFileLen = %d\r\n",__FUNCTION__,__LINE__,sztvid,jQpid,jDefinition,szurl,szabsolutepath,jFileLen);
	
	//gHCDNAdForPlay->SetSavePathAd(sztvid,jQpid,jDefinition,szurl,szabsolutepath,jFileLen);
	
	env->ReleaseStringUTFChars(jTvid,sztvid);
	env->ReleaseStringUTFChars(jUrl,szurl);
	env->ReleaseStringUTFChars(jAbsolutePath,szabsolutepath);	
}