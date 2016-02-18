#ifndef _CRESWOK_H_
#define _CRESWOK_H_
#include "nwndef.h"
#include "CRes.h"

class CResWOK : public CRes
{
public:
    unsigned char * GetWOKDataPtr();
    unsigned long GetWOKSize();
    int IsLoaded();
    int OnResourceFreed();
    int OnResourceServiced();
    ~CResWOK();
    CResWOK();

};
#endif
