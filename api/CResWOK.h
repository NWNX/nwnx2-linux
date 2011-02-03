#ifndef _CRESWOK_H_
#define _CRESWOK_H_
#include "nwndef.h"

class CResWOK
{
public:
	int GetWOKDataPtr();
	int GetWOKSize();
	int IsLoaded();
	int OnResourceFreed();
	int OnResourceServiced();
	~CResWOK();
	CResWOK();

};
#endif
