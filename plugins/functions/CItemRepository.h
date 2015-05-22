#ifndef _CITEMREPOSITORY_H_
#define _CITEMREPOSITORY_H_

#include "typedefs.h"
#include "CExoLinkedList.h"
#include <stddef.h>

class CItemRepository
{
public:
    byte unk1;
    byte unk2;
    byte align1;
    byte align2;
    dword unk3;
    dword unk4;
    dword ObjectID;
    CExoLinkedList ItemList;

    dword GetItemCount();
    dword GetItemByPosition(dword nPos);
};

#endif
