#include "CBWCBlowFish.h"

void CBWCBlowFish::BlockToBytes(CBWCBlowFishBlock const &, unsigned char *)
{
    asm("leave");
    asm("mov $0x08308520, %eax");
    asm("jmp *%eax");
}

void CBWCBlowFish::BytesToBlock(unsigned char const *, CBWCBlowFishBlock &)
{
    asm("leave");
    asm("mov $0x083084d4, %eax");
    asm("jmp *%eax");
}

void CBWCBlowFish::DecryptBlock(CBWCBlowFishBlock &)
{
    asm("leave");
    asm("mov $0x08307c6c, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::Decrypt(unsigned char *, unsigned long, unsigned long &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08308164, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::Decrypt(unsigned char *, unsigned long, unsigned char *, unsigned long &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08308014, %eax");
    asm("jmp *%eax");
}

void CBWCBlowFish::EncryptBlock(CBWCBlowFishBlock &)
{
    asm("leave");
    asm("mov $0x08307b60, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::Encrypt(unsigned char *, unsigned long, unsigned long &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08307ec8, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::Encrypt(unsigned char *, unsigned long, unsigned char *, unsigned long &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08307d78, %eax");
    asm("jmp *%eax");
}

unsigned long CBWCBlowFish::F(unsigned long)
{
    asm("leave");
    asm("mov $0x083085d0, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::GetDecryptedSize(unsigned long, unsigned long &)
{
    asm("leave");
    asm("mov $0x083085a8, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::GetEncryptedSize(unsigned long, unsigned long &)
{
    asm("leave");
    asm("mov $0x08308584, %eax");
    asm("jmp *%eax");
}

unsigned char CBWCBlowFish::GetLowOrderByte(unsigned long)
{
    asm("leave");
    asm("mov $0x083085c8, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::GetStateSize(unsigned long &)
{
    asm("leave");
    asm("mov $0x0830849c, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::GetState(void *)
{
    asm("leave");
    asm("mov $0x083084b0, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::ResetChain()
{
    asm("leave");
    asm("mov $0x08308450, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::ResetKey()
{
    asm("leave");
    asm("mov $0x083083f4, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::SetKey(unsigned char *, unsigned long, unsigned char &)
{
    asm("leave");
    asm("mov $0x08307980, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFish::SetState(void *, unsigned long)
{
    asm("leave");
    asm("mov $0x0830846c, %eax");
    asm("jmp *%eax");
}

