#ifndef _CITEMREPOSITORY_H_
#define _CITEMREPOSITORY_H_
#include "nwndef.h"
#include "CExoLinkedList.h"

class CItemRepository
{
public:
    int AddItem(CNWSItem **, unsigned char, unsigned char, int, int);
    int AddPanel();
    int CalculateContentsWeight();
    unsigned char CalculatePage(unsigned char, unsigned char);
    int CheckFit(CNWSItem *, unsigned char, unsigned char);
    int CheckItemOverlaps(CNWSItem *, CNWSItem *, unsigned char, unsigned char);
    unsigned long FindItemWithBaseItemId(unsigned long, int);
    unsigned long FindItemWithTag(CExoString *);
    int FindPosition(CNWSItem *, unsigned char &, unsigned char &, int);
    int GetItemInRepository(CNWSItem *, int);
    unsigned long GetItemInRepository(unsigned char, unsigned char);
    unsigned long ItemListGetItemObjectID(CExoLinkedListNode *);
    CNWSItem * ItemListGetItem(CExoLinkedListNode *);
    int MoveItem(CNWSItem *, unsigned char, unsigned char);
    int RemoveItem(CNWSItem *);
    ~CItemRepository();
    CItemRepository(unsigned long, unsigned char, unsigned char, unsigned long, int);

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long field_C;
    /* (mtype:CExoLinkedList<unsigned long>) */
    /* 0x10/16 */ CExoLinkedList<unsigned long> ItemList;
};
#endif
