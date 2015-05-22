#include "typedefs.h"

#ifndef NWNXStructures_h_
#define NWNXStructures_h_

#define VECTOR "vector"
#define LOCATION "location"
#define EFFECT "effect"
#define EVENT "event"
#define TALENT "talent"
#define ITEMPROPERTY "itemproperty"

typedef struct {
    char *Text;
    dword Length;
} CExoString;

struct CNWSAmbientSound {
    dword Enabled;
    dword MusicDelay;
    dword MusicDay;
    dword MusicNight;
    dword field_10;
    dword MusicBattle;
    dword field_18;
    dword AmbientSndDay;
    dword AmbientSndNight;
    byte  AmbientSndDayVol;
    byte  AmbientSndNitVol;
    byte  field_26;
    byte  field_27;
    void *CNWSAmbientSoundClass;
};

/*
00000000 CGameEffect struc ; (sizeof=0x90)
00000000 Id dd ?                                 ; size 90
00000004 field_4 dd ?
00000008 Type dw ?
0000000A SubType dw ?
0000000C field_C dd ?
00000010 ExpireDay dd ?
00000014 ExpireTime dd ?
00000018 CreatorId dd ?
0000001C SpellId dd ?
00000020 IsExposed dd ?
00000024 IsIconShown dd ?
00000028 field_28 dd ?
0000002C LinkEffectID dd ?
00000030 Link2 dd ?
00000034 NumIntegers dd ?
00000038 IntList dd ?
0000003C FloatList dd 4 dup(?)
0000004C StringList CExoString 6 dup(?)
0000007C ObjectList dd 4 dup(?)
0000008C SkipOnLoad dd ?
00000090 CGameEffect ends
*/

typedef struct {
    float X;
    float Y;
    float Z;
} Vector;

typedef struct {
    dword ID;
    dword field_4;
    dword Type;
    dword field_C;
    dword ExpireDay;
    dword ExpireTime;
    dword CreatorId;
    dword SpellId;
    dword IsExposed;
    dword IsIconShown;
    dword field_28;
    dword LinkEffectID;
    dword Link2;
    dword NumIntegers;
    int  *IntList;
    float FloatList[4];
    CExoString StringList[6];
    dword ObjectList[4];
    dword SkipOnLoad;
} CGameEffect;


typedef struct {
    float X;
    float Y;
    float Z;
    float OrientationX;
    float OrientationY;
    float OrientationZ;
    dword AreaID;
} CScriptLocation;

typedef struct {
    CExoString sVarName;
    dword      nVarType;
    dword       nVarValue;
} CNWObjectVarListElement;

typedef struct {
    CNWObjectVarListElement *VarList;
    dword                    VarCount;
} CNWObjectVarList;

#endif
