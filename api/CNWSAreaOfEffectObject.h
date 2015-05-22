#ifndef _CNWSAREAOFEFFECTOBJECT_H_
#define _CNWSAREAOFEFFECTOBJECT_H_
#include "nwndef.h"
#include "Vector.h"
#include "CExoString.h"

class CNWSAreaOfEffectObject
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

};
#endif
