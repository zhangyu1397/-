#include "udpBroadcast.h"



udpBroadcast::udpBroadcast(char* data, int dataLen, int port)
{
	this->ClientAddr.sin_family = AF_INET;
	this->ClientAddr.sin_port = htons(port);
	this->ClientAddr.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");
	ret = 0;
	this->setupClient(data, dataLen);
}


int udpBroadcast::setupClient(char *data, int dataLen)
{
	if ((this->clientfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		ret = -1;
		return -1;
	}

	int on = 1;
	setsockopt(clientfd, SOL_SOCKET, SO_BROADCAST, (char*)&on, sizeof(int));
	sendto(this->clientfd, data, dataLen, 0, (sockaddr *)&this->ClientAddr, sizeof(SOCKADDR_IN));
	
	return 1;
}

udpBroadcast::~udpBroadcast()
{
	closesocket(this->clientfd);
	WSACleanup();
}

