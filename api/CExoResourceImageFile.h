#ifndef _CEXORESOURCEIMAGEFILE_H_
#define _CEXORESOURCEIMAGEFILE_H_
#include "nwndef.h"
#include "CExoPackedFile.h"

class CExoResourceImageFile
{
public:
    void AddAsyncRefCount();
    void AddRefCount();
    int CloseAsyncFile();
    int CloseFile();
    void DeleteAsyncRefCount();
    void DeleteRefCount();
    int GetHeader();
    int GetKeyListEntry(unsigned long);
    int GetKeyList();
    EncapsulatedResListEntry_st * GetResourceListEntry(unsigned long);
    unsigned long GetResourceSize(unsigned long);
    void * GetResource(unsigned long);
    int Initialize();
    int LoadHeader(unsigned char);
    int OpenAsyncFile();
    int OpenFile();
    int OpenFile(unsigned char *);
    void ReadResourceAsync(unsigned long, void *, unsigned long, unsigned long);
    unsigned long ReadResource(unsigned long, void *, unsigned long, unsigned long);
    int UnloadHeader();
    ~CExoResourceImageFile();
    CExoResourceImageFile();

    /* 0x0/0 */ CExoPackedFile PackedFile;
};
#endif
