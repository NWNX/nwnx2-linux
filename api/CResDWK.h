#ifndef _CRESDWK_H_
#define _CRESDWK_H_
#include "nwndef.h"
#include "CRes.h"

class CResDWK : public CRes
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
