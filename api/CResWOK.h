#ifndef _CRESWOK_H_
#define _CRESWOK_H_
#include "nwndef.h"

class CResWOK
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
