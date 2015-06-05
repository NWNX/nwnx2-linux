#ifndef _CNWSCREATURESTATS_CLASSINFO_H_
#define _CNWSCREATURESTATS_CLASSINFO_H_
#include "nwndef.h"
#include "CExoArrayList.h"

class CNWSCreatureStats_ClassInfo
{
public:
    int AddKnownSpell(unsigned char, unsigned long);
    void ClearMemorizedKnownSpells(unsigned long);
    void ClearMemorizedSpellSlot(unsigned char, unsigned char);
    int ConfirmDomainSpell(unsigned char, unsigned long);
    int DecrementSpellsPerDayLeft(unsigned char);
    int GetIsDomainSpell(unsigned char, unsigned char);
    unsigned long GetKnownSpell(unsigned char, unsigned char);
    int GetMaxSpellsPerDayLeft(unsigned char);
    CNWSStats_Spell * GetMemorizedSpellInSlotDetails(unsigned char, unsigned char);
    unsigned char GetMemorizedSpellInSlotMetaType(unsigned char, unsigned char);
    int GetMemorizedSpellInSlotReady(unsigned char, unsigned char);
    unsigned long GetMemorizedSpellInSlot(unsigned char, unsigned char);
    unsigned char GetMemorizedSpellReadyCount(unsigned long, unsigned char *, unsigned char *, unsigned char);
    int GetMemorizedSpellReadyCount(unsigned long, unsigned char);
    int GetNumberBonusSpells(unsigned char);
    int GetNumberKnownSpells(unsigned char);
    unsigned char GetNumberMemorizedSpellSlots(unsigned char);
    int GetSpellsPerDayLeft(unsigned char);
    int IncrementSpellsPerDayLeft(unsigned char);
    void RemoveKnownSpell(unsigned char, unsigned long);
    int ResetSpellsPerDayLeft(unsigned char, unsigned char);
    int SetMaxSpellsPerDayLeft(unsigned char, unsigned char);
    void SetMemorizedSpellInSlotReady(unsigned char, unsigned char, int);
    void SetMemorizedSpellSlot(unsigned char, unsigned char, unsigned long, int, unsigned char);
    int SetNumberBonusSpells(unsigned char, unsigned char);
    void SetNumberMemorizedSpellSlots(unsigned char, unsigned char);
    int SetSpellsPerDayLeft(unsigned char, unsigned char);
    ~CNWSCreatureStats_ClassInfo();
    CNWSCreatureStats_ClassInfo();

    /* (mtype:CExoArrayList<unsigned long>) */
    /* 0x0/0 */ CExoArrayList<unsigned long> SpellsKnown[10];
    /* (mtype:CExoArrayList<CNWSStats_Spell *>) */
    /* 0x78/120 */ CExoArrayList<CNWSStats_Spell *> SpellsMemorized[10];
    /* 0xF0/240 */ char field_F0[10];
    /* 0xFA/250 */ char field_FA[10];
    /* 0x104/260 */ char field_104[10];
    /* 0x10E/270 */ char field_10E;
    /* 0x10F/271 */ char field_10F;
    /* 0x110/272 */ char field_110;
    /* 0x111/273 */ char field_111;
    /* 0x112/274 */ char field_112;
    /* 0x113/275 */ char field_113;
    /* 0x114/276 */ unsigned long field_114;
};
#endif
