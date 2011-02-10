#include "CGameEffect.h"

int CGameEffect::CopyEffect(CGameEffect *, int)
{
	asm("leave");
	asm("mov $0x0817e08c, %eax");
	asm("jmp *%eax");
}

int CGameEffect::GetExpiryTime(unsigned long *, unsigned long *)
{
	asm("leave");
	asm("mov $0x0817f714, %eax");
	asm("jmp *%eax");
}

int CGameEffect::GetFloat(int)
{
	asm("leave");
	asm("mov $0x0817f620, %eax");
	asm("jmp *%eax");
}

int CGameEffect::GetInteger(int)
{
	asm("leave");
	asm("mov $0x0817f5f8, %eax");
	asm("jmp *%eax");
}

int CGameEffect::GetObjectID(int)
{
	asm("leave");
	asm("mov $0x0817f64c, %eax");
	asm("jmp *%eax");
}

int CGameEffect::GetScriptEffectType()
{
	asm("leave");
	asm("mov $0x0817efb8, %eax");
	asm("jmp *%eax");
}

int CGameEffect::GetString(int)
{
	asm("leave");
	asm("mov $0x0817f678, %eax");
	asm("jmp *%eax");
}

int CGameEffect::LoadGameEffect(CResGFF *, CResStruct *)
{
	asm("leave");
	asm("mov $0x0817e6f0, %eax");
	asm("jmp *%eax");
}

int CGameEffect::SaveGameEffect(CResGFF *, CResStruct *)
{
	asm("leave");
	asm("mov $0x0817ebc4, %eax");
	asm("jmp *%eax");
}

int CGameEffect::SetCreator(unsigned long)
{
	asm("leave");
	asm("mov $0x0817eecc, %eax");
	asm("jmp *%eax");
}

int CGameEffect::SetExpiryTime(unsigned long, unsigned long)
{
	asm("leave");
	asm("mov $0x0817f700, %eax");
	asm("jmp *%eax");
}

int CGameEffect::SetFloat(int, float)
{
	asm("leave");
	asm("mov $0x0817f634, %eax");
	asm("jmp *%eax");
}

int CGameEffect::SetInteger(int, int)
{
	asm("leave");
	asm("mov $0x0817f60c, %eax");
	asm("jmp *%eax");
}

int CGameEffect::SetLinked(CGameEffect *, CGameEffect *)
{
	asm("leave");
	asm("mov $0x0817f750, %eax");
	asm("jmp *%eax");
}

int CGameEffect::SetNumIntegersInitializeToNegativeOne(int)
{
	asm("leave");
	asm("mov $0x0817f5a0, %eax");
	asm("jmp *%eax");
}

int CGameEffect::SetNumIntegers(int)
{
	asm("leave");
	asm("mov $0x0817f54c, %eax");
	asm("jmp *%eax");
}

int CGameEffect::SetObjectID(int, unsigned long)
{
	asm("leave");
	asm("mov $0x0817f660, %eax");
	asm("jmp *%eax");
}

int CGameEffect::SetString(int, CExoString)
{
	asm("leave");
	asm("mov $0x0817f6a4, %eax");
	asm("jmp *%eax");
}

int CGameEffect::UpdateLinked()
{
	asm("leave");
	asm("mov $0x0817e57c, %eax");
	asm("jmp *%eax");
}

int CGameEffect::operator=(CGameEffect const &)
{
	asm("leave");
	asm("mov $0x0817e294, %eax");
	asm("jmp *%eax");
}

int CGameEffect::operator==(CGameEffect const &) const
{
	asm("leave");
	asm("mov $0x0817e47c, %eax");
	asm("jmp *%eax");
}

int CGameEffect::operator!=(CGameEffect const &) const
{
	asm("leave");
	asm("mov $0x0817f730, %eax");
	asm("jmp *%eax");
}

