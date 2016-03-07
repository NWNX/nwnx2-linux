#ifndef _CNWFEAT_H_
#define _CNWFEAT_H_
#include "nwndef.h"
#include "CResRef.h"

class CNWFeat
{
public:
    int GetDescriptionText();
    CExoString GetNameText();
    ~CNWFeat();
    CNWFeat();

    /* 0x0/0 */ unsigned long NameStrref;
    /* 0x4/4 */ unsigned long DescriptionStrref;
    /* 0x8/8 */ unsigned long Category;
    /* 0xC/12 */ unsigned long MaxCR;
    /* 0x10/16 */ CResRef Icon;
    /* 0x20/32 */ unsigned long GainMultiple;
    /* 0x24/36 */ unsigned long AllClassesUse;
    /* 0x28/40 */ unsigned long TargetSelf;
    /* 0x2C/44 */ unsigned long Hostile;
    /* 0x30/48 */ unsigned char MinBAB;
    /* 0x31/49 */ unsigned char MinStr;
    /* 0x32/50 */ unsigned char MinDex;
    /* 0x33/51 */ unsigned char MinInt;
    /* 0x34/52 */ unsigned char MinWis;
    /* 0x35/53 */ unsigned char MinCon;
    /* 0x36/54 */ unsigned char MinCha;
    /* 0x37/55 */ unsigned char MinSpellLvl;
    /* 0x38/56 */ unsigned short ReqFeat1;
    /* 0x3A/58 */ unsigned short ReqFeat2;
    /* 0x3C/60 */ unsigned short ReqFeatOr[5];
    /* 0x46/70 */ unsigned short ReqSkill1;
    /* 0x48/72 */ unsigned short ReqSkillRanks1;
    /* 0x4A/74 */ unsigned short ReqSkill2;
    /* 0x4C/76 */ unsigned short ReqSkillRanks2;
    /* 0x4E/78 */ unsigned short field_4E;
    /* 0x50/80 */ unsigned long field_50;
    /* 0x54/84 */ unsigned char Master;
    /* 0x55/85 */ unsigned char MinLevel;
    /* 0x56/86 */ unsigned char MaxLevel;
    /* 0x57/87 */ unsigned char MinLevelClass;
    /* 0x58/88 */ unsigned long field_58;
    /* 0x5C/92 */ unsigned long SpellID;
    /* 0x60/96 */ unsigned char Uses;
    /* 0x61/97 */ unsigned char field_61;
    /* 0x62/98 */ unsigned char field_62;
    /* 0x63/99 */ unsigned char field_63;
    /* 0x64/100 */ unsigned long field_64;
    /* 0x68/104 */ unsigned long field_68;
    /* 0x6C/108 */ unsigned long RequiresAction;
};

static_assert_size(CNWFeat,  0x70);

#endif
