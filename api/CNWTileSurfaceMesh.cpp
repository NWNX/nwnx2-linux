#include "CNWTileSurfaceMesh.h"

int CNWTileSurfaceMesh::CheckAABBNodeOneWay(int, CNWTileSurfaceMeshAABBNode *, Vector const &, Vector &)
{
    asm("leave");
    asm("mov $0x0808bbcc, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::CheckAABBNode(int, CNWTileSurfaceMeshAABBNode *, Vector const &, Vector &)
{
    asm("leave");
    asm("mov $0x0808b6c0, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::ClearLineOfSightOneWay(int, Vector, Vector, Vector *)
{
    asm("leave");
    asm("mov $0x080935b0, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::ClearLineOfSight(int, Vector, Vector, Vector *)
{
    asm("leave");
    asm("mov $0x08093540, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::ClearSubdivision()
{
    asm("leave");
    asm("mov $0x0808b5fc, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::ClippedLineSegmentWalkable(CNWTile *, float, float, float, float, float *, float *, float *, float *, float *, float *)
{
    asm("leave");
    asm("mov $0x0808a790, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::ComputeClippedLineSegment(CNWTile *, float, float, float, float, float *, float *, float *, float *)
{
    asm("leave");
    asm("mov $0x0808afcc, %eax");
    asm("jmp *%eax");
}

float CNWTileSurfaceMesh::ComputeHeight(Vector)
{
    asm("leave");
    asm("mov $0x0808b410, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::ComputePathNodes()
{
    asm("leave");
    asm("mov $0x08093620, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::ComputeTriangleAdjacency()
{
    asm("leave");
    asm("mov $0x0808bd98, %eax");
    asm("jmp *%eax");
}

unsigned char CNWTileSurfaceMesh::ConvertToTileOrientation(int)
{
    asm("leave");
    asm("mov $0x08093e64, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::EstimateDistanceToTarget(float, float)
{
    asm("leave");
    asm("mov $0x08093680, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::FindClosestRegion(CNWTile *, float, float, unsigned char, int)
{
    asm("leave");
    asm("mov $0x0808c1e8, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::FindRegionViaTriangle(int, int, int *, int *)
{
    asm("leave");
    asm("mov $0x0808c3f4, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::FindTriangle(int, int, float, float, int)
{
    asm("leave");
    asm("mov $0x0808c4e0, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GenerateBestIntraTileExit(CNWTile *, CNWArea *, CPathfindInformation *, float, float)
{
    asm("leave");
    asm("mov $0x0808c788, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetDoorVisNodeOrientation()
{
    asm("leave");
    asm("mov $0x08094264, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetDoorVisNode()
{
    asm("leave");
    asm("mov $0x0809424c, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetExitNumber(float, float)
{
    asm("leave");
    asm("mov $0x0808d6c0, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetExit(int, float *, float *, int *)
{
    asm("leave");
    asm("mov $0x08093718, %eax");
    asm("jmp *%eax");
}

int * CNWTileSurfaceMesh::GetLOSMaterials()
{
    asm("leave");
    asm("mov $0x0808a6d0, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetNumTriangles()
{
    asm("leave");
    asm("mov $0x08094104, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetPathNodeOrientation()
{
    asm("leave");
    asm("mov $0x080937a0, %eax");
    asm("jmp *%eax");
}

unsigned char CNWTileSurfaceMesh::GetPathNode()
{
    asm("leave");
    asm("mov $0x08093794, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetRegionCoords(int, float *, float *, unsigned char, int)
{
    asm("leave");
    asm("mov $0x080937ac, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetRegionEntrance(float, float, unsigned char, int)
{
    asm("leave");
    asm("mov $0x0809380c, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetSurfaceMaterial(Vector)
{
    asm("leave");
    asm("mov $0x080934ec, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetTopLevelVertexGeometry(int, float *, float *, float *)
{
    asm("leave");
    asm("mov $0x080938cc, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetTotalExits()
{
    asm("leave");
    asm("mov $0x0809392c, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::GetTriangleAdjacency(int, int, int *, int *, int *)
{
    asm("leave");
    asm("mov $0x08093958, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::GetTriangleCentroid(int, float *, float *, float *)
{
    asm("leave");
    asm("mov $0x080939c0, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::GetTriangleVertices(int, int, int *, int *, int *)
{
    asm("leave");
    asm("mov $0x08093a44, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetVertexGeometry(int, Vector *)
{
    asm("leave");
    asm("mov $0x08093ae0, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetVertexGeometry(int, float *, float *, float *)
{
    asm("leave");
    asm("mov $0x08093aa4, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetVisibilityNodeOrientation()
{
    asm("leave");
    asm("mov $0x08094258, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetVisibilityNode()
{
    asm("leave");
    asm("mov $0x08094240, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetWalkMesh()
{
    asm("leave");
    asm("mov $0x08093b18, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::GetWalkTileHashTable()
{
    asm("leave");
    asm("mov $0x08094110, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::IntersectLineSegments(Vector, Vector, Vector, Vector, Vector *)
{
    asm("leave");
    asm("mov $0x0808d818, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::IntraTileDFSGenerateSuccessors(int, CNWTile *, CNWArea *, float, float, int, CPathfindInformation *, CPathfindInfoIntraTileSuccessors **)
{
    asm("leave");
    asm("mov $0x0808e1cc, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::IntraTileDFS(CNWTile *, CNWArea *, CPathfindInformation *, int, float, int, float, float, float, float, float, int)
{
    asm("leave");
    asm("mov $0x0808dcfc, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::LoadDefaultWalkMesh()
{
    asm("leave");
    asm("mov $0x0808fd50, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::LoadWalkMeshString(unsigned char **, unsigned long *, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08093ddc, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::LoadWalkMesh()
{
    asm("leave");
    asm("mov $0x08090134, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::NoNonWalkPolysOnTile(float, float, float, float, float, float, float)
{
    asm("leave");
    asm("mov $0x08092148, %eax");
    asm("jmp *%eax");
}

unsigned long CNWTileSurfaceMesh::PlotIntraTilePath(CNWTile *, CNWArea *, CPathfindInformation *, float, float, float, float, unsigned long, int)
{
    asm("leave");
    asm("mov $0x080929e8, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::PolyHit(Vector const *, int, Vector const &, Vector const &, Vector const &, float, Vector *)
{
    asm("leave");
    asm("mov $0x0808b940, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::PrintAABBTreeToPrintLog(CNWTileSurfaceMeshAABBNode *, int)
{
    asm("leave");
    asm("mov $0x0808ffdc, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::RunSubdivision(int *, int, float *, int, int *, int *, int, float *, int, int *)
{
    asm("leave");
    asm("mov $0x08092f88, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::SetDoorVisNodeOrientation(int)
{
    asm("leave");
    asm("mov $0x080941c0, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::SetDoorVisNode(unsigned char)
{
    asm("leave");
    asm("mov $0x08094130, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::SetPathNodeOrientation(int)
{
    asm("leave");
    asm("mov $0x08094270, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::SetPathNode(unsigned char)
{
    asm("leave");
    asm("mov $0x08093e54, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::SetVisibilityNodeOrientation(int)
{
    asm("leave");
    asm("mov $0x08094140, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::SetVisibilityNode(unsigned char)
{
    asm("leave");
    asm("mov $0x08094120, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::SetWalkMesh(CResRef)
{
    asm("leave");
    asm("mov $0x08093ed8, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::SetWalkTileHashTable(CNWTileSurfaceMeshHashTableEntry *)
{
    asm("leave");
    asm("mov $0x080942f0, %eax");
    asm("jmp *%eax");
}

void CNWTileSurfaceMesh::Subdivide()
{
    asm("leave");
    asm("mov $0x0809329c, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::TestLineForWalkableOnArea(float, float, float, float, float, float, CPathfindInformation *, CNWTile *, CNWArea *)
{
    asm("leave");
    asm("mov $0x08093cb0, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMesh::TestLineForWalkableOnTile(float, float, float, float, float *, float *, CPathfindInformation *, CNWTile *, int)
{
    asm("leave");
    asm("mov $0x08093b38, %eax");
    asm("jmp *%eax");
}

