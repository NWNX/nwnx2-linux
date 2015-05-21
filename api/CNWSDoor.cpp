#include "CNWSDoor.h"

void CNWSDoor::AIUpdate()
{
    asm("leave");
    asm("mov $0x08166d64, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::AddToArea(CNWSArea *, float, float, float, int)
{
    asm("leave");
    asm("mov $0x081669bc, %eax");
    asm("jmp *%eax");
}

CNWSDoor * CNWSDoor::AsNWSDoor()
{
    asm("leave");
    asm("mov $0x0816a9d8, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::DoDamage(int)
{
    asm("leave");
    asm("mov $0x0816a8d4, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08166e4c, %eax");
    asm("jmp *%eax");
}

Vector CNWSDoor::GetActionPoint(int, unsigned char)
{
    asm("leave");
    asm("mov $0x08169fe4, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetActive()
{
    asm("leave");
    asm("mov $0x0816b148, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetAppearanceType()
{
    asm("leave");
    asm("mov $0x0816aa94, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetAutoRemoveKey()
{
    asm("leave");
    asm("mov $0x0816af00, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetBaseType()
{
    asm("leave");
    asm("mov $0x0816b004, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetBearing()
{
    asm("leave");
    asm("mov $0x0816aaf0, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetCreatureList()
{
    asm("leave");
    asm("mov $0x0816b2e4, %eax");
    asm("jmp *%eax");
}

CExoString CNWSDoor::GetDescriptionOverride()
{
    asm("leave");
    asm("mov $0x0816ac40, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSDoor::GetDescription()
{
    asm("leave");
    asm("mov $0x0816abd8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetDetectDC()
{
    asm("leave");
    asm("mov $0x0816b070, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetDetectable()
{
    asm("leave");
    asm("mov $0x0816b0dc, %eax");
    asm("jmp *%eax");
}

CResRef CNWSDoor::GetDialogResref()
{
    asm("leave");
    asm("mov $0x0816a9e0, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetDisarmDC()
{
    asm("leave");
    asm("mov $0x0816b04c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetDisarmable()
{
    asm("leave");
    asm("mov $0x0816b0b8, %eax");
    asm("jmp *%eax");
}

CExoString CNWSDoor::GetDisplayName()
{
    asm("leave");
    asm("mov $0x0816ad28, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetFactionId()
{
    asm("leave");
    asm("mov $0x0816ab14, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSDoor::GetFirstName()
{
    asm("leave");
    asm("mov $0x0816acc0, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetFlagged()
{
    asm("leave");
    asm("mov $0x0816b094, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetFortitudeSave()
{
    asm("leave");
    asm("mov $0x0816ab5c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetGenericType()
{
    asm("leave");
    asm("mov $0x0816aab8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetHardness()
{
    asm("leave");
    asm("mov $0x0816abc8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetIsLinked()
{
    asm("leave");
    asm("mov $0x0816a744, %eax");
    asm("jmp *%eax");
}

CExoString * CNWSDoor::GetKeyName()
{
    asm("leave");
    asm("mov $0x0816ae38, %eax");
    asm("jmp *%eax");
}

CExoString CNWSDoor::GetKeyRequiredFeedbackMessage()
{
    asm("leave");
    asm("mov $0x0816aec4, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetKeyRequired()
{
    asm("leave");
    asm("mov $0x0816ae5c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetLastClosed()
{
    asm("leave");
    asm("mov $0x0816aa70, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetLastDisarmed()
{
    asm("leave");
    asm("mov $0x0816b29c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetLastLocked()
{
    asm("leave");
    asm("mov $0x0816b254, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetLastOpened()
{
    asm("leave");
    asm("mov $0x0816aa28, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetLastTriggered()
{
    asm("leave");
    asm("mov $0x0816aa4c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetLastUnlocked()
{
    asm("leave");
    asm("mov $0x0816b278, %eax");
    asm("jmp *%eax");
}

CNWSObject * CNWSDoor::GetLinkedObject()
{
    asm("leave");
    asm("mov $0x0816a4e4, %eax");
    asm("jmp *%eax");
}

CExoString CNWSDoor::GetLinkedToTag()
{
    asm("leave");
    asm("mov $0x0816b190, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSDoor::GetLoadScreenID()
{
    asm("leave");
    asm("mov $0x0816b2f4, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetLockDC()
{
    asm("leave");
    asm("mov $0x0816af48, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetLockable()
{
    asm("leave");
    asm("mov $0x0816adec, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetLocked()
{
    asm("leave");
    asm("mov $0x0816ae10, %eax");
    asm("jmp *%eax");
}

Vector CNWSDoor::GetNearestActionPoint(Vector const &, int)
{
    asm("leave");
    asm("mov $0x0816a14c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetOneShot()
{
    asm("leave");
    asm("mov $0x0816b100, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetOpenLockDC()
{
    asm("leave");
    asm("mov $0x0816af24, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSDoor::GetOpenState()
{
    asm("leave");
    asm("mov $0x0816a908, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetRecoverable()
{
    asm("leave");
    asm("mov $0x0816b124, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetReflexSave()
{
    asm("leave");
    asm("mov $0x0816ab38, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetScriptName(int)
{
    asm("leave");
    asm("mov $0x0816afb8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetSecretDoorDC()
{
    asm("leave");
    asm("mov $0x0816aba4, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetTrapCreator()
{
    asm("leave");
    asm("mov $0x0816afe0, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetTrapFactionId()
{
    asm("leave");
    asm("mov $0x0816b16c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetTrapped()
{
    asm("leave");
    asm("mov $0x0816b028, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetUpdateDisplayName()
{
    asm("leave");
    asm("mov $0x0816adb4, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetVisibleModel()
{
    asm("leave");
    asm("mov $0x0816b2c0, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::GetWillSave()
{
    asm("leave");
    asm("mov $0x0816ab80, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::LoadDoor(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08167bc8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::NoNonWalkPolysInDoor(float, float, float, float, float, float, float)
{
    asm("leave");
    asm("mov $0x0816a75c, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::PostProcess()
{
    asm("leave");
    asm("mov $0x08169c54, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::RemoveFromArea()
{
    asm("leave");
    asm("mov $0x08169d3c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SaveDoor(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081692ec, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetActive(int)
{
    asm("leave");
    asm("mov $0x0816b134, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetAppearanceType(unsigned long)
{
    asm("leave");
    asm("mov $0x0816aaa4, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetAutoRemoveKey(int)
{
    asm("leave");
    asm("mov $0x0816aeec, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetBaseType(unsigned char)
{
    asm("leave");
    asm("mov $0x0816aff0, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetBearing(float)
{
    asm("leave");
    asm("mov $0x0816aadc, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::SetDescriptionOverride(CExoString)
{
    asm("leave");
    asm("mov $0x0816ac68, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::SetDescription(CExoLocString)
{
    asm("leave");
    asm("mov $0x0816abe8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetDetectDC(unsigned char)
{
    asm("leave");
    asm("mov $0x0816b05c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetDetectable(int)
{
    asm("leave");
    asm("mov $0x0816b0c8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetDialogResref(CResRef)
{
    asm("leave");
    asm("mov $0x0816aa04, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetDisarmDC(unsigned char)
{
    asm("leave");
    asm("mov $0x0816b038, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetDisarmable(int)
{
    asm("leave");
    asm("mov $0x0816b0a4, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::SetDisplayName(CExoString)
{
    asm("leave");
    asm("mov $0x0816ad50, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetFactionId(int)
{
    asm("leave");
    asm("mov $0x0816ab00, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::SetFirstName(CExoLocString)
{
    asm("leave");
    asm("mov $0x0816acd0, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetFlagged(unsigned char)
{
    asm("leave");
    asm("mov $0x0816b080, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetFortitudeSave(unsigned char)
{
    asm("leave");
    asm("mov $0x0816ab48, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetGenericType(unsigned long)
{
    asm("leave");
    asm("mov $0x0816aac8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetHardness(unsigned char)
{
    asm("leave");
    asm("mov $0x0816abb4, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetKeyName(CExoString const &)
{
    asm("leave");
    asm("mov $0x0816ae20, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::SetKeyRequiredFeedbackMessage(CExoString)
{
    asm("leave");
    asm("mov $0x0816ae6c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetKeyRequired(int)
{
    asm("leave");
    asm("mov $0x0816ae48, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetLastClosed(unsigned long)
{
    asm("leave");
    asm("mov $0x0816aa80, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetLastDisarmed(unsigned long)
{
    asm("leave");
    asm("mov $0x0816b2ac, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetLastLocked(unsigned long)
{
    asm("leave");
    asm("mov $0x0816b264, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetLastOpened(unsigned long)
{
    asm("leave");
    asm("mov $0x0816aa38, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetLastTriggered(unsigned long)
{
    asm("leave");
    asm("mov $0x0816aa5c, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetLastUnlocked(unsigned long)
{
    asm("leave");
    asm("mov $0x0816b288, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetLinkedFlags(unsigned char)
{
    asm("leave");
    asm("mov $0x0816b17c, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::SetLinkedToTag(CExoString)
{
    asm("leave");
    asm("mov $0x0816b1b8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetLockDC(unsigned char)
{
    asm("leave");
    asm("mov $0x0816af34, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetLockable(int)
{
    asm("leave");
    asm("mov $0x0816add8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetLocked(int)
{
    asm("leave");
    asm("mov $0x0816adfc, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetOneShot(int)
{
    asm("leave");
    asm("mov $0x0816b0ec, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetOpenLockDC(unsigned char)
{
    asm("leave");
    asm("mov $0x0816af10, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::SetOpenState(unsigned char)
{
    asm("leave");
    asm("mov $0x0816a5b8, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetRecoverable(int)
{
    asm("leave");
    asm("mov $0x0816b110, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetReflexSave(unsigned char)
{
    asm("leave");
    asm("mov $0x0816ab24, %eax");
    asm("jmp *%eax");
}

void CNWSDoor::SetScriptName(int, CExoString)
{
    asm("leave");
    asm("mov $0x0816af58, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetSecretDoorDC(unsigned char)
{
    asm("leave");
    asm("mov $0x0816ab90, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetTrapCreator(unsigned long)
{
    asm("leave");
    asm("mov $0x0816afcc, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetTrapFactionId(int)
{
    asm("leave");
    asm("mov $0x0816b158, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetTrapped(int)
{
    asm("leave");
    asm("mov $0x0816b014, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetUpdateDisplayName(int)
{
    asm("leave");
    asm("mov $0x0816adc4, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetVisibleModel(int)
{
    asm("leave");
    asm("mov $0x0816b2d0, %eax");
    asm("jmp *%eax");
}

int CNWSDoor::SetWillSave(unsigned char)
{
    asm("leave");
    asm("mov $0x0816ab6c, %eax");
    asm("jmp *%eax");
}

