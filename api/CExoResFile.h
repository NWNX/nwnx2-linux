#ifndef _CEXORESFILE_H_
#define _CEXORESFILE_H_
#include "nwndef.h"

class CExoResFile
{
public:
    void AddAsyncRefCount();
    void AddRefCount();
    int CloseAsyncFile();
    int CloseFile();
    void DeleteAsyncRefCount();
    void DeleteRefCount();
    unsigned long GetResourceSize(unsigned long);
    int Initialize();
    int LoadHeader(unsigned char);
    int OpenAsyncFile();
    int OpenFile();
    int OpenFile(unsigned char *);
    void ReadResourceAsync(unsigned long, void *, unsigned long, unsigned long);
    unsigned long ReadResource(unsigned long, void *, unsigned long, unsigned long);
    int UnloadHeader();
    ~CExoResFile();
    CExoResFile();

};
#endif
