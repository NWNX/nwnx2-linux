#ifndef _CGAMEEFFECT_H_
#define _CGAMEEFFECT_H_
#include "nwndef.h"
#include "CExoString.h"

class CGameEffect
{
public:
	int CopyEffect(CGameEffect *, int);
	int GetExpiryTime(unsigned long *, unsigned long *);
	int GetFloat(int);
	int GetInteger(int);
	int GetObjectID(int);
	int GetScriptEffectType();
	int GetString(int);
	int LoadGameEffect(CResGFF *, CResStruct *);
	int SaveGameEffect(CResGFF *, CResStruct *);
	int SetCreator(unsigned long);
	int SetExpiryTime(unsigned long, unsigned long);
	int SetFloat(int, float);
	int SetInteger(int, int);
	int SetLinked(CGameEffect *, CGameEffect *);
	int SetNumIntegersInitializeToNegativeOne(int);
	int SetNumIntegers(int);
	int SetObjectID(int, unsigned long);
	int SetString(int, CExoString);
	int UpdateLinked();
	~CGameEffect();
	CGameEffect(CGameEffect *, int);
	CGameEffect(int);
	int operator=(CGameEffect const &);
	int operator==(CGameEffect const &) const;
	int operator!=(CGameEffect const &) const;

	/* 0x0/0 */ unsigned long Id;
	/* 0x4/4 */ unsigned long field_4;
	/* 0x8/8 */ unsigned short Type;
	/* 0xA/10 */ unsigned short SubType;
	/* 0xC/12 */ unsigned long Duration;
	/* 0x10/16 */ unsigned long ExpireDay;
	/* 0x14/20 */ unsigned long ExpireTime;
	/* 0x18/24 */ unsigned long CreatorId;
	/* 0x1C/28 */ unsigned long SpellId;
	/* 0x20/32 */ unsigned long IsExposed;
	/* 0x24/36 */ unsigned long IsIconShown;
	/* 0x28/40 */ unsigned long CasterLevel;
	/* 0x2C/44 */ unsigned long LinkLeft;
	/* 0x30/48 */ unsigned long LinkRight;
	/* 0x34/52 */ unsigned long NumIntegers;
	/* 0x38/56 */ unsigned long IntList;
	/* 0x3C/60 */ float FloatList[4];
	/* 0x4C/76 */ CExoString StringList[6];
	/* 0x7C/124 */ unsigned long ObjectList[4];
	/* 0x8C/140 */ unsigned long SkipOnLoad;
};
#endif
