#ifndef _CNWPLACEMESHMANAGER_H_
#define _CNWPLACEMESHMANAGER_H_
#include "nwndef.h"

class CNWPlaceMeshManager
{
public:
	int ClearWalkMeshes();
	int GetWalkMesh(int);
	int InitializeWalkMeshes(int);
	~CNWPlaceMeshManager();
	CNWPlaceMeshManager();

};
#endif
