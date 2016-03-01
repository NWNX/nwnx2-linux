#ifndef _CNWTILE_H_
#define _CNWTILE_H_
#include "nwndef.h"

class CNWTile
{
public:
    void GetAnimLoop(unsigned char *, unsigned char *, unsigned char *);
    int GetHeight();
    int GetID();
    void GetLocation(int *, int *);
    void GetMainLightColor(unsigned char *, unsigned char *);
    int GetModelPosition();
    int GetOrientation();
    int GetReplaceTexture();
    void GetSourceLightColor(unsigned char *, unsigned char *);
    void RotateCanonicalToRealTile(float, float, float *, float *);
    void RotateCanonicalToReal(float, float, float *, float *);
    void RotateRealToCanonicalTile(float, float, float *, float *);
    void RotateRealToCanonical(float, float, float *, float *);
    void SetAnimLoop(unsigned char, unsigned char, unsigned char);
    void SetID(int);
    void SetMainLightColor(unsigned char, unsigned char);
    void SetOrientation(int);
    void SetPosition(int, int, int, float);
    void SetReplaceTexture(unsigned char);
    void SetSourceLightColor(unsigned char, unsigned char);
    ~CNWTile();
    CNWTile();

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long TileID;
    /* 0x14/20 */ unsigned long Height;
    /* 0x18/24 */ unsigned long field_18;
    /* 0x1C/28 */ unsigned long field_1C;
    /* 0x20/32 */ unsigned long Orientation;
    /* 0x24/36 */ unsigned long field_24;
    /* 0x28/40 */ unsigned char ReplaceTexture;
    /* 0x29/41 */ unsigned char field_29;
    /* 0x2A/42 */ unsigned char field_2A;
    /* 0x2B/43 */ unsigned char field_2B;
    /* 0x2C/44 */ unsigned long field_2C;
};

static_assert_size(CNWTile, 0x30);

#endif
