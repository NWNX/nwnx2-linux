#ifndef _CRES2DA_H_
#define _CRES2DA_H_
#include "nwndef.h"
#include "CRes.h"

class CRes2DA : public CRes
{
public:
    unsigned char * Get2DADataPtr();
    int Get2DAHeaderPtr();
    unsigned long Get2DASize();
    int IsLoaded();
    int OnResourceFreed();
    int OnResourceServiced();
    ~CRes2DA();
    CRes2DA();

    /* 0x2C/44 */ unsigned long m_bLoaded;
    /* 0x30/48 */ unsigned long m_n2DANormalSize;
    /* 0x34/52 */ unsigned long m_p2DAData;
    /* 0x38/56 */ unsigned long m_p2DAHeader;
};
#endif
