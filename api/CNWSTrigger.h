#ifndef _CNWSTRIGGER_H_
#define _CNWSTRIGGER_H_
#include "nwndef.h"
#include "CNWSObject.h"
#include "Vector.h"
#include "CExoString.h"
#include "CResRef.h"

class CNWSTrigger : public CNWSObject
{
public:
    void AIUpdate();
    void AddToArea(CNWSArea *, float, float, float, int);
    CNWSTrigger * AsNWSTrigger();
    int CalculateNearestPoint(Vector, Vector *);
    void ComputeBoundingBox(float *, float *, float *, float *);
    void CreateNewGeometry(float, Vector, CNWSArea *);
    void CreateNewGeometry(float, CScriptLocation *, CNWSArea *);
    void EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
    int GetActive();
    int GetAutoRemoveKey();
    int GetBaseType();
    int GetCanFireTrapOnObject(unsigned long, int);
    int GetClosestPointWithinTrigger(Vector, Vector *);
    int GetCreator();
    int GetCreatureList();
    int GetCursor();
    int GetCustomScriptEventId();
    CExoString GetDescriptionOverride();
    int GetDetectDC();
    int GetDetectable();
    int GetDisarmDC();
    int GetDisarmable();
    Vector GetFacingPosition();
    int GetFactionId();
    CExoLocString & GetFirstName();
    int GetFlagged();
    int GetIsAreaTransition();
    int GetIsTrap();
    int GetKeyName();
    int GetLastDisarmed();
    int GetLastEntered();
    int GetLastLeft();
    int GetLinkedFlags();
    CExoString GetLinkedTo();
    unsigned short GetLoadScreenID();
    int GetNumVertices();
    int GetObjectArrayIndex();
    int GetOneShot();
    int GetRecoverable();
    CExoString * GetScriptName(int);
    unsigned long GetTargetArea();
    int GetTriggerHeight();
    int GetVertices();
    int InTrigger(Vector);
    int LineSegmentIntersectTrigger(Vector, Vector);
    int LoadFromTemplate(CResRef);
    int LoadTrigger(CResGFF *, CResStruct *);
    void OnEnterTrap(int);
    void RemoveFromArea();
    int SaveTrigger(CResGFF *, CResStruct *);
    int SetActive(int);
    int SetAutoRemoveKey(int);
    int SetBaseType(unsigned char);
    int SetCreator(unsigned long);
    int SetCursor(unsigned char);
    int SetCustomScriptEventId(int);
    void SetDescriptionOverride(CExoString);
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
    void SetScriptName(int, CExoString);
    int SetTriggerHeight(float);
    ~CNWSTrigger();
    CNWSTrigger(unsigned long);

    /* 0x1C4/452 */ unsigned long field_1C4;
    /* 0x1C8/456 */ unsigned long field_1C8;
    /* 0x2B0/688 */ char rsvd1[228];
    /* 0x2B0/688 */ unsigned long field_2B0;
};
#endif
