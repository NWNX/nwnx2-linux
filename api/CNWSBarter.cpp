#include "CNWSBarter.h"

int CNWSBarter::AddItem(unsigned long, unsigned char &, unsigned char &)
{
    asm("leave");
    asm("mov $0x080df07c, %eax");
    asm("jmp *%eax");
}

void CNWSBarter::CleanUp()
{
    asm("leave");
    asm("mov $0x080dee24, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSBarter::GetState()
{
    asm("leave");
    asm("mov $0x080dfe18, %eax");
    asm("jmp *%eax");
}

int CNWSBarter::MoveItem(unsigned long, unsigned char &, unsigned char &)
{
    asm("leave");
    asm("mov $0x080df3b4, %eax");
    asm("jmp *%eax");
}

int CNWSBarter::PullItemOut(unsigned long)
{
    asm("leave");
    asm("mov $0x080df4a0, %eax");
    asm("jmp *%eax");
}

int CNWSBarter::RemoveItem(unsigned long, unsigned char &, unsigned char &)
{
    asm("leave");
    asm("mov $0x080df254, %eax");
    asm("jmp *%eax");
}

void CNWSBarter::Reset(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080dff24, %eax");
    asm("jmp *%eax");
}

int CNWSBarter::SetListAccepted(int)
{
    asm("leave");
    asm("mov $0x080df6ac, %eax");
    asm("jmp *%eax");
}

int CNWSBarter::SetListLocked(int)
{
    asm("leave");
    asm("mov $0x080df568, %eax");
    asm("jmp *%eax");
}

