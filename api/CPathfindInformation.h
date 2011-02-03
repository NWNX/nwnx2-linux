#ifndef _CPATHFINDINFORMATION_H_
#define _CPATHFINDINFORMATION_H_
#include "nwndef.h"

class CPathfindInformation
{
public:
	int ComputeStepTolerance();
	int CreateFirstTileFValueAlternatives(int);
	int DeleteFirstTileFValueAlternatives();
	int FlipStartEndPoints();
	int FlipTempEndPoints();
	int GetFirstTileFValueAlternatives(int, int *, int *, CPathfindInfoIntraTileSuccessors **);
	int Initialize();
	int ResetAtEndOfPath();
	int ResetGridSearchData();
	int ResetInterAreaPathSearchData();
	int ResetInterAreaSearchData();
	int ResetInterTileSearchData();
	int ResetIntraTileSearchData();
	int ResetWayPointData();
	int SetFirstTileFValueAlternatives(int, int, int, CPathfindInfoIntraTileSuccessors *);
	int Shutdown();
	~CPathfindInformation();
	CPathfindInformation();

};
#endif
