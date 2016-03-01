#ifndef _CNWRACE_H_
#define _CNWRACE_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWRace
{
public:
    int GetConverNameLowerText();
    int GetConverNameText();
    int GetDefaultBiographyText();
    int GetDescriptionText();
    int GetNamePluralText();
    int GetNameText();
    int IsFirstLevelGrantedFeat(unsigned short);
    void LoadFeatsTable(CExoString);
    ~CNWRace();
    CNWRace();

    /* 0x0/0 */ unsigned long Name;
    /* 0x4/4 */ unsigned long ConverName;
    /* 0x8/8 */ unsigned long ConverNameLower;
    /* 0xC/12 */ unsigned long NamePlural;
    /* 0x10/16 */ unsigned long Desciption;
    /* 0x14/20 */ unsigned long Biography;
    /* 0x18/24 */ unsigned char StrAdjust;
    /* 0x19/25 */ unsigned char DexAdjust;
    /* 0x1A/26 */ unsigned char IntAdjust;
    /* 0x1B/27 */ unsigned char ChaAdjust;
    /* 0x1C/28 */ unsigned char WisAdjust;
    /* 0x1D/29 */ unsigned char ConAdjust;
    /* 0x1E/30 */ unsigned char Endurance;
    /* 0x1F/31 */ unsigned char Favored;
    /* 0x20/32 */ unsigned long PlayerRace;
    /* 0x24/36 */ unsigned short FeatTableLength;
    /* 0x26/38 */ unsigned short field_26;
    /* 0x28/40 */ unsigned short* FeatTable;
    /* 0x2C/44 */ unsigned long Age;
    /* 0x30/48 */ unsigned short Appearance;
    /* 0x32/50 */ unsigned short field_32;
};

static_assert_size(CNWRace, 0x34);

#endif
