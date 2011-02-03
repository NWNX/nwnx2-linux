#ifndef _CNWSCLIENT_H_
#define _CNWSCLIENT_H_
#include "nwndef.h"
#include "CExoLinkedList.h"

class CNWSClient
{
public:
	int AsNWSDungeonMaster();
	int AsNWSPlayer();
	int GetLanguage();
	int GetPlayerId();
	int SetLanguage(int);
	~CNWSClient();
	CNWSClient(unsigned long);

	/* 0x0/0 */ unsigned long PlayerID;
	/* 0x4/4 */ unsigned long field_4;
	/* 0x8/8 */ void *vtable;
	/* (ptr_to:CExoLinkedList<int>) */
	/* 0xC/12 */ CExoLinkedList<int> *ObjectUpdateArray;
	/* 0x10/16 */ void *field_10;
	/* 0x14/20 */ unsigned long field_14;
	/* 0x18/24 */ unsigned long field_18;
	/* 0x1C/28 */ unsigned long field_1C;
	/* 0x20/32 */ unsigned long field_20;
	/* 0x24/36 */ unsigned long field_24;
	/* 0x28/40 */ unsigned long field_28;
	/* 0x2C/44 */ unsigned long field_2C;
	/* 0x30/48 */ unsigned long GameObjectID;
	/* 0x34/52 */ unsigned long unknown;
	/* 0x38/56 */ unsigned long field_38;
	/* 0x3C/60 */ unsigned long field_3C;
	/* 0x40/64 */ unsigned long CreatureObjID;
	/* 0x44/68 */ unsigned long field_44;
	/* 0x48/72 */ unsigned long field_48;
	/* 0x4C/76 */ unsigned long field_4C;
	/* 0x50/80 */ unsigned long field_50;
	/* 0x54/84 */ unsigned long field_54;
	/* 0x58/88 */ unsigned long field_58;
	/* 0x5C/92 */ unsigned long field_5C;
	/* 0x60/96 */ unsigned long field_60;
	/* 0x64/100 */ void *InventoryGUI;
};
#endif
