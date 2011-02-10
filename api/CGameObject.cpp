#include "CGameObject.h"

int CGameObject::AsNWCAreaOfEffectObject()
{
	asm("leave");
	asm("mov $0x08060c78, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCArea()
{
	asm("leave");
	asm("mov $0x08060c18, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCCreature()
{
	asm("leave");
	asm("mov $0x08060c28, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCDoor()
{
	asm("leave");
	asm("mov $0x08060bf8, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCItem()
{
	asm("leave");
	asm("mov $0x08060c38, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCModule()
{
	asm("leave");
	asm("mov $0x08060c08, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCObject()
{
	asm("leave");
	asm("mov $0x08060bf0, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCPlaceable()
{
	asm("leave");
	asm("mov $0x08060c68, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCProjectile()
{
	asm("leave");
	asm("mov $0x08060c58, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCSoundObject()
{
	asm("leave");
	asm("mov $0x08060ca8, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCStore()
{
	asm("leave");
	asm("mov $0x08060c90, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWCTrigger()
{
	asm("leave");
	asm("mov $0x08060c48, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSAreaOfEffectObject()
{
	asm("leave");
	asm("mov $0x08060c70, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSArea()
{
	asm("leave");
	asm("mov $0x08060c20, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSCreature()
{
	asm("leave");
	asm("mov $0x08060c30, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSDoor()
{
	asm("leave");
	asm("mov $0x08060c00, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSEncounter()
{
	asm("leave");
	asm("mov $0x08060c88, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSItem()
{
	asm("leave");
	asm("mov $0x08060c40, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSModule()
{
	asm("leave");
	asm("mov $0x08060c10, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSObject()
{
	asm("leave");
	asm("mov $0x080bb3ac, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSPlaceable()
{
	asm("leave");
	asm("mov $0x08060c60, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSPlayerTURD()
{
	asm("leave");
	asm("mov $0x08086108, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSSoundObject()
{
	asm("leave");
	asm("mov $0x08060ca0, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSStore()
{
	asm("leave");
	asm("mov $0x08060c98, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSTrigger()
{
	asm("leave");
	asm("mov $0x08060c50, %eax");
	asm("jmp *%eax");
}

int CGameObject::AsNWSWaypoint()
{
	asm("leave");
	asm("mov $0x08060c80, %eax");
	asm("jmp *%eax");
}

int CGameObject::ResetUpdateTimes(unsigned long, unsigned long)
{
	asm("leave");
	asm("mov $0x08060be8, %eax");
	asm("jmp *%eax");
}

int CGameObject::SetId(unsigned long)
{
	asm("leave");
	asm("mov $0x08060be0, %eax");
	asm("jmp *%eax");
}

