#ifndef _CRESPWK_H_
#define _CRESPWK_H_
#include "nwndef.h"

class CResPWK
{
public:
	int GetPWKDataPtr();
	int GetPWKSize();
	int IsLoaded();
	int OnResourceFreed();
	int OnResourceServiced();
	~CResPWK();
	CResPWK();

};
#endif
