/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_qiyi_hcdndownloader_HCDNDownloaderCreator */

#ifndef _Included_com_qiyi_hcdndownloader_HCDNDownloaderCreator
#define _Included_com_qiyi_hcdndownloader_HCDNDownloaderCreator
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    CreateTaskNative
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;
 */
JNIEXPORT jobject JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_CreateTaskNative
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring, jstring, jstring, jstring, jboolean);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    CreateTaskByUrlNative
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;
 */
JNIEXPORT jobject JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_CreateTaskByUrlNative
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring, jstring);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    CreateNormalTaskNative
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;
 */
JNIEXPORT jobject JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_CreateNormalTaskNative
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring, jstring, jboolean);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    CreateTaskWithADNative
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ZIIIZZIII)Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;
 */
JNIEXPORT jobject JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_CreateTaskWithADNative
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring, jstring, jstring, jstring, jboolean, jint, jint, jint, jboolean, jboolean, jint, jint, jint);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    DestroryTaskNative
 * Signature: (Lcom/qiyi/hcdndownloader/HCDNDownloaderTask;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_DestroryTaskNative
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    InitHCDNDownloaderCreatorNative
 * Signature: (IIILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_InitHCDNDownloaderCreatorNative
  (JNIEnv *, jobject, jint, jint, jint, jstring, jstring, jstring);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    InitCubeCreatorNative
 * Signature: (IIILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_InitCubeCreatorNative
  (JNIEnv *, jobject, jint, jint, jint, jstring, jstring, jstring, jstring, jstring, jstring);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    DestroyHCDNDownloaderCreatorNative
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_DestroyHCDNDownloaderCreatorNative
  (JNIEnv *, jobject);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    GetVersion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_GetVersion
  (JNIEnv *, jclass);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    GetInterfaceVersionNative
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_GetInterfaceVersionNative
  (JNIEnv *, jclass);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    SetCubeParamNative
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_SetCubeParamNative
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    GetParamNative
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_GetParamNative
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    SetParamNative
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_SetParamNative
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    StartCubeNative
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_StartCubeNative
  (JNIEnv *, jobject);

/*
 * Class:     com_qiyi_hcdndownloader_HCDNDownloaderCreator
 * Method:    StopCubeNative
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_qiyi_hcdndownloader_HCDNDownloaderCreator_StopCubeNative
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif