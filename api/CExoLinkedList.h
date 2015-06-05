#ifndef _CEXOLINKEDLIST_H_
#define _CEXOLINKEDLIST_H_
#include "nwndef.h"

template <class T>
class CExoLinkedList
{
public:
    int AddAfter(T *, CExoLinkedListNode *);
    int AddBefore(T *, CExoLinkedListNode *);
    int AddHead(T *);
    int AddTail(T *);
    int Count();
    int GetAtPos(CExoLinkedListNode *);
    int GetHeadPos();
    int GetHead();
    int GetNext(CExoLinkedListNode *&);
    int GetPrev(CExoLinkedListNode *&);
    int GetTailPos();
    int IsEmpty();
    int RemoveHead();
    int RemoveTail();
    int Remove(CExoLinkedListNode *);
    ~CExoLinkedList();
    CExoLinkedList();

    /* 0x0/0 */ CExoLinkedListInternal *List;
};
#endif
