#ifndef _CNWNAMEGEN_H_
#define _CNWNAMEGEN_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWNameGen
{
public:
	int GetRandomName();
	int GetRandomName(unsigned short, unsigned char);
	int LoadNameTable(CExoString);
	int UnloadNameTable();
	~CNWNameGen();
	CNWNameGen();

};
#endif
