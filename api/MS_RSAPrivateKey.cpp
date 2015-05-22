#include "MS_RSAPrivateKey.h"

int MS_RSAPrivateKey::create(MS_RSAVLong const &, MS_RSAVLong const &)
{
    asm("leave");
    asm("mov $0x08299c60, %eax");
    asm("jmp *%eax");
}

void MS_RSAPrivateKey::decryptDDCipher(unsigned char *, unsigned char const *)
{
    asm("leave");
    asm("mov $0x0829a19c, %eax");
    asm("jmp *%eax");
}

int MS_RSAPrivateKey::decryptHash(char *, unsigned char const *)
{
    asm("leave");
    asm("mov $0x08299fdc, %eax");
    asm("jmp *%eax");
}

MS_RSAVLong MS_RSAPrivateKey::decrypt(MS_RSAVLong const &)
{
    asm("leave");
    asm("mov $0x0829a330, %eax");
    asm("jmp *%eax");
}

