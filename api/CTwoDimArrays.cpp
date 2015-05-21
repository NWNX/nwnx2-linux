#include "CTwoDimArrays.h"

void CTwoDimArrays::ClearCached2DAs()
{
    asm("leave");
    asm("mov $0x080b98a4, %eax");
    asm("jmp *%eax");
}

C2DA * CTwoDimArrays::GetCached2DA(CExoString, int)
{
    asm("leave");
    asm("mov $0x080b92a8, %eax");
    asm("jmp *%eax");
}

unsigned char CTwoDimArrays::GetEpicAttackBonus(unsigned char)
{
    asm("leave");
    asm("mov $0x080b9a68, %eax");
    asm("jmp *%eax");
}

unsigned char CTwoDimArrays::GetEpicFortSaveBonus(unsigned char)
{
    asm("leave");
    asm("mov $0x080b9a04, %eax");
    asm("jmp *%eax");
}

unsigned char CTwoDimArrays::GetEpicRefSaveBonus(unsigned char)
{
    asm("leave");
    asm("mov $0x080b9a24, %eax");
    asm("jmp *%eax");
}

unsigned char CTwoDimArrays::GetEpicWillSaveBonus(unsigned char)
{
    asm("leave");
    asm("mov $0x080b9a48, %eax");
    asm("jmp *%eax");
}

C2DA * CTwoDimArrays::GetIPRPCostTable(unsigned char)
{
    asm("leave");
    asm("mov $0x080b99e0, %eax");
    asm("jmp *%eax");
}

int CTwoDimArrays::Load2DArrays()
{
    asm("leave");
    asm("mov $0x080b4cac, %eax");
    asm("jmp *%eax");
}

int CTwoDimArrays::LoadEpicAttacks()
{
    asm("leave");
    asm("mov $0x080b91a0, %eax");
    asm("jmp *%eax");
}

int CTwoDimArrays::LoadEpicSaves()
{
    asm("leave");
    asm("mov $0x080b8fe4, %eax");
    asm("jmp *%eax");
}

int CTwoDimArrays::LoadIPRPCostTables()
{
    asm("leave");
    asm("mov $0x080b8d14, %eax");
    asm("jmp *%eax");
}

int CTwoDimArrays::UnLoad2DArrays()
{
    asm("leave");
    asm("mov $0x080b7728, %eax");
    asm("jmp *%eax");
}

int CTwoDimArrays::UnLoadIPRPCostTables()
{
    asm("leave");
    asm("mov $0x080b9964, %eax");
    asm("jmp *%eax");
}

int CTwoDimArrays::Update2DACache(CExoLinkedList<C2DA> *, int, C2DA *)
{
    asm("leave");
    asm("mov $0x080b9a88, %eax");
    asm("jmp *%eax");
}

