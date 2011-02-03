#ifndef _CNWSPLAYERLASTUPDATEOBJECT_H_
#define _CNWSPLAYERLASTUPDATEOBJECT_H_
#include "nwndef.h"

class CNWSPlayerLastUpdateObject
{
public:
	int AddKnownSpell(unsigned char, unsigned char, unsigned long);
	int ClearActionQueue();
	int ClearAutoMapData();
	int ClearEffectIcons();
	int ClearKnownSpellUsesLeft();
	int ClearKnownSpells();
	int ClearMemorizedSpells();
	int ClearSpellAddDeleteLists();
	int ClearVisibilityList();
	int GetIsDomainSpell(unsigned char, unsigned char, unsigned char);
	int GetKnownSpellUsesLeft(unsigned char, unsigned char);
	int GetKnownSpell(unsigned char, unsigned char, unsigned char);
	int GetMemorizedSpellMetaType(unsigned char, unsigned char, unsigned char);
	int GetMemorizedSpellReadied(unsigned char, unsigned char, unsigned char);
	int GetMemorizedSpell(unsigned char, unsigned char, unsigned char);
	int InitializeAutoMapData();
	int ResetAutoMapData(unsigned long);
	int SetKnownSpellUsesLeft(unsigned char, unsigned char, unsigned char);
	int SetMemorizedSpellReadied(unsigned char, unsigned char, unsigned char, int);
	int SetMemorizedSpellSlot(unsigned char, unsigned char, unsigned char, unsigned long, int, unsigned char);
	int SetNumberMemorizedSpellSlots(unsigned char, unsigned char, unsigned char);
	~CNWSPlayerLastUpdateObject();
	CNWSPlayerLastUpdateObject();

};
#endif
