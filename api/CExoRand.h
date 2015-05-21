#ifndef _CEXORAND_H_
#define _CEXORAND_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoRand
{
public:
    CExoString GetString(unsigned short);
    unsigned long Rand();
    void SignalEvent();
    int SignalEvent(unsigned long);
    ~CExoRand();
    CExoRand();

};
#endif
