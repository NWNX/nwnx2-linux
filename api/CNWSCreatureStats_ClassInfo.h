#ifndef _CNWSCREATURESTATS_CLASSINFO_H_
#define _CNWSCREATURESTATS_CLASSINFO_H_
#include "nwndef.h"

class CNWSCreatureStats_ClassInfo
{
public:
	int AddKnownSpell(unsigned char, unsigned long);
	int ClearMemorizedKnownSpells(unsigned long);
	int ClearMemorizedSpellSlot(unsigned char, unsigned char);
	int ConfirmDomainSpell(unsigned char, unsigned long);
	int DecrementSpellsPerDayLeft(unsigned char);
	int GetIsDomainSpell(unsigned char, unsigned char);
	int GetKnownSpell(unsigned char, unsigned char);
	int GetMaxSpellsPerDayLeft(unsigned char);
	int GetMemorizedSpellInSlotDetails(unsigned char, unsigned char);
	int GetMemorizedSpellInSlotMetaType(unsigned char, unsigned char);
	int GetMemorizedSpellInSlotReady(unsigned char, unsigned char);
	int GetMemorizedSpellInSlot(unsigned char, unsigned char);
	int GetMemorizedSpellReadyCount(unsigned long, unsigned char *, unsigned char *, unsigned char);
	int GetMemorizedSpellReadyCount(unsigned long, unsigned char);
	int GetNumberBonusSpells(unsigned char);
	int GetNumberKnownSpells(unsigned char);
	int GetNumberMemorizedSpellSlots(unsigned char);
	int GetSpellsPerDayLeft(unsigned char);
	int IncrementSpellsPerDayLeft(unsigned char);
	int RemoveKnownSpell(unsigned char, unsigned long);
	int ResetSpellsPerDayLeft(unsigned char, unsigned char);
	int SetMaxSpellsPerDayLeft(unsigned char, unsigned char);
	int SetMemorizedSpellInSlotReady(unsigned char, unsigned char, int);
	int SetMemorizedSpellSlot(unsigned char, unsigned char, unsigned long, int, unsigned char);
	int SetNumberBonusSpells(unsigned char, unsigned char);
	int SetNumberMemorizedSpellSlots(unsigned char, unsigned char);
	int SetSpellsPerDayLeft(unsigned char, unsigned char);
	~CNWSCreatureStats_ClassInfo();
	CNWSCreatureStats_ClassInfo();

};
#endif
