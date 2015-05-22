#ifndef _CNWCLASS_H_
#define _CNWCLASS_H_
#include "nwndef.h"
#include "CExoString.h"

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

};
#endif
