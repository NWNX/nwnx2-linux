#ifndef _CEXOFILEINTERNAL_H_
#define _CEXOFILEINTERNAL_H_
#include "nwndef.h"

class CExoFileInternal
{
public:
    unsigned long GetOffset();
    int GetSize();
    int ReadAsyncBytesRead();
    int ReadAsyncComplete();
    void ReadAsync(void *, unsigned long, unsigned long);
    unsigned long Read(CExoString *, unsigned long);
    int Write(char const *);
    ~CExoFileInternal();
    CExoFileInternal(CExoString const &, unsigned short, CExoString const &);

};
#endif
