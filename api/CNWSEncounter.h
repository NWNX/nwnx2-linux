#ifndef _CNWSENCOUNTER_H_
#define _CNWSENCOUNTER_H_
#include "nwndef.h"
#include "nwnstructs.h"
#include "Vector.h"
#include "CResRef.h"
#include "CExoString.h"

class CNWSEncounter : public CNWSObject
{
public:
    void AIUpdate();
    void AddCreaturesToSpawnList(CEncounterListEntry *, int &, int, CEncounterListEntry);
    void AddToActivateAreaList(unsigned long);
    void AddToArea(CNWSArea *, float, float, float, int);
    CNWSEncounter * AsNWSEncounter();
    float CalculatePointsFromCR(float);
    void CalculateSpawnPool(float);
    void EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
    int GetActivateObjectArrayIndex();
    int GetActive();
    int GetCustomScriptEventId();
    int GetDifficultyIndex();
    int GetDifficulty();
    int GetEncounterCanReset();
    int GetEncounterExhausted();
    int GetEncounterStarted();
    int GetFactionId();
    CExoLocString & GetFirstName();
    int GetInActivateAreaList(unsigned long);
    int GetInActivateArea(Vector);
    int GetLastEntered();
    int GetLastLeft();
    int GetMaxActivateX();
    int GetMaxActivateY();
    int GetMinActivateX();
    int GetMinActivateY();
    int GetNewEntry();
    int GetPlayerTriggeredOnly();
    int GetPosition();
    int GetRespawnsCurrent();
    int GetRespawnsMax();
    int GetScriptName(int);
    int GetSpawnMode();
    int LineSegmentIntersectActivateArea(Vector, Vector);
    int LoadEncounter(CResGFF *, CResStruct *);
    int LoadFractionalCRData();
    void LoadFromTemplate(CResRef, int, Vector *);
    void MakeSpawnList(CEncounterListEntry *, int &);
    void PadOutCreatureCount(CEncounterListEntry *, int &);
    int ReadEncounterFromGff(CResGFF *, CResStruct *, int, Vector *);
    void ReadEncounterScriptsFromGff(CResGFF *, CResStruct *);
    int RemoveFromActivateAreaList(unsigned long);
    void RemoveFromActiveCreatureCount(float, int);
    void RemoveFromArea();
    int SaveEncounter(CResGFF *, CResStruct *);
    int SetActivateObjectArrayIndex(unsigned short);
    void SetActive(int);
    int SetCustomScriptEventId(int);
    void SetDifficulty(int);
    int SetEncounterCanReset(int);
    int SetEncounterExhausted(int);
    int SetEncounterStarted(int);
    int SetLastEntered(unsigned long);
    int SetLastLeft(unsigned long);
    int SetNewEntry(int);
    int SetPlayerTriggeredOnly(int);
    int SetRespawnsCurrent(int);
    int SetRespawnsMax(int);
    void SetScriptName(int, CExoString);
    int SetSpawnMode(int);
    void SpawnEncounterCreatures();
    void SpawnIfAppropriate(unsigned long, float);
    void TallyEnemyRadiusPoints();
    void UpdateActivateAreaList(unsigned long);
    ~CNWSEncounter();
    CNWSEncounter(unsigned long);

    /* 0x1C4/452 */ unsigned short ActivateObjectArrayIndex;
    /* 0x1C6/454 */ unsigned short field_1C6;
    /* 0x1C8/456 */ unsigned long Faction;
    /* 0x1CC/460 */ CExoLocString Name;
    /* 0x1D4/468 */ unsigned char IsActive;
    /* 0x1D5/469 */ unsigned char field_1D5;
    /* 0x1D6/470 */ unsigned char field_1D6;
    /* 0x1D7/471 */ unsigned char field_1D7;
    /* 0x1D8/472 */ unsigned char Reset;
    /* 0x1D9/473 */ unsigned char field_1D9;
    /* 0x1DA/474 */ unsigned char field_1DA;
    /* 0x1DB/475 */ unsigned char field_1DB;
    /* 0x1DC/476 */ int ResetTime;
    /* 0x1E0/480 */ int SpawnOption;
    /* 0x1E4/484 */ int Difficulty;
    /* 0x1E8/488 */ int DifficultyIndex;
    /* 0x1EC/492 */ int RecCreatures;
    /* 0x1F0/496 */ int MaxCreatures;
    /* 0x1F4/500 */ int NumberSpawned;
    /* 0x1F8/504 */ unsigned long HeartbeatDay;
    /* 0x1FC/508 */ unsigned long HeartbeatTime;
    /* 0x200/512 */ unsigned long LastSpawnDay;
    /* 0x204/516 */ unsigned long LastSpawnTime;
    /* 0x208/520 */ unsigned char Started;
    /* 0x209/521 */ unsigned char field_209;
    /* 0x20A/522 */ unsigned char field_20A;
    /* 0x20B/523 */ unsigned char field_20B;
    /* 0x20C/524 */ unsigned char Exhausted;
    /* 0x20D/525 */ unsigned char field_20D;
    /* 0x20E/526 */ unsigned char field_20E;
    /* 0x20F/527 */ unsigned char field_20F;
    /* 0x210/528 */ int AreaListMaxSize;
    /* 0x214/532 */ nwobjid* AreaList;
    /* 0x218/536 */ unsigned long AreaListSize;
    /* 0x21C/540 */ unsigned long NewEntry;
    /* 0x220/544 */ Vector* Geometry;
    /* 0x224/548 */ unsigned long GeometryLength;
    /* 0x228/552 */ unsigned long field_228;
    /* 0x22C/556 */ unsigned long field_22C;
    /* 0x230/560 */ float MinActivateX;
    /* 0x234/564 */ float MaxActivateX;
    /* 0x238/568 */ float MinActivateY;
    /* 0x23C/572 */ float MaxActivateY;
    /* 0x240/576 */ void* CreatureList;
    /* 0x244/580 */ unsigned long CreatureListLength;
    /* 0x248/584 */ CSpawnPoint* SpawnPoints;
    /* 0x24C/588 */ unsigned long SpawnPointsLength;
    /* 0x250/592 */ int Respawns;
    /* 0x254/596 */ int RespawnsMax;
    /* 0x258/600 */ int SpawnsCurrent;
    /* 0x25C/604 */ unsigned long field_25C;
    /* 0x260/608 */ unsigned long field_260;
    /* 0x264/612 */ float AreaPoints;
    /* 0x268/616 */ unsigned long field_268;
    /* 0x26C/620 */ float SpawnPoolActive;
    /* 0x270/624 */ unsigned long LastEntered;
    /* 0x274/628 */ unsigned long LastLeft;
    /* 0x278/632 */ CExoString Scripts[5];
    /* 0x2A0/672 */ unsigned long field_2A0;
    /* 0x2A4/676 */ int CustomScriptID;
    /* 0x2A8/680 */ unsigned char PlayerOnly;
    /* 0x2A9/681 */ unsigned char field_2A9;
    /* 0x2AA/682 */ unsigned char field_2AA;
    /* 0x2AB/683 */ unsigned char field_2AB;
};

static_assert_size(CNWSEncounter, 0x2AC);

#endif
