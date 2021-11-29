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
	bool AdviseJavaCallBack(JavaVM * jvm,jobject jcb,jobject jtask,IHCDNDownloaderTask* pCubeTask);		//ͨ��java������callback
	bool UnAdviseJavaCallBack(IHCDNDownloaderTask* pCubeTask);												//���javacallback

public:
	virtual void OnComplete(IHCDNDownloaderTask* pTask);																//����������� 
	virtual void OnError(IHCDNDownloaderTask* pTask, int ierror);														// ��������ʧ�� 
	virtual void OnProcess(IHCDNDownloaderTask* pTask, unsigned long long& ullTotal, unsigned long long& ullPos);		// �������ؽ��ȣ� total���ܳ��ȣ� pos����ǰ���س��ȣ� ��λ�ֽ� 
	virtual void OnStartTaskSuccess(IHCDNDownloaderTask* pTask);														//hcdn ���������ɹ��ص� 

private:
	psl::CLock m_lock;
	std::map<IHCDNDownloaderTask*,CHCDNDownloaderTaskCallBackImplPtr> m_taskcbmap;
};

extern CCubeTaskCallBackImpl* gCubeTaskCallBackImpl;
extern IHCDNDownloaderCreator* gIHCDNDownloaderCreator;

#endif