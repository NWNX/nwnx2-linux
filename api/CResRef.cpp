#include "CResRef.h"

void CResRef::CopyToString(char *) const
{
    asm("leave");
    asm("mov $0x082b3338, %eax");
    asm("jmp *%eax");
}

void CResRef::CopyToString(CExoString &) const
{
    asm("leave");
    asm("mov $0x082b3304, %eax");
    asm("jmp *%eax");
}

unsigned char CResRef::GetLength() const
{
    asm("leave");
    asm("mov $0x082b3398, %eax");
    asm("jmp *%eax");
}

char * CResRef::GetResRefStr() const
{
    asm("leave");
    asm("mov $0x082b3360, %eax");
    asm("jmp *%eax");
}

char * CResRef::GetResRef() const
{
    asm("leave");
    asm("mov $0x082b3358, %eax");
    asm("jmp *%eax");
}

int CResRef::GetResRef(unsigned char *) const
{
    asm("leave");
    asm("mov $0x082b35b0, %eax");
    asm("jmp *%eax");
}

int CResRef::IsValid() const
{
    asm("leave");
    asm("mov $0x082b3388, %eax");
    asm("jmp *%eax");
}

int CResRef::operator+=(CExoString const &)
{
    asm("leave");
    asm("mov $0x082aeb2c, %eax");
    asm("jmp *%eax");
}

int CResRef::operator=(unsigned char *)
{
    asm("leave");
    asm("mov $0x082b34c8, %eax");
    asm("jmp *%eax");
}

CResRef CResRef::operator=(char *)
{
    asm("leave");
    asm("mov $0x082b3544, %eax");
    asm("jmp *%eax");
}

CResRef CResRef::operator=(CExoString const &)
{
    asm("leave");
    asm("mov $0x082aea8c, %eax");
    asm("jmp *%eax");
}

CResRef CResRef::operator=(CResRef const &)
{
    asm("leave");
    asm("mov $0x082b347c, %eax");
    asm("jmp *%eax");
}

int CResRef::operator==(char *) const
{
    asm("leave");
    asm("mov $0x082aea24, %eax");
    asm("jmp *%eax");
}

int CResRef::operator==(CExoString const &) const
{
    asm("leave");
    asm("mov $0x082b3418, %eax");
    asm("jmp *%eax");
}

int CResRef::operator==(CResRef const &) const
{
    asm("leave");
    asm("mov $0x082b33f4, %eax");
    asm("jmp *%eax");
}

int CResRef::operator!=(char *) const
{
    asm("leave");
    asm("mov $0x082ae9c0, %eax");
    asm("jmp *%eax");
}

int CResRef::operator!=(CExoString const &) const
{
    asm("leave");
    asm("mov $0x082b33d4, %eax");
    asm("jmp *%eax");
}

int CResRef::operator!=(CResRef const &) const
{
    asm("leave");
    asm("mov $0x082b33b4, %eax");
    asm("jmp *%eax");
}

int CResRef::operator!()
{
    asm("leave");
    asm("mov $0x082b346c, %eax");
    asm("jmp *%eax");
}

