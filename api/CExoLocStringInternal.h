#ifndef _CEXOLOCSTRINGINTERNAL_H_
#define _CEXOLOCSTRINGINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoLocStringInternal
{
public:
    int AddString(int, CExoString);
    int Assign(CExoLocStringInternal *);
    void ClearLocString();
    int Compare(CExoLocString &);
    unsigned long GetStringCount();
    int GetStringLength(unsigned long);
    int GetString(unsigned long, int *, CExoString *);
    int GetString(int, CExoString *);
    int RemoveString(int);
    ~CExoLocStringInternal();
    CExoLocStringInternal();

};
#endif
