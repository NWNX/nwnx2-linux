#ifndef _CRES_H_
#define _CRES_H_
#include "nwndef.h"

class CRes
{
public:
    int CancelRequest();
    void * Demand();
    void Dump(int);
    void * GetData();
    int GetDemands();
    int GetFixedResourceDataOffset();
    int GetFixedResourceSize();
    int GetID();
    int GetRequests();
    int GetSize();
    int OnResourceFreed();
    int OnResourceServiced();
    int ReadRaw(int, char *);
    int Release();
    int Request();
    int SetID(unsigned long);
    int SetPos(CExoLinkedListNode *);
    ~CRes();
    CRes();
    CRes(unsigned long);

    /* 0x0/0 */ unsigned short m_nDemands;
    /* 0x2/2 */ unsigned short m_nRequests;
    /* 0x4/4 */ unsigned long m_nID;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ void *m_pResource;
    /* 0x10/16 */ CKeyTableEntry *m_pKeyEntry;
    /* 0x14/20 */ unsigned long m_nSize;
    /* 0x18/24 */ unsigned long m_status;
    /* 0x1C/28 */ unsigned long field_1C;
    /* 0x20/32 */ unsigned long field_20;
    /* 0x24/36 */ CExoLinkedListNode *m_pToBeFreedListNode;
    /* 0x28/40 */ CRes_vtbl *vptr;
};
#endif
