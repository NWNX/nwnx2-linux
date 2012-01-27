#ifndef _CRESREF_H_
#define _CRESREF_H_
#include "nwndef.h"

class CResRef
{
public:
	int CopyToString(char *) const;
	int CopyToString(CExoString &) const;
	int GetLength() const;
	int GetResRefStr() const;
	int GetResRef() const;
	int GetResRef(unsigned char *) const;
	int IsValid() const;
	CResRef();
	CResRef(unsigned char *);
	CResRef(unsigned char *, unsigned char);
	CResRef(char *);
	CResRef(CExoString const &);
	int operator+=(CExoString const &);
	int operator=(unsigned char *);
	int operator=(char *);
	int operator=(CExoString const &);
	int operator=(CResRef const &);
	int operator==(char *) const;
	int operator==(CExoString const &) const;
	int operator==(CResRef const &) const;
	int operator!=(char *) const;
	int operator!=(CExoString const &) const;
	int operator!=(CResRef const &) const;
	int operator!();

	/* 0x0/0 */ char m_resRef[16];
};
#endif
