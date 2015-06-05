#ifndef _CEXOLINKEDLISTINTERNAL_H_
#define _CEXOLINKEDLISTINTERNAL_H_
#include "nwndef.h"

class CExoLinkedListInternal
{
public:
    CExoLinkedListNode * AddAfter(void *, CExoLinkedListNode *);
    CExoLinkedListNode * AddBefore(void *, CExoLinkedListNode *);
    CExoLinkedListNode * AddHead(void *);
    CExoLinkedListNode * AddTail(void *);
    void * GetAtPos(CExoLinkedListNode *);
    int GetNext(CExoLinkedListNode *&);
    int GetPrev(CExoLinkedListNode *&);
    void * RemoveHead();
    void * RemoveTail();
    void * Remove(CExoLinkedListNode *);
    ~CExoLinkedListInternal();

    /* 0x0/0 */ CExoLinkedListNode *FirstElement;
    /* 0x4/4 */ CExoLinkedListNode *LastElement;
    /* 0x8/8 */ unsigned long Count;
};
#endif
