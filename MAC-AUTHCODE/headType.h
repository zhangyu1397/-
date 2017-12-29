#ifndef _HEADTYPE_H_
#define _HEADTYPE_H_

typedef struct {
	unsigned char HFlag;
	unsigned char VER;
	unsigned char RES1;
	unsigned char RES2;
	unsigned int SESID;
	unsigned int SEQNUM;
	unsigned char TOLPCK;
	unsigned char CPCK;
	unsigned short MESID;
	unsigned int DATLEN;

}HEADTYPE;
	
#endif

