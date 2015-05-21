#include "CNWSScriptVarTable.h"

int CNWSScriptVarTable::DeleteIndex(CExoString &, unsigned long)
{
    asm("leave");
    asm("mov $0x081f3f5c, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::DestroyFloat(CExoString &)
{
    asm("leave");
    asm("mov $0x081f4320, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::DestroyInt(CExoString &)
{
    asm("leave");
    asm("mov $0x081f362c, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::DestroyLocation(CExoString &)
{
    asm("leave");
    asm("mov $0x081f4458, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::DestroyObject(CExoString &)
{
    asm("leave");
    asm("mov $0x081f43f0, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::DestroyString(CExoString &)
{
    asm("leave");
    asm("mov $0x081f4388, %eax");
    asm("jmp *%eax");
}

float CNWSScriptVarTable::GetFloat(CExoString &)
{
    asm("leave");
    asm("mov $0x081f3ff0, %eax");
    asm("jmp *%eax");
}

int CNWSScriptVarTable::GetInt(CExoString &)
{
    asm("leave");
    asm("mov $0x081f3fc8, %eax");
    asm("jmp *%eax");
}

CScriptLocation CNWSScriptVarTable::GetLocation(CExoString &)
{
    asm("leave");
    asm("mov $0x081f40e8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSScriptVarTable::GetObject(CExoString &)
{
    asm("leave");
    asm("mov $0x081f40bc, %eax");
    asm("jmp *%eax");
}

CExoString CNWSScriptVarTable::GetString(CExoString &)
{
    asm("leave");
    asm("mov $0x081f4020, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::LoadVarTable(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081f3740, %eax");
    asm("jmp *%eax");
}

CNWSScriptVar * CNWSScriptVarTable::MatchIndex(CExoString &, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081f32b4, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::SaveVarTable(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081f3b3c, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::SetFloat(CExoString &, float)
{
    asm("leave");
    asm("mov $0x081f4190, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::SetInt(CExoString &, int, int)
{
    asm("leave");
    asm("mov $0x081f3454, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::SetLocation(CExoString &, CScriptLocation)
{
    asm("leave");
    asm("mov $0x081f4204, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::SetObject(CExoString &, unsigned long)
{
    asm("leave");
    asm("mov $0x081f41e0, %eax");
    asm("jmp *%eax");
}

void CNWSScriptVarTable::SetString(CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x081f41b4, %eax");
    asm("jmp *%eax");
}

