#include "CubeTaskCallBackImpl.h"
#include <Logger/include/InterfaceLogger.h>

CCubeTaskCallBackImpl::CCubeTaskCallBackImpl()
{

}

CCubeTaskCallBackImpl::~CCubeTaskCallBackImpl()
{
	m_taskcbmap.clear();
}

bool CCubeTaskCallBackImpl::AdviseJavaCallBack(JavaVM * jvm,jobject jcb,jobject jtask,IHCDNDownloaderTask* pCubeTask)
{
	if((NULL == jvm)||(NULL == jcb)||(NULL == jtask)||(NULL == pCubeTask))
		return false;

	psl::AutoLock ALock(m_lock);

	CHCDNDownloaderTaskCallBackImplPtr cbptr(new CHCDNDownloaderTaskCallBackImpl());
	cbptr->SetJavaCallBack(jvm,jcb,jtask);

	//std::map<IHCDNDownloaderTask*,CHCDNDownloaderTaskCallBackImplPtr>::iterator it_task = m_taskcbmap.find(pCubeTask);
	//if (m_taskcbmap.end() != it_task)
	//{
	//	it_task->second = cbptr;
	//}
	//else
	//{
	//	m_taskcbmap.insert(std::pair<IHCDNDownloaderTask*,CHCDNDownloaderTaskCallBackImplPtr>(pCubeTask,cbptr));
	//}
	m_taskcbmap[pCubeTask] = cbptr;

	return true;
}

bool CCubeTaskCallBackImpl::UnAdviseJavaCallBack(IHCDNDownloaderTask* pCubeTask)
{
	psl::AutoLock ALock(m_lock);

	std::map<IHCDNDownloaderTask*,CHCDNDownloaderTaskCallBackImplPtr>::iterator it_task = m_taskcbmap.find(pCubeTask);
	if (m_taskcbmap.end() != it_task)
		m_taskcbmap.erase(it_task);

	return true;
}

void CCubeTaskCallBackImpl::OnStartTaskSuccess(IHCDNDownloaderTask* pTask)
{
	CHCDNDownloaderTaskCallBackImplPtr HCDNCBptr;

	{
		psl::AutoLock ALock(m_lock);
		std::map<IHCDNDownloaderTask*,CHCDNDownloaderTaskCallBackImplPtr>::iterator it_task = m_taskcbmap.find(pTask);
		if(m_taskcbmap.end() != it_task)
		{
			HCDNCBptr = it_task->second;
		}
		else
		{
			psl::logger::CLogger::PrintA("CHCDNDownloaderTaskCallBackImpl",psl::logger::_Fatal, "%s %d: not find callback m_taskcbmap.count = %d\r\n",__FUNCTION__,__LINE__,m_taskcbmap.size());
			return;
		}
	}

	HCDNCBptr->OnStartTaskSuccess(pTask);
}

void CCubeTaskCallBackImpl::OnProcess(IHCDNDownloaderTask* pTask, unsigned long long& ullTotal, unsigned long long& ullPos)
{
	CHCDNDownloaderTaskCallBackImplPtr HCDNCBptr;

	{
		psl::AutoLock ALock(m_lock);
		std::map<IHCDNDownloaderTask*,CHCDNDownloaderTaskCallBackImplPtr>::iterator it_task = m_taskcbmap.find(pTask);
		if(m_taskcbmap.end() != it_task)
		{
			HCDNCBptr = it_task->second;
		}
		else
		{
			return;
		}
	}

	HCDNCBptr->OnProcess(pTask,ullTotal,ullPos);
}

void CCubeTaskCallBackImpl::OnComplete(IHCDNDownloaderTask* pTask)
{
	CHCDNDownloaderTaskCallBackImplPtr HCDNCBptr;

	{
		psl::AutoLock ALock(m_lock);
		std::map<IHCDNDownloaderTask*,CHCDNDownloaderTaskCallBackImplPtr>::iterator it_task = m_taskcbmap.find(pTask);
		if(m_taskcbmap.end() != it_task)
		{
			HCDNCBptr = it_task->second;
		}
		else
		{
			return;
		}
	}

	HCDNCBptr->OnComplete(pTask);
}

void CCubeTaskCallBackImpl::OnError(IHCDNDownloaderTask* pTask, int ierror)
{
	CHCDNDownloaderTaskCallBackImplPtr HCDNCBptr;

	{
		psl::AutoLock ALock(m_lock);
		std::map<IHCDNDownloaderTask*,CHCDNDownloaderTaskCallBackImplPtr>::iterator it_task = m_taskcbmap.find(pTask);
		if(m_taskcbmap.end() != it_task)
		{
			HCDNCBptr = it_task->second;
		}
		else
		{
			return;
		}
	}

	HCDNCBptr->OnError(pTask,ierror);
}