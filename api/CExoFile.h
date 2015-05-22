#ifndef _CEXOFILE_H_
#define _CEXOFILE_H_
#include "nwndef.h"

class CExoFile
{
public:
    int Eof();
    int FileOpened();
    int Flush();
    unsigned long GetOffset();
    int GetSize();
    int ReadAsyncBytesRead();
    int ReadAsyncComplete();
    void ReadAsync(void *, unsigned long, unsigned long);
    int ReadStringLineFromBuffer(unsigned char **, unsigned long *, unsigned char *, unsigned long);
    unsigned long Read(void *, unsigned long, unsigned long);
    unsigned long Read(CExoString &, unsigned long);
    int SeekBeginning();
    int SeekEnd();
    int Seek(int, int);
    int Write(char const *);
    unsigned long Write(void const *, unsigned long, unsigned long);
    unsigned long Write(CExoString const &);
    ~CExoFile();
    CExoFile(CExoString const &, unsigned short, CExoString const &);

};
#endif
