#include "CNWTile.h"

int CNWTile::GetAnimLoop(unsigned char *, unsigned char *, unsigned char *)
{
	asm("leave");
	asm("mov $0x08086a78, %eax");
	asm("jmp *%eax");
}

int CNWTile::GetHeight()
{
	asm("leave");
	asm("mov $0x08086b48, %eax");
	asm("jmp *%eax");
}

int CNWTile::GetID()
{
	asm("leave");
	asm("mov $0x08086b54, %eax");
	asm("jmp *%eax");
}

int CNWTile::GetLocation(int *, int *)
{
	asm("leave");
	asm("mov $0x08086810, %eax");
	asm("jmp *%eax");
}

int CNWTile::GetMainLightColor(unsigned char *, unsigned char *)
{
	asm("leave");
	asm("mov $0x08086a40, %eax");
	asm("jmp *%eax");
}

int CNWTile::GetModelPosition()
{
	asm("leave");
	asm("mov $0x08086b28, %eax");
	asm("jmp *%eax");
}

int CNWTile::GetOrientation()
{
	asm("leave");
	asm("mov $0x08086b60, %eax");
	asm("jmp *%eax");
}

int CNWTile::GetReplaceTexture()
{
	asm("leave");
	asm("mov $0x08086b6c, %eax");
	asm("jmp *%eax");
}

int CNWTile::GetSourceLightColor(unsigned char *, unsigned char *)
{
	asm("leave");
	asm("mov $0x08086a5c, %eax");
	asm("jmp *%eax");
}

int CNWTile::RotateCanonicalToRealTile(float, float, float *, float *)
{
	asm("leave");
	asm("mov $0x08086834, %eax");
	asm("jmp *%eax");
}

int CNWTile::RotateCanonicalToReal(float, float, float *, float *)
{
	asm("leave");
	asm("mov $0x080868ec, %eax");
	asm("jmp *%eax");
}

int CNWTile::RotateRealToCanonicalTile(float, float, float *, float *)
{
	asm("leave");
	asm("mov $0x08086890, %eax");
	asm("jmp *%eax");
}

int CNWTile::RotateRealToCanonical(float, float, float *, float *)
{
	asm("leave");
	asm("mov $0x08086950, %eax");
	asm("jmp *%eax");
}

int CNWTile::SetAnimLoop(unsigned char, unsigned char, unsigned char)
{
	asm("leave");
	asm("mov $0x08086ad4, %eax");
	asm("jmp *%eax");
}

int CNWTile::SetID(int)
{
	asm("leave");
	asm("mov $0x080869b4, %eax");
	asm("jmp *%eax");
}

int CNWTile::SetMainLightColor(unsigned char, unsigned char)
{
	asm("leave");
	asm("mov $0x08086a9c, %eax");
	asm("jmp *%eax");
}

int CNWTile::SetOrientation(int)
{
	asm("leave");
	asm("mov $0x08086a30, %eax");
	asm("jmp *%eax");
}

int CNWTile::SetPosition(int, int, int, float)
{
	asm("leave");
	asm("mov $0x080869c4, %eax");
	asm("jmp *%eax");
}

int CNWTile::SetReplaceTexture(unsigned char)
{
	asm("leave");
	asm("mov $0x08086ac4, %eax");
	asm("jmp *%eax");
}

int CNWTile::SetSourceLightColor(unsigned char, unsigned char)
{
	asm("leave");
	asm("mov $0x08086ab0, %eax");
	asm("jmp *%eax");
}

