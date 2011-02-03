#ifndef _CNWSPLAYERINVENTORYGUI_H_
#define _CNWSPLAYERINVENTORYGUI_H_
#include "nwndef.h"

class CNWSPlayerInventoryGUI
{
public:
	int SetOpen(int);
	int SetOwner(unsigned long);
	int SetPanel(CNWSPlayer *, unsigned char);
	~CNWSPlayerInventoryGUI();
	CNWSPlayerInventoryGUI();

	/* 0x0/0 */ void *LUOInventory;
	/* 0x4/4 */ unsigned long Open;
	/* 0x8/8 */ unsigned long field_8;
	/* 0xC/12 */ unsigned long Owner;
	/* 0x10/16 */ void *PlayerContainerGUI;
};
#endif
