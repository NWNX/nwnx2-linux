#ifndef _CNWSTRIGGER_H_
#define _CNWSTRIGGER_H_
#include "nwndef.h"
#include "CNWSObject.h"
#include "Vector.h"
#include "CExoString.h"
#include "CResRef.h"
#include "CExoString.h"
#include "CExoArrayList.h"

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

    /* 0x1C4/452 */ CExoLocString FirstName;
    /* 0x1CC/460 */ CExoString LinkedTo;
    /* 0x1D4/468 */ unsigned char LinkedFlags;
    /* 0x1D5/469 */ unsigned char field_1D5;
    /* 0x1D6/470 */ unsigned char field_1D6;
    /* 0x1D7/471 */ unsigned char field_1D7;
    /* 0x1D8/472 */ unsigned long field_1D8;
    /* 0x1DC/476 */ unsigned long field_1DC;
    /* 0x1E0/480 */ unsigned long field_1E0;
    /* 0x1E4/484 */ unsigned long field_1E4;
    /* 0x1E8/488 */ unsigned long field_1E8;
    /* 0x1EC/492 */ unsigned long field_1EC;
    /* 0x1F0/496 */ unsigned long field_1F0;
    /* 0x1F4/500 */ unsigned long field_1F4;
    /* 0x1F8/504 */ unsigned long field_1F8;
    /* 0x1FC/508 */ unsigned long field_1FC;
    /* 0x200/512 */ unsigned long field_200;
    /* 0x204/516 */ unsigned long field_204;
    /* 0x208/520 */ unsigned long field_208;
    /* 0x20C/524 */ unsigned long field_20C;
    /* 0x210/528 */ unsigned long field_210;
    /* 0x214/532 */ unsigned long field_214;
    /* 0x218/536 */ CExoString KeyName;
    /* 0x220/544 */ unsigned long NumVertices;
    /* 0x224/548 */ unsigned long Vertices;
    /* 0x228/552 */ unsigned long field_228;
    /* 0x22C/556 */ unsigned long field_22C;
    /* 0x230/560 */ unsigned long field_230;
    /* 0x234/564 */ unsigned long field_234;
    /* 0x238/568 */ unsigned long LastEntered;
    /* 0x23C/572 */ unsigned long LastLeft;
    /* 0x240/576 */ unsigned long LastDisarmed;
    /* 0x244/580 */ CExoArrayList<unsigned long> CreatureList;
    /* 0x250/592 */ unsigned long IsAreaTransition;
    /* 0x254/596 */ unsigned long FactionID;
    /* 0x258/600 */ unsigned long Trapped;
    /* 0x25C/604 */ unsigned long TrapDetectable;
    /* 0x260/608 */ unsigned long TrapDisarmable;
    /* 0x264/612 */ unsigned long TrapFlagged;
    /* 0x268/616 */ unsigned long AutoRemoveKey;
    /* 0x26C/620 */ unsigned long TrapOneShot;
    /* 0x270/624 */ unsigned char TrapBaseType;
    /* 0x271/625 */ unsigned char field_271;
    /* 0x272/626 */ unsigned char field_272;
    /* 0x273/627 */ unsigned char field_273;
    /* 0x274/628 */ unsigned long TrapDetectDC;
    /* 0x278/632 */ unsigned long TrapDisarmDC;
    /* 0x27C/636 */ unsigned long TrapRecoverable;
    /* 0x280/640 */ unsigned long TrapActive;
    /* 0x284/644 */ unsigned long TrapCreator;
    /* 0x288/648 */ float TriggerHeight;
    /* 0x28C/652 */ unsigned long Creator;
    /* 0x290/656 */ unsigned long field_290;
    /* 0x294/660 */ unsigned long field_294;
    /* 0x298/664 */ unsigned long field_298;
    /* 0x29C/668 */ unsigned long field_29C;
    /* 0x2A0/672 */ unsigned long CustomScriptEventId;
    /* 0x2A4/676 */ unsigned char Cursor;
    /* 0x2A5/677 */ unsigned char field_2A5;
    /* 0x2A6/678 */ unsigned char field_2A6;
    /* 0x2A7/679 */ unsigned char field_2A7;
    /* 0x2A8/680 */ unsigned long field_2A8;
    /* 0x2AC/684 */ unsigned long field_2AC;
    /* 0x2B0/688 */ unsigned short LoadScreenID;
    /* 0x2B2/690 */ unsigned short field_2B2;
};

static_assert_size(CNWSTrigger, 0x2B4);

#endif
