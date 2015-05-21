#include "CBWCMD5.h"

int CBWCMD5::Decrypt(unsigned char *, unsigned long, unsigned long &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08309030, %eax");
    asm("jmp *%eax");
}

int CBWCMD5::Decrypt(unsigned char *, unsigned long, unsigned char *, unsigned long &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08309028, %eax");
    asm("jmp *%eax");
}

void CBWCMD5::EncryptBlock(unsigned long const *)
{
    asm("leave");
    asm("mov $0x083086b8, %eax");
    asm("jmp *%eax");
}

void CBWCMD5::EncryptFinalBlock(unsigned long const *, unsigned long)
{
    asm("leave");
    asm("mov $0x08308f80, %eax");
    asm("jmp *%eax");
}

int CBWCMD5::Encrypt(unsigned char *, unsigned long, unsigned long &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08309020, %eax");
    asm("jmp *%eax");
}

int CBWCMD5::Encrypt(unsigned char *, unsigned long, unsigned char *, unsigned long &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08308d64, %eax");
    asm("jmp *%eax");
}

unsigned long CBWCMD5::F(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08309090, %eax");
    asm("jmp *%eax");
}

unsigned long CBWCMD5::G(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x083090a4, %eax");
    asm("jmp *%eax");
}

int CBWCMD5::GetDecryptedSize(unsigned long, unsigned long &)
{
    asm("leave");
    asm("mov $0x0830904c, %eax");
    asm("jmp *%eax");
}

int CBWCMD5::GetEncryptedSize(unsigned long, unsigned long &)
{
    asm("leave");
    asm("mov $0x08309038, %eax");
    asm("jmp *%eax");
}

int CBWCMD5::GetStateSize(unsigned long &)
{
    asm("leave");
    asm("mov $0x08308f54, %eax");
    asm("jmp *%eax");
}

int CBWCMD5::GetState(void *)
{
    asm("leave");
    asm("mov $0x08308f68, %eax");
    asm("jmp *%eax");
}

unsigned long CBWCMD5::H(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x083090b8, %eax");
    asm("jmp *%eax");
}

unsigned long CBWCMD5::I(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x083090c8, %eax");
    asm("jmp *%eax");
}

void CBWCMD5::Reset()
{
    asm("leave");
    asm("mov $0x08308ef0, %eax");
    asm("jmp *%eax");
}

int CBWCMD5::SetKey(unsigned char *, unsigned long, unsigned char &)
{
    asm("leave");
    asm("mov $0x08308f14, %eax");
    asm("jmp *%eax");
}

int CBWCMD5::SetState(void *, unsigned long)
{
    asm("leave");
    asm("mov $0x08308f30, %eax");
    asm("jmp *%eax");
}

