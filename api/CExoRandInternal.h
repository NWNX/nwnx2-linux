#ifndef _CEXORANDINTERNAL_H_
#define _CEXORANDINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoRandInternal
{
public:
    int Add(unsigned char *, int);
    int GenSeed();
    CExoString GetString(unsigned short);
    unsigned long Rand();
    void ReSeed(unsigned long, unsigned long, unsigned long, unsigned long);
    void SignalEvent();
    int SignalEvent(unsigned long);
    ~CExoRandInternal();
    CExoRandInternal();

};
#endif
