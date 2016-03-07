#ifndef _CNWCLASS_H_
#define _CNWCLASS_H_
#include "nwndef.h"
#include "CExoString.h"
#include "nwnstructs.h"

class CNWClass
{
public:
    unsigned char GetAttackBonus(unsigned char);
    unsigned char GetBonusFeats(unsigned char);
    int GetClassFeat(unsigned short);
    int GetDescriptionText();
    unsigned char GetFortSaveBonus(unsigned char);
    int GetIsAlignmentAllowed(unsigned char, unsigned char);
    int GetLevelFeatGranted(unsigned short);
    int GetLevelGranted(unsigned short);
    int GetNameLowerText();
    int GetNamePluralText();
    int GetNameText();
    unsigned char GetRefSaveBonus(unsigned char);
    unsigned char GetSpellGain(unsigned char, unsigned char);
    unsigned char GetSpellsKnownPerLevel(unsigned char, unsigned char, unsigned char, unsigned short, unsigned char);
    unsigned char GetWillSaveBonus(unsigned char);
    int IsBonusFeat(unsigned short);
    int IsFeatUseable(unsigned short);
    int IsGrantedFeat(unsigned short, unsigned char &);
    int IsNormalFeat(unsigned short);
    int IsSkillClassSkill(unsigned short);
    int IsSkillUseable(unsigned short);
    void LoadAttackBonusTable(CExoString);
    void LoadBonusFeatsTable(CExoString);
    void LoadFeatsTable(CExoString, CNWRules *);
    void LoadSavingThrowTable(CExoString);
    void LoadSkillsTable(CExoString);
    void LoadSpellGainTable(CExoString);
    void LoadSpellKnownTable(CExoString);
    ~CNWClass();
    CNWClass();

    /* 0x0/0 */ unsigned long NameStrref;
    /* 0x4/4 */ unsigned long NameLowerStrref;
    /* 0x8/8 */ unsigned long NamePluralStrref;
    /* 0xC/12 */ unsigned long DescriptionStrref;
    /* 0x10/16 */ CExoString Icon;
    /* 0x18/24 */ CExoString* PrereqTable;
    /* 0x1C/28 */ unsigned char field_1C;
    /* 0x1D/29 */ unsigned char field_1D;
    /* 0x1E/30 */ unsigned char field_1E;
    /* 0x1F/31 */ unsigned char AttackBonus[60];
    /* 0x5C/92 */ unsigned char HitDice;
    /* 0x5D/93 */ unsigned char SkillPoints;
    /* 0x5E/94 */ unsigned char SavesFort[60];
    /* 0x99/153 */ unsigned char SavesWill[60];
    /* 0xD5/213 */ unsigned char SavesReflex[60];
    /* 0x112/274 */ unsigned char field_112;
    /* 0x113/275 */ unsigned char field_113;
    /* 0x114/276 */ unsigned char** SpellKnownTable;
    /* 0x118/280 */ unsigned char NumSpellLevels[40];
    /* 0x140/320 */ int* SpellGainTable[40];
    /* 0x1E0/480 */ CNWClass_SkillTableEntry* SkillsTable;
    /* 0x1E4/484 */ unsigned short SkillTableLength;
    /* 0x1E6/486 */ unsigned short field_1E6;
    /* 0x1E8/488 */ CNWClass_FeatTableEntry* Feats;
    /* 0x1EC/492 */ unsigned char FeatsLength;
    /* 0x1ED/493 */ unsigned char BonusFeats[40];
    /* 0x215/533 */ unsigned char field_215;
    /* 0x216/534 */ unsigned char PrimaryAbility;
    /* 0x217/535 */ unsigned char AbilityAdjust[6];
    /* 0x21D/541 */ unsigned char AlignmentRestriction;
    /* 0x21E/542 */ unsigned char AlignmentRestrictionType;
    /* 0x21F/543 */ unsigned char field_21F;
    /* 0x220/544 */ unsigned long InvertRestriction;
    /* 0x224/548 */ unsigned char EffectiveLevel[40];
    /* 0x24C/588 */ unsigned long field_24C;
    /* 0x250/592 */ unsigned long PlayerClass;
    /* 0x254/596 */ unsigned long SpellCaster;
    /* 0x258/600 */ unsigned long MaxLevel;
    /* 0x25C/604 */ unsigned long XPPenalty;
    /* 0x260/608 */ unsigned long Package;
    /* 0x264/612 */ unsigned char ArcaneSpellLevelMod;
    /* 0x265/613 */ unsigned char DivineSpellLevelMod;
    /* 0x266/614 */ unsigned char EpicLevel;
    /* 0x267/615 */ unsigned char field_267;
};

static_assert_size(CNWClass, 0x268);

#endif
