#include "pickupData.h"

pickupData::pickupData(HEADTYPE headType, char *data, int *dataLen)
{
	this->headtype = headType;
	this->data = data;
	this->dataLen = dataLen;
	this->pickDataProcess();
}

pickupData::pickupData(int a)
{
	;
}

pickupData::pickupData(char *b,int a)
{
	;
}
void pickupData::pickDataProcess()
{
	int headLen = sizeof(HEADTYPE);
	memcpy( this->data, (char *)&(this->headtype), headLen);
	*this->dataLen = headLen;
	if (this->data != nullptr)
	{
		int datalen = strlen( this->data );
		memcpy(&this->data[headLen], this->data, datalen);
		*this->dataLen += datalen;
	}
}



