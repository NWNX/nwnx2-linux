#ifndef _CEXOTIMERSINTERNAL_H_
#define _CEXOTIMERSINTERNAL_H_
#include "nwndef.h"

class CExoTimersInternal
{
public:
	int GetHighResolutionTimer();
	int GetLowResolutionTimer();
	~CExoTimersInternal();
	CExoTimersInternal();

};
#endif
