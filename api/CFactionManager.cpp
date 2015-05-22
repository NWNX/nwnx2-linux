#include "CFactionManager.h"

void CFactionManager::CreateDefaultFactions()
{
    asm("leave");
    asm("mov $0x080ba230, %eax");
    asm("jmp *%eax");
}

void CFactionManager::DeleteFaction(int)
{
    asm("leave");
    asm("mov $0x080bab0c, %eax");
    asm("jmp *%eax");
}

CExoArrayList<int> * CFactionManager::GetDefaultPCReputation()
{
    asm("leave");
    asm("mov $0x080b9c68, %eax");
    asm("jmp *%eax");
}

int CFactionManager::GetFactionIdByName(CExoString const &)
{
    asm("leave");
    asm("mov $0x080ba3d8, %eax");
    asm("jmp *%eax");
}

CNWSFaction * CFactionManager::GetFaction(int)
{
    asm("leave");
    asm("mov $0x080ba9a0, %eax");
    asm("jmp *%eax");
}

int CFactionManager::GetIsNPCFaction(int)
{
    asm("leave");
    asm("mov $0x080baa40, %eax");
    asm("jmp *%eax");
}

int CFactionManager::GetNPCFactionReputation(int, int)
{
    asm("leave");
    asm("mov $0x080b9bc0, %eax");
    asm("jmp *%eax");
}

int CFactionManager::LoadFactions(CResGFF *, CResList *)
{
    asm("leave");
    asm("mov $0x080b9cfc, %eax");
    asm("jmp *%eax");
}

int CFactionManager::LoadReputations(CResGFF *, CResList *)
{
    asm("leave");
    asm("mov $0x080b9f68, %eax");
    asm("jmp *%eax");
}

int CFactionManager::SaveFactions(CResGFF *, CResList *)
{
    asm("leave");
    asm("mov $0x080ba130, %eax");
    asm("jmp *%eax");
}

int CFactionManager::SaveReputations(CResGFF *, CResList *)
{
    asm("leave");
    asm("mov $0x080baa60, %eax");
    asm("jmp *%eax");
}

void CFactionManager::SetNPCFactionReputation(int, int, int)
{
    asm("leave");
    asm("mov $0x080ba9d0, %eax");
    asm("jmp *%eax");
}

