#include "CExoBase.h"

int CExoBase::CheckForCD(unsigned long)
{
    asm("leave");
    asm("mov $0x082c8e9c, %eax");
    asm("jmp *%eax");
}

int CExoBase::GetAugmentedDirectoryList(CExoArrayList<CFileInfo> *, CExoString, unsigned short, int)
{
    asm("leave");
    asm("mov $0x082c8d5c, %eax");
    asm("jmp *%eax");
}

int CExoBase::GetDirectoryList(CExoArrayList<CExoString> *, CExoString, unsigned short, int, int)
{
    asm("leave");
    asm("mov $0x082c8ce0, %eax");
    asm("jmp *%eax");
}

unsigned short CExoBase::GetResTypeFromExtension(CExoString const &)
{
    asm("leave");
    asm("mov $0x082c8df0, %eax");
    asm("jmp *%eax");
}

CExoString const & CExoBase::GetResourceExtension(unsigned short)
{
    asm("leave");
    asm("mov $0x082c8dd4, %eax");
    asm("jmp *%eax");
}

void CExoBase::LoadAliases(CExoString)
{
    asm("leave");
    asm("mov $0x082c8e08, %eax");
    asm("jmp *%eax");
}

int CExoBase::ShutDown()
{
    asm("leave");
    asm("mov $0x082c8e6c, %eax");
    asm("jmp *%eax");
}

int CExoBase::SpawnExternalApplication(CExoString const &, CExoString const &, int)
{
    asm("leave");
    asm("mov $0x082c8e84, %eax");
    asm("jmp *%eax");
}

