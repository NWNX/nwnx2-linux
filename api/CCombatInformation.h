#ifndef _CCOMBATINFORMATION_H_
#define _CCOMBATINFORMATION_H_
#include "nwndef.h"
#include "CResGFF.h"
#include "nwnstructs.h"

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
