#include "CGameObject.h"

CNWCAreaOfEffectObject * CGameObject::AsNWCAreaOfEffectObject()
{
    asm("leave");
    asm("mov $0x08060c78, %eax");
    asm("jmp *%eax");
}

CNWCArea * CGameObject::AsNWCArea()
{
    asm("leave");
    asm("mov $0x08060c18, %eax");
    asm("jmp *%eax");
}

CNWCCreature * CGameObject::AsNWCCreature()
{
    asm("leave");
    asm("mov $0x08060c28, %eax");
    asm("jmp *%eax");
}

CNWCDoor * CGameObject::AsNWCDoor()
{
    asm("leave");
    asm("mov $0x08060bf8, %eax");
    asm("jmp *%eax");
}

CNWCItem * CGameObject::AsNWCItem()
{
    asm("leave");
    asm("mov $0x08060c38, %eax");
    asm("jmp *%eax");
}

CNWCModule * CGameObject::AsNWCModule()
{
    asm("leave");
    asm("mov $0x08060c08, %eax");
    asm("jmp *%eax");
}

CNWCObject * CGameObject::AsNWCObject()
{
    asm("leave");
    asm("mov $0x08060bf0, %eax");
    asm("jmp *%eax");
}

CNWCPlaceable * CGameObject::AsNWCPlaceable()
{
    asm("leave");
    asm("mov $0x08060c68, %eax");
    asm("jmp *%eax");
}

CNWCProjectile * CGameObject::AsNWCProjectile()
{
    asm("leave");
    asm("mov $0x08060c58, %eax");
    asm("jmp *%eax");
}

CNWCSoundObject * CGameObject::AsNWCSoundObject()
{
    asm("leave");
    asm("mov $0x08060ca8, %eax");
    asm("jmp *%eax");
}

CNWCStore * CGameObject::AsNWCStore()
{
    asm("leave");
    asm("mov $0x08060c90, %eax");
    asm("jmp *%eax");
}

CNWCTrigger * CGameObject::AsNWCTrigger()
{
    asm("leave");
    asm("mov $0x08060c48, %eax");
    asm("jmp *%eax");
}

CNWSAreaOfEffectObject * CGameObject::AsNWSAreaOfEffectObject()
{
    asm("leave");
    asm("mov $0x08060c70, %eax");
    asm("jmp *%eax");
}

CNWSArea * CGameObject::AsNWSArea()
{
    asm("leave");
    asm("mov $0x08060c20, %eax");
    asm("jmp *%eax");
}

CNWSCreature * CGameObject::AsNWSCreature()
{
    asm("leave");
    asm("mov $0x08060c30, %eax");
    asm("jmp *%eax");
}

CNWSDoor * CGameObject::AsNWSDoor()
{
    asm("leave");
    asm("mov $0x08060c00, %eax");
    asm("jmp *%eax");
}

CNWSEncounter * CGameObject::AsNWSEncounter()
{
    asm("leave");
    asm("mov $0x08060c88, %eax");
    asm("jmp *%eax");
}

CNWSItem * CGameObject::AsNWSItem()
{
    asm("leave");
    asm("mov $0x08060c40, %eax");
    asm("jmp *%eax");
}

CNWSModule * CGameObject::AsNWSModule()
{
    asm("leave");
    asm("mov $0x08060c10, %eax");
    asm("jmp *%eax");
}

CNWSObject * CGameObject::AsNWSObject()
{
    asm("leave");
    asm("mov $0x080bb3ac, %eax");
    asm("jmp *%eax");
}

CNWSPlaceable * CGameObject::AsNWSPlaceable()
{
    asm("leave");
    asm("mov $0x08060c60, %eax");
    asm("jmp *%eax");
}

CNWSPlayerTURD * CGameObject::AsNWSPlayerTURD()
{
    asm("leave");
    asm("mov $0x08086108, %eax");
    asm("jmp *%eax");
}

CNWSSoundObject * CGameObject::AsNWSSoundObject()
{
    asm("leave");
    asm("mov $0x08060ca0, %eax");
    asm("jmp *%eax");
}

CNWSStore * CGameObject::AsNWSStore()
{
    asm("leave");
    asm("mov $0x08060c98, %eax");
    asm("jmp *%eax");
}

CNWSTrigger * CGameObject::AsNWSTrigger()
{
    asm("leave");
    asm("mov $0x08060c50, %eax");
    asm("jmp *%eax");
}

CNWSWaypoint * CGameObject::AsNWSWaypoint()
{
    asm("leave");
    asm("mov $0x08060c80, %eax");
    asm("jmp *%eax");
}

void CGameObject::ResetUpdateTimes(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08060be8, %eax");
    asm("jmp *%eax");
}

void CGameObject::SetId(unsigned long)
{
    asm("leave");
    asm("mov $0x08060be0, %eax");
    asm("jmp *%eax");
}

