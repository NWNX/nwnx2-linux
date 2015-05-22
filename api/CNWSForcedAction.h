#ifndef _CNWSFORCEDACTION_H_
#define _CNWSFORCEDACTION_H_
#include "nwndef.h"

class CNWSForcedAction
{
public:
    int LoadForcedAction(CResGFF *, CResStruct *);
    int SaveForcedAction(CResGFF *, CResStruct *);
    ~CNWSForcedAction();
    CNWSForcedAction();

};
#endif
