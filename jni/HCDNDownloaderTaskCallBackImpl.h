#ifndef _HCDNDownloaderTaskCallBackImpl_H_
{
	virtual void OnComplete(IHCDNDownloaderTask*task);

	// 任务下载失败 
	virtual void OnError(IHCDNDownloaderTask*task, int error);

	// 任务下载进度， total，总长度， pos，当前下载长度， 单位字节 
	virtual void OnProcess(IHCDNDownloaderTask*task, unsigned long long& total, unsigned long long& pos);

	//hcdn 任务启动成功回调 
	virtual void OnStartTaskSuccess(IHCDNDownloaderTask* task);