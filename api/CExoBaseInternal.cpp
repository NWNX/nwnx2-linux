#include "CExoBaseInternal.h"

void CExoBaseInternal::AddAlias(CExoString, CExoString, CExoString)
{
    asm("leave");
    asm("mov $0x082cd1b0, %eax");
    asm("jmp *%eax");
}

int CExoBaseInternal::CheckForCD(unsigned long)
{
    asm("leave");
    asm("mov $0x082ce988, %eax");
    asm("jmp *%eax");
}

void CExoBaseInternal::CreateResourceExtensionTable()
{
    asm("leave");
    asm("mov $0x082cc7bc, %eax");
    asm("jmp *%eax");
}

int CExoBaseInternal::GetAugmentedDirectoryList(CExoArrayList<CFileInfo> *, CExoString, unsigned short, int)
{
    asm("leave");
    asm("mov $0x082cd8e8, %eax");
    asm("jmp *%eax");
}

int CExoBaseInternal::GetDirectoryList(CExoArrayList<CExoString> *, CExoString, unsigned short, int, int)
{
    asm("leave");
    asm("mov $0x082cd33c, %eax");
    asm("jmp *%eax");
}

unsigned short CExoBaseInternal::GetResTypeFromExtension(CExoString const &)
{
    asm("leave");
    asm("mov $0x082ce890, %eax");
    asm("jmp *%eax");
}

CExoString const & CExoBaseInternal::GetResourceExtension(unsigned short)
{
    asm("leave");
    asm("mov $0x082ce854, %eax");
    asm("jmp *%eax");
}

void CExoBaseInternal::LoadAliases(CExoString)
{
    asm("leave");
    asm("mov $0x082cde74, %eax");
    asm("jmp *%eax");
}

int CExoBaseInternal::ShutDown()
{
    asm("leave");
    asm("mov $0x082ce8e0, %eax");
    asm("jmp *%eax");
}

int CExoBaseInternal::SpawnExternalApplication(CExoString const &, CExoString const &, int)
{
    asm("leave");
    asm("mov $0x082ce8e8, %eax");
    asm("jmp *%eax");
}

