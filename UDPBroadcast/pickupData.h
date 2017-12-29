#ifndef _PICKUPDATA_H_
#define _PICKUPDATA_H_
#include <string.h>
#include "headType.h"

class pickupData {

private:

	HEADTYPE headtype;
	char *data;
	void pickDataProcess();
	int *dataLen;
public:
	pickupData(HEADTYPE headType, char *data, int *dataLen);
	pickupData(int a);
	pickupData(char *b ,int a);
};
#endif
