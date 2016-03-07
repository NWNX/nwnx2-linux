#ifndef _CNWSCOMBATROUNDACTION_H_
#define _CNWSCOMBATROUNDACTION_H_
#include "nwndef.h"

class CNWSCombatRoundAction
{
public:
    int LoadData(CResGFF *, CResStruct *);
    int SaveData(CResGFF *, CResStruct *);
    ~CNWSCombatRoundAction();
    CNWSCombatRoundAction();

    /* 0x0/0 */ int ActionTimer;
    /* 0x4/4 */ unsigned short Animation;
    /* 0x6/6 */ unsigned short field_06;
    /* 0x8/8 */ int AnimationTime;
    /* 0xC/12 */ int NumAttacks;
    /* 0x10/16 */ unsigned char ActionType;
    /* 0x11/17 */ unsigned char field_11;
    /* 0x12/18 */ unsigned char field_12;
    /* 0x13/19 */ unsigned char field_13;
    /* 0x14/20 */ unsigned long Target;
    /* 0x18/24 */ unsigned char Retargettable;
    /* 0x19/25 */ unsigned char field_19;
    /* 0x1A/26 */ unsigned char field_1A;
    /* 0x1B/27 */ unsigned char field_1B;
    /* 0x1C/28 */ unsigned long InventorySlot;
    /* 0x20/32 */ unsigned long TargetRepository;
    /* 0x24/36 */ unsigned char RepositoryX;
    /* 0x25/37 */ unsigned char RepositoryY;
    /* 0x26/38 */ unsigned char field_26;
    /* 0x27/39 */ unsigned char field_27;
};

static_assert_size(CNWSCombatRoundAction, 0x28);

#endif
