#include "CExoDebug.h"

int CExoDebug::Assert(int, char *, char const *)
{
    asm("leave");
    asm("mov $0x082c904c, %eax");
    asm("jmp *%eax");
}

int CExoDebug::CloseLogFiles()
{
    asm("leave");
    asm("mov $0x082c9084, %eax");
    asm("jmp *%eax");
}

void CExoDebug::FlushErrorFile()
{
    asm("leave");
    asm("mov $0x082c90a4, %eax");
    asm("jmp *%eax");
}

void CExoDebug::FlushLogFile()
{
    asm("leave");
    asm("mov $0x082c90ac, %eax");
    asm("jmp *%eax");
}

int CExoDebug::GetCurrentAllocatedMemory()
{
    asm("leave");
    asm("mov $0x082c90cc, %eax");
    asm("jmp *%eax");
}

int CExoDebug::GetCurrentMemoryAllocations()
{
    asm("leave");
    asm("mov $0x082c90e4, %eax");
    asm("jmp *%eax");
}

void CExoDebug::GetCurrentTimestamp(CExoString &)
{
    asm("leave");
    asm("mov $0x082c9198, %eax");
    asm("jmp *%eax");
}

int CExoDebug::GetMaxAllocatedMemory()
{
    asm("leave");
    asm("mov $0x082c90d4, %eax");
    asm("jmp *%eax");
}

int CExoDebug::GetTotalMemoryAllocations()
{
    asm("leave");
    asm("mov $0x082c90dc, %eax");
    asm("jmp *%eax");
}

void CExoDebug::OpenLogFiles(CExoString, int)
{
    asm("leave");
    asm("mov $0x082c90ec, %eax");
    asm("jmp *%eax");
}

void CExoDebug::SetRotateLogFile(int)
{
    asm("leave");
    asm("mov $0x082c91bc, %eax");
    asm("jmp *%eax");
}

void CExoDebug::Warning(int, char *, char const *)
{
    asm("leave");
    asm("mov $0x082c9164, %eax");
    asm("jmp *%eax");
}

void CExoDebug::WriteToErrorFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082c916c, %eax");
    asm("jmp *%eax");
}

void CExoDebug::WriteToLogFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082c9174, %eax");
    asm("jmp *%eax");
}

