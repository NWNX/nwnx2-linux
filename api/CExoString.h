#ifndef _CEXOSTRING_H_
#define _CEXOSTRING_H_
#include "nwndef.h"

class CExoString
{
public:
    float AsFLOAT() const;
    int AsINT() const;
    CExoString AsTAG() const;
    char * CStr() const;
    int CompareNoCase(CExoString const &) const;
    int ComparePrefixNoCase(CExoString const &, int) const;
    int FindNot(char, int) const;
    int Find(CExoString const &, int) const;
    int Find(char, int) const;
    int GetLength() const;
    void Insert(CExoString const &, int);
    int IsEmpty() const;
    CExoString Left(int) const;
    CExoString LowerCase() const;
    CExoString Right(int) const;
    int StripNonAlphaNumeric(int, int, int);
    CExoString SubString(int, int) const;
    CExoString UpperCase() const;
    ~CExoString();
    CExoString();
    CExoString(char const *);
    CExoString(char const *, int);
    CExoString(CExoString const &);
    CExoString(int);
    CExoString & operator=(char const *);
    CExoString & operator=(CExoString const &);
    int operator==(char const *) const;
    int operator==(CExoString const &) const;
    int operator>=(char const *) const;
    int operator>=(CExoString const &) const;
    int operator>(char const *) const;
    int operator>(CExoString const &) const;
    int operator<=(char const *) const;
    int operator<=(CExoString const &) const;
    int operator<(char const *) const;
    int operator<(CExoString const &) const;
    int operator!=(char const *) const;
    int operator!=(CExoString const &) const;
    CExoString operator+(CExoString const &) const;
    char operator[](int) const;

    /* 0x0/0 */ char *Text;
    /* 0x4/4 */ unsigned long Length;
};
#endif
