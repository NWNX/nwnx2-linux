#ifndef _CERFRES_H_
#define _CERFRES_H_
#include "nwndef.h"

class CERFRes
{
public:
    int Read();
    int Reset();
    int Write(CExoFile &, unsigned long);
    ~CERFRes();
    CERFRes();

};
#endif
