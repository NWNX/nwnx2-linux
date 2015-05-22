#ifndef _CCOMBATINFORMATION_H_
#define _CCOMBATINFORMATION_H_
#include "nwndef.h"

class CCombatInformation
{
public:
    int LoadData(CResGFF *, CResStruct *);
    int SaveData(CResGFF *, CResStruct *);
    ~CCombatInformation();
    CCombatInformation();
    CCombatInformation & operator=(CCombatInformation &);
    int operator==(CCombatInformation &);
    int operator!=(CCombatInformation &);

};
#endif
