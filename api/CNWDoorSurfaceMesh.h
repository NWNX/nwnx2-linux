#ifndef _CNWDOORSURFACEMESH_H_
#define _CNWDOORSURFACEMESH_H_
#include "nwndef.h"
#include "Vector.h"
#include "CResRef.h"

class CNWDoorSurfaceMesh
{
public:
    int GetMeshBoundingBox(Vector, Vector, Vector &, Vector &);
    int GetOpenLocation(unsigned char, unsigned char);
    int IntersectLineSegments(Vector, Vector, Vector, Vector, Vector *);
    int LoadWalkMeshString(unsigned char **, unsigned long *, unsigned char *, unsigned long);
    int LoadWalkMesh(CResRef);
    int NoNonWalkPolysOnSurfaceMesh(int, float, float, float, float, float, float, float);
    ~CNWDoorSurfaceMesh();
    CNWDoorSurfaceMesh();

};
#endif
