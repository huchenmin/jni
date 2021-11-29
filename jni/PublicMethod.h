#ifndef _PUBLICMETHOD_H_
#define _PUBLICMETHOD_H_

#include <jni.h>
#include <stdlib.h>
#include <string>
#include "../HCDNDownloader.h"	#include <logger/include/InterfaceLogger.h>

std::string jstringTostring(JNIEnv* env, jstring jstr);
char* jstringTochar(JNIEnv* env, jstring jstr);

IHCDNDownloaderTask* gettaskptrbyjava(JNIEnv* env,jobject jtask);

#endif
