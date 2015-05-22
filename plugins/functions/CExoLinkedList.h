#ifndef _CEXOLINKEDLIST_H_
#define _CEXOLINKEDLIST_H_

#include "typedefs.h"

struct CExoLinkedListElement {
    CExoLinkedListElement *PrevoiusElement;
    CExoLinkedListElement *NextElement;
    void                  *Data;
};

struct CExoLinkedListHeader {
    CExoLinkedListElement *FirstElement;
    CExoLinkedListElement *LastElement;
    //dword                  Count;
};

class CExoLinkedList
{
public:
    CExoLinkedListHeader *ListHeader;
    dword                 Count;

    CExoLinkedListElement *GetHeadPos();
    void                  *GetHead();
    void                  *GetAtPos(CExoLinkedListElement *Position);
    CExoLinkedListElement *GetNext(CExoLinkedListElement *Position);
    CExoLinkedListElement *AddTail(void *pData);
};

#endif
