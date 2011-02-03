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
	int AIUpdate();
	int AddCreaturesToSpawnList(CEncounterListEntry *, int &, int, CEncounterListEntry);
	int AddToActivateAreaList(unsigned long);
	int AddToArea(CNWSArea *, float, float, float, int);
	int AsNWSEncounter();
	int CalculatePointsFromCR(float);
	int CalculateSpawnPool(float);
	int EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
	int GetActivateObjectArrayIndex();
	int GetActive();
	int GetCustomScriptEventId();
	int GetDifficultyIndex();
	int GetDifficulty();
	int GetEncounterCanReset();
	int GetEncounterExhausted();
	int GetEncounterStarted();
	int GetFactionId();
	int GetFirstName();
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
	int LoadFromTemplate(CResRef, int, Vector *);
	int MakeSpawnList(CEncounterListEntry *, int &);
	int PadOutCreatureCount(CEncounterListEntry *, int &);
	int ReadEncounterFromGff(CResGFF *, CResStruct *, int, Vector *);
	int ReadEncounterScriptsFromGff(CResGFF *, CResStruct *);
	int RemoveFromActivateAreaList(unsigned long);
	int RemoveFromActiveCreatureCount(float, int);
	int RemoveFromArea();
	int SaveEncounter(CResGFF *, CResStruct *);
	int SetActivateObjectArrayIndex(unsigned short);
	int SetActive(int);
	int SetCustomScriptEventId(int);
	int SetDifficulty(int);
	int SetEncounterCanReset(int);
	int SetEncounterExhausted(int);
	int SetEncounterStarted(int);
	int SetLastEntered(unsigned long);
	int SetLastLeft(unsigned long);
	int SetNewEntry(int);
	int SetPlayerTriggeredOnly(int);
	int SetRespawnsCurrent(int);
	int SetRespawnsMax(int);
	int SetScriptName(int, CExoString);
	int SetSpawnMode(int);
	int SpawnEncounterCreatures();
	int SpawnIfAppropriate(unsigned long, float);
	int TallyEnemyRadiusPoints();
	int UpdateActivateAreaList(unsigned long);
	~CNWSEncounter();
	CNWSEncounter(unsigned long);

};
#endif
