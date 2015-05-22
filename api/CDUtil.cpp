#include "CDUtil.h"

int CDUtil::CalculateCRC(char *, int, char *, int, char *&, int)
{
    asm("leave");
    asm("mov $0x08299168, %eax");
    asm("jmp *%eax");
}

int CDUtil::CreateChallengeString(unsigned long)
{
    asm("leave");
    asm("mov $0x08293f04, %eax");
    asm("jmp *%eax");
}

int CDUtil::DecodeBase(char *, int)
{
    asm("leave");
    asm("mov $0x082992e8, %eax");
    asm("jmp *%eax");
}

int CDUtil::EncodeBase(unsigned long long, char *, int)
{
    asm("leave");
    asm("mov $0x0829925c, %eax");
    asm("jmp *%eax");
}

int CDUtil::GenerateResponse(CExoString const &, CExoString const &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x08293fc8, %eax");
    asm("jmp *%eax");
}

void CDUtil::InitializeBaseConvert()
{
    asm("leave");
    asm("mov $0x08299208, %eax");
    asm("jmp *%eax");
}

void CDUtil::InitializeCrc()
{
    asm("leave");
    asm("mov $0x0829912c, %eax");
    asm("jmp *%eax");
}

void CDUtil::Initialize()
{
    asm("leave");
    asm("mov $0x082940a0, %eax");
    asm("jmp *%eax");
}

int CDUtil::ScrambleKey(char *, char const *, char const *, char const *, int)
{
    asm("leave");
    asm("mov $0x08298ed8, %eax");
    asm("jmp *%eax");
}

void CDUtil::UnScrambleKey(char const *, char *, char *, char *)
{
    asm("leave");
    asm("mov $0x08298fa8, %eax");
    asm("jmp *%eax");
}

int CDUtil::ValidateKey(char *)
{
    asm("leave");
    asm("mov $0x08299074, %eax");
    asm("jmp *%eax");
}

