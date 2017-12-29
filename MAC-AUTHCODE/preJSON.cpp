#include "preJSON.h"
#include <iostream>
using namespace std;

int preJson::doPreProcess(char *datap[], int countLen, char *MAC[])
{
	
	for (int i = 0; i < countLen; i++)
	{
		getMACByJson(&datap[i][20], MAC, i);
		
	}
	return 0;
}

int preJson::getMACByJson(char *data, char *mac[], int count)
{
	cJSON *root, *item, *NetCom;
	root = cJSON_Parse(data);
	if (item = cJSON_GetObjectItem(root, "NetWork.NetCommon"))
	{	
		if (NetCom = cJSON_GetObjectItem(item, "MAC"))
		{
			mac[count] = (char *)malloc(strlen(NetCom->valuestring)+1);
			memset(mac[count], 0, strlen(NetCom->valuestring) + 1);
			strncpy(mac[count], NetCom->valuestring, strlen(NetCom->valuestring));
		}
		else
		{
			cout << "error MAC" << endl;
		}
		cJSON_Delete(NetCom);
	}
	else
	{
		cout << "error NetWork.NetCommon" << endl;
	}
	return 0;
}