#include "CScriptEvent.h"

void CScriptEvent::CopyScriptEvent(CScriptEvent *)
{
    asm("leave");
    asm("mov $0x08061164, %eax");
    asm("jmp *%eax");
}

float CScriptEvent::GetFloat(int)
{
    asm("leave");
    asm("mov $0x080619a4, %eax");
    asm("jmp *%eax");
}

int CScriptEvent::GetInteger(int)
{
    asm("leave");
    asm("mov $0x08061938, %eax");
    asm("jmp *%eax");
}

unsigned long CScriptEvent::GetObjectID(int)
{
    asm("leave");
    asm("mov $0x08061a10, %eax");
    asm("jmp *%eax");
}

CExoString CScriptEvent::GetString(int)
{
    asm("leave");
    asm("mov $0x08061a80, %eax");
    asm("jmp *%eax");
}

int CScriptEvent::LoadEvent(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0806147c, %eax");
    asm("jmp *%eax");
}

int CScriptEvent::SaveEvent(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080612a8, %eax");
    asm("jmp *%eax");
}

void CScriptEvent::SetFloat(int, float)
{
    asm("leave");
    asm("mov $0x080619d0, %eax");
    asm("jmp *%eax");
}

void CScriptEvent::SetInteger(int, int)
{
    asm("leave");
    asm("mov $0x08061964, %eax");
    asm("jmp *%eax");
}

void CScriptEvent::SetObjectID(int, unsigned long)
{
    asm("leave");
    asm("mov $0x08061a40, %eax");
    asm("jmp *%eax");
}

void CScriptEvent::SetString(int, CExoString)
{
    asm("leave");
    asm("mov $0x08061ac8, %eax");
    asm("jmp *%eax");
}

int CScriptEvent::operator==(CScriptEvent const &) const
{
    asm("leave");
    asm("mov $0x080617b0, %eax");
    asm("jmp *%eax");
}

int CScriptEvent::operator!=(CScriptEvent const &) const
{
    asm("leave");
    asm("mov $0x08061b4c, %eax");
    asm("jmp *%eax");
}

