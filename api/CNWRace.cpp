#include "CNWRace.h"

int CNWRace::GetConverNameLowerText()
{
    asm("leave");
    asm("mov $0x080c4970, %eax");
    asm("jmp *%eax");
}

int CNWRace::GetConverNameText()
{
    asm("leave");
    asm("mov $0x080c48bc, %eax");
    asm("jmp *%eax");
}

int CNWRace::GetDefaultBiographyText()
{
    asm("leave");
    asm("mov $0x080c4758, %eax");
    asm("jmp *%eax");
}

int CNWRace::GetDescriptionText()
{
    asm("leave");
    asm("mov $0x080c46a4, %eax");
    asm("jmp *%eax");
}

int CNWRace::GetNamePluralText()
{
    asm("leave");
    asm("mov $0x080c4a24, %eax");
    asm("jmp *%eax");
}

int CNWRace::GetNameText()
{
    asm("leave");
    asm("mov $0x080c480c, %eax");
    asm("jmp *%eax");
}

int CNWRace::IsFirstLevelGrantedFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x080c4e44, %eax");
    asm("jmp *%eax");
}

void CNWRace::LoadFeatsTable(CExoString)
{
    asm("leave");
    asm("mov $0x080c4ad8, %eax");
    asm("jmp *%eax");
}

