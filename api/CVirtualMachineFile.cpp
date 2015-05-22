#include "CVirtualMachineFile.h"

int CVirtualMachineFile::GetData(char **, unsigned long &)
{
    asm("leave");
    asm("mov $0x082640a4, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineFile::LoadFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x08264028, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineFile::UnloadFile()
{
    asm("leave");
    asm("mov $0x08264068, %eax");
    asm("jmp *%eax");
}

