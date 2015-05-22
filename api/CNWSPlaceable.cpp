#include "CNWSPlaceable.h"

unsigned long CNWSPlaceable::AIActionCastSpell(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081e16b8, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::AIUpdate()
{
    asm("leave");
    asm("mov $0x081e0614, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::AcquireItem(CNWSItem **, unsigned long, unsigned char, unsigned char, int)
{
    asm("leave");
    asm("mov $0x081e0860, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSPlaceable::AcquireItemsFromObject(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081e0a0c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::AddCastSpellActions(unsigned long, int, Vector, unsigned long, int, unsigned char)
{
    asm("leave");
    asm("mov $0x081e15bc, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::AddToArea(CNWSArea *, float, float, float, int)
{
    asm("leave");
    asm("mov $0x081df174, %eax");
    asm("jmp *%eax");
}

CNWSPlaceable * CNWSPlaceable::AsNWSPlaceable()
{
    asm("leave");
    asm("mov $0x081e1e6c, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::CalculateActionPoints()
{
    asm("leave");
    asm("mov $0x081df588, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::CloseInventory(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081e11d0, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::ClosePlaceableForAllPlayers()
{
    asm("leave");
    asm("mov $0x081e1b48, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::DoDamage(int)
{
    asm("leave");
    asm("mov $0x081e1c94, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::DropItemsIntoArea()
{
    asm("leave");
    asm("mov $0x081e1330, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081df88c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetActive()
{
    asm("leave");
    asm("mov $0x081e26b0, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetAppearance()
{
    asm("leave");
    asm("mov $0x081e1fb0, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetAutoRemoveKey()
{
    asm("leave");
    asm("mov $0x081e223c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetBaseType()
{
    asm("leave");
    asm("mov $0x081e25fc, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetBearing()
{
    asm("leave");
    asm("mov $0x081e214c, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSPlaceable::GetBodyBagAppearance()
{
    asm("leave");
    asm("mov $0x081e1958, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetBodyBag()
{
    asm("leave");
    asm("mov $0x081e2924, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetCloseLockDC()
{
    asm("leave");
    asm("mov $0x081e2284, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetCreatureList()
{
    asm("leave");
    asm("mov $0x081e256c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetCurrentItemContainer()
{
    asm("leave");
    asm("mov $0x081e27f0, %eax");
    asm("jmp *%eax");
}

CExoString CNWSPlaceable::GetDescriptionOverride()
{
    asm("leave");
    asm("mov $0x081e2084, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSPlaceable::GetDescription()
{
    asm("leave");
    asm("mov $0x081e201c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetDetectDC()
{
    asm("leave");
    asm("mov $0x081e25c4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetDetectable()
{
    asm("leave");
    asm("mov $0x081e2644, %eax");
    asm("jmp *%eax");
}

CResRef CNWSPlaceable::GetDialogResref()
{
    asm("leave");
    asm("mov $0x081e272c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetDieWhenEmpty()
{
    asm("leave");
    asm("mov $0x081e2784, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetDisarmDC()
{
    asm("leave");
    asm("mov $0x081e26e4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetDisarmable()
{
    asm("leave");
    asm("mov $0x081e2620, %eax");
    asm("jmp *%eax");
}

CExoString CNWSPlaceable::GetDisplayName()
{
    asm("leave");
    asm("mov $0x081e1f00, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSPlaceable::GetEffectSpellId()
{
    asm("leave");
    asm("mov $0x081e28dc, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetFactionId()
{
    asm("leave");
    asm("mov $0x081e2104, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSPlaceable::GetFirstName()
{
    asm("leave");
    asm("mov $0x081e1e98, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetFlagged()
{
    asm("leave");
    asm("mov $0x081e2708, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetFortSave()
{
    asm("leave");
    asm("mov $0x081e22a8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetHardness()
{
    asm("leave");
    asm("mov $0x081e2128, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetHasInventory()
{
    asm("leave");
    asm("mov $0x081e235c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetIsBodyBag()
{
    asm("leave");
    asm("mov $0x081e29b4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetIsGroundPile()
{
    asm("leave");
    asm("mov $0x081e200c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetItemContainerArrayIndex()
{
    asm("leave");
    asm("mov $0x081e27cc, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSPlaceable::GetItemCount(int)
{
    asm("leave");
    asm("mov $0x081e1ab4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetItemRepository()
{
    asm("leave");
    asm("mov $0x081e2774, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetKeyName()
{
    asm("leave");
    asm("mov $0x081e2170, %eax");
    asm("jmp *%eax");
}

CExoString CNWSPlaceable::GetKeyRequiredFeedbackMessage()
{
    asm("leave");
    asm("mov $0x081e2214, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetKeyRequired()
{
    asm("leave");
    asm("mov $0x081e2198, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLastClosed()
{
    asm("leave");
    asm("mov $0x081e2548, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLastDefaultClickedBy()
{
    asm("leave");
    asm("mov $0x081e2524, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLastDisarmed()
{
    asm("leave");
    asm("mov $0x081e2494, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLastLocked()
{
    asm("leave");
    asm("mov $0x081e24b8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLastOpened()
{
    asm("leave");
    asm("mov $0x081e244c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLastTriggered()
{
    asm("leave");
    asm("mov $0x081e2470, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLastUnlocked()
{
    asm("leave");
    asm("mov $0x081e24dc, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLastUser()
{
    asm("leave");
    asm("mov $0x081e2500, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLightIsOn()
{
    asm("leave");
    asm("mov $0x081e1d74, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLightStateChange()
{
    asm("leave");
    asm("mov $0x081e2900, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLockable()
{
    asm("leave");
    asm("mov $0x081e2338, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLocked()
{
    asm("leave");
    asm("mov $0x081e2314, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetLootableCreatureId()
{
    asm("leave");
    asm("mov $0x081e2990, %eax");
    asm("jmp *%eax");
}

Vector CNWSPlaceable::GetNearestActionPoint(Vector const &)
{
    asm("leave");
    asm("mov $0x081e142c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetNeverMakeIntoStaticObject()
{
    asm("leave");
    asm("mov $0x081e296c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetOneShot()
{
    asm("leave");
    asm("mov $0x081e2668, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetOpenLockDC()
{
    asm("leave");
    asm("mov $0x081e2260, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetPickable()
{
    asm("leave");
    asm("mov $0x081e23a4, %eax");
    asm("jmp *%eax");
}

CExoString CNWSPlaceable::GetPortalInfo()
{
    asm("leave");
    asm("mov $0x081e28b4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetRecoverable()
{
    asm("leave");
    asm("mov $0x081e268c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetReflexSave()
{
    asm("leave");
    asm("mov $0x081e22f0, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetRepositoryArrayIndex()
{
    asm("leave");
    asm("mov $0x081e27a8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetScriptName(int)
{
    asm("leave");
    asm("mov $0x081e23c8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetSittingCreature()
{
    asm("leave");
    asm("mov $0x081e1e74, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetStaticObject()
{
    asm("leave");
    asm("mov $0x081e2948, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetTemplateResRef()
{
    asm("leave");
    asm("mov $0x081e2814, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetTrapCreator()
{
    asm("leave");
    asm("mov $0x081e257c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetTrapFaction()
{
    asm("leave");
    asm("mov $0x081e26d4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetTrapped()
{
    asm("leave");
    asm("mov $0x081e25a0, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetType()
{
    asm("leave");
    asm("mov $0x081e1fd4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetUpdateDisplayName()
{
    asm("leave");
    asm("mov $0x081e1f8c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetUseable()
{
    asm("leave");
    asm("mov $0x081e2380, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::GetWillSave()
{
    asm("leave");
    asm("mov $0x081e22cc, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::LoadBodyBag(unsigned short)
{
    asm("leave");
    asm("mov $0x081ddb44, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::LoadFromTemplate(CResRef, CExoString *)
{
    asm("leave");
    asm("mov $0x081dbf94, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::LoadPlaceable(CResGFF *, CResStruct *, CExoString *)
{
    asm("leave");
    asm("mov $0x081dc150, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::OpenInventory(unsigned long)
{
    asm("leave");
    asm("mov $0x081e0ff0, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::PostProcess()
{
    asm("leave");
    asm("mov $0x081defbc, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::RemoveFromArea()
{
    asm("leave");
    asm("mov $0x081df7c0, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::RemoveItem(CNWSItem *, int)
{
    asm("leave");
    asm("mov $0x081e1c30, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SavePlaceable(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081de414, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetActive(int)
{
    asm("leave");
    asm("mov $0x081e269c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetAppearance(unsigned short)
{
    asm("leave");
    asm("mov $0x081e1fc0, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetAutoRemoveKey(int)
{
    asm("leave");
    asm("mov $0x081e224c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetBaseType(unsigned char)
{
    asm("leave");
    asm("mov $0x081e25e8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetBearing(float)
{
    asm("leave");
    asm("mov $0x081e215c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetBodyBag(unsigned char)
{
    asm("leave");
    asm("mov $0x081e2934, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetCloseLockDC(unsigned char)
{
    asm("leave");
    asm("mov $0x081e2294, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetCurrentItemContainer(unsigned long)
{
    asm("leave");
    asm("mov $0x081e2800, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetDescriptionOverride(CExoString)
{
    asm("leave");
    asm("mov $0x081e20ac, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetDescription(CExoLocString)
{
    asm("leave");
    asm("mov $0x081e202c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetDetectDC(unsigned char)
{
    asm("leave");
    asm("mov $0x081e25d4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetDetectable(int)
{
    asm("leave");
    asm("mov $0x081e2630, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetDialogResref(CResRef)
{
    asm("leave");
    asm("mov $0x081e2750, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetDieWhenEmpty(int)
{
    asm("leave");
    asm("mov $0x081e2794, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetDisarmDC(unsigned char)
{
    asm("leave");
    asm("mov $0x081e26f4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetDisarmable(int)
{
    asm("leave");
    asm("mov $0x081e260c, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetDisplayName(CExoString)
{
    asm("leave");
    asm("mov $0x081e1f28, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetEffectSpellId(unsigned long)
{
    asm("leave");
    asm("mov $0x081e28ec, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetFactionId(int)
{
    asm("leave");
    asm("mov $0x081e2114, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetFirstName(CExoLocString)
{
    asm("leave");
    asm("mov $0x081e1ea8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetFlagged(unsigned char)
{
    asm("leave");
    asm("mov $0x081e2718, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetFortSave(unsigned char)
{
    asm("leave");
    asm("mov $0x081e22b8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetHardness(unsigned char)
{
    asm("leave");
    asm("mov $0x081e2138, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetHasInventory(int)
{
    asm("leave");
    asm("mov $0x081e236c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetIsBodyBag(int)
{
    asm("leave");
    asm("mov $0x081e29c4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetIsGroundPile(int)
{
    asm("leave");
    asm("mov $0x081e1ff8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetItemContainerArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x081e27dc, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetKeyName(CExoString const &)
{
    asm("leave");
    asm("mov $0x081e2180, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetKeyRequiredFeedbackMessage(CExoString)
{
    asm("leave");
    asm("mov $0x081e21bc, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetKeyRequired(int)
{
    asm("leave");
    asm("mov $0x081e21a8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLastClosed(unsigned long)
{
    asm("leave");
    asm("mov $0x081e2558, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLastDefaultClickedBy(unsigned long)
{
    asm("leave");
    asm("mov $0x081e2534, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLastDisarmed(unsigned long)
{
    asm("leave");
    asm("mov $0x081e24a4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLastLocked(unsigned long)
{
    asm("leave");
    asm("mov $0x081e24c8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLastOpened(unsigned long)
{
    asm("leave");
    asm("mov $0x081e245c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLastTriggered(unsigned long)
{
    asm("leave");
    asm("mov $0x081e2480, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLastUnlocked(unsigned long)
{
    asm("leave");
    asm("mov $0x081e24ec, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLastUser(unsigned long)
{
    asm("leave");
    asm("mov $0x081e2510, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetLightIsOn(int)
{
    asm("leave");
    asm("mov $0x081e1cc8, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLightStateChange(int)
{
    asm("leave");
    asm("mov $0x081e2910, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLockable(int)
{
    asm("leave");
    asm("mov $0x081e2348, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLocked(int)
{
    asm("leave");
    asm("mov $0x081e2324, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetLootableCreatureId(unsigned long)
{
    asm("leave");
    asm("mov $0x081e29a0, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetNeverMakeIntoStaticObject(int)
{
    asm("leave");
    asm("mov $0x081e297c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetOneShot(int)
{
    asm("leave");
    asm("mov $0x081e2654, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetOpenLockDC(unsigned char)
{
    asm("leave");
    asm("mov $0x081e2270, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetOrientation(Vector)
{
    asm("leave");
    asm("mov $0x081df084, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetPickable(int)
{
    asm("leave");
    asm("mov $0x081e23b4, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetPortalInfo(CExoString)
{
    asm("leave");
    asm("mov $0x081e285c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetRecoverable(int)
{
    asm("leave");
    asm("mov $0x081e2678, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetReflexSave(unsigned char)
{
    asm("leave");
    asm("mov $0x081e2300, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetRepositoryArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x081e27b8, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetScriptName(int, CExoString)
{
    asm("leave");
    asm("mov $0x081e23e4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetSittingCreature(unsigned long)
{
    asm("leave");
    asm("mov $0x081e1e84, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetStaticObject(int)
{
    asm("leave");
    asm("mov $0x081e2958, %eax");
    asm("jmp *%eax");
}

void CNWSPlaceable::SetTemplateResRef(CResRef)
{
    asm("leave");
    asm("mov $0x081e2838, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetTrapCreator(unsigned long)
{
    asm("leave");
    asm("mov $0x081e258c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetTrapFaction(int)
{
    asm("leave");
    asm("mov $0x081e26c0, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetTrapped(int)
{
    asm("leave");
    asm("mov $0x081e25b0, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetType(unsigned char)
{
    asm("leave");
    asm("mov $0x081e1fe4, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetUpdateDisplayName(int)
{
    asm("leave");
    asm("mov $0x081e1f9c, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetUseable(int)
{
    asm("leave");
    asm("mov $0x081e2390, %eax");
    asm("jmp *%eax");
}

int CNWSPlaceable::SetWillSave(unsigned char)
{
    asm("leave");
    asm("mov $0x081e22dc, %eax");
    asm("jmp *%eax");
}

