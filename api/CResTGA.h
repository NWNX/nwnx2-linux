#ifndef _CRESTGA_H_
#define _CRESTGA_H_
#include "nwndef.h"
#include "CRes.h"

class CResTGA : public CRes
{
public:
    int CopyTGAData(unsigned char *);
    int GetTGAAttrib(unsigned long *, unsigned long *, unsigned char *);
    int GetTGAColorMapPtr();
    int GetTGADataPtr();
    int GetTGAHeaderPtr();
    int GetTGASize();
    int IsColorMapped();
    int IsCompressed();
    int IsLoaded();
    int OnResourceFreed();
    int OnResourceServiced();
    int ReadColorMappedRLETGA();
    int ReadUnmappedRLETGA();
    int Write(CExoString &);
    ~CResTGA();
    CResTGA();

};
#endif
