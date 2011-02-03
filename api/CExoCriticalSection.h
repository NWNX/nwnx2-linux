#ifndef _CEXOCRITICALSECTION_H_
#define _CEXOCRITICALSECTION_H_
#include "nwndef.h"

class CExoCriticalSection
{
public:
	int EnterCriticalSection();
	int LeaveCriticalSection();
	~CExoCriticalSection();
	CExoCriticalSection();

};
#endif
