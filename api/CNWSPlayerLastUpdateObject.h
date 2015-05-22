#ifndef _CNWSPLAYERLASTUPDATEOBJECT_H_
#define _CNWSPLAYERLASTUPDATEOBJECT_H_
#include "nwndef.h"

class CNWSPlayerLastUpdateObject
{
public:
    void AddKnownSpell(unsigned char, unsigned char, unsigned long);
    void ClearActionQueue();
    void ClearAutoMapData();
    int ClearEffectIcons();
    void ClearKnownSpellUsesLeft();
    void ClearKnownSpells();
    void ClearMemorizedSpells();
    void ClearSpellAddDeleteLists();
    void ClearVisibilityList();
    int GetIsDomainSpell(unsigned char, unsigned char, unsigned char);
    unsigned char GetKnownSpellUsesLeft(unsigned char, unsigned char);
    unsigned long GetKnownSpell(unsigned char, unsigned char, unsigned char);
    unsigned char GetMemorizedSpellMetaType(unsigned char, unsigned char, unsigned char);
    int GetMemorizedSpellReadied(unsigned char, unsigned char, unsigned char);
    unsigned long GetMemorizedSpell(unsigned char, unsigned char, unsigned char);
    int InitializeAutoMapData();
    void ResetAutoMapData(unsigned long);
    void SetKnownSpellUsesLeft(unsigned char, unsigned char, unsigned char);
    void SetMemorizedSpellReadied(unsigned char, unsigned char, unsigned char, int);
    void SetMemorizedSpellSlot(unsigned char, unsigned char, unsigned char, unsigned long, int, unsigned char);
    void SetNumberMemorizedSpellSlots(unsigned char, unsigned char, unsigned char);
    ~CNWSPlayerLastUpdateObject();
    CNWSPlayerLastUpdateObject();

};
#endif
