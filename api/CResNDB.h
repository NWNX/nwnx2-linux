#ifndef _CRESNDB_H_
#define _CRESNDB_H_
#include "nwndef.h"

class CResNDB
{
public:
	int GetNDBDataPtr();
	int GetNDBSize();
	int IsLoaded();
	int OnResourceFreed();
	int OnResourceServiced();
	~CResNDB();
	CResNDB();

};
#endif
