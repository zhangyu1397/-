#ifndef _MACTOAUTHCODE_H_
#define _MACTOAUTHCODE_H_
#include "string.h"
#include "stdio.h"
#include "md5.h"
#define curlx_uztoui(x) (unsigned int)((x)&(size_t)0xffff)
static char ipcFanvilMagic[] = "+\\<_\\>\\)\\<ipCameraFanvil";
class MacTOAuthCode
{
private:
	void mystrlwr(char *data);
	void Curl_md5_get(unsigned char *outbuffer, unsigned char *input, long int length);
	int GetAuthCode(char *data, char* codeOut);

public:
	int tramMAC(char *mac, char *outPut);
};

#endif
