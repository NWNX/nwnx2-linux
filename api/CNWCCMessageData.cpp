#include "CNWCCMessageData.h"

int CNWCCMessageData::ClearData()
{
    asm("leave");
    asm("mov $0x080c31fc, %eax");
    asm("jmp *%eax");
}

void CNWCCMessageData::CopyTo(CNWCCMessageData *)
{
    asm("leave");
    asm("mov $0x080c212c, %eax");
    asm("jmp *%eax");
}

int CNWCCMessageData::GetFloat(int)
{
    asm("leave");
    asm("mov $0x080c3054, %eax");
    asm("jmp *%eax");
}

int CNWCCMessageData::GetInteger(int)
{
    asm("leave");
    asm("mov $0x080c2fe8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWCCMessageData::GetObjectID(int)
{
    asm("leave");
    asm("mov $0x080c30c0, %eax");
    asm("jmp *%eax");
}

CExoString CNWCCMessageData::GetString(int)
{
    asm("leave");
    asm("mov $0x080c3130, %eax");
    asm("jmp *%eax");
}

int CNWCCMessageData::LoadData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080c1dd8, %eax");
    asm("jmp *%eax");
}

int CNWCCMessageData::SaveData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080c1c14, %eax");
    asm("jmp *%eax");
}

int CNWCCMessageData::SetFloat(int, float)
{
    asm("leave");
    asm("mov $0x080c3080, %eax");
    asm("jmp *%eax");
}

void CNWCCMessageData::SetInteger(int, int)
{
    asm("leave");
    asm("mov $0x080c3014, %eax");
    asm("jmp *%eax");
}

void CNWCCMessageData::SetObjectID(int, unsigned long)
{
    asm("leave");
    asm("mov $0x080c30f0, %eax");
    asm("jmp *%eax");
}

void CNWCCMessageData::SetString(int, CExoString)
{
    asm("leave");
    asm("mov $0x080c3178, %eax");
    asm("jmp *%eax");
}

