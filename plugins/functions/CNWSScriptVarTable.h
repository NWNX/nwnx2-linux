#ifndef CNWSScriptVarTable_H_
#define CNWSScriptVarTable_H_

#include "typedefs.h"
#include "NWNStructures.h"

#define VARIABLE_TYPE_INT      1
#define VARIABLE_TYPE_FLOAT    2
#define VARIABLE_TYPE_STRING   3
#define VARIABLE_TYPE_OBJECT   4
#define VARIABLE_TYPE_LOCATION 5

struct CScriptLocation {
    float X;
    float Y;
    float Z;
    float OrientationX;
    float OrientationY;
    float OrientationZ;
    dword AreaID;
};

struct CNWSScriptVar {
    CExoString VarName;
    dword      VarType;
    dword      VarValue;
};

class CNWSScriptVarTable
{
public:
    CNWSScriptVar *VarList;
    dword          VarCount;

    CNWSScriptVar *GetVarByPosition(dword nPosition);
};

#endif
