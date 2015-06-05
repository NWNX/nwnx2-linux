#ifndef _CEXOKEYTABLE_H_
#define _CEXOKEYTABLE_H_
#include "nwndef.h"
#include "CExoLinkedList.h"
#include "CExoString.h"

class CExoKeyTable
{
public:
    int AddDirectoryContents(int);
    int AddEncapsulatedContents(int);
    int AddKeyTableContents(int);
    CKeyTableEntry * AddKey(CResRef const &, unsigned short, unsigned long, int);
    int AddResourceImageContents(int, unsigned char *);
    int AllocateTable(unsigned long, int);
    int BuildNewTable(unsigned long, CExoString const &, unsigned long, int, unsigned char *);
    int DeleteTableList(CExoLinkedList<CKeyTableInfo> *);
    void DestroyTable();
    int FindKey(CRes *);
    CKeyTableEntry * FindKey(CResRef const &, unsigned short);
    int GetEntryCount(int);
    CExoStringList * GetKeysOfType(unsigned short);
    int GetResID(CResRef const &, unsigned short);
    int GetRes(CResRef const &, unsigned short);
    int GetTableEntry(unsigned long, CResRef &, unsigned short &);
    int GetTableIndex(unsigned long &, CResRef const &, unsigned short);
    int Hash(CResRef const &, unsigned short);
    int LocateBifFile(CExoString const &);
    void RebuildTable(unsigned char *);
    ~CExoKeyTable();
    CExoKeyTable();

    /* 0x0/0 */ unsigned long Loaded;
    /* 0x4/4 */ unsigned long ExcludeFromSearches;
    /* 0x8/8 */ unsigned long TableEntries;
    /* 0xC/12 */ CKeyTableEntry *Entries;
    /* 0x10/16 */ unsigned long Searchs;
    /* 0x14/20 */ unsigned long WorstSearch;
    /* 0x18/24 */ unsigned long TableType;
    /* 0x1C/28 */ CExoString Name;
    /* 0x24/36 */ CExoString Directory;
    /* 0x2C/44 */ unsigned long TableID;
    /* 0x30/48 */ unsigned long NumPackedFiles;
    /* 0x34/52 */ CExoPackedFile **ExoPackedFile;
};
#endif
