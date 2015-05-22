#include <stdlib.h>
#include <string.h>
#include "CNWSScriptVarTable.h"

CNWSScriptVar *CNWSScriptVarTable::GetVarByPosition(dword nPosition)
{
    if (this->VarCount <= nPosition)
        return NULL;
    return &this->VarList[nPosition];
}


