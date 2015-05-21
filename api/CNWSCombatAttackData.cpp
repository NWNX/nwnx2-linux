#include "CNWSCombatAttackData.h"

void CNWSCombatAttackData::AddDamage(unsigned short, int)
{
    asm("leave");
    asm("mov $0x080e4c74, %eax");
    asm("jmp *%eax");
}

void CNWSCombatAttackData::ClearAttackData()
{
    asm("leave");
    asm("mov $0x080e0314, %eax");
    asm("jmp *%eax");
}

void CNWSCombatAttackData::Copy(CNWSCombatAttackData *, int)
{
    asm("leave");
    asm("mov $0x080e0430, %eax");
    asm("jmp *%eax");
}

int CNWSCombatAttackData::GetDamage(unsigned short)
{
    asm("leave");
    asm("mov $0x080e0544, %eax");
    asm("jmp *%eax");
}

int CNWSCombatAttackData::GetTotalDamage(int)
{
    asm("leave");
    asm("mov $0x080e4cec, %eax");
    asm("jmp *%eax");
}

int CNWSCombatAttackData::LoadData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080e08f4, %eax");
    asm("jmp *%eax");
}

int CNWSCombatAttackData::SaveData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080e0610, %eax");
    asm("jmp *%eax");
}

void CNWSCombatAttackData::SetBaseDamage(int)
{
    asm("leave");
    asm("mov $0x080e4c2c, %eax");
    asm("jmp *%eax");
}

int CNWSCombatAttackData::SetDamage(unsigned short, int)
{
    asm("leave");
    asm("mov $0x080e4c3c, %eax");
    asm("jmp *%eax");
}

