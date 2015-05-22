#ifndef _CEXOCRITICALSECTIONINTERNAL_H_
#define _CEXOCRITICALSECTIONINTERNAL_H_
#include "nwndef.h"

class CExoCriticalSectionInternal
{
public:
    void EnterCriticalSection();
    void LeaveCriticalSection();
    ~CExoCriticalSectionInternal();
    CExoCriticalSectionInternal();

};
#endif
