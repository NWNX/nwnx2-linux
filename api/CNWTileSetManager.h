#ifndef _CNWTILESETMANAGER_H_
#define _CNWTILESETMANAGER_H_
#include "nwndef.h"
#include "CResRef.h"

class CNWTileSetManager
{
public:
	int ClearTilePathNodes();
	int ComputePathNodeInformation(unsigned char, int, int &, int &, float **, float **, int **);
	int ComputePathNodeRotation(int, float *, float *);
	int GetTilePathNode(unsigned char, unsigned char);
	int InitializeTilePathNodes();
	int RegisterTileSet(CResRef);
	int UnregisterTileSet(CNWTileSet *);
	~CNWTileSetManager();
	CNWTileSetManager();

};
#endif
