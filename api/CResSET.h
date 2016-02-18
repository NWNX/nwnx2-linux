#ifndef _CRESSET_H_
#define _CRESSET_H_
#include "nwndef.h"
#include "CRes.h"

class CResSET : public CRes
{
public:
    int CopySETData(unsigned char *);
    int CreateSectionTable();
    int GetNextLine(unsigned long, unsigned long *);
    int GetSETDataPtr();
    int GetSETSize();
    void GetSectionEntryValue(char *, char *, char *);
    int IsLoaded();
    int OnResourceFreed();
    int OnResourceServiced();
    int SkipWhiteSpace(char *);
    ~CResSET();
    CResSET();

};
#endif
