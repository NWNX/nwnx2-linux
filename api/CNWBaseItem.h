#ifndef _CNWBASEITEM_H_
#define _CNWBASEITEM_H_
#include "nwndef.h"
#include "CResRef.h"

class CNWBaseItem
{
public:
    CResRef GetIconResRef(unsigned char, short, char);
    CResRef GetModelResRef(unsigned char, short, char);
    int GetNameText();
    unsigned short GetRequiredFeat(unsigned char);
    int SetRequiredFeatCount(unsigned char);
    int SetRequiredFeat(unsigned char, unsigned short);
    ~CNWBaseItem();
    CNWBaseItem();

    /* 0x0/0 */ unsigned long Name;
    /* 0x4/4 */ unsigned long EquipableSlots;
    /* 0x8/8 */ char WeaponWield;
    /* 0x9/9 */ char WeaponType;
    /* 0xC/12 */ char rsvd1[2];
    /* 0xC/12 */ unsigned long MinRange;
    /* 0x10/16 */ unsigned long MaxRange;
    /* 0x14/20 */ char InvSlotWidth;
    /* 0x15/21 */ char InvSlotHeight;
    /* 0x16/22 */ char ModelType;
    /* 0x17/23 */ char ChargesStarting;
    /* 0x18/24 */ char RangedWeapon;
    /* 0x19/25 */ char WeaponSize;
    /* 0x1A/26 */ char NumDice;
    /* 0x1B/27 */ char DieToRoll;
    /* 0x1C/28 */ char CritThreat;
    /* 0x1D/29 */ char CritHitMult;
    /* 0x1E/30 */ char Category;
    /* 0x20/32 */ char rsvd2;
    /* 0x20/32 */ unsigned long BaseCost;
    /* 0x24/36 */ char Stacking;
    /* 0x28/40 */ char rsvd3[3];
    /* 0x28/40 */ unsigned long ItemMultiplier;
    /* 0x2C/44 */ unsigned long Description;
    /* 0x30/48 */ char MinProps;
    /* 0x31/49 */ char MaxProps;
    /* 0x32/50 */ char PropColumn;
    /* 0x33/51 */ char StorePanel;
    /* 0x34/52 */ char StorePanelSort;
    /* 0x35/53 */ char AnimSlashL;
    /* 0x36/54 */ char AnimSlashR;
    /* 0x37/55 */ char AnimSlashS;
    /* 0x38/56 */ char ILRStackSize;
    /* 0x3C/60 */ char rsvd4[3];
    /* 0x3C/60 */ unsigned long PrefAttackDist;
    /* 0x40/64 */ char ItemClass[10];
    /* 0x4C/76 */ char rsvd5[2];
    /* 0x4C/76 */ unsigned long Part1EnvMap;
    /* 0x50/80 */ unsigned long Part2EnvMap;
    /* 0x54/84 */ unsigned long Part3EnvMap;
    /* 0x58/88 */ CResRef DefaultIcon;
    /* 0x68/104 */ CResRef DefaultModel;
    /* 0x78/120 */ unsigned long CanRotateIcon;
    /* 0x7C/124 */ unsigned long Container;
    /* 0x80/128 */ unsigned long GenderSpecific;
    /* 0x84/132 */ char InvSoundType;
    /* 0x88/136 */ char rsvd6[3];
    /* 0x88/136 */ unsigned long ReqFeatList;
    /* 0x8C/140 */ unsigned long ReqFeatCount;
    /* 0x90/144 */ unsigned long BaseItemStatRef;
    /* 0x94/148 */ char RotateOnGround;
    /* 0x98/152 */ char rsvd7[3];
    /* 0x98/152 */ unsigned long TenthLBS;
    /* 0x9C/156 */ char BaseAC;
    /* 0x9D/157 */ char AC_Enchant;
    /* 0x9E/158 */ char WeaponMatType;
    /* 0x9F/159 */ char ArmorCheckPen;
    /* 0xA0/160 */ char AmmunitionType;
    /* 0xA1/161 */ char QBBehaviour;
    /* 0xA2/162 */ char ArcaneSpellFailure;
    /* 0xA3/163 */ char field_A3;
};
#endif
