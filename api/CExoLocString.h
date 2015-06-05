#ifndef _CEXOLOCSTRING_H_
#define _CEXOLOCSTRING_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoLocString
{
public:
    int AddString(int, CExoString, unsigned char);
    void ClearLocString();
    unsigned long GetStringCount();
    int GetStringInternal(int, CExoString *);
    int GetStringLength(unsigned long);
    int GetStringLoc(int, CExoString *, unsigned char);
    int GetString(unsigned long, int *, CExoString *, unsigned char *);
    int GetString(int, CExoString *, unsigned char, bool);
    int RemoveString(int);
    int RemoveString(int, unsigned char);
    ~CExoLocString();
    CExoLocString();
    CExoLocString(CExoLocString const &);
    CExoLocString & operator=(CExoLocString const &);
    int operator==(CExoLocString &);
    int operator!=(CExoLocString &);

    /* 0x0/0 */ CExoLocStringInternal *Internal;
    /* 0x4/4 */ unsigned long StrRef;
};
#endif
