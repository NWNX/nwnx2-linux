#ifndef _CEXOLINKEDLIST_H_
#define _CEXOLINKEDLIST_H_

#include "typedefs.h"

struct CExoLinkedListElement {
    CExoLinkedListElement *PrevoiusElement;
    CExoLinkedListElement *NextElement;
    void                  *Data;
};

struct CExoLinkedListHeader_1 {
    CExoLinkedListElement *FirstElement;
    CExoLinkedListElement *LastElement;
    //dword                  Count;
};

class CExoLinkedList_c
{
public:
    CExoLinkedListHeader_1 *ListHeader;
    dword                 Count;

    CExoLinkedListElement *GetHeadPos();
    void                  *GetHead();
    void                  *GetAtPos(CExoLinkedListElement *Position);
    CExoLinkedListElement *GetNext(CExoLinkedListElement *Position);
    CExoLinkedListElement *AddTail(void *pData);
};

#endif
