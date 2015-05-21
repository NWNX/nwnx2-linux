#include "CCodeBaseInternal.h"

int CCodeBaseInternal::AddBinaryData(CExoString &, CExoString &, CExoString &, char, void *, int)
{
    asm("leave");
    asm("mov $0x082db040, %eax");
    asm("jmp *%eax");
}

int CCodeBaseInternal::AddFloat(CExoString &, CExoString &, CExoString &, float)
{
    asm("leave");
    asm("mov $0x082dae40, %eax");
    asm("jmp *%eax");
}

int CCodeBaseInternal::AddInt(CExoString &, CExoString &, CExoString &, int)
{
    asm("leave");
    asm("mov $0x082daeb4, %eax");
    asm("jmp *%eax");
}

int CCodeBaseInternal::AddLocation(CExoString &, CExoString &, CExoString &, CScriptLocation const &)
{
    asm("leave");
    asm("mov $0x082d9f30, %eax");
    asm("jmp *%eax");
}

int CCodeBaseInternal::AddString(CExoString &, CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082dafbc, %eax");
    asm("jmp *%eax");
}

int CCodeBaseInternal::AddVarEnd(SCodeBaseData *, int)
{
    asm("leave");
    asm("mov $0x082db0b8, %eax");
    asm("jmp *%eax");
}

int CCodeBaseInternal::AddVarStart(SCodeBaseData *, CExoString &, CExoString &, int &)
{
    asm("leave");
    asm("mov $0x082da944, %eax");
    asm("jmp *%eax");
}

int CCodeBaseInternal::AddVector(CExoString &, CExoString &, CExoString &, Vector const &)
{
    asm("leave");
    asm("mov $0x082daf24, %eax");
    asm("jmp *%eax");
}

void CCodeBaseInternal::CloseAllFiles()
{
    asm("leave");
    asm("mov $0x082dac88, %eax");
    asm("jmp *%eax");
}

void CCodeBaseInternal::CloseFile(int)
{
    asm("leave");
    asm("mov $0x082da664, %eax");
    asm("jmp *%eax");
}

int CCodeBaseInternal::DeleteVar(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082da000, %eax");
    asm("jmp *%eax");
}

void CCodeBaseInternal::DestroyDatabase(CExoString &)
{
    asm("leave");
    asm("mov $0x082da0c0, %eax");
    asm("jmp *%eax");
}

void * CCodeBaseInternal::GetBinaryData(CExoString &, CExoString &, CExoString &, char &, int &)
{
    asm("leave");
    asm("mov $0x082dada8, %eax");
    asm("jmp *%eax");
}

SCodeBaseData * CCodeBaseInternal::GetFile(CExoString &, int)
{
    asm("leave");
    asm("mov $0x082da57c, %eax");
    asm("jmp *%eax");
}

float CCodeBaseInternal::GetFloat(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082dacb4, %eax");
    asm("jmp *%eax");
}

int CCodeBaseInternal::GetInt(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082dad30, %eax");
    asm("jmp *%eax");
}

CScriptLocation * CCodeBaseInternal::GetLocation(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082d9d9c, %eax");
    asm("jmp *%eax");
}

CExoString * CCodeBaseInternal::GetString(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082d9e74, %eax");
    asm("jmp *%eax");
}

SRecord * CCodeBaseInternal::GetVar(SCodeBaseData *, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082da6e0, %eax");
    asm("jmp *%eax");
}

Vector * CCodeBaseInternal::GetVector(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082d9cf0, %eax");
    asm("jmp *%eax");
}

int CCodeBaseInternal::OpenFile(CExoString &, int)
{
    asm("leave");
    asm("mov $0x082da22c, %eax");
    asm("jmp *%eax");
}

