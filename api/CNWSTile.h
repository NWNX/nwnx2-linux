#ifndef _CNWSTILE_H_
#define _CNWSTILE_H_
#include "nwndef.h"
#include "Vector.h"
#include "CExoArrayList.h"

class CNWSTile
{
public:
	int AddDoor(unsigned long);
	int AddTrigger(unsigned long);
	int ClearLineOfSight(int, Vector, Vector, Vector *);
	int ClippedLineSegmentWalkable(float, float, float, float, float *, float *, float *, float *, float *, float *);
	int ComputeClippedLineSegment(Vector, Vector, Vector *, Vector *);
	int ComputeHeight(Vector);
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
	int GetTileData();
	int GetTotalExits();
	int GetTriggerData();
	int GetWalkMesh();
	int InTrigger(Vector, CExoArrayList<unsigned long> *);
	int IntersectLineSegments(float, float, float, float, float, float, float, float, float *, float *);
	int LoadWalkMesh();
	int NoNonWalkPolysOnTile(float, float, float, float, float, float, float);
	int PlotIntraTilePath(CNWArea *, CPathfindInformation *, float, float, float, float, unsigned long);
	int RemoveDoor(unsigned long);
	int SetFlaggedAsProblem();
	int SetHasPlaceableWithWalkMesh();
	int SetMainLightColorChange(int);
	int SetMainLightColor(unsigned char, unsigned char);
	int SetSourceLightColorChange(int);
	int SetSourceLightColor(unsigned char, unsigned char);
	int SetTileData(CNWTileData *);
	~CNWSTile();
	CNWSTile();

};
#endif
