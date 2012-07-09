#ifndef _CNWSCREATURESTATS_CLASSINFO_H_
#define _CNWSCREATURESTATS_CLASSINFO_H_
#include "nwndef.h"

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

};
#endif
