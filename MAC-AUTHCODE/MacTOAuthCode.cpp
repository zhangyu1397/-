#include "MacTOAuthCode.h"

void MacTOAuthCode::mystrlwr(char *data)
{
	int dataLen = strlen(data);
	for (int i = 0; i < dataLen; i++)
	{
		if ((data[i] < 'Z') && (data[i] > 'A'))
		{
			data[i] = data[i] + 32;
		}
	}
}

int MacTOAuthCode::tramMAC(char *mac, char *outPut)
{
	char cmd[100];
	memset(cmd, 0, sizeof(cmd));
	mystrlwr(mac);
	sprintf_s(cmd, "%s%s", mac, ipcFanvilMagic);
	GetAuthCode(cmd, outPut);
	return 0;
}
void MacTOAuthCode::Curl_md5_get(unsigned char *outbuffer, unsigned char *input, long int length)
{
	MD5_CTX ctx;
	MyMD5Init(&ctx);
	MyMD5Update(&ctx, input, curlx_uztoui(length));
	MyMD5Final(&ctx, outbuffer);
}
int MacTOAuthCode::GetAuthCode(char *data, char* codeOut)
{
	int dataLen = strlen(data);
	int i, j;
	unsigned char md[16];
	memset(md, 0, sizeof(md));

	Curl_md5_get(md, (unsigned char *)data, dataLen);
	i = 0;
	j = 0;
	while (i < 16)
	{
		sprintf(codeOut + j, "%02x", md[i]);
		i += 1;
		j += 2;
	}
	*(codeOut + 32) = '\0';
	return 0;
}