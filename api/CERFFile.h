#ifndef _CERFFILE_H_
#define _CERFFILE_H_
#include "nwndef.h"

class CERFFile
{
public:
    int AddResource(char *, unsigned short, CRes *);
    int AddResource(CExoString &);
    int AddString(CERFString *);
    int Create(CExoString &);
    int Finish();
    int ReadModuleDescription(CExoString const &, unsigned short, unsigned long *, CExoString *);
    int Read();
    int RecalculateOffsets();
    int RemoveResource(CERFRes *);
    int RemoveResource(CExoString &, unsigned short);
    int Reset();
    int SetNumEntries(unsigned long);
    void SetVersion(char *);
    int WriteHeader();
    int WriteResource(char *, unsigned short, CRes *, int);
    int WriteStringTable();
    int Write(CExoString &);
    ~CERFFile();
    CERFFile();

    /* 0x0/0 */ unsigned long field_0;
};
#endif
