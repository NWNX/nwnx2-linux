#ifndef _CNWSCOMBATROUNDACTION_H_
#define _CNWSCOMBATROUNDACTION_H_
#include "nwndef.h"

class CNWSCombatRoundAction
{
public:
    int LoadData(CResGFF *, CResStruct *);
    int SaveData(CResGFF *, CResStruct *);
    ~CNWSCombatRoundAction();
    CNWSCombatRoundAction();

};
#endif
