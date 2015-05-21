#ifndef _CEXOENCAPSULATEDFILE_H_
#define _CEXOENCAPSULATEDFILE_H_
#include "nwndef.h"

class CExoEncapsulatedFile
{
public:
    void AddAsyncRefCount();
    void AddRefCount();
    int CloseAsyncFile();
    int CloseFile();
    void DeleteAsyncRefCount();
    void DeleteRefCount();
    int GetDescription();
    unsigned long GetResourceSize(unsigned long);
    int Initialize();
    int LoadHeader(unsigned char);
    int OpenAsyncFile();
    int OpenFile();
    int OpenFile(unsigned char *);
    void ReadResourceAsync(unsigned long, void *, unsigned long, unsigned long);
    unsigned long ReadResource(unsigned long, void *, unsigned long, unsigned long);
    int UnloadHeader();
    ~CExoEncapsulatedFile();
    CExoEncapsulatedFile();

};
#endif
