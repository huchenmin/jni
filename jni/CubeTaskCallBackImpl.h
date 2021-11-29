#ifndef _CUBETASKCALLBACK_H_
#define _CUBETASKCALLBACK_H_
#include "HCDNDownloader.h"
#include <base/include/AutoLock.h>
#include "HCDNDownloaderTaskCallBackImpl.h"
#include <jni.h>
#include <map>

class CCubeTaskCallBackImpl : public IHCDNDownloaderTaskCallBack
{
public:
	CCubeTaskCallBackImpl();
	~CCubeTaskCallBackImpl();

public:
	bool AdviseJavaCallBack(JavaVM * jvm,jobject jcb,jobject jtask,IHCDNDownloaderTask* pCubeTask);		//通过java参数绑定callback
	bool UnAdviseJavaCallBack(IHCDNDownloaderTask* pCubeTask);												//解绑javacallback

public:
	virtual void OnComplete(IHCDNDownloaderTask* pTask);																//任务下载完成 
	virtual void OnError(IHCDNDownloaderTask* pTask, int ierror);														// 任务下载失败 
	virtual void OnProcess(IHCDNDownloaderTask* pTask, unsigned long long& ullTotal, unsigned long long& ullPos);		// 任务下载进度， total，总长度， pos，当前下载长度， 单位字节 
	virtual void OnStartTaskSuccess(IHCDNDownloaderTask* pTask);														//hcdn 任务启动成功回调 

private:
	psl::CLock m_lock;
	std::map<IHCDNDownloaderTask*,CHCDNDownloaderTaskCallBackImplPtr> m_taskcbmap;
};

extern CCubeTaskCallBackImpl* gCubeTaskCallBackImpl;
extern IHCDNDownloaderCreator* gIHCDNDownloaderCreator;

#endif