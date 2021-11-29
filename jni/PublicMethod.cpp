#include "PublicMethod.h"

std::string jstringTostring(JNIEnv* env, jstring jstr)
{
	char* rtn = NULL;
	jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("utf-8");
	jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0)
	{
		rtn = (char*)malloc(alen + 1);

		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	env->ReleaseByteArrayElements(barr, ba, 0);
	std::string str = rtn;
	free(rtn);

	return str;
}

char* jstringTochar(JNIEnv* env, jstring jstr)
{
	char* rtn = NULL;
	jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("utf-8");
	jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0)
	{
		rtn = (char*)malloc(alen + 1);

		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	env->ReleaseByteArrayElements(barr, ba, 0);
	return rtn;
}

IHCDNDownloaderTask* gettaskptrbyjava(JNIEnv* env,jobject jtask)
{	IHCDNDownloaderTask* task =NULL;	jclass cls = env->GetObjectClass( jtask);	do 
	{
		if(NULL == cls)
		{
			psl::logger::CLogger::PrintA("HCDNDownloaderCreator",psl::logger::_Fatal, "%s %d: cls is null\r\n",__FUNCTION__,__LINE__);
			break;
		}

		jfieldID fid = env->GetFieldID( cls, "jtaskptr", "J");

		if(NULL == fid)
		{
			psl::logger::CLogger::PrintA("HCDNDownloaderCreator",psl::logger::_Fatal, "%s %d: fid is null\r\n",__FUNCTION__,__LINE__);
			break;
		}

		jlong taskptr = env->GetLongField(jtask,fid);

		task = (IHCDNDownloaderTask*)taskptr;
	}while(false);

	env->DeleteLocalRef(cls);

	return task;
}