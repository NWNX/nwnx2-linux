#include "CServerAIBodyBagInfo.h"

int CServerAIBodyBagInfo::LoadBodyBag(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080985d8, %eax");
    asm("jmp *%eax");
}

int CServerAIBodyBagInfo::SaveBodyBag(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08098578, %eax");
    asm("jmp *%eax");
}

