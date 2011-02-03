#ifndef _CNWTILE_H_
#define _CNWTILE_H_
#include "nwndef.h"

class CNWTile
{
public:
	int GetAnimLoop(unsigned char *, unsigned char *, unsigned char *);
	int GetHeight();
	int GetID();
	int GetLocation(int *, int *);
	int GetMainLightColor(unsigned char *, unsigned char *);
	int GetModelPosition();
	int GetOrientation();
	int GetReplaceTexture();
	int GetSourceLightColor(unsigned char *, unsigned char *);
	int RotateCanonicalToRealTile(float, float, float *, float *);
	int RotateCanonicalToReal(float, float, float *, float *);
	int RotateRealToCanonicalTile(float, float, float *, float *);
	int RotateRealToCanonical(float, float, float *, float *);
	int SetAnimLoop(unsigned char, unsigned char, unsigned char);
	int SetID(int);
	int SetMainLightColor(unsigned char, unsigned char);
	int SetOrientation(int);
	int SetPosition(int, int, int, float);
	int SetReplaceTexture(unsigned char);
	int SetSourceLightColor(unsigned char, unsigned char);
	~CNWTile();
	CNWTile();

};
#endif
