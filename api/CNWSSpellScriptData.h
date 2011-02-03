#ifndef _CNWSSPELLSCRIPTDATA_H_
#define _CNWSSPELLSCRIPTDATA_H_
#include "nwndef.h"

class CNWSSpellScriptData
{
public:
	int LoadData(CResGFF *, CResStruct *);
	int SaveData(CResGFF *, CResStruct *);

};
#endif
