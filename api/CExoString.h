#ifndef _CEXOSTRING_H_
#define _CEXOSTRING_H_
#include "nwndef.h"

class CExoString
{
public:
	int AsFLOAT() const;
	int AsINT() const;
	int AsTAG() const;
	int CStr() const;
	int CompareNoCase(CExoString const &) const;
	int ComparePrefixNoCase(CExoString const &, int) const;
	int FindNot(char, int) const;
	int Find(CExoString const &, int) const;
	int Find(char, int) const;
	int GetLength() const;
	int Insert(CExoString const &, int);
	int IsEmpty() const;
	int Left(int) const;
	int LowerCase() const;
	int Right(int) const;
	int StripNonAlphaNumeric(int, int, int);
	int SubString(int, int) const;
	int UpperCase() const;
	~CExoString();
	CExoString();
	CExoString(char const *);
	CExoString(char const *, int);
	CExoString(CExoString const &);
	CExoString(int);
	int operator=(char const *);
	int operator=(CExoString const &);
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
	int operator+(CExoString const &) const;
	int operator[](int) const;

	/* 0x0/0 */ char *Text;
	/* 0x4/4 */ unsigned long Length;
};
#endif
