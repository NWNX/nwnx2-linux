#include "CItemRepository.h"

dword CItemRepository::GetItemCount()
{
    //if(!this->ItemList.ListHeader) return 0;
    return this->ItemList.Count;
}

dword CItemRepository::GetItemByPosition(dword nPos)
{
    if (!this->ItemList.ListHeader) return OBJECT_INVALID;
    if (this->GetItemCount() < nPos) return OBJECT_INVALID;
    CExoLinkedListElement *pListElement = this->ItemList.ListHeader->FirstElement;
    if (!pListElement) return OBJECT_INVALID;

    for (int i = 0; i < nPos; i++) {
        pListElement = pListElement->NextElement;
        if (!pListElement) return OBJECT_INVALID;
    }
    if (!pListElement->Data) return OBJECT_INVALID;
    return *(dword*)pListElement->Data;
}


