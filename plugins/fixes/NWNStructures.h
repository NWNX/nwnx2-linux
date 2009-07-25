#include "typedefs.h"
#include "NWNXLib.h"

#ifndef NWNXStructures_h_
#define NWNXStructures_h_
/*
struct CExoString
{
	char *Text;
	dword Length;
};
*/
struct CNWObjectVarListElement
{
    CExoString sVarName;
    dword      nVarType;
    dword       nVarValue;
};

struct CNWObjectVarList
{
	CNWObjectVarListElement *VarList;
	dword                    VarCount;
};

#endif