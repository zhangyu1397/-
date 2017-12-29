#include "udpGetBroadcast.h"
#include "iostream"
#include "winSock2.h"
using namespace std;



udpGetBroadcast::udpGetBroadcast(int port)
{
	serverAddr.sin_family= AF_INET;
	serverAddr.sin_port= htons(port);
	serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	setupServer();
}
int udpGetBroadcast::setupServer()
{
	this->serverfd = socket(AF_INET, SOCK_DGRAM, 0);
	int set = 1;
	setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR, (char*)&set, sizeof(int));
	if (bind(serverfd, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
	{
		cout << "bind error"<<endl;
		return -1;
	}
	return 0;
}


int udpGetBroadcast::getdata(char *data, int *dataLen)
{
	char getDat[1024];
	int len = sizeof(serverAddr);
	memset(getDat, 0, sizeof(getDat));
	int getDatLen = recvfrom(serverfd, getDat, sizeof(getDat), 0, (sockaddr*)&serverfd, &len);
	memcpy(data, getDat, getDatLen);	
	*dataLen = getDatLen;
	return getDatLen;
}

udpGetBroadcast::~udpGetBroadcast()
{
	closesocket(this->serverfd);
	WSACleanup();
}


int udpGetBroadcast::getAllDat(char *data[], int *count, int *countLen)
{
	FD_ZERO(&sockFD);
	FD_SET(serverfd, &sockFD);
	int cnt = 10, result = 0;
	int getDatLen = 0;
	struct timeval timeOut;
	int addrLen = sizeof(serverAddr);
	char buf[1024];
	*countLen = 0;
	cout << "Searching......\n" << endl;
	while (cnt --)
	{
		timeOut.tv_sec = 1;
		timeOut.tv_usec = 0;
		resSockFD = sockFD;
		result = select(FD_SETSIZE, &resSockFD, NULL, NULL, &timeOut);
		if (result > 0)
		{
			if (FD_ISSET(serverfd, &resSockFD))
			{
				memset(buf, 0, 1024);
				if (0 < (getDatLen = recvfrom(serverfd, buf, 1024, 0, (struct sockaddr *)&serverAddr, &addrLen)))
				{
					if (getDatLen > 30)
					{
						data[*countLen] = (char*)malloc(getDatLen + 1);
						memset(data[*countLen], 0, getDatLen + 1);
						memcpy(data[*countLen], buf, getDatLen);
						count[*countLen] = getDatLen;
						*countLen += 1;
						getDatLen = 0;
						
					}
				}
			}

		}
	}
	cout << "Search Over\n" << endl;
	return 0;
}