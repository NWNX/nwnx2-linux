#ifndef _CEXOLOCSTRINGINTERNAL_H_
#define _CEXOLOCSTRINGINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoLinkedList.h"

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

    /* (mtype:CExoLinkedList<ExoLocString_st>) */
    /* 0x0/0 */ CExoLinkedList<ExoLocString_st> List;
    /* 0x4/4 */ unsigned long StringCount;
};
#endif
