#ifndef _CEXORAND_H_
#define _CEXORAND_H_
#include "nwndef.h"

class CExoRand
{
public:
	int GetString(unsigned short);
	int Rand();
	int SignalEvent();
	int SignalEvent(unsigned long);
	~CExoRand();
	CExoRand();

};
#endif
