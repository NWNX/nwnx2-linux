#ifndef _CRESNSS_H_
#define _CRESNSS_H_
#include "nwndef.h"
#include "CRes.h"

class CResNSS : public CRes
{
public:
    unsigned char * GetNSSDataPtr();
    unsigned long GetNSSSize();
    int IsLoaded();
    int OnResourceFreed();
    int OnResourceServiced();
    ~CResNSS();
    CResNSS();

};
#endif
