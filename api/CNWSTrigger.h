#ifndef _CNWSTRIGGER_H_
#define _CNWSTRIGGER_H_
#include "nwndef.h"
#include "Vector.h"
#include "CResRef.h"
#include "CExoString.h"
#include "CNWSObject.h"

class CNWSTrigger
{
public:
	int AIUpdate();
	int AddToArea(CNWSArea *, float, float, float, int);
	int AsNWSTrigger();
	int CalculateNearestPoint(Vector, Vector *);
	int ComputeBoundingBox(float *, float *, float *, float *);
	int CreateNewGeometry(float, Vector, CNWSArea *);
	int CreateNewGeometry(float, CScriptLocation *, CNWSArea *);
	int EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
	int GetActive();
	int GetAutoRemoveKey();
	int GetBaseType();
	int GetCanFireTrapOnObject(unsigned long, int);
	int GetClosestPointWithinTrigger(Vector, Vector *);
	int GetCreator();
	int GetCreatureList();
	int GetCursor();
	int GetCustomScriptEventId();
	int GetDescriptionOverride();
	int GetDetectDC();
	int GetDetectable();
	int GetDisarmDC();
	int GetDisarmable();
	int GetFacingPosition();
	int GetFactionId();
	int GetFirstName();
	int GetFlagged();
	int GetIsAreaTransition();
	int GetIsTrap();
	int GetKeyName();
	int GetLastDisarmed();
	int GetLastEntered();
	int GetLastLeft();
	int GetLinkedFlags();
	int GetLinkedTo();
	int GetLoadScreenID();
	int GetNumVertices();
	int GetObjectArrayIndex();
	int GetOneShot();
	int GetRecoverable();
	int GetScriptName(int);
	int GetTargetArea();
	int GetTriggerHeight();
	int GetVertices();
	int InTrigger(Vector);
	int LineSegmentIntersectTrigger(Vector, Vector);
	int LoadFromTemplate(CResRef);
	int LoadTrigger(CResGFF *, CResStruct *);
	int OnEnterTrap(int);
	int RemoveFromArea();
	int SaveTrigger(CResGFF *, CResStruct *);
	int SetActive(int);
	int SetAutoRemoveKey(int);
	int SetBaseType(unsigned char);
	int SetCreator(unsigned long);
	int SetCursor(unsigned char);
	int SetCustomScriptEventId(int);
	int SetDescriptionOverride(CExoString);
	int SetDetectDC(int);
	int SetDetectable(int);
	int SetDisarmDC(int);
	int SetDisarmable(int);
	int SetFactionId(int);
	int SetFirstName(unsigned long);
	int SetFlagged(int);
	int SetIsAreaTransition(int);
	int SetIsTrap(int);
	int SetKeyName(CExoString const &);
	int SetLastDisarmed(unsigned long);
	int SetLastEntered(unsigned long);
	int SetLastLeft(unsigned long);
	int SetLinkedFlags(unsigned char);
	int SetLinkedTo(CExoString);
	int SetObjectArrayIndex(unsigned short);
	int SetOneShot(unsigned char);
	int SetRecoverable(int);
	int SetScriptName(int, CExoString);
	int SetTriggerHeight(float);
	~CNWSTrigger();
	CNWSTrigger(unsigned long);

	/* 0x0/0 */ CNWSObject Object;
	/* 0x1C4/452 */ unsigned long field_1C4;
	/* 0x1C8/456 */ unsigned long field_1C8;
	/* 0x2B0/688 */ char rsvd1[228];
	/* 0x2B0/688 */ unsigned long field_2B0;
};
#endif
