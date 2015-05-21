#ifndef _CNWSTILE_H_
#define _CNWSTILE_H_
#include "nwndef.h"
#include "Vector.h"
#include "CExoArrayList.h"

class CNWSTile
{
public:
    int AddDoor(unsigned long);
    void AddTrigger(unsigned long);
    int ClearLineOfSight(int, Vector, Vector, Vector *);
    int ClippedLineSegmentWalkable(float, float, float, float, float *, float *, float *, float *, float *, float *);
    int ComputeClippedLineSegment(Vector, Vector, Vector *, Vector *);
    float ComputeHeight(Vector);
    int FindClosestRegion(float, float);
    int GetDoorsList();
    int GetExitNumber(float, float);
    int GetExit(int, float *, float *, int *);
    int GetFlaggedAsProblem();
    int GetHasPlaceableWithWalkMesh();
    int GetMainLightColorChange();
    int GetNumTriggers();
    int GetRegionCoords(int, float *, float *);
    int GetRegionEntrance(float, float);
    int GetSourceLightColorChange();
    int GetSurfaceMaterial(Vector);
    CNWTileData * GetTileData();
    int GetTotalExits();
    int GetTriggerData();
    int GetWalkMesh();
    int InTrigger(Vector, CExoArrayList<unsigned long> *);
    int IntersectLineSegments(float, float, float, float, float, float, float, float, float *, float *);
    int LoadWalkMesh();
    int NoNonWalkPolysOnTile(float, float, float, float, float, float, float);
    unsigned long PlotIntraTilePath(CNWArea *, CPathfindInformation *, float, float, float, float, unsigned long);
    int RemoveDoor(unsigned long);
    int SetFlaggedAsProblem();
    int SetHasPlaceableWithWalkMesh();
    int SetMainLightColorChange(int);
    void SetMainLightColor(unsigned char, unsigned char);
    int SetSourceLightColorChange(int);
    void SetSourceLightColor(unsigned char, unsigned char);
    void SetTileData(CNWTileData *);
    ~CNWSTile();
    CNWSTile();

};
#endif
