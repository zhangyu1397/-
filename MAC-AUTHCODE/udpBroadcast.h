#ifndef _UDPBROADCAST_H_
#define _UDPBROADCAST_H_
//#include "stdafx.h"
#include "WinSock2.h"
class udpBroadcast
{
private:
	SOCKADDR_IN ClientAddr;
	int clientfd;
	int  setupClient(char *data, int dataLen);
	//int sendData();
public:
	int ret;
	udpBroadcast(char* data, int dataLen, int port);
	~udpBroadcast();
};


#endif