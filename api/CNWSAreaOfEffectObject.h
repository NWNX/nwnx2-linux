#ifndef _CNWSAREAOFEFFECTOBJECT_H_
#define _CNWSAREAOFEFFECTOBJECT_H_
#include "nwndef.h"
#include "Vector.h"
#include "CExoString.h"
#include "CNWSObject.h"

class CNWSAreaOfEffectObject : public CNWSObject
{
public:
    void AIUpdate();
    void AddToArea(CNWSArea *, float, float, float, int);
    CNWSAreaOfEffectObject * AsNWSAreaOfEffectObject();
    void EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
    int GetAreaEffectId();
    int GetCreator();
    unsigned long GetEffectSpellId();
    int GetLastEntered();
    int GetLastLeft();
    int GetObjectArrayIndex();
    Vector GetPosition();
    int GetRadius();
    int GetScriptName(int);
    int GetShape();
    int GetSpellLevel();
    int GetSpellSaveDC();
    int GetTargetObjID();
    int InAreaOfEffect(Vector);
    void JumpToPoint(CNWSArea *, Vector const &);
    int LineSegmentIntersectAreaOfEffect(Vector, Vector);
    void LoadAreaEffect(int);
    int LoadEffect(CResGFF *, CResStruct *);
    void RemoveFromArea();
    void RemoveFromSubAreas(int);
    int SaveEffect(CResGFF *, CResStruct *);
    void SetCreator(unsigned long);
    void SetDuration(unsigned char, float);
    void SetEffectSpellId(unsigned long);
    int SetLastEntered(unsigned long);
    int SetLastLeft(unsigned long);
    int SetObjectArrayIndex(unsigned short);
    void SetScriptName(int, CExoString);
    int SetShape(unsigned char, float, float);
    void SetTargetObjID(unsigned long);
    void UpdateSubAreas(Vector *);
    ~CNWSAreaOfEffectObject();
    CNWSAreaOfEffectObject(unsigned long);

    /* 0x1C4/452 */ short ObjectArrayIndex;
    /* 0x1C6/456 */ unsigned short field_01C6;
    /* 0x1C8/458 */ unsigned long EffectID;
    /* 0x1CC/460 */ unsigned char Shape;
    /* 0x1CD/461 */ unsigned char field_01CD;
    /* 0x1CE/462 */ unsigned char field_01CE;
    /* 0x1CF/463 */ unsigned char field_01CF;
    /* 0x1D0/464 */ unsigned long SpellID;
    /* 0x1D4/468 */ float Radius;
    /* 0x1D8/472 */ float Length;
    /* 0x1DC/476 */ float Width;
    /* 0x1E0/480 */ unsigned long field_01E0;
    /* 0x1E4/484 */ nwobjid Creator;
    /* 0x1E8/488 */ unsigned long LinkedObject;
    /* 0x1EC/492 */ nwobjid LastEntered;
    /* 0x1F0/496 */ nwobjid LastExited;
    /* 0x1F4/500 */ unsigned long SpellDC;
    /* 0x1F8/504 */ unsigned long SpellLevel;
    /* 0x1FC/508 */ CExoString Scripts[4];
    /* 0x21C/540 */ unsigned long field_021C;
    /* 0x220/544 */ unsigned long LastHeartbeatDay;
    /* 0x224/548 */ unsigned long LastHeartbeatTime;
    /* 0x228/552 */ unsigned char Duration;
    /* 0x229/553 */ unsigned char DurationType;
    /* 0x22A/554 */ unsigned char field_022A;
    /* 0x22B/555 */ unsigned char field_022B;
};

static_assert_size(CNWSAreaOfEffectObject, 0x22C);

#endif
