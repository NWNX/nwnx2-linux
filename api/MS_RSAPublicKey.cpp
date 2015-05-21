#include "MS_RSAPublicKey.h"

int MS_RSAPublicKey::encryptDDCipher(unsigned char *, unsigned char const *)
{
    asm("leave");
    asm("mov $0x0829b084, %eax");
    asm("jmp *%eax");
}

int MS_RSAPublicKey::encryptHash(unsigned char *, char const *)
{
    asm("leave");
    asm("mov $0x0829ac04, %eax");
    asm("jmp *%eax");
}

int MS_RSAPublicKey::encrypt(MS_RSAVLong const &)
{
    asm("leave");
    asm("mov $0x0829b3d8, %eax");
    asm("jmp *%eax");
}

int MS_RSAPublicKey::exportPublicKey(unsigned char *)
{
    asm("leave");
    asm("mov $0x0829a9e4, %eax");
    asm("jmp *%eax");
}

int MS_RSAPublicKey::importPublicKey(unsigned char *)
{
    asm("leave");
    asm("mov $0x0829aaf8, %eax");
    asm("jmp *%eax");
}

