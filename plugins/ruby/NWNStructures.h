#ifndef NWNXStructures_h_
#define NWNXStructures_h_

typedef unsigned long dword;
typedef unsigned short int word;
typedef unsigned char byte;

#ifdef __cplusplus

#include "../../api/Vector.h"
#include "../../api/CGameEffect.h"
#include "../../api/CScriptLocation.h"

#else
typedef struct {
    char *Text;
    dword Length;
} CExoString;

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
#endif

#endif
