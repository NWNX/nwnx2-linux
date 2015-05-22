#ifndef _CNWTILEDATA_H_
#define _CNWTILEDATA_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CResRef.h"

class CNWTileData
{
public:
    int AddPropertyMethodString(unsigned long, CExoString);
    int GetCornerType(unsigned char);
    int GetEdgeType(unsigned char);
    int GetMapIcon();
    int GetModelResRef();
    int GetNumDoors();
    int GetPropertyMethodStringList(unsigned long);
    CNWTileSurfaceMesh * GetSurfaceMesh();
    void SetCornerType(unsigned char, CExoString, int);
    void SetEdgeType(unsigned char, CExoString);
    void SetMapIcon(CResRef);
    void SetModelResRef(CResRef);
    int SetNumDoors(unsigned char);
    ~CNWTileData();
    CNWTileData();

};
#endif
