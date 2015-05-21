#ifndef _CEXOTIMERSINTERNAL_H_
#define _CEXOTIMERSINTERNAL_H_
#include "nwndef.h"

class CExoTimersInternal
{
public:
    unsigned __int64 GetHighResolutionTimer();
    unsigned long GetLowResolutionTimer();
    ~CExoTimersInternal();
    CExoTimersInternal();

};
#endif
