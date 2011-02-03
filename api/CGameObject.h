#ifndef _CGAMEOBJECT_H_
#define _CGAMEOBJECT_H_
#include "nwndef.h"
#include "nwnstructs.h"

class CGameObject
{
public:
	int AsNWCAreaOfEffectObject();
	int AsNWCArea();
	int AsNWCCreature();
	int AsNWCDoor();
	int AsNWCItem();
	int AsNWCModule();
	int AsNWCObject();
	int AsNWCPlaceable();
	int AsNWCProjectile();
	int AsNWCSoundObject();
	int AsNWCStore();
	int AsNWCTrigger();
	int AsNWSAreaOfEffectObject();
	int AsNWSArea();
	int AsNWSCreature();
	int AsNWSDoor();
	int AsNWSEncounter();
	int AsNWSItem();
	int AsNWSModule();
	int AsNWSObject();
	int AsNWSPlaceable();
	int AsNWSPlayerTURD();
	int AsNWSSoundObject();
	int AsNWSStore();
	int AsNWSTrigger();
	int AsNWSWaypoint();
	int ResetUpdateTimes(unsigned long, unsigned long);
	int SetId(unsigned long);
	~CGameObject();
	CGameObject(unsigned char, unsigned long);

	/* 0x0/0 */ unsigned long field_0;
	/* 0x4/4 */ unsigned long ObjectID;
	/* 0x8/8 */ char ObjectType;
	/* 0x9/9 */ char field_9;
	/* 0xA/10 */ char field_A;
	/* 0xB/11 */ char field_B;
	/* 0xC/12 */ CNWSObjectMethods *Methods;
};
#endif
