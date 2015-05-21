#include "CExoDebugInternal.h"

int CExoDebugInternal::Assert(int, char *, char const *)
{
    asm("leave");
    asm("mov $0x082cfbb8, %eax");
    asm("jmp *%eax");
}

void CExoDebugInternal::CloseLogFiles()
{
    asm("leave");
    asm("mov $0x082cfc44, %eax");
    asm("jmp *%eax");
}

int CExoDebugInternal::CreateDirectory(CExoString)
{
    asm("leave");
    asm("mov $0x082cf9cc, %eax");
    asm("jmp *%eax");
}

int CExoDebugInternal::FlushErrorFile()
{
    asm("leave");
    asm("mov $0x082cfc9c, %eax");
    asm("jmp *%eax");
}

void CExoDebugInternal::FlushLogFile()
{
    asm("leave");
    asm("mov $0x082cfcbc, %eax");
    asm("jmp *%eax");
}

void CExoDebugInternal::GetCurrentTimestamp(CExoString &)
{
    asm("leave");
    asm("mov $0x082cfd78, %eax");
    asm("jmp *%eax");
}

void CExoDebugInternal::OpenLogFiles(CExoString, int)
{
    asm("leave");
    asm("mov $0x082ceccc, %eax");
    asm("jmp *%eax");
}

int CExoDebugInternal::Warning(int, char *, char const *)
{
    asm("leave");
    asm("mov $0x082cfcdc, %eax");
    asm("jmp *%eax");
}

int CExoDebugInternal::WriteToErrorFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082cf4cc, %eax");
    asm("jmp *%eax");
}

void CExoDebugInternal::WriteToLogFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082cf764, %eax");
    asm("jmp *%eax");
}

