#include "CNWSPlayerTURD.h"

void CNWSPlayerTURD::AIUpdate()
{
    asm("leave");
    asm("mov $0x08060914, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerTURD::AddToArea(CNWSArea *, int)
{
    asm("leave");
    asm("mov $0x08060924, %eax");
    asm("jmp *%eax");
}

CNWSPlayerTURD * CNWSPlayerTURD::AsNWSPlayerTURD()
{
    asm("leave");
    asm("mov $0x08060ce4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::ClearAutomapData()
{
    asm("leave");
    asm("mov $0x08060a60, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::CopyAutomapData(int, CExoArrayList<unsigned long> *, unsigned char **)
{
    asm("leave");
    asm("mov $0x080605e4, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerTURD::CopyEffectList(CExoArrayList<CGameEffect *> *)
{
    asm("leave");
    asm("mov $0x080609d4, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerTURD::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0806091c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::GetAutoMapAreasList()
{
    asm("leave");
    asm("mov $0x08060e18, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::GetAutoMapTileData()
{
    asm("leave");
    asm("mov $0x08060e28, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::GetCalendarDay()
{
    asm("leave");
    asm("mov $0x08060da0, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::GetCalendarTimeOfDay()
{
    asm("leave");
    asm("mov $0x08060dc4, %eax");
    asm("jmp *%eax");
}

CExoString CNWSPlayerTURD::GetCommunityName()
{
    asm("leave");
    asm("mov $0x08060cec, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSPlayerTURD::GetFirstName()
{
    asm("leave");
    asm("mov $0x08060d2c, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSPlayerTURD::GetLastName()
{
    asm("leave");
    asm("mov $0x08060d54, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::GetNumAutoMapAreas()
{
    asm("leave");
    asm("mov $0x08060e08, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::GetPersonalReputation()
{
    asm("leave");
    asm("mov $0x08060df8, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::GetPlayerID()
{
    asm("leave");
    asm("mov $0x08060d7c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::GetReputation()
{
    asm("leave");
    asm("mov $0x08060de8, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerTURD::LoadAutoMapData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080606f8, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::LoadTURD(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0805f858, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerTURD::RemoveFromArea()
{
    asm("leave");
    asm("mov $0x08060990, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::SaveAutoMapData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08060af8, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerTURD::SaveTURD(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0805ff5c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::SetCalendarDay(unsigned long)
{
    asm("leave");
    asm("mov $0x08060db0, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::SetCalendarTimeOfDay(unsigned long)
{
    asm("leave");
    asm("mov $0x08060dd4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::SetCommunityName(CExoString const &)
{
    asm("leave");
    asm("mov $0x08060d14, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::SetFirstName(CExoLocString const &)
{
    asm("leave");
    asm("mov $0x08060d3c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::SetLastName(CExoLocString const &)
{
    asm("leave");
    asm("mov $0x08060d64, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerTURD::SetPersonalReputation(CExoArrayList<CNWSPersonalReputation> *)
{
    asm("leave");
    asm("mov $0x080604f0, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerTURD::SetPlayerID(unsigned long)
{
    asm("leave");
    asm("mov $0x08060d8c, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerTURD::SetReputation(CExoArrayList<int> *)
{
    asm("leave");
    asm("mov $0x08060430, %eax");
    asm("jmp *%eax");
}

