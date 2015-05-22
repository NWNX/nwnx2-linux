#ifndef _CNWRULES_H_
#define _CNWRULES_H_
#include "nwndef.h"
#include "CExoString.h"

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

};
#endif
