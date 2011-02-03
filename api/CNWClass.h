#ifndef _CNWCLASS_H_
#define _CNWCLASS_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWClass
{
public:
	int GetAttackBonus(unsigned char);
	int GetBonusFeats(unsigned char);
	int GetClassFeat(unsigned short);
	int GetDescriptionText();
	int GetFortSaveBonus(unsigned char);
	int GetIsAlignmentAllowed(unsigned char, unsigned char);
	int GetLevelFeatGranted(unsigned short);
	int GetLevelGranted(unsigned short);
	int GetNameLowerText();
	int GetNamePluralText();
	int GetNameText();
	int GetRefSaveBonus(unsigned char);
	int GetSpellGain(unsigned char, unsigned char);
	int GetSpellsKnownPerLevel(unsigned char, unsigned char, unsigned char, unsigned short, unsigned char);
	int GetWillSaveBonus(unsigned char);
	int IsBonusFeat(unsigned short);
	int IsFeatUseable(unsigned short);
	int IsGrantedFeat(unsigned short, unsigned char &);
	int IsNormalFeat(unsigned short);
	int IsSkillClassSkill(unsigned short);
	int IsSkillUseable(unsigned short);
	int LoadAttackBonusTable(CExoString);
	int LoadBonusFeatsTable(CExoString);
	int LoadFeatsTable(CExoString, CNWRules *);
	int LoadSavingThrowTable(CExoString);
	int LoadSkillsTable(CExoString);
	int LoadSpellGainTable(CExoString);
	int LoadSpellKnownTable(CExoString);
	~CNWClass();
	CNWClass();

};
#endif
