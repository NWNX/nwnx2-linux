#ifndef _CEXOCRITICALSECTION_H_
#define _CEXOCRITICALSECTION_H_
#include "nwndef.h"

class CExoCriticalSection
{
public:
    void EnterCriticalSection();
    void LeaveCriticalSection();
    ~CExoCriticalSection();
    CExoCriticalSection();

};
#endif
