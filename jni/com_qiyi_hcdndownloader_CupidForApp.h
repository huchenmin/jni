/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_qiyi_hcdndownloader_CupidForApp */

#ifndef _Included_com_qiyi_hcdndownloader_CupidForApp
#define _Included_com_qiyi_hcdndownloader_CupidForApp
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_qiyi_hcdndownloader_CupidForApp
 * Method:    CreateAdTask
 * Signature: (IIIZZZLjava/lang/String;ILjava/lang/String;Ljava/lang/String;I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_CupidForApp_CreateAdTask
  (JNIEnv *, jobject, jint, jint, jint, jboolean, jboolean, jboolean, jstring, jint, jstring, jstring, jint);

/*
 * Class:     com_qiyi_hcdndownloader_CupidForApp
 * Method:    DeleteAd
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_CupidForApp_DeleteAd
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_qiyi_hcdndownloader_CupidForApp
 * Method:    PauseAD
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_CupidForApp_PauseAd
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_qiyi_hcdndownloader_CupidForApp
 * Method:    RestartAd
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_CupidForApp_RestartAd
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif
