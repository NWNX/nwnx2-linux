#include "CExoEncrypt.h"

CExoString CExoEncrypt::EncryptString(CExoString const &)
{
    asm("leave");
    asm("mov $0x082c91d4, %eax");
    asm("jmp *%eax");
}

CExoString CExoEncrypt::GenerateChallenge(unsigned short)
{
    asm("leave");
    asm("mov $0x082c92b0, %eax");
    asm("jmp *%eax");
}

