#ifndef _CNWSITEM_H_
#define _CNWSITEM_H_
#include "nwndef.h"
#include "nwnstructs.h"
#include "CResRef.h"
#include "CExoString.h"
#include "CExoLocString.h"
#include "CNWSObject.h"

class CNWSItem
{
public:
	int AIUpdate();
	int AcquireItem(CNWSItem **, unsigned long, unsigned char, unsigned char, int);
	int ActiveProperty(unsigned short);
	int AddActiveProperty(CNWItemProperty);
	int AddPassiveProperty(CNWItemProperty);
	int AddToArea(CNWSArea *, float, float, float, int);
	int ApplyItemProperties(CNWSCreature *, unsigned long, int);
	int AsNWSItem();
	int CalculateBaseCosts();
	int CalculatePassiveCost(CNWItemProperty *);
	int CloseInventory(unsigned long, int);
	int CloseItemForAllPlayers();
	int CompareItem(CNWSItem *);
	int ComputeArmorClass();
	int ComputeWeight();
	int CopyItem(CNWSItem *, int);
	int EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
	int GetActivePropertiesList();
	int GetActiveProperty(int);
	int GetArmorModelPart(unsigned char);
	int GetArmorValue();
	int GetCost(int, int, int, int);
	int GetDamageFlags();
	int GetDescriptionOverride(int);
	int GetDescription(int);
	int GetDisplayName();
	int GetFirstName();
	int GetIdentified();
	int GetInfinite();
	int GetIsCursed();
	int GetIsDroppable();
	int GetIsPickPocketable();
	int GetLastUsedActiveProperties();
	int GetLastUsedActivePropertyUsesLeft(unsigned char);
	int GetMinEquipLevel();
	int GetModelPart(unsigned char);
	int GetName();
	int GetNumActiveProperties();
	int GetNumCharges();
	int GetNumPassiveProperties();
	int GetPassivePropertiesList();
	int GetPassiveProperty(int);
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
	int GetUsedActivePropertyUsesLeft(unsigned char);
	int GetVisualEffect();
	int GetWeight();
	int InitRepository(unsigned long);
	int LoadDataFromGff(CResGFF *, CResStruct *, int);
	int LoadFromTemplate(CResRef, CExoString *);
	int LoadItem(CResGFF *, CResStruct *, int);
	int MergeItem(CNWSItem *);
	int OpenInventory(unsigned long);
	int ReadContainerItemsFromGff(CResGFF *, CResStruct *);
	int RemoveActiveProperty(int);
	int RemoveFromArea();
	int RemoveItemProperties(CNWSCreature *, unsigned long);
	int RemovePassiveProperty(int);
	int RestoreUsedActiveProperties(int);
	int RestoreUsedActiveProperty(CNWItemProperty *, int);
	int SaveContainerItems(CResGFF *, CResStruct *);
	int SaveItemProperties(CResGFF *, CResStruct *);
	int SaveItem(CResGFF *, CResStruct *, int);
	int SetArmorModelPart(unsigned char, unsigned char);
	int SetArmorValue(int);
	int SetBarterOwner(unsigned long);
	int SetDisplayName(CExoString);
	int SetFirstName(unsigned long);
	int SetIdentifiedDescriptionOverride(CExoString);
	int SetIdentifiedDescription(CExoLocString);
	int SetIdentified(int);
	int SetInfinite(int);
	int SetIsCursed(int);
	int SetIsDroppable(int);
	int SetIsPickPocketable(int);
	int SetModelPart(unsigned char, unsigned char);
	int SetName(CExoLocString);
	int SetNumCharges(int);
	int SetPossessor(unsigned long, int, int, int);
	int SetRecalculateCostFlag(int);
	int SetRepositoryArrayIndex(unsigned short);
	int SetRepositoryPosition(unsigned char, unsigned char);
	int SetStackSize(int);
	int SetStolen(int);
	int SetUnalteredArmorModelPart(unsigned char, unsigned char);
	int SetUnidentifiedDescriptionOverride(CExoString);
	int SetUnidentifiedDescription(CExoLocString);
	int SetUpdateDisplayName(int);
	int SetWeight(int);
	int SplitItem(int);
	int UpdateUsedActiveProperties(int);
	int UpdateVisualEffect();
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
