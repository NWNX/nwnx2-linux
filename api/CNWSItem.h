#ifndef _CNWSITEM_H_
#define _CNWSITEM_H_
#include "nwndef.h"
#include "nwnstructs.h"
#include "CExoString.h"
#include "CExoLocString.h"
#include "CResRef.h"
#include "CNWSObject.h"

class CNWSItem
{
public:
    void AIUpdate();
    int AcquireItem(CNWSItem **, unsigned long, unsigned char, unsigned char, int);
    int ActiveProperty(unsigned short);
    void AddActiveProperty(CNWItemProperty);
    void AddPassiveProperty(CNWItemProperty);
    void AddToArea(CNWSArea *, float, float, float, int);
    void ApplyItemProperties(CNWSCreature *, unsigned long, int);
    CNWSItem * AsNWSItem();
    void CalculateBaseCosts();
    float CalculatePassiveCost(CNWItemProperty *);
    void CloseInventory(unsigned long, int);
    void CloseItemForAllPlayers();
    int CompareItem(CNWSItem *);
    int ComputeArmorClass();
    void ComputeWeight();
    int CopyItem(CNWSItem *, int);
    void EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
    int GetActivePropertiesList();
    CNWItemProperty * GetActiveProperty(int);
    int GetArmorModelPart(unsigned char);
    int GetArmorValue();
    unsigned long GetCost(int, int, int, int);
    unsigned short GetDamageFlags();
    CExoString GetDescriptionOverride(int);
    CExoLocString GetDescription(int);
    CExoString GetDisplayName();
    CExoLocString & GetFirstName();
    int GetIdentified();
    int GetInfinite();
    int GetIsCursed();
    int GetIsDroppable();
    int GetIsPickPocketable();
    int GetLastUsedActiveProperties();
    int GetLastUsedActivePropertyUsesLeft(unsigned char);
    unsigned char GetMinEquipLevel();
    int GetModelPart(unsigned char);
    CExoLocString GetName();
    int GetNumActiveProperties();
    int GetNumCharges();
    int GetNumPassiveProperties();
    int GetPassivePropertiesList();
    CNWItemProperty * GetPassiveProperty(int);
    int GetPossessor();
    int GetPropertyByTypeExists(unsigned short, unsigned short);
    int GetPropertyByType(CNWItemProperty **, unsigned short, unsigned short);
    int GetRepositoryArrayIndex();
    int GetRepositoryPosition(unsigned char &, unsigned char &);
    int GetRepositoryPtr();
    int GetStackSize();
    int GetStolen();
    int GetUnalteredArmorModelPart(unsigned char);
    int GetUpdateDisplayName();
    unsigned short GetUsedActivePropertyUsesLeft(unsigned char);
    int GetVisualEffect();
    int GetWeight();
    int InitRepository(unsigned long);
    int LoadDataFromGff(CResGFF *, CResStruct *, int);
    int LoadFromTemplate(CResRef, CExoString *);
    int LoadItem(CResGFF *, CResStruct *, int);
    int MergeItem(CNWSItem *);
    void OpenInventory(unsigned long);
    void ReadContainerItemsFromGff(CResGFF *, CResStruct *);
    int RemoveActiveProperty(int);
    void RemoveFromArea();
    void RemoveItemProperties(CNWSCreature *, unsigned long);
    int RemovePassiveProperty(int);
    void RestoreUsedActiveProperties(int);
    void RestoreUsedActiveProperty(CNWItemProperty *, int);
    int SaveContainerItems(CResGFF *, CResStruct *);
    int SaveItemProperties(CResGFF *, CResStruct *);
    int SaveItem(CResGFF *, CResStruct *, int);
    int SetArmorModelPart(unsigned char, unsigned char);
    int SetArmorValue(int);
    int SetBarterOwner(unsigned long);
    void SetDisplayName(CExoString);
    int SetFirstName(unsigned long);
    void SetIdentifiedDescriptionOverride(CExoString);
    void SetIdentifiedDescription(CExoLocString);
    void SetIdentified(int);
    int SetInfinite(int);
    int SetIsCursed(int);
    int SetIsDroppable(int);
    int SetIsPickPocketable(int);
    int SetModelPart(unsigned char, unsigned char);
    void SetName(CExoLocString);
    int SetNumCharges(int);
    void SetPossessor(unsigned long, int, int, int);
    int SetRecalculateCostFlag(int);
    int SetRepositoryArrayIndex(unsigned short);
    int SetRepositoryPosition(unsigned char, unsigned char);
    int SetStackSize(int);
    int SetStolen(int);
    int SetUnalteredArmorModelPart(unsigned char, unsigned char);
    void SetUnidentifiedDescriptionOverride(CExoString);
    void SetUnidentifiedDescription(CExoLocString);
    int SetUpdateDisplayName(int);
    int SetWeight(int);
    CNWSItem * SplitItem(int);
    void UpdateUsedActiveProperties(int);
    void UpdateVisualEffect();
    ~CNWSItem();
    CNWSItem(unsigned long);

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long BaseItem;
    /* 0xC/12 */ void *CNWItem;
    /* 0x10/16 */ CNWSObject Object;
    /* 0x1D4/468 */ unsigned long field_1D4;
    /* 0x1D8/472 */ unsigned long field_1D8;
    /* 0x1DC/476 */ unsigned long field_1DC;
    /* 0x1E0/480 */ unsigned long field_1E0;
    /* 0x1E4/484 */ unsigned long field_1E4;
    /* 0x1E8/488 */ unsigned long field_1E8;
    /* 0x1EC/492 */ unsigned long ItemProperties;
    /* 0x1F0/496 */ unsigned long field_1F0;
    /* 0x1F4/500 */ unsigned long field_1F4;
    /* 0x1F8/504 */ unsigned long ItemProperties2;
    /* 0x244/580 */ char rsvd1[72];
    /* 0x244/580 */ unsigned long Possessor;
    /* 0x248/584 */ unsigned long field_248;
    /* 0x24C/588 */ char Repos_PosX;
    /* 0x24D/589 */ char Repos_PosY;
    /* 0x250/592 */ char rsvd2[2];
    /* 0x250/592 */ unsigned long field_250;
    /* 0x288/648 */ char rsvd3[52];
    /* 0x288/648 */ unsigned long Dropable;
    /* 0x28C/652 */ unsigned long Pickpocketable;
    /* 0x290/656 */ unsigned long Cursed;
    /* 0x2A4/676 */ char rsvd4[16];
    /* 0x2A4/676 */ unsigned long field_1FC;
};
#endif
