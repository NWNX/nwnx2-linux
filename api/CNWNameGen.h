#ifndef _CNWNAMEGEN_H_
#define _CNWNAMEGEN_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWNameGen
{
public:
    CExoString GetRandomName();
    CExoString GetRandomName(unsigned short, unsigned char);
    int LoadNameTable(CExoString);
    void UnloadNameTable();
    ~CNWNameGen();
    CNWNameGen();

};
#endif
