#include "CResLTR.h"

int CResLTR::GetEndDoubleLetterProb()
{
    asm("leave");
    asm("mov $0x08271cf4, %eax");
    asm("jmp *%eax");
}

int CResLTR::GetEndSingleLetterProb()
{
    asm("leave");
    asm("mov $0x08271d18, %eax");
    asm("jmp *%eax");
}

int CResLTR::GetEndTripleLetterProb()
{
    asm("leave");
    asm("mov $0x08271cd0, %eax");
    asm("jmp *%eax");
}

int CResLTR::GetLTRHeaderPtr()
{
    asm("leave");
    asm("mov $0x08271cac, %eax");
    asm("jmp *%eax");
}

int CResLTR::GetMiddleDoubleLetterProb()
{
    asm("leave");
    asm("mov $0x08271ce8, %eax");
    asm("jmp *%eax");
}

int CResLTR::GetMiddleSingleLetterProb()
{
    asm("leave");
    asm("mov $0x08271d0c, %eax");
    asm("jmp *%eax");
}

int CResLTR::GetMiddleTripleLetterProb()
{
    asm("leave");
    asm("mov $0x08271cc4, %eax");
    asm("jmp *%eax");
}

int CResLTR::GetStartDoubleLetterProb()
{
    asm("leave");
    asm("mov $0x08271cdc, %eax");
    asm("jmp *%eax");
}

int CResLTR::GetStartSingleLetterProb()
{
    asm("leave");
    asm("mov $0x08271d00, %eax");
    asm("jmp *%eax");
}

int CResLTR::GetStartTripleLetterProb()
{
    asm("leave");
    asm("mov $0x08271cb8, %eax");
    asm("jmp *%eax");
}

int CResLTR::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x08271378, %eax");
    asm("jmp *%eax");
}

int CResLTR::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x08271648, %eax");
    asm("jmp *%eax");
}

