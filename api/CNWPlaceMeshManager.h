#ifndef _CNWPLACEMESHMANAGER_H_
#define _CNWPLACEMESHMANAGER_H_
#include "nwndef.h"

class CNWPlaceMeshManager
{
public:
    void ClearWalkMeshes();
    CNWPlaceableSurfaceMesh * GetWalkMesh(int);
    int InitializeWalkMeshes(int);
    ~CNWPlaceMeshManager();
    CNWPlaceMeshManager();

};
#endif
