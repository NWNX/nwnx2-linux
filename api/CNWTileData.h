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
	int GetSurfaceMesh();
	int SetCornerType(unsigned char, CExoString, int);
	int SetEdgeType(unsigned char, CExoString);
	int SetMapIcon(CResRef);
	int SetModelResRef(CResRef);
	int SetNumDoors(unsigned char);
	~CNWTileData();
	CNWTileData();

};
#endif
