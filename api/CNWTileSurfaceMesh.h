#ifndef _CNWTILESURFACEMESH_H_
#define _CNWTILESURFACEMESH_H_
#include "nwndef.h"
#include "Vector.h"
#include "CResRef.h"

class CNWTileSurfaceMesh
{
public:
    int CheckAABBNodeOneWay(int, CNWTileSurfaceMeshAABBNode *, Vector const &, Vector &);
    int CheckAABBNode(int, CNWTileSurfaceMeshAABBNode *, Vector const &, Vector &);
    int ClearLineOfSightOneWay(int, Vector, Vector, Vector *);
    int ClearLineOfSight(int, Vector, Vector, Vector *);
    void ClearSubdivision();
    int ClippedLineSegmentWalkable(CNWTile *, float, float, float, float, float *, float *, float *, float *, float *, float *);
    int ComputeClippedLineSegment(CNWTile *, float, float, float, float, float *, float *, float *, float *);
    float ComputeHeight(Vector);
    void ComputePathNodes();
    void ComputeTriangleAdjacency();
    unsigned char ConvertToTileOrientation(int);
    int EstimateDistanceToTarget(float, float);
    int FindClosestRegion(CNWTile *, float, float, unsigned char, int);
    int FindRegionViaTriangle(int, int, int *, int *);
    int FindTriangle(int, int, float, float, int);
    int GenerateBestIntraTileExit(CNWTile *, CNWArea *, CPathfindInformation *, float, float);
    int GetDoorVisNodeOrientation();
    int GetDoorVisNode();
    int GetExitNumber(float, float);
    int GetExit(int, float *, float *, int *);
    static int * GetLOSMaterials();
    int GetNumTriangles();
    int GetPathNodeOrientation();
    unsigned char GetPathNode();
    int GetRegionCoords(int, float *, float *, unsigned char, int);
    int GetRegionEntrance(float, float, unsigned char, int);
    int GetSurfaceMaterial(Vector);
    int GetTopLevelVertexGeometry(int, float *, float *, float *);
    int GetTotalExits();
    void GetTriangleAdjacency(int, int, int *, int *, int *);
    void GetTriangleCentroid(int, float *, float *, float *);
    void GetTriangleVertices(int, int, int *, int *, int *);
    int GetVertexGeometry(int, Vector *);
    int GetVertexGeometry(int, float *, float *, float *);
    int GetVisibilityNodeOrientation();
    int GetVisibilityNode();
    int GetWalkMesh();
    int GetWalkTileHashTable();
    int IntersectLineSegments(Vector, Vector, Vector, Vector, Vector *);
    int IntraTileDFSGenerateSuccessors(int, CNWTile *, CNWArea *, float, float, int, CPathfindInformation *, CPathfindInfoIntraTileSuccessors **);
    int IntraTileDFS(CNWTile *, CNWArea *, CPathfindInformation *, int, float, int, float, float, float, float, float, int);
    void LoadDefaultWalkMesh();
    int LoadWalkMeshString(unsigned char **, unsigned long *, unsigned char *, unsigned long);
    int LoadWalkMesh();
    int NoNonWalkPolysOnTile(float, float, float, float, float, float, float);
    unsigned long PlotIntraTilePath(CNWTile *, CNWArea *, CPathfindInformation *, float, float, float, float, unsigned long, int);
    int PolyHit(Vector const *, int, Vector const &, Vector const &, Vector const &, float, Vector *);
    int PrintAABBTreeToPrintLog(CNWTileSurfaceMeshAABBNode *, int);
    void RunSubdivision(int *, int, float *, int, int *, int *, int, float *, int, int *);
    int SetDoorVisNodeOrientation(int);
    int SetDoorVisNode(unsigned char);
    int SetPathNodeOrientation(int);
    void SetPathNode(unsigned char);
    int SetVisibilityNodeOrientation(int);
    int SetVisibilityNode(unsigned char);
    void SetWalkMesh(CResRef);
    int SetWalkTileHashTable(CNWTileSurfaceMeshHashTableEntry *);
    void Subdivide();
    int TestLineForWalkableOnArea(float, float, float, float, float, float, CPathfindInformation *, CNWTile *, CNWArea *);
    int TestLineForWalkableOnTile(float, float, float, float, float *, float *, CPathfindInformation *, CNWTile *, int);
    ~CNWTileSurfaceMesh();
    CNWTileSurfaceMesh();

};
#endif
