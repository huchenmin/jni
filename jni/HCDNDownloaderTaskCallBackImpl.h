#ifndef _HCDNDownloaderTaskCallBackImpl_H_#define _HCDNDownloaderTaskCallBackImpl_H_#include "../HCDNDownloader.h"#include "base/include/AutoLock.h"#include <jni.h>#include <map>  #include <memory>class CHCDNDownloaderTaskCallBackImpl:public IHCDNDownloaderTaskCallBack
{public:	CHCDNDownloaderTaskCallBackImpl();	~CHCDNDownloaderTaskCallBackImpl();public:	//任务下载完成 
	virtual void OnComplete(IHCDNDownloaderTask*task);

	// 任务下载失败 
	virtual void OnError(IHCDNDownloaderTask*task, int error);

	// 任务下载进度， total，总长度， pos，当前下载长度， 单位字节 
	virtual void OnProcess(IHCDNDownloaderTask*task, unsigned long long& total, unsigned long long& pos);

	//hcdn 任务启动成功回调 
	virtual void OnStartTaskSuccess(IHCDNDownloaderTask* task);	//绑定javacallback	void SetJavaCallBack(JavaVM * jvm,jobject cb,jobject jtask);	//解绑javacallback	void ResetJavaCallBack();private:	jobject m_task;	jobject m_objInterface;	jclass m_jclsProcess;	JNIEnv* m_pEnv;	JavaVM* m_pVm;	//jmethodID m_jmidOnComplete;	//jmethodID m_jmidOnError;	//jmethodID m_jmidOnProcess;	//jmethodID m_jmidOnStartTaskSuccess;	bool breset;	bool attached_;	bool m_bcallfunc;	int m_preretryerrorcode;		bool Check();	void detachJNI();};typedef std::shared_ptr<CHCDNDownloaderTaskCallBackImpl> CHCDNDownloaderTaskCallBackImplPtr;#endif 