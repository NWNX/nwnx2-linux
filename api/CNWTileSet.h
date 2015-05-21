#ifndef _CNWTILESET_H_
#define _CNWTILESET_H_
#include "nwndef.h"
#include "CResRef.h"

class CNWTileSet
{
public:
    int GetCornerType(int, unsigned char, unsigned char);
    int GetEdgeType(int, unsigned char, unsigned char);
    int GetEnvMapResRef();
    int GetGrassAmbientColor();
    int GetGrassDensity();
    int GetGrassDiffuseColor();
    int GetGrassHeight();
    int GetGrassTexture();
    int GetHasGrass();
    float GetHeightTransition();
    CNWTileData * GetTileData(int);
    int GetTileSetName();
    int LoadTileSet();
    int ParseLine(char *);
    int SetTileValue(char *, char *);
    int UnloadTileSet();
    ~CNWTileSet();
    CNWTileSet(CResRef, int);

};
#endif
