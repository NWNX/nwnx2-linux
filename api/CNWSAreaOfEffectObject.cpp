#include "CNWSAreaOfEffectObject.h"

void CNWSAreaOfEffectObject::AIUpdate()
{
    asm("leave");
    asm("mov $0x081ea1ec, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::AddToArea(CNWSArea *, float, float, float, int)
{
    asm("leave");
    asm("mov $0x081ea548, %eax");
    asm("jmp *%eax");
}

CNWSAreaOfEffectObject * CNWSAreaOfEffectObject::AsNWSAreaOfEffectObject()
{
    asm("leave");
    asm("mov $0x081ece10, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081ea450, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetAreaEffectId()
{
    asm("leave");
    asm("mov $0x081ecf14, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetCreator()
{
    asm("leave");
    asm("mov $0x081ece9c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSAreaOfEffectObject::GetEffectSpellId()
{
    asm("leave");
    asm("mov $0x081ecf34, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetLastEntered()
{
    asm("leave");
    asm("mov $0x081ecec0, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetLastLeft()
{
    asm("leave");
    asm("mov $0x081eced0, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetObjectArrayIndex()
{
    asm("leave");
    asm("mov $0x081ecf58, %eax");
    asm("jmp *%eax");
}

Vector CNWSAreaOfEffectObject::GetPosition()
{
    asm("leave");
    asm("mov $0x081eccc8, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetRadius()
{
    asm("leave");
    asm("mov $0x081ecf24, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetScriptName(int)
{
    asm("leave");
    asm("mov $0x081ece18, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetShape()
{
    asm("leave");
    asm("mov $0x081ecf04, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetSpellLevel()
{
    asm("leave");
    asm("mov $0x081ecf8c, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetSpellSaveDC()
{
    asm("leave");
    asm("mov $0x081ecf7c, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::GetTargetObjID()
{
    asm("leave");
    asm("mov $0x081ecef4, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::InAreaOfEffect(Vector)
{
    asm("leave");
    asm("mov $0x081eabf0, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::JumpToPoint(CNWSArea *, Vector const &)
{
    asm("leave");
    asm("mov $0x081ec87c, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::LineSegmentIntersectAreaOfEffect(Vector, Vector)
{
    asm("leave");
    asm("mov $0x081ea948, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::LoadAreaEffect(int)
{
    asm("leave");
    asm("mov $0x081eaeb0, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::LoadEffect(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081eb4b4, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::RemoveFromArea()
{
    asm("leave");
    asm("mov $0x081ecc2c, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::RemoveFromSubAreas(int)
{
    asm("leave");
    asm("mov $0x081ec928, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::SaveEffect(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081ebb68, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::SetCreator(unsigned long)
{
    asm("leave");
    asm("mov $0x081ecaf4, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::SetDuration(unsigned char, float)
{
    asm("leave");
    asm("mov $0x081ecd58, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::SetEffectSpellId(unsigned long)
{
    asm("leave");
    asm("mov $0x081ecf44, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::SetLastEntered(unsigned long)
{
    asm("leave");
    asm("mov $0x081eceac, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::SetLastLeft(unsigned long)
{
    asm("leave");
    asm("mov $0x081ecee0, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::SetObjectArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x081ecf68, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::SetScriptName(int, CExoString)
{
    asm("leave");
    asm("mov $0x081ece34, %eax");
    asm("jmp *%eax");
}

int CNWSAreaOfEffectObject::SetShape(unsigned char, float, float)
{
    asm("leave");
    asm("mov $0x081ead30, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::SetTargetObjID(unsigned long)
{
    asm("leave");
    asm("mov $0x081eade0, %eax");
    asm("jmp *%eax");
}

void CNWSAreaOfEffectObject::UpdateSubAreas(Vector *)
{
    asm("leave");
    asm("mov $0x081ebef8, %eax");
    asm("jmp *%eax");
}

