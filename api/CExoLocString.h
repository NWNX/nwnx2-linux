#ifndef _CEXOLOCSTRING_H_
#define _CEXOLOCSTRING_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoLinkedList.h"

class CExoLocString
{
public:
	int AddString(int, CExoString, unsigned char);
	int ClearLocString();
	int GetStringCount();
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
	int operator=(CExoLocString const &);
	int operator==(CExoLocString &);
	int operator!=(CExoLocString &);

	/* (mtype:CExoLinkedList<ExoLocString_st>) */
	/* 0x0/0 */ CExoLinkedList<ExoLocString_st> List;
};
#endif
