#ifndef _CUBECHECKQSVCALLBACK_H_
#define _CUBECHECKQSVCALLBACK_H_#include "HCDNDownloader.h"#include <base/include/AutoLock.h>#include <jni.h>

class CCubeCheckQSVCallBackImpl
{
public:    CCubeCheckQSVCallBackImpl();    ~CCubeCheckQSVCallBackImpl();public:    int OnCheckStatus(const char* szFilePath,int iState,int iValue);    bool SetJavaCallBack(JavaVM * jvm,jobject cb);private:    void ResetJavaCallBack();    bool Check();    void detachJNI();private:    jobject m_objInterface;    jclass m_jclsProcess;    JNIEnv* m_pEnv;    JavaVM* m_pVm;        bool attached_;    bool m_bcallfunc;    bool m_bSetCallBack;
};

extern CCubeCheckQSVCallBackImpl* gCubeCheckQSVCallBack;

int funcCheckQSVCallBack(const char *szFilePath, int iState, int iValue);


#endif