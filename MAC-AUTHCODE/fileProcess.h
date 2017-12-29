#ifndef _FILEPROCESS_H_
#define _FILEPROCESS_H_
#include <stdio.h>
class fileProcess
{
private:
	FILE *fd;
public:
	int write(char *data);
	fileProcess();
	~fileProcess();
};

#endif
