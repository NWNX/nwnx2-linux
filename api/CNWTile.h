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

};
#endif
