#ifndef _CNWTILESETMANAGER_H_
#define _CNWTILESETMANAGER_H_
#include "nwndef.h"
#include "nwnstructs.h"
#include "CResRef.h"
#include "CNWTileSet.h"

class CNWTileSetManager
{
public:
	void ClearTilePathNodes();
	int ComputePathNodeInformation(unsigned char, int, int &, int &, float **, float **, int **);
	int ComputePathNodeRotation(int, float *, float *);
	CNWTilePathNode * GetTilePathNode(unsigned char, unsigned char);
	int InitializeTilePathNodes();
	CNWTileSet * RegisterTileSet(CResRef);
	void UnregisterTileSet(CNWTileSet *);
	~CNWTileSetManager();
	CNWTileSetManager();

};
#endif
