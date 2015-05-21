#ifndef _CRESNDB_H_
#define _CRESNDB_H_
#include "nwndef.h"

class CResNDB
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
