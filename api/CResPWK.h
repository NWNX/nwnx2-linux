#ifndef _CRESPWK_H_
#define _CRESPWK_H_
#include "nwndef.h"
#include "CRes.h"

class CResPWK : public CRes
{
public:
    unsigned char * GetPWKDataPtr();
    unsigned long GetPWKSize();
    int IsLoaded();
    int OnResourceFreed();
    int OnResourceServiced();
    ~CResPWK();
    CResPWK();

};
#endif
