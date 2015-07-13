#ifndef _CEXOARRAYLIST_H_
#define _CEXOARRAYLIST_H_
#include "nwndef.h"

template <class T>
class CExoArrayList
{
public:
    int AddUnique(T);
    void Add(T);
    void Allocate(int);
    int Contains(T);
    int DelIndex(int);
    int DerefContains(T);
    int IndexOf(T);
    void Insert(T, int);
    T Pack();
    void Remove(T);
    int SetSize(int);
    ~CExoArrayList();
    int operator=(CExoArrayList<T> const &);
    CExoArrayList(int);
    CExoArrayList(CExoArrayList<T> const &);
    T & operator[](int) const;
    T & operator[](int);

    /* 0x0/0 */ T *Array;

    /* You might have come here for compile errors regarding nAllocatedSize.
     * The fields were labelled incorrectly, so they have been swapped.
     * In order to not break plugins in subtle ways we've renamed them.
     * You probably want "Length" now.
     */
    /* 0x4/4 */ unsigned long Length;
    /* 0x8/8 */ unsigned long ArraySize;
};
#endif
