#ifndef _UDPGETBROADCAST_H_
#define _UDPGETBROADCAST_H_
#include "WinSock2.h"
#pragma comment(lib, "Ws2_32.lib")
class udpGetBroadcast
{
private:
	SOCKADDR_IN serverAddr;
	int serverfd;
	int setupServer();
	fd_set sockFD, resSockFD;
public:
	int getAllDat(char *data[], int *count, int *countLen);
	udpGetBroadcast(int port);
	~udpGetBroadcast();
	int getdata(char *data, int *dataLen);
};

#endif

