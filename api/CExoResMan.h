#ifndef _CEXORESMAN_H_
#define _CEXORESMAN_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoLinkedList.h"

class CExoResMan
{
public:
    int AddEncapsulatedResourceFile(CExoString const &);
    int AddFixedKeyTableFile(CExoString const &);
    int AddKeyTable(CExoString const &, unsigned long, unsigned char *);
    int AddResourceDirectory(CExoString const &);
    int AddResourceImageFile(CExoString const &, unsigned char *);
    int CancelRequest(CRes *);
    int CleanDirectory(CExoString, int, int);
    int CreateDirectory(CExoString);
    void * Demand(CRes *);
    int DumpAll();
    int Dump(CRes *, int);
    int Exists(CResRef const &, unsigned short, unsigned long *);
    int FreeChunk();
    int FreeResourceData(CRes *);
    int Free(CRes *);
    int GetEncapsulatedFileDescription(CExoString const &);
    int GetFreeDiskSpace(CExoString const &, unsigned long long *);
    int GetIsStaticType(unsigned short);
    int GetKeyEntry(CResRef const &, unsigned short, CExoKeyTable **, CKeyTableEntry **);
    int GetNewResRef(CResRef const &, unsigned short, CResRef &);
    int GetResID(CResRef const &, unsigned short);
    CRes * GetResObject(CResRef const &, unsigned short);
    CExoStringList * GetResOfType(unsigned short, CRes *);
    int GetResOfType(unsigned short, int);
    void GetResRefFromFile(CResRef &, CExoString const &);
    unsigned short GetResTypeFromFile(CExoString const &);
    int GetTableCount(CRes *, int);
    CExoKeyTable * GetTable(CRes *);
    int GetTotalPhysicalMemory();
    int Malloc(CRes *);
    int NukeDirectory(CExoString, int, int);
    int ReadRaw(CRes *, int, char *);
    int ReleaseResObject(CRes *);
    int Release(CRes *);
    int RemoveEncapsulatedResourceFile(CExoString const &);
    int RemoveFile(CExoString const &, unsigned short);
    int RemoveFixedKeyTableFile(CExoString const &);
    int RemoveFromToBeFreedList(CRes *);
    int RemoveKeyTable(CExoString const &, unsigned long);
    int RemoveResourceDirectory(CExoString const &);
    int RemoveResourceImageFile(CExoString const &);
    int Request(CRes *);
    int ResumeServicing();
    int ServiceCurrentAsyncRes();
    int ServiceFromDirectoryRaw(CRes *, int, char *);
    int ServiceFromDirectory(CRes *, int);
    int ServiceFromEncapsulatedRaw(CRes *, int, char *);
    int ServiceFromEncapsulated(CRes *, int);
    int ServiceFromImageRaw(CRes *, int, char *);
    int ServiceFromImage(CRes *, int);
    int ServiceFromResFileRaw(CRes *, int, char *);
    int ServiceFromResFile(CRes *, int);
    void SetResObject(CResRef const &, unsigned short, CRes *);
    int SetTotalResourceMemory(int);
    int SuspendServicing();
    int UpdateEncapsulatedResourceFile(CExoString const &);
    int UpdateFixedKeyTableFile(CExoString const &);
    int UpdateKeyTable(CExoString const &, unsigned long);
    int UpdateResourceDirectory(CExoString const &);
    int Update(unsigned long);
    int WipeDirectory(CExoString, int, int, int, int);
    ~CExoResMan();
    CExoResMan();

    /* 0x0/0 */ unsigned long TotalPhysicalMemory;
    /* 0x4/4 */ unsigned long TotalAvailableMemory;
    /* 0x8/8 */ unsigned long AvailableMemory;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ void *FixedKeyTables;
    /* 0x14/20 */ void *DirectoryKeyTables;
    /* 0x18/24 */ void *EncapsulatedKeyTables;
    /* 0x1C/28 */ void *ImageKeyTables;
    /* (mtype:CExoLinkedList<CRes *>) */
    /* 0x20/32 */ CExoLinkedList<CRes *> ToBeFreedList;
    /* 0x24/36 */ unsigned long AsyncResQueue;
    /* 0x28/40 */ unsigned long CurrentAsyncRes;
    /* 0x2C/44 */ unsigned long AsyncFile;
    /* 0x30/48 */ unsigned long AsyncSuspended;
    /* 0x34/52 */ unsigned long field_34;
    /* 0x38/56 */ unsigned long field_38;
    /* 0x3C/60 */ unsigned long field_3C;
    /* 0x40/64 */ unsigned long field_40;
    /* 0x44/68 */ unsigned long field_44;
};
#endif
