#include "CNWSEncounter.h"

void CNWSEncounter::AIUpdate()
{
    asm("leave");
    asm("mov $0x0817fc8c, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::AddCreaturesToSpawnList(CEncounterListEntry *, int &, int, CEncounterListEntry)
{
    asm("leave");
    asm("mov $0x08181330, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::AddToActivateAreaList(unsigned long)
{
    asm("leave");
    asm("mov $0x08181590, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::AddToArea(CNWSArea *, float, float, float, int)
{
    asm("leave");
    asm("mov $0x08183fac, %eax");
    asm("jmp *%eax");
}

CNWSEncounter * CNWSEncounter::AsNWSEncounter()
{
    asm("leave");
    asm("mov $0x08184360, %eax");
    asm("jmp *%eax");
}

float CNWSEncounter::CalculatePointsFromCR(float)
{
    asm("leave");
    asm("mov $0x08183724, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::CalculateSpawnPool(float)
{
    asm("leave");
    asm("mov $0x08183604, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0817fef0, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetActivateObjectArrayIndex()
{
    asm("leave");
    asm("mov $0x08184570, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetActive()
{
    asm("leave");
    asm("mov $0x081843b8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetCustomScriptEventId()
{
    asm("leave");
    asm("mov $0x08184594, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetDifficultyIndex()
{
    asm("leave");
    asm("mov $0x08184438, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetDifficulty()
{
    asm("leave");
    asm("mov $0x08184428, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetEncounterCanReset()
{
    asm("leave");
    asm("mov $0x081843c8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetEncounterExhausted()
{
    asm("leave");
    asm("mov $0x08184488, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetEncounterStarted()
{
    asm("leave");
    asm("mov $0x08184478, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetFactionId()
{
    asm("leave");
    asm("mov $0x08184368, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSEncounter::GetFirstName()
{
    asm("leave");
    asm("mov $0x081845b8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetInActivateAreaList(unsigned long)
{
    asm("leave");
    asm("mov $0x08184178, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetInActivateArea(Vector)
{
    asm("leave");
    asm("mov $0x08180088, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetLastEntered()
{
    asm("leave");
    asm("mov $0x08184378, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetLastLeft()
{
    asm("leave");
    asm("mov $0x08184388, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetMaxActivateX()
{
    asm("leave");
    asm("mov $0x081843f8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetMaxActivateY()
{
    asm("leave");
    asm("mov $0x08184418, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetMinActivateX()
{
    asm("leave");
    asm("mov $0x081843e8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetMinActivateY()
{
    asm("leave");
    asm("mov $0x08184408, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetNewEntry()
{
    asm("leave");
    asm("mov $0x08184498, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetPlayerTriggeredOnly()
{
    asm("leave");
    asm("mov $0x081843d8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetPosition()
{
    asm("leave");
    asm("mov $0x08184398, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetRespawnsCurrent()
{
    asm("leave");
    asm("mov $0x08184458, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetRespawnsMax()
{
    asm("leave");
    asm("mov $0x08184448, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetScriptName(int)
{
    asm("leave");
    asm("mov $0x081845c8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::GetSpawnMode()
{
    asm("leave");
    asm("mov $0x08184468, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::LineSegmentIntersectActivateArea(Vector, Vector)
{
    asm("leave");
    asm("mov $0x081840ac, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::LoadEncounter(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081817e8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::LoadFractionalCRData()
{
    asm("leave");
    asm("mov $0x08183914, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::LoadFromTemplate(CResRef, int, Vector *)
{
    asm("leave");
    asm("mov $0x08181a08, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::MakeSpawnList(CEncounterListEntry *, int &)
{
    asm("leave");
    asm("mov $0x08180ef0, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::PadOutCreatureCount(CEncounterListEntry *, int &)
{
    asm("leave");
    asm("mov $0x081839f4, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::ReadEncounterFromGff(CResGFF *, CResStruct *, int, Vector *)
{
    asm("leave");
    asm("mov $0x08181bdc, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::ReadEncounterScriptsFromGff(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08182bc8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::RemoveFromActivateAreaList(unsigned long)
{
    asm("leave");
    asm("mov $0x081841ac, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::RemoveFromActiveCreatureCount(float, int)
{
    asm("leave");
    asm("mov $0x08181668, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::RemoveFromArea()
{
    asm("leave");
    asm("mov $0x0818402c, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SaveEncounter(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08182e68, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetActivateObjectArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x08184580, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::SetActive(int)
{
    asm("leave");
    asm("mov $0x08184278, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetCustomScriptEventId(int)
{
    asm("leave");
    asm("mov $0x081845a4, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::SetDifficulty(int)
{
    asm("leave");
    asm("mov $0x08183864, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetEncounterCanReset(int)
{
    asm("leave");
    asm("mov $0x081844d0, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetEncounterExhausted(int)
{
    asm("leave");
    asm("mov $0x08184548, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetEncounterStarted(int)
{
    asm("leave");
    asm("mov $0x08184534, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetLastEntered(unsigned long)
{
    asm("leave");
    asm("mov $0x081844a8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetLastLeft(unsigned long)
{
    asm("leave");
    asm("mov $0x081844bc, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetNewEntry(int)
{
    asm("leave");
    asm("mov $0x0818455c, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetPlayerTriggeredOnly(int)
{
    asm("leave");
    asm("mov $0x0818450c, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetRespawnsCurrent(int)
{
    asm("leave");
    asm("mov $0x081844f8, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetRespawnsMax(int)
{
    asm("leave");
    asm("mov $0x081844e4, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::SetScriptName(int, CExoString)
{
    asm("leave");
    asm("mov $0x081845e4, %eax");
    asm("jmp *%eax");
}

int CNWSEncounter::SetSpawnMode(int)
{
    asm("leave");
    asm("mov $0x08184520, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::SpawnEncounterCreatures()
{
    asm("leave");
    asm("mov $0x08180510, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::SpawnIfAppropriate(unsigned long, float)
{
    asm("leave");
    asm("mov $0x081841fc, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::TallyEnemyRadiusPoints()
{
    asm("leave");
    asm("mov $0x08183c00, %eax");
    asm("jmp *%eax");
}

void CNWSEncounter::UpdateActivateAreaList(unsigned long)
{
    asm("leave");
    asm("mov $0x0818028c, %eax");
    asm("jmp *%eax");
}

