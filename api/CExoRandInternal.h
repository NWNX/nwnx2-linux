#ifndef _CEXORANDINTERNAL_H_
#define _CEXORANDINTERNAL_H_
#include "nwndef.h"

class CExoRandInternal
{
public:
	int Add(unsigned char *, int);
	int GenSeed();
	int GetString(unsigned short);
	int Rand();
	int ReSeed(unsigned long, unsigned long, unsigned long, unsigned long);
	int SignalEvent();
	int SignalEvent(unsigned long);
	~CExoRandInternal();
	CExoRandInternal();

};
#endif
