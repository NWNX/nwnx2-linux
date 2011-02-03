#ifndef _CEXOTIMERS_H_
#define _CEXOTIMERS_H_
#include "nwndef.h"

class CExoTimers
{
public:
	int GetHighResolutionTimer();
	int GetLowResolutionTimer();
	~CExoTimers();
	CExoTimers();

};
#endif
