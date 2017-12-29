#include <iostream>
#include <stdlib.h>

#include "preJSON.h"
#include "udpBroadcast.h"
#include "udpGetBroadcast.h"
#include "pickupData.h"
#include "fileProcess.h"
#include "headType.h"
#include "md5.h"
#include "MacTOAuthCode.h"
#include <Windows.h>

using namespace std;

DWORD CreateChildProcess(LPSTR szChildProcessCmd)
{
	STARTUPINFO si;
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOW;
	PROCESS_INFORMATION pi;
	if (!CreateProcess(NULL, szChildProcessCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		cout << "Create Fail!" << endl;
		getchar();
		exit(1);
	}
	
	//return 0;

}
int main()
{

	
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		cout << "error WSA\n" << endl;
		return 0;
	}

	char port[20] = {0};
	
	cout << "Input your PortNum" << endl;
	cin >> port;
	getchar();
	char pickEdata[50];
	char *data[10];
	int count[10];
	int countLen = 0;
	int dataLen = 0;
	char *mac[10], authCode[50];
	char writeBuf[100];
	char cmdBuf[50] = {0};
	
	
	fileProcess file;
	
	sprintf(cmdBuf, "UDPBroadcast.exe %s", port);
	udpGetBroadcast getbroadcast(atoi(port));
	
	
	CreateChildProcess((LPSTR )cmdBuf);
	getbroadcast.getAllDat(data, count, &countLen);
	preJson preJSON;
	preJSON.doPreProcess(data, countLen, mac);
	MacTOAuthCode macToAuth;
	for (int i = 0; i < countLen; i++)
	{
		memset(authCode, 0, 50);
		macToAuth.tramMAC(mac[i], authCode);
		memset(writeBuf, 0, sizeof(writeBuf));
		sprintf_s(writeBuf, "MAC: %s    AuthCode: %s\n", mac[i], authCode);
		printf("%d:  %s\n",i ,writeBuf);
		file.write(writeBuf);
	}
	if (countLen == 0)
	cout << "put data in file: MAC-AUTHCODE.txt\n" << endl;
	cout <<"Input enter\n" << endl;
	getchar();
	printf(pickEdata);
}