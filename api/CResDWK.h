#ifndef _CRESDWK_H_
#define _CRESDWK_H_
#include "nwndef.h"

class CResDWK
{
public:
    unsigned char * GetDWKDataPtr();
    unsigned long GetDWKSize();
    int IsLoaded();
    int OnResourceFreed();
    int OnResourceServiced();
    ~CResDWK();
    CResDWK();

};
#endif
