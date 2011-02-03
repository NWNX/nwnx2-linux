#ifndef _CNWSPLAYERLUOINVENTORY_H_
#define _CNWSPLAYERLUOINVENTORY_H_
#include "nwndef.h"

class CNWSPlayerLUOInventory
{
public:
	int ClearBarter();
	int ClearContainer();
	int ClearRepository();
	int ClearSlots();
	int ClearStore();
	int ItemListAddHead(unsigned long, unsigned char, unsigned char, unsigned char, unsigned long, unsigned long);
	int ItemListGetItemObjectID(CExoLinkedListNode *, unsigned char);
	int ItemListGetItem(CExoLinkedListNode *, unsigned char);
	int ItemListGetNext(CExoLinkedListNode *&, unsigned char);
	int ItemListGetNumber(unsigned char);
	int ItemListGetPrev(CExoLinkedListNode *&, unsigned char);
	int ItemListGetUpdateItem(CExoLinkedListNode *, unsigned char);
	int ItemListRemove(CExoLinkedListNode *, unsigned char);
	int ItemListSetEnd(CExoLinkedListNode *&, unsigned char);
	int ItemListSetStart(CExoLinkedListNode *&, unsigned char);
	~CNWSPlayerLUOInventory();
	CNWSPlayerLUOInventory();

};
#endif
