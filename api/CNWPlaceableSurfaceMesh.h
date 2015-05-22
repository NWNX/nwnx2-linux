#ifndef _CNWPLACEABLESURFACEMESH_H_
#define _CNWPLACEABLESURFACEMESH_H_
#include "nwndef.h"
#include "CResRef.h"

class CNWPlaceableSurfaceMesh
{
public:
    int LoadWalkMeshString(unsigned char **, unsigned long *, unsigned char *, unsigned long);
    int LoadWalkMesh(CResRef);
    ~CNWPlaceableSurfaceMesh();
    CNWPlaceableSurfaceMesh();

};
#endif
