#include "CNWSTrigger.h"

void CNWSTrigger::AIUpdate()
{
    asm("leave");
    asm("mov $0x081f2880, %eax");
    asm("jmp *%eax");
}

void CNWSTrigger::AddToArea(CNWSArea *, float, float, float, int)
{
    asm("leave");
    asm("mov $0x081ee668, %eax");
    asm("jmp *%eax");
}

CNWSTrigger * CNWSTrigger::AsNWSTrigger()
{
    asm("leave");
    asm("mov $0x081f2d5c, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::CalculateNearestPoint(Vector, Vector *)
{
    asm("leave");
    asm("mov $0x081eeaa0, %eax");
    asm("jmp *%eax");
}

void CNWSTrigger::ComputeBoundingBox(float *, float *, float *, float *)
{
    asm("leave");
    asm("mov $0x081f2a80, %eax");
    asm("jmp *%eax");
}

void CNWSTrigger::CreateNewGeometry(float, Vector, CNWSArea *)
{
    asm("leave");
    asm("mov $0x081f1d18, %eax");
    asm("jmp *%eax");
}

void CNWSTrigger::CreateNewGeometry(float, CScriptLocation *, CNWSArea *)
{
    asm("leave");
    asm("mov $0x081f1f94, %eax");
    asm("jmp *%eax");
}

void CNWSTrigger::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081eedfc, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetActive()
{
    asm("leave");
    asm("mov $0x081f31f4, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetAutoRemoveKey()
{
    asm("leave");
    asm("mov $0x081f3068, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetBaseType()
{
    asm("leave");
    asm("mov $0x081f3140, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetCanFireTrapOnObject(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081f24d4, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetClosestPointWithinTrigger(Vector, Vector *)
{
    asm("leave");
    asm("mov $0x081ee868, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetCreator()
{
    asm("leave");
    asm("mov $0x081f3020, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetCreatureList()
{
    asm("leave");
    asm("mov $0x081f3204, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetCursor()
{
    asm("leave");
    asm("mov $0x081f3238, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetCustomScriptEventId()
{
    asm("leave");
    asm("mov $0x081f3214, %eax");
    asm("jmp *%eax");
}

CExoString CNWSTrigger::GetDescriptionOverride()
{
    asm("leave");
    asm("mov $0x081f2d74, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetDetectDC()
{
    asm("leave");
    asm("mov $0x081f3188, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetDetectable()
{
    asm("leave");
    asm("mov $0x081f30d4, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetDisarmDC()
{
    asm("leave");
    asm("mov $0x081f31ac, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetDisarmable()
{
    asm("leave");
    asm("mov $0x081f30f8, %eax");
    asm("jmp *%eax");
}

Vector CNWSTrigger::GetFacingPosition()
{
    asm("leave");
    asm("mov $0x081f2948, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetFactionId()
{
    asm("leave");
    asm("mov $0x081f30b0, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSTrigger::GetFirstName()
{
    asm("leave");
    asm("mov $0x081f3280, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetFlagged()
{
    asm("leave");
    asm("mov $0x081f311c, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetIsAreaTransition()
{
    asm("leave");
    asm("mov $0x081f2d64, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetIsTrap()
{
    asm("leave");
    asm("mov $0x081f308c, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetKeyName()
{
    asm("leave");
    asm("mov $0x081f2ffc, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetLastDisarmed()
{
    asm("leave");
    asm("mov $0x081f2eb8, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetLastEntered()
{
    asm("leave");
    asm("mov $0x081f2e70, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetLastLeft()
{
    asm("leave");
    asm("mov $0x081f2e94, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetLinkedFlags()
{
    asm("leave");
    asm("mov $0x081f3270, %eax");
    asm("jmp *%eax");
}

CExoString CNWSTrigger::GetLinkedTo()
{
    asm("leave");
    asm("mov $0x081f2fbc, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSTrigger::GetLoadScreenID()
{
    asm("leave");
    asm("mov $0x081f32a4, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetNumVertices()
{
    asm("leave");
    asm("mov $0x081f2f10, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetObjectArrayIndex()
{
    asm("leave");
    asm("mov $0x081f2edc, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetOneShot()
{
    asm("leave");
    asm("mov $0x081f3164, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetRecoverable()
{
    asm("leave");
    asm("mov $0x081f31d0, %eax");
    asm("jmp *%eax");
}

CExoString * CNWSTrigger::GetScriptName(int)
{
    asm("leave");
    asm("mov $0x081f2cdc, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSTrigger::GetTargetArea()
{
    asm("leave");
    asm("mov $0x081f29f8, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetTriggerHeight()
{
    asm("leave");
    asm("mov $0x081f3044, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::GetVertices()
{
    asm("leave");
    asm("mov $0x081f2f00, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::InTrigger(Vector)
{
    asm("leave");
    asm("mov $0x081ef0a0, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::LineSegmentIntersectTrigger(Vector, Vector)
{
    asm("leave");
    asm("mov $0x081f2c18, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::LoadFromTemplate(CResRef)
{
    asm("leave");
    asm("mov $0x081ef2a4, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::LoadTrigger(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081f0138, %eax");
    asm("jmp *%eax");
}

void CNWSTrigger::OnEnterTrap(int)
{
    asm("leave");
    asm("mov $0x081f25cc, %eax");
    asm("jmp *%eax");
}

void CNWSTrigger::RemoveFromArea()
{
    asm("leave");
    asm("mov $0x081f2418, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SaveTrigger(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081f1610, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetActive(int)
{
    asm("leave");
    asm("mov $0x081f31e0, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetAutoRemoveKey(int)
{
    asm("leave");
    asm("mov $0x081f3054, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetBaseType(unsigned char)
{
    asm("leave");
    asm("mov $0x081f312c, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetCreator(unsigned long)
{
    asm("leave");
    asm("mov $0x081f300c, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetCursor(unsigned char)
{
    asm("leave");
    asm("mov $0x081f3248, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetCustomScriptEventId(int)
{
    asm("leave");
    asm("mov $0x081f3224, %eax");
    asm("jmp *%eax");
}

void CNWSTrigger::SetDescriptionOverride(CExoString)
{
    asm("leave");
    asm("mov $0x081f2d9c, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetDetectDC(int)
{
    asm("leave");
    asm("mov $0x081f3174, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetDetectable(int)
{
    asm("leave");
    asm("mov $0x081f30c0, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetDisarmDC(int)
{
    asm("leave");
    asm("mov $0x081f3198, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetDisarmable(int)
{
    asm("leave");
    asm("mov $0x081f30e4, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetFactionId(int)
{
    asm("leave");
    asm("mov $0x081f309c, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetFirstName(unsigned long)
{
    asm("leave");
    asm("mov $0x081f3290, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetFlagged(int)
{
    asm("leave");
    asm("mov $0x081f3108, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetIsAreaTransition(int)
{
    asm("leave");
    asm("mov $0x081f2e5c, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetIsTrap(int)
{
    asm("leave");
    asm("mov $0x081f3078, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetKeyName(CExoString const &)
{
    asm("leave");
    asm("mov $0x081f2fe4, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetLastDisarmed(unsigned long)
{
    asm("leave");
    asm("mov $0x081f2ec8, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetLastEntered(unsigned long)
{
    asm("leave");
    asm("mov $0x081f2e80, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetLastLeft(unsigned long)
{
    asm("leave");
    asm("mov $0x081f2ea4, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetLinkedFlags(unsigned char)
{
    asm("leave");
    asm("mov $0x081f325c, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetLinkedTo(CExoString)
{
    asm("leave");
    asm("mov $0x081f2f20, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetObjectArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x081f2eec, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetOneShot(unsigned char)
{
    asm("leave");
    asm("mov $0x081f3150, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetRecoverable(int)
{
    asm("leave");
    asm("mov $0x081f31bc, %eax");
    asm("jmp *%eax");
}

void CNWSTrigger::SetScriptName(int, CExoString)
{
    asm("leave");
    asm("mov $0x081f2df4, %eax");
    asm("jmp *%eax");
}

int CNWSTrigger::SetTriggerHeight(float)
{
    asm("leave");
    asm("mov $0x081f3030, %eax");
    asm("jmp *%eax");
}

