#include "CCodeBase.h"

int CCodeBase::AddBinaryData(CExoString &, CExoString &, CExoString &, char, void *, int)
{
    asm("leave");
    asm("mov $0x082d9c44, %eax");
    asm("jmp *%eax");
}

int CCodeBase::AddFloat(CExoString &, CExoString &, CExoString &, float)
{
    asm("leave");
    asm("mov $0x082d9b90, %eax");
    asm("jmp *%eax");
}

int CCodeBase::AddInt(CExoString &, CExoString &, CExoString &, int)
{
    asm("leave");
    asm("mov $0x082d9bb4, %eax");
    asm("jmp *%eax");
}

int CCodeBase::AddLocation(CExoString &, CExoString &, CExoString &, CScriptLocation const &)
{
    asm("leave");
    asm("mov $0x082d9bfc, %eax");
    asm("jmp *%eax");
}

int CCodeBase::AddString(CExoString &, CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082d9c20, %eax");
    asm("jmp *%eax");
}

int CCodeBase::AddVector(CExoString &, CExoString &, CExoString &, Vector const &)
{
    asm("leave");
    asm("mov $0x082d9bd8, %eax");
    asm("jmp *%eax");
}

int CCodeBase::CloseAllFiles()
{
    asm("leave");
    asm("mov $0x082d9cac, %eax");
    asm("jmp *%eax");
}

int CCodeBase::DeleteVar(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082d9c88, %eax");
    asm("jmp *%eax");
}

void CCodeBase::DestroyDatabase(CExoString &)
{
    asm("leave");
    asm("mov $0x082d9ccc, %eax");
    asm("jmp *%eax");
}

void * CCodeBase::GetBinaryData(CExoString &, CExoString &, CExoString &, char &, int &)
{
    asm("leave");
    asm("mov $0x082d9b60, %eax");
    asm("jmp *%eax");
}

float CCodeBase::GetFloat(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082d9aac, %eax");
    asm("jmp *%eax");
}

int CCodeBase::GetInt(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082d9ad0, %eax");
    asm("jmp *%eax");
}

CScriptLocation * CCodeBase::GetLocation(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082d9b18, %eax");
    asm("jmp *%eax");
}

CExoString * CCodeBase::GetString(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082d9b3c, %eax");
    asm("jmp *%eax");
}

Vector * CCodeBase::GetVector(CExoString &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082d9af4, %eax");
    asm("jmp *%eax");
}

