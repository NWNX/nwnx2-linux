#ifndef _CNWRULES_H_
#define _CNWRULES_H_
#include "nwndef.h"

class CNWRules
{
public:
	int CompareFeatName(void const *, void const *);
	int Get2DArrays();
	int GetBaseItem(unsigned long);
	int GetClassExpansionLevel(unsigned char);
	int GetClass(unsigned char);
	int GetDamageIndexFromFlags(unsigned long);
	int GetDifficultyOption(int, int);
	int GetDomain(unsigned short);
	int GetExperienceLevel(unsigned char);
	int GetFamiliarExpansionLevel(unsigned char, int);
	int GetFeatExpansionLevel(unsigned short);
	int GetFeat(unsigned short);
	int GetIsClassValid(unsigned char);
	int GetMasterFeatDescriptionText(char);
	int GetMasterFeatIcon(char);
	int GetMasterFeatNameText(char);
	int GetMetaMagicLevelCost(unsigned char);
	int GetNumClasses();
	int GetNumDomains();
	int GetNumFeats();
	int GetNumRaces();
	int GetNumSkills();
	int GetNumSortedFeats();
	int GetNumSpells();
	int GetRace(unsigned short);
	int GetSkillExpansionLevel(unsigned short);
	int GetSkill(unsigned short);
	int GetSortedFeatID(unsigned short);
	int GetSpellExpansionLevel(unsigned long);
	int GetSpellRange(int);
	int GetSpell(unsigned long);
	int GetWeightedDamageAmount(int, int, int, int, int);
	int IsArcaneClass(unsigned char);
	int IsFeatUseable(unsigned char, unsigned short);
	int LoadClassInfo();
	int LoadDifficultyInfo();
	int LoadDomainInfo();
	int LoadFeatInfo();
	int LoadRaceInfo();
	int LoadSkillInfo();
	int ReloadAll();
	int RollDice(unsigned char, unsigned char);
	int SortFeats();
	int UnloadAll();
	~CNWRules();
	CNWRules();

};
#endif
