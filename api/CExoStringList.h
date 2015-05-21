#ifndef _CEXOSTRINGLIST_H_
#define _CEXOSTRINGLIST_H_
#include "nwndef.h"

class CExoStringList
{
public:
    void AddSorted(CExoString *);
    void Add(CExoString *);
    int Clear();
    int Delete(CExoString *);
    int GetCount();
    int GetDuplicate();
    int GetSize();
    int GetSorted();
    CExoString * GetString(int);
    int Insert(CExoString *, int);
    void Introduce(CExoString *, int);
    int Merge(CExoStringList *, int, int);
    int Remove(int);
    ~CExoStringList();
    CExoStringList();
    CExoStringList(CExoStringList *);
    CExoStringList(int, int, int);
    int operator=(CExoStringList &);
    int operator[](int);

    /* 0x0/0 */ CExoString **Array;
    /* 0x4/4 */ unsigned long Count;
    /* 0x8/8 */ unsigned long Duplicate;
    /* 0xC/12 */ unsigned long Sorted;
    /* 0x10/16 */ unsigned long Size;
};
#endif
