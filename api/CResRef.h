#ifndef _CRESREF_H_
#define _CRESREF_H_
#include "nwndef.h"

class CResRef
{
public:
    void CopyToString(char *) const;
    void CopyToString(CExoString &) const;
    unsigned char GetLength() const;
    char * GetResRefStr() const;
    char * GetResRef() const;
    int GetResRef(unsigned char *) const;
    int IsValid() const;
    CResRef();
    CResRef(unsigned char *);
    CResRef(unsigned char *, unsigned char);
    CResRef(char *);
    CResRef(CExoString const &);
    int operator+=(CExoString const &);
    int operator=(unsigned char *);
    CResRef operator=(char *);
    CResRef operator=(CExoString const &);
    CResRef operator=(CResRef const &);
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
