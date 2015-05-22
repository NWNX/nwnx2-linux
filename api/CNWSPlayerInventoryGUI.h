#ifndef _CNWSPLAYERINVENTORYGUI_H_
#define _CNWSPLAYERINVENTORYGUI_H_
#include "nwndef.h"

class CNWSPlayerInventoryGUI
{
public:
    void SetOpen(int);
    void SetOwner(unsigned long);
    void SetPanel(CNWSPlayer *, unsigned char);
    ~CNWSPlayerInventoryGUI();
    CNWSPlayerInventoryGUI();

    /* 0x0/0 */ void *m_aLUOInventory;
    /* 0x4/4 */ unsigned long m_bGuiInventoryOpen;
    /* 0x8/8 */ unsigned long m_bUpdateRequested;
    /* 0xC/12 */ unsigned long m_oidCurrentCreature;
    /* 0x10/16 */ void *m_pContainerGUI;
};
#endif
