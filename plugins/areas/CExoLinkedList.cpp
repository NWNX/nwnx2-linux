#include <stdlib.h>
#include "CExoLinkedList.h"

CExoLinkedListElement *CExoLinkedList::GetHeadPos()
{
    return this->ListHeader->FirstElement;
}

void *CExoLinkedList::GetHead()
{
    if (this->ListHeader->FirstElement)
        return this->ListHeader->FirstElement->Data;
    else return NULL;

}

void *CExoLinkedList::GetAtPos(CExoLinkedListElement *Position)
{
    if (!Position) return NULL;
    return Position->Data;
}

CExoLinkedListElement *CExoLinkedList::GetNext(CExoLinkedListElement *Position)
{
    if (!Position) return NULL;
    return Position->NextElement;
}

CExoLinkedListElement *CExoLinkedList::AddTail(void *pData)
{
    CExoLinkedListElement *pNewElement = new CExoLinkedListElement;
    pNewElement->PrevoiusElement = NULL;
    pNewElement->NextElement = NULL;
    pNewElement->Data = NULL;

    pNewElement->PrevoiusElement = this->ListHeader->LastElement;
    if (this->ListHeader->LastElement) {
        this->ListHeader->LastElement = pNewElement;
    }
    this->ListHeader->LastElement = pNewElement;
    pNewElement->Data = pData;
    if (!this->ListHeader->FirstElement) {
        this->ListHeader->FirstElement = pNewElement;
    }

    return pNewElement;
}

