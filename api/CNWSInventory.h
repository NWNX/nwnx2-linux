#ifndef _CNWSINVENTORY_H_
#define _CNWSINVENTORY_H_
#include "nwndef.h"

class CNWSInventory
{
public:
    int GetArraySlotFromSlotFlag(unsigned long);
    int GetItemInInventory(CNWSItem *);
    CNWSItem * GetItemInSlot(unsigned long);
    unsigned long GetSlotFromItem(CNWSItem *);
    void PutItemInSlot(unsigned long, CNWSItem *);
    int RemoveItem(CNWSItem *);
    ~CNWSInventory();
    CNWSInventory();

};
#endif
