#ifndef _CNWSENCOUNTER_H_
#define _CNWSENCOUNTER_H_
#include "nwndef.h"
#include "nwnstructs.h"
#include "Vector.h"
#include "CResRef.h"
#include "CExoString.h"

class CNWSEncounter
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

};
#endif
