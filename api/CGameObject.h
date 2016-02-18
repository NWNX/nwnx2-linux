#ifndef _CGAMEOBJECT_H_
#define _CGAMEOBJECT_H_
#include "nwndef.h"

class CGameObject
{
public:
    CNWCAreaOfEffectObject * AsNWCAreaOfEffectObject();
    CNWCArea * AsNWCArea();
    CNWCCreature * AsNWCCreature();
    CNWCDoor * AsNWCDoor();
    CNWCItem * AsNWCItem();
    CNWCModule * AsNWCModule();
    CNWCObject * AsNWCObject();
    CNWCPlaceable * AsNWCPlaceable();
    CNWCProjectile * AsNWCProjectile();
    CNWCSoundObject * AsNWCSoundObject();
    CNWCStore * AsNWCStore();
    CNWCTrigger * AsNWCTrigger();
    CNWSAreaOfEffectObject * AsNWSAreaOfEffectObject();
    CNWSArea * AsNWSArea();
    CNWSCreature * AsNWSCreature();
    CNWSDoor * AsNWSDoor();
    CNWSEncounter * AsNWSEncounter();
    CNWSItem * AsNWSItem();
    CNWSModule * AsNWSModule();
    CNWSObject * AsNWSObject();
    CNWSPlaceable * AsNWSPlaceable();
    CNWSPlayerTURD * AsNWSPlayerTURD();
    CNWSSoundObject * AsNWSSoundObject();
    CNWSStore * AsNWSStore();
    CNWSTrigger * AsNWSTrigger();
    CNWSWaypoint * AsNWSWaypoint();
    void ResetUpdateTimes(unsigned long, unsigned long);
    void SetId(unsigned long);
    ~CGameObject();
    CGameObject(unsigned char, unsigned long);

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long ObjectID;
    /* 0x8/8 */ char ObjectType;
    /* 0x9/9 */ char field_9;
    /* 0xA/10 */ char field_A;
    /* 0xB/11 */ char field_B;
    /* 0xC/12 */ CGameObject_vtbl<CGameObject>* vptr;
};
#endif
