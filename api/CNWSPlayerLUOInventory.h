#ifndef _CNWSPLAYERLUOINVENTORY_H_
#define _CNWSPLAYERLUOINVENTORY_H_
#include "nwndef.h"

class CNWSPlayerLUOInventory
{
public:
    void ClearBarter();
    void ClearContainer();
    void ClearRepository();
    void ClearSlots();
    void ClearStore();
    void ItemListAddHead(unsigned long, unsigned char, unsigned char, unsigned char, unsigned long, unsigned long);
    unsigned long ItemListGetItemObjectID(CExoLinkedListNode *, unsigned char);
    CNWSItem * ItemListGetItem(CExoLinkedListNode *, unsigned char);
    int ItemListGetNext(CExoLinkedListNode *&, unsigned char);
    unsigned long ItemListGetNumber(unsigned char);
    int ItemListGetPrev(CExoLinkedListNode *&, unsigned char);
    CNWSPlayerLUOInventoryItem * ItemListGetUpdateItem(CExoLinkedListNode *, unsigned char);
    void ItemListRemove(CExoLinkedListNode *, unsigned char);
    int ItemListSetEnd(CExoLinkedListNode *&, unsigned char);
    int ItemListSetStart(CExoLinkedListNode *&, unsigned char);
    ~CNWSPlayerLUOInventory();
    CNWSPlayerLUOInventory();

};
#endif
