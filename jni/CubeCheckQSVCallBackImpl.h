#ifndef _CUBECHECKQSVCALLBACK_H_
#define _CUBECHECKQSVCALLBACK_H_

class CCubeCheckQSVCallBackImpl
{
public:
};

extern CCubeCheckQSVCallBackImpl* gCubeCheckQSVCallBack;

int funcCheckQSVCallBack(const char *szFilePath, int iState, int iValue);


#endif