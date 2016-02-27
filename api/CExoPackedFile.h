#ifndef _CEXOPACKEDFILE_H_
#define _CEXOPACKEDFILE_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoPackedFile
{
public:
    CExoFile * GetAsyncFile();
    CExoFile * GetFile();
    ~CExoPackedFile();
    CExoPackedFile();

    /* 0x0/0 */ CExoString field_0;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long File;
    /* 0x14/20 */ unsigned long AsyncFile;
    /* 0x18/24 */ unsigned long field_18;
    /* 0x1C/28 */ unsigned long field_1C;
    /* 0x20/32 */ unsigned long field_20;
    /* 0x24/36 */ unsigned long field_24;
    /* 0x28/40 */ unsigned long field_28;
    /* 0x2C/44 */ CExoPackedFile_vtbl *vptr;
    /* 0x30/48 */ unsigned long field_30;
    /* 0x34/52 */ unsigned long field_34;
};
#endif
