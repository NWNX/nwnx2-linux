#ifndef _CEXOTIMERS_H_
#define _CEXOTIMERS_H_
#include "nwndef.h"

class CExoTimers
{
public:
    unsigned __int64 GetHighResolutionTimer();
    unsigned long GetLowResolutionTimer();
    ~CExoTimers();
    CExoTimers();

};
#endif
