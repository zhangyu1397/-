#ifndef _PRESION_H_
#define _PRESION_H_

#include "cJSON.h"
#include "md5.h"

class preJson {

public :
	int doPreProcess(char *data[], int countLen, char *MAC[]);
	int getMACByJson(char *data, char *mac[], int count);
	

};
#endif

