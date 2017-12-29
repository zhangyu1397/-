#include "fileProcess.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"



fileProcess::fileProcess()
{

	fopen_s(&fd, "MAC-AUTHCODE.txt","a+");
	if (fd == NULL)
	{
		printf(__FILE__);
		getchar();
		exit(-1);
	}
}

int fileProcess::write(char *data)
{
	return fwrite(data, strlen(data), 1, fd);
}


fileProcess::~fileProcess()
{
	fclose(fd);
}
