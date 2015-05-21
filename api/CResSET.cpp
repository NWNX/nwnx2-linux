#include "CResSET.h"

int CResSET::CopySETData(unsigned char *)
{
    asm("leave");
    asm("mov $0x080956d0, %eax");
    asm("jmp *%eax");
}

int CResSET::CreateSectionTable()
{
    asm("leave");
    asm("mov $0x08094fe8, %eax");
    asm("jmp *%eax");
}

int CResSET::GetNextLine(unsigned long, unsigned long *)
{
    asm("leave");
    asm("mov $0x080958dc, %eax");
    asm("jmp *%eax");
}

int CResSET::GetSETDataPtr()
{
    asm("leave");
    asm("mov $0x08095700, %eax");
    asm("jmp *%eax");
}

int CResSET::GetSETSize()
{
    asm("leave");
    asm("mov $0x0809570c, %eax");
    asm("jmp *%eax");
}

void CResSET::GetSectionEntryValue(char *, char *, char *)
{
    asm("leave");
    asm("mov $0x080957f4, %eax");
    asm("jmp *%eax");
}

int CResSET::IsLoaded()
{
    asm("leave");
    asm("mov $0x08095718, %eax");
    asm("jmp *%eax");
}

int CResSET::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x08094ee0, %eax");
    asm("jmp *%eax");
}

int CResSET::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x08095724, %eax");
    asm("jmp *%eax");
}

int CResSET::SkipWhiteSpace(char *)
{
    asm("leave");
    asm("mov $0x08095930, %eax");
    asm("jmp *%eax");
}

