#include "com_qiyi_hcdndownloader_CupidForApp.h"
#include <logger/InterfaceLogger.h>
#include "HCDNDownloaderTaskCallBackImpl.h"
#include "stdafx.h"

JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_CupidForApp_CreateAdTask(JNIEnv * env, jobject jCupidForApp, jint jPageType, jint jPlayBackScene, jint jUserType, jboolean jisOfflineVideo, jboolean jisVipVideo, jboolean jDownloading, jstring jTvid, jint jDefinition,jstring jQyPid, jstring jDevicesID,jint jNetStatus)
{
	if(NULL == gHCDNAdForApp)
		return JNI_FALSE;
		
	if((NULL == env)||(NULL == jTvid)||(NULL == jQyPid)||(NULL == jDevicesID))
	{
		psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Fatal, "%s %d: param not enough\r\n",__FUNCTION__,__LINE__);
		return JNI_FALSE;
	}
	
	const char *sztvid = env->GetStringUTFChars(jTvid,NULL);
    const char *szqypid = env->GetStringUTFChars(jQyPid,NULL);
	const char *szdevicesid = env->GetStringUTFChars(jDevicesID,NULL);
	
	psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Debug, "%s %d: jPageType = %d,jPlayBackScene = %d,jUserType = %d,jisOfflineVideo = %d,jisVipVideo = %d,jDownloading = %d,jTvid = %s,,jDefinition = %d,jQyPid = %s,jDevicesID = %s,jNetStatus = %d\r\n",__FUNCTION__,__LINE__,jPageType,jPlayBackScene,jUserType,jisOfflineVideo,jisVipVideo,jDownloading,sztvid,jDefinition,szqypid,szdevicesid,jNetStatus);

	bool brt = gHCDNAdForApp->CreateAdTask(jPageType,jPlayBackScene,jUserType,jisOfflineVideo,jisVipVideo,jDownloading,sztvid,jDefinition,szqypid,szdevicesid,jNetStatus);
	
	env->ReleaseStringUTFChars(jTvid,sztvid);
	env->ReleaseStringUTFChars(jQyPid,szqypid);
	env->ReleaseStringUTFChars(jDevicesID,szdevicesid);
	
	return brt?JNI_TRUE:JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_CupidForApp_DeleteAd(JNIEnv *env, jobject jCupidForApp, jstring jTvid)
{
	if(NULL == gHCDNAdForApp)
		return;
		
	if((NULL == env)||(NULL == jTvid))
	{
		psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Fatal, "%s %d: param not enough\r\n",__FUNCTION__,__LINE__);
		return;
	}
	
	const char *sztvid = env->GetStringUTFChars(jTvid,NULL);
	
	psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Debug, "%s %d: jTvid = %s\r\n",__FUNCTION__,__LINE__,sztvid);
	
	gHCDNAdForApp->DeleteAd(sztvid);
	
	env->ReleaseStringUTFChars(jTvid,sztvid);
	
	return;
}

JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_CupidForApp_PauseAd(JNIEnv *env, jobject jCupidForApp, jstring jTvid)
{
	if(NULL == gHCDNAdForApp)
		return;
		
	if((NULL == env)||(NULL == jTvid))
	{
		psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Fatal, "%s %d: param not enough\r\n",__FUNCTION__,__LINE__);
		return JNI_FALSE;
	}
	
	const char *sztvid = env->GetStringUTFChars(jTvid,NULL);
	
	psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Debug, "%s %d: jTvid = %s\r\n",__FUNCTION__,__LINE__,sztvid);
	
	gHCDNAdForApp->PauseAd(sztvid);
	
	env->ReleaseStringUTFChars(jTvid,sztvid);
	
	return;
}

JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_CupidForApp_RestartAd(JNIEnv *env, jobject jCupidForApp, jstring jTvid)
{
	if(NULL == gHCDNAdForApp)
		return;
		
	if((NULL == env)||(NULL == jTvid))
	{
		psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Fatal, "%s %d: param not enough\r\n",__FUNCTION__,__LINE__);
		return JNI_FALSE;
	}
	
	const char *sztvid = env->GetStringUTFChars(jTvid,NULL);
	
	psl::logger::CLogger::PrintA(LOG_CUBE_CUPID_PLAYER,psl::logger::_Debug, "%s %d: jTvid = %s\r\n",__FUNCTION__,__LINE__,sztvid);
	
	gHCDNAdForApp->RestartAd(sztvid);
	
	env->ReleaseStringUTFChars(jTvid,sztvid);
	
	return;
}