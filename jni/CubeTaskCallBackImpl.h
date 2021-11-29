#ifndef _CUBETASKCALLBACK_H_
#define _CUBETASKCALLBACK_H_

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
	std::map<IHCDNDownloaderTask*,CHCDNDownloaderTaskCallBackImplPtr> m_taskcbmap;
};


#endif