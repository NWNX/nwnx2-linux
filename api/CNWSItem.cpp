#include "CNWSItem.h"

void CNWSItem::AIUpdate()
{
    asm("leave");
    asm("mov $0x081a6648, %eax");
    asm("jmp *%eax");
}

int CNWSItem::AcquireItem(CNWSItem **, unsigned long, unsigned char, unsigned char, int)
{
    asm("leave");
    asm("mov $0x081a5f4c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::ActiveProperty(unsigned short)
{
    asm("leave");
    asm("mov $0x081a6754, %eax");
    asm("jmp *%eax");
}

void CNWSItem::AddActiveProperty(CNWItemProperty)
{
    asm("leave");
    asm("mov $0x081a6784, %eax");
    asm("jmp *%eax");
}

void CNWSItem::AddPassiveProperty(CNWItemProperty)
{
    asm("leave");
    asm("mov $0x081a67ec, %eax");
    asm("jmp *%eax");
}

void CNWSItem::AddToArea(CNWSArea *, float, float, float, int)
{
    asm("leave");
    asm("mov $0x081a65d0, %eax");
    asm("jmp *%eax");
}

void CNWSItem::ApplyItemProperties(CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081a68ac, %eax");
    asm("jmp *%eax");
}

CNWSItem * CNWSItem::AsNWSItem()
{
    asm("leave");
    asm("mov $0x081a6ca0, %eax");
    asm("jmp *%eax");
}

void CNWSItem::CalculateBaseCosts()
{
    asm("leave");
    asm("mov $0x081a5794, %eax");
    asm("jmp *%eax");
}

float CNWSItem::CalculatePassiveCost(CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x081a54b0, %eax");
    asm("jmp *%eax");
}

void CNWSItem::CloseInventory(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081a4e14, %eax");
    asm("jmp *%eax");
}

void CNWSItem::CloseItemForAllPlayers()
{
    asm("leave");
    asm("mov $0x081a5e90, %eax");
    asm("jmp *%eax");
}

int CNWSItem::CompareItem(CNWSItem *)
{
    asm("leave");
    asm("mov $0x081a2ed0, %eax");
    asm("jmp *%eax");
}

int CNWSItem::ComputeArmorClass()
{
    asm("leave");
    asm("mov $0x081a2d58, %eax");
    asm("jmp *%eax");
}

void CNWSItem::ComputeWeight()
{
    asm("leave");
    asm("mov $0x081a137c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::CopyItem(CNWSItem *, int)
{
    asm("leave");
    asm("mov $0x081a4f98, %eax");
    asm("jmp *%eax");
}

void CNWSItem::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0819fb08, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetActivePropertiesList()
{
    asm("leave");
    asm("mov $0x081a721c, %eax");
    asm("jmp *%eax");
}

CNWItemProperty * CNWSItem::GetActiveProperty(int)
{
    asm("leave");
    asm("mov $0x081a6854, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetArmorModelPart(unsigned char)
{
    asm("leave");
    asm("mov $0x081a6ca8, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetArmorValue()
{
    asm("leave");
    asm("mov $0x081a7120, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSItem::GetCost(int, int, int, int)
{
    asm("leave");
    asm("mov $0x081a53a8, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSItem::GetDamageFlags()
{
    asm("leave");
    asm("mov $0x081a5ca0, %eax");
    asm("jmp *%eax");
}

CExoString CNWSItem::GetDescriptionOverride(int)
{
    asm("leave");
    asm("mov $0x081a6fcc, %eax");
    asm("jmp *%eax");
}

CExoLocString CNWSItem::GetDescription(int)
{
    asm("leave");
    asm("mov $0x081a6f98, %eax");
    asm("jmp *%eax");
}

CExoString CNWSItem::GetDisplayName()
{
    asm("leave");
    asm("mov $0x081a704c, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSItem::GetFirstName()
{
    asm("leave");
    asm("mov $0x081a7028, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetIdentified()
{
    asm("leave");
    asm("mov $0x081a7110, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetInfinite()
{
    asm("leave");
    asm("mov $0x081a7144, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetIsCursed()
{
    asm("leave");
    asm("mov $0x081a72ac, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetIsDroppable()
{
    asm("leave");
    asm("mov $0x081a7250, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetIsPickPocketable()
{
    asm("leave");
    asm("mov $0x081a7274, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetLastUsedActiveProperties()
{
    asm("leave");
    asm("mov $0x081a71d4, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetLastUsedActivePropertyUsesLeft(unsigned char)
{
    asm("leave");
    asm("mov $0x081a71e4, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSItem::GetMinEquipLevel()
{
    asm("leave");
    asm("mov $0x081a5de4, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetModelPart(unsigned char)
{
    asm("leave");
    asm("mov $0x081a6ce8, %eax");
    asm("jmp *%eax");
}

CExoLocString CNWSItem::GetName()
{
    asm("leave");
    asm("mov $0x081a7000, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetNumActiveProperties()
{
    asm("leave");
    asm("mov $0x081a71fc, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetNumCharges()
{
    asm("leave");
    asm("mov $0x081a71b0, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetNumPassiveProperties()
{
    asm("leave");
    asm("mov $0x081a720c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetPassivePropertiesList()
{
    asm("leave");
    asm("mov $0x081a722c, %eax");
    asm("jmp *%eax");
}

CNWItemProperty * CNWSItem::GetPassiveProperty(int)
{
    asm("leave");
    asm("mov $0x081a6880, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetPossessor()
{
    asm("leave");
    asm("mov $0x081a6d3c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetPropertyByTypeExists(unsigned short, unsigned short)
{
    asm("leave");
    asm("mov $0x081a2a6c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetPropertyByType(CNWItemProperty **, unsigned short, unsigned short)
{
    asm("leave");
    asm("mov $0x081a2b34, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetRepositoryArrayIndex()
{
    asm("leave");
    asm("mov $0x081a6da0, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetRepositoryPosition(unsigned char &, unsigned char &)
{
    asm("leave");
    asm("mov $0x081a6d08, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetRepositoryPtr()
{
    asm("leave");
    asm("mov $0x081a6d2c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetStackSize()
{
    asm("leave");
    asm("mov $0x081a7168, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetStolen()
{
    asm("leave");
    asm("mov $0x081a718c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetUnalteredArmorModelPart(unsigned char)
{
    asm("leave");
    asm("mov $0x081a6cc8, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetUpdateDisplayName()
{
    asm("leave");
    asm("mov $0x081a70d8, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSItem::GetUsedActivePropertyUsesLeft(unsigned char)
{
    asm("leave");
    asm("mov $0x081a28f0, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetVisualEffect()
{
    asm("leave");
    asm("mov $0x081a72e4, %eax");
    asm("jmp *%eax");
}

int CNWSItem::GetWeight()
{
    asm("leave");
    asm("mov $0x081a6b90, %eax");
    asm("jmp *%eax");
}

int CNWSItem::InitRepository(unsigned long)
{
    asm("leave");
    asm("mov $0x0819fe3c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::LoadDataFromGff(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x081a00c4, %eax");
    asm("jmp *%eax");
}

int CNWSItem::LoadFromTemplate(CResRef, CExoString *)
{
    asm("leave");
    asm("mov $0x0819fedc, %eax");
    asm("jmp *%eax");
}

int CNWSItem::LoadItem(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x081a17cc, %eax");
    asm("jmp *%eax");
}

int CNWSItem::MergeItem(CNWSItem *)
{
    asm("leave");
    asm("mov $0x081a31b4, %eax");
    asm("jmp *%eax");
}

void CNWSItem::OpenInventory(unsigned long)
{
    asm("leave");
    asm("mov $0x081a4c00, %eax");
    asm("jmp *%eax");
}

void CNWSItem::ReadContainerItemsFromGff(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081a160c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::RemoveActiveProperty(int)
{
    asm("leave");
    asm("mov $0x081a67b8, %eax");
    asm("jmp *%eax");
}

void CNWSItem::RemoveFromArea()
{
    asm("leave");
    asm("mov $0x081a669c, %eax");
    asm("jmp *%eax");
}

void CNWSItem::RemoveItemProperties(CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081a2cc0, %eax");
    asm("jmp *%eax");
}

int CNWSItem::RemovePassiveProperty(int)
{
    asm("leave");
    asm("mov $0x081a6820, %eax");
    asm("jmp *%eax");
}

void CNWSItem::RestoreUsedActiveProperties(int)
{
    asm("leave");
    asm("mov $0x081a670c, %eax");
    asm("jmp *%eax");
}

void CNWSItem::RestoreUsedActiveProperty(CNWItemProperty *, int)
{
    asm("leave");
    asm("mov $0x081a2a0c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SaveContainerItems(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081a267c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SaveItemProperties(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081a241c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SaveItem(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x081a19c4, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetArmorModelPart(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081a6d4c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetArmorValue(int)
{
    asm("leave");
    asm("mov $0x081a7130, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetBarterOwner(unsigned long)
{
    asm("leave");
    asm("mov $0x081a72d0, %eax");
    asm("jmp *%eax");
}

void CNWSItem::SetDisplayName(CExoString)
{
    asm("leave");
    asm("mov $0x081a7074, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetFirstName(unsigned long)
{
    asm("leave");
    asm("mov $0x081a7038, %eax");
    asm("jmp *%eax");
}

void CNWSItem::SetIdentifiedDescriptionOverride(CExoString)
{
    asm("leave");
    asm("mov $0x081a6e90, %eax");
    asm("jmp *%eax");
}

void CNWSItem::SetIdentifiedDescription(CExoLocString)
{
    asm("leave");
    asm("mov $0x081a6de0, %eax");
    asm("jmp *%eax");
}

void CNWSItem::SetIdentified(int)
{
    asm("leave");
    asm("mov $0x081a6bd8, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetInfinite(int)
{
    asm("leave");
    asm("mov $0x081a7154, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetIsCursed(int)
{
    asm("leave");
    asm("mov $0x081a7298, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetIsDroppable(int)
{
    asm("leave");
    asm("mov $0x081a723c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetIsPickPocketable(int)
{
    asm("leave");
    asm("mov $0x081a7260, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetModelPart(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081a6dc4, %eax");
    asm("jmp *%eax");
}

void CNWSItem::SetName(CExoLocString)
{
    asm("leave");
    asm("mov $0x081a6f40, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetNumCharges(int)
{
    asm("leave");
    asm("mov $0x081a71c0, %eax");
    asm("jmp *%eax");
}

void CNWSItem::SetPossessor(unsigned long, int, int, int)
{
    asm("leave");
    asm("mov $0x0819f23c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetRecalculateCostFlag(int)
{
    asm("leave");
    asm("mov $0x081a70fc, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetRepositoryArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x081a6db0, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetRepositoryPosition(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081a6d84, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetStackSize(int)
{
    asm("leave");
    asm("mov $0x081a7178, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetStolen(int)
{
    asm("leave");
    asm("mov $0x081a719c, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetUnalteredArmorModelPart(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081a6d68, %eax");
    asm("jmp *%eax");
}

void CNWSItem::SetUnidentifiedDescriptionOverride(CExoString)
{
    asm("leave");
    asm("mov $0x081a6ee8, %eax");
    asm("jmp *%eax");
}

void CNWSItem::SetUnidentifiedDescription(CExoLocString)
{
    asm("leave");
    asm("mov $0x081a6e38, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetUpdateDisplayName(int)
{
    asm("leave");
    asm("mov $0x081a70e8, %eax");
    asm("jmp *%eax");
}

int CNWSItem::SetWeight(int)
{
    asm("leave");
    asm("mov $0x081a72bc, %eax");
    asm("jmp *%eax");
}

CNWSItem * CNWSItem::SplitItem(int)
{
    asm("leave");
    asm("mov $0x081a3230, %eax");
    asm("jmp *%eax");
}

void CNWSItem::UpdateUsedActiveProperties(int)
{
    asm("leave");
    asm("mov $0x081a2770, %eax");
    asm("jmp *%eax");
}

void CNWSItem::UpdateVisualEffect()
{
    asm("leave");
    asm("mov $0x081a61c8, %eax");
    asm("jmp *%eax");
}

