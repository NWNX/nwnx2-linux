#ifndef _CRESGFFFIELDIDHASH_H_
#define _CRESGFFFIELDIDHASH_H_
#include "nwndef.h"

class CResGFFFieldIDHash
{
public:
    static unsigned long Hash(char const *, unsigned long);
    static void Initialize();

};
#endif
