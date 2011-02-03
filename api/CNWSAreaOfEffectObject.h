#ifndef _CNWSAREAOFEFFECTOBJECT_H_
#define _CNWSAREAOFEFFECTOBJECT_H_
#include "nwndef.h"
#include "Vector.h"
#include "CExoString.h"

class CNWSAreaOfEffectObject
{
public:
	int AIUpdate();
	int AddToArea(CNWSArea *, float, float, float, int);
	int AsNWSAreaOfEffectObject();
	int EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
	int GetAreaEffectId();
	int GetCreator();
	int GetEffectSpellId();
	int GetLastEntered();
	int GetLastLeft();
	int GetObjectArrayIndex();
	int GetPosition();
	int GetRadius();
	int GetScriptName(int);
	int GetShape();
	int GetSpellLevel();
	int GetSpellSaveDC();
	int GetTargetObjID();
	int InAreaOfEffect(Vector);
	int JumpToPoint(CNWSArea *, Vector const &);
	int LineSegmentIntersectAreaOfEffect(Vector, Vector);
	int LoadAreaEffect(int);
	int LoadEffect(CResGFF *, CResStruct *);
	int RemoveFromArea();
	int RemoveFromSubAreas(int);
	int SaveEffect(CResGFF *, CResStruct *);
	int SetCreator(unsigned long);
	int SetDuration(unsigned char, float);
	int SetEffectSpellId(unsigned long);
	int SetLastEntered(unsigned long);
	int SetLastLeft(unsigned long);
	int SetObjectArrayIndex(unsigned short);
	int SetScriptName(int, CExoString);
	int SetShape(unsigned char, float, float);
	int SetTargetObjID(unsigned long);
	int UpdateSubAreas(Vector *);
	~CNWSAreaOfEffectObject();
	CNWSAreaOfEffectObject(unsigned long);

};
#endif
