#ifndef NWNX_MODULES_H_
#define NWNX_MODULES_H_

typedef struct
{
	char* database;
	char* key;
	char* player;
	unsigned char *pData;
	int size;
}
	SCORCOStruct;

typedef struct
{
	char* resref; // "whatever.uti"
	unsigned char *pData;
	int size;
}
	ResManDemandResStruct;


#endif  // NWNX_MODULES_H_
