#include <stdio.h>
#include "pickupData.h"
#include "headType.h"
#include "udpBroadcast.h"
#include "string.h"
#include <iostream>

using namespace std;

int main(int arg, char *argv[])
{
	
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		cout << "error WSA" << endl;
		return 0;
	}
	HEADTYPE trafm;
	if (arg != 2)
	{
		cout << "error arg" << endl;
		return 0;
	}
	char pickEdata[50];
	int dataLen = 0;
	trafm.HFlag = 0xff;
	trafm.VER = 0;
	trafm.RES1 = 0;
	trafm.RES2 = 0;
	trafm.SESID = 0;
	trafm.SEQNUM = 0;
	trafm.TOLPCK = 0;
	trafm.CPCK = 0;
	trafm.MESID = 0x5fa;
	trafm.DATLEN = 0;
	pickupData pickData(trafm, pickEdata, &dataLen);
	udpBroadcast Broadcast(pickEdata,dataLen, atoi(argv[1]));
	return 0;
}