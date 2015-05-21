#include "CRes.h"

int CRes::CancelRequest()
{
    asm("leave");
    asm("mov $0x082b36d4, %eax");
    asm("jmp *%eax");
}

void * CRes::Demand()
{
    asm("leave");
    asm("mov $0x082b36f0, %eax");
    asm("jmp *%eax");
}

void CRes::Dump(int)
{
    asm("leave");
    asm("mov $0x082b372c, %eax");
    asm("jmp *%eax");
}

void * CRes::GetData()
{
    asm("leave");
    asm("mov $0x082b3748, %eax");
    asm("jmp *%eax");
}

int CRes::GetDemands()
{
    asm("leave");
    asm("mov $0x082b3754, %eax");
    asm("jmp *%eax");
}

int CRes::GetFixedResourceDataOffset()
{
    asm("leave");
    asm("mov $0x082b3fe8, %eax");
    asm("jmp *%eax");
}

int CRes::GetFixedResourceSize()
{
    asm("leave");
    asm("mov $0x082b3fdc, %eax");
    asm("jmp *%eax");
}

int CRes::GetID()
{
    asm("leave");
    asm("mov $0x082b376c, %eax");
    asm("jmp *%eax");
}

int CRes::GetRequests()
{
    asm("leave");
    asm("mov $0x082b3760, %eax");
    asm("jmp *%eax");
}

int CRes::GetSize()
{
    asm("leave");
    asm("mov $0x082b3778, %eax");
    asm("jmp *%eax");
}

int CRes::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x082b3ff0, %eax");
    asm("jmp *%eax");
}

int CRes::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x082b3ffc, %eax");
    asm("jmp *%eax");
}

int CRes::ReadRaw(int, char *)
{
    asm("leave");
    asm("mov $0x082b370c, %eax");
    asm("jmp *%eax");
}

int CRes::Release()
{
    asm("leave");
    asm("mov $0x082b3784, %eax");
    asm("jmp *%eax");
}

int CRes::Request()
{
    asm("leave");
    asm("mov $0x082b37a0, %eax");
    asm("jmp *%eax");
}

int CRes::SetID(unsigned long)
{
    asm("leave");
    asm("mov $0x082b37bc, %eax");
    asm("jmp *%eax");
}

int CRes::SetPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082b4008, %eax");
    asm("jmp *%eax");
}

