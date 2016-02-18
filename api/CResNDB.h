#ifndef _CRESNDB_H_
#define _CRESNDB_H_
#include "nwndef.h"
#include "CRes.h"

class CResNDB : public CRes
{
public:
    unsigned char * GetNDBDataPtr();
    unsigned long GetNDBSize();
    int IsLoaded();
    int OnResourceFreed();
    int OnResourceServiced();
    ~CResNDB();
    CResNDB();

};
#endif
