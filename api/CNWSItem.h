#ifndef _CNWSITEM_H_
#define _CNWSITEM_H_
#include "nwndef.h"
#include "nwnstructs.h"
#include "CExoString.h"
#include "CExoLocString.h"
#include "CResRef.h"
#include "CNWSObject.h"
#include "CNWItem.h"

class CNWSItem : public CNWItem, public CNWSObject
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

    /* 0x1D4/468 */ unsigned char LastUsedActiveProperties;
    /* 0x1D5/469 */ unsigned char field_1D5;
    /* 0x1D6/470 */ unsigned char field_1D6;
    /* 0x1D7/471 */ unsigned char field_1D7;
    /* 0x1D8/472 */ unsigned long field_1D8;
    /* 0x1DC/476 */ unsigned long field_1DC;
    /* 0x1E0/480 */ unsigned long ArmorValue;
    /* 0x1E4/484 */ unsigned char Identified;
    /* 0x1E5/485 */ unsigned char field_1E5;
    /* 0x1E6/486 */ unsigned char field_1E6;
    /* 0x1E7/487 */ unsigned char field_1E7;
    /* 0x1E8/488 */ unsigned long field_1E8;
    /* 0x1EC/492 */ CExoArrayList<CNWItemProperty> ActiveItemProperties;
    /* 0x1F8/504 */ CExoArrayList<CNWItemProperty> PassiveItemProperties;
    /* 0x204/516 */ unsigned long Charges;
    /* 0x208/520 */ unsigned long CostIdentified;
    /* 0x20C/524 */ unsigned long CostUnidentified;
    /* 0x210/528 */ unsigned long CostAdditional;
    /* 0x214/532 */ unsigned long RecalculateCostFlag;
    /* 0x218/536 */ unsigned char Model[22];
    /* 0x22E/558 */ unsigned char field_22E;
    /* 0x22F/559 */ unsigned char field_22F;
    /* 0x230/560 */ unsigned long field_230;
    /* 0x234/564 */ unsigned long field_234;
    /* 0x238/568 */ unsigned long field_238;
    /* 0x23C/572 */ unsigned long field_23C;
    /* 0x240/576 */ unsigned long field_240;
    /* 0x244/580 */ unsigned long Possessor;
    /* 0x248/584 */ unsigned long RepositoryPtr;
    /* 0x24C/588 */ char Repos_PosX;
    /* 0x24D/589 */ char Repos_PosY;
    /* 0x25E/590 */ char rsvd2[2];
    /* 0x250/592 */ CExoLocString DescriptionIdentified;
    /* 0x258/600 */ CExoLocString DescriptionUnidentified;
    /* 0x260/608 */ CExoString DescriptionIdentifiedOverride;
    /* 0x268/616 */ CExoString DescriptionUnidentifiedOverride;
    /* 0x270/624 */ CExoLocString LocalizedName;
    /* 0x278/632 */ CExoString DisplayName;
    /* 0x280/640 */ unsigned long UpdateDisplayName;
    /* 0x284/644 */ unsigned long Infinite;
    /* 0x288/648 */ unsigned char Dropable;
    /* 0x289/649 */ unsigned char field_289;
    /* 0x28A/650 */ unsigned char field_28A;
    /* 0x28B/651 */ unsigned char field_28B;
    /* 0x28C/652 */ unsigned long Pickpocketable;
    /* 0x290/656 */ unsigned long Cursed;
    /* 0x294/660 */ unsigned long Stacksize;
    /* 0x298/664 */ unsigned char Stolen;
    /* 0x299/665 */ unsigned char field_299;
    /* 0x29A/666 */ unsigned char field_29A;
    /* 0x29V/667*/ unsigned char field_29B;
    /* 0x29C/668 */ unsigned long Weight;
    /* 0x2A0/672 */ unsigned short RepositoryArrayIndex;
    /* 0x2A2/674 */ unsigned char VisualEffect;
    /* 0x2A3/675 */ unsigned char field_2A3;
    /* 0x2A4/676 */ unsigned long field_2A4;
};

static_assert_size(CNWSItem, 0x2a8);
static_assert_offset(CNWSItem, BaseItem, 0x8);
static_assert_offset(CNWSItem, ObjectID, 0x14);

#endif
