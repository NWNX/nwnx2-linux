#ifndef _CEXOBASE_H_
#define _CEXOBASE_H_
#include "nwndef.h"
#include "CExoArrayList.h"
#include "CExoString.h"

class CExoBase
{
public:
    int CheckForCD(unsigned long);
    int GetAugmentedDirectoryList(CExoArrayList<CFileInfo> *, CExoString, unsigned short, int);
    int GetDirectoryList(CExoArrayList<CExoString> *, CExoString, unsigned short, int, int);
    unsigned short GetResTypeFromExtension(CExoString const &);
    CExoString const & GetResourceExtension(unsigned short);
    void LoadAliases(CExoString);
    int ShutDown();
    int SpawnExternalApplication(CExoString const &, CExoString const &, int);
    ~CExoBase();
    CExoBase();

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long CExoTimers;
    /* 0x8/8 */ unsigned long CExoDebug;
    /* 0xC/12 */ unsigned long CExoAliasList;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ unsigned long field_14;
    /* 0x18/24 */ unsigned long field_18;
};
#endif
