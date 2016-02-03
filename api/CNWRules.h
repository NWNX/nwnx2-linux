#ifndef _CNWRULES_H_
#define _CNWRULES_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CTwoDimArrays.h"

class CNWRules
{
public:
    static int CompareFeatName(void const *, void const *);
    CTwoDimArrays * Get2DArrays();
    int GetBaseItem(unsigned long);
    unsigned char GetClassExpansionLevel(unsigned char);
    int GetClass(unsigned char);
    int GetDamageIndexFromFlags(unsigned long);
    int GetDifficultyOption(int, int);
    CNWDomain * GetDomain(unsigned short);
    int GetExperienceLevel(unsigned char);
    unsigned char GetFamiliarExpansionLevel(unsigned char, int);
    unsigned char GetFeatExpansionLevel(unsigned short);
    CNWFeat * GetFeat(unsigned short);
    int GetIsClassValid(unsigned char);
    int GetMasterFeatDescriptionText(char);
    int GetMasterFeatIcon(char);
    CExoString GetMasterFeatNameText(char);
    unsigned char GetMetaMagicLevelCost(unsigned char);
    int GetNumClasses();
    int GetNumDomains();
    int GetNumFeats();
    int GetNumRaces();
    int GetNumSkills();
    int GetNumSortedFeats();
    int GetNumSpells();
    int GetRace(unsigned short);
    unsigned char GetSkillExpansionLevel(unsigned short);
    int GetSkill(unsigned short);
    int GetSortedFeatID(unsigned short);
    unsigned char GetSpellExpansionLevel(unsigned long);
    int GetSpellRange(int);
    int GetSpell(unsigned long);
    int GetWeightedDamageAmount(int, int, int, int, int);
    int IsArcaneClass(unsigned char);
    int IsFeatUseable(unsigned char, unsigned short);
    void LoadClassInfo();
    void LoadDifficultyInfo();
    void LoadDomainInfo();
    void LoadFeatInfo();
    void LoadRaceInfo();
    void LoadSkillInfo();
    void ReloadAll();
    unsigned short RollDice(unsigned char, unsigned char);
    int SortFeats();
    void UnloadAll();
    ~CNWRules();
    CNWRules();

    /* 0x0/0 */ float SpellRanges[5];
    /* 0x14/20 */ CNWBaseItemArray *BaseItems;
    /* 0x18/24 */ unsigned long XPRequiredForLevel[41];
    /* 0xBC/188 */ CNWSpellArray *Spells;
    /* 0xC0/192 */ CNWFeat *Feats;
    /* 0xC4/196 */ unsigned long field_C4;
    /* 0xC8/200 */ unsigned long field_C8;
    /* 0xCC/204 */ unsigned long field_CC;
    /* 0xD0/208 */ unsigned short *SortedFeats;
    /* 0xD4/212 */ unsigned short FeatsLength;
    /* 0xD6/214 */ unsigned short SortedFeatsLength;
    /* 0xD8/216 */ unsigned char UnknownLength;
    /* 0xD9/217 */ unsigned char ClassesLength;
    /* 0xDA/218 */ unsigned char RacesLength;
    /* 0xDB/219 */ unsigned char SkillsLength;
    /* 0xDC/220 */ unsigned char DomainsLength;
    /* 0xDD/221 */ unsigned char field_DD;
    /* 0xDE/222 */ unsigned char field_DE;
    /* 0xDF/223 */ unsigned char field_DF;
    /* 0xE0/224 */ CNWClass *Classes;
    /* 0xE4/228 */ CNWRace *Races;
    /* 0xE8/232 */ CNWSkill *Skills;
    /* 0xEC/236 */ CNWDomain *Domains;
    /* 0xF0/240 */ CTwoDimArrays *TwoDAs;
    /* 0xF4/244 */ unsigned long Difficulty_1;
    /* 0xF8/248 */ unsigned long Difficulty_2;
    /* 0xFC/252 */ unsigned long Difficulty_3;
    /* 0x100/256 */ unsigned long Difficulty_4;
    /* 0x104/260 */ unsigned long Difficulty_5;
    /* 0x108/264 */ unsigned long Difficulty_6;
    /* 0x10C/268 */ unsigned long Difficulty_7;
    /* 0x110/272 */ unsigned long Difficulty_8;
    /* 0x114/276 */ unsigned long Difficulty_9;
    /* 0x118/280 */ void *vptr;
};

static_assert_size(CNWRules, 0x11C);

#endif
