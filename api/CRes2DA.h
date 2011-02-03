#ifndef _CRES2DA_H_
#define _CRES2DA_H_
#include "nwndef.h"

class CRes2DA
{
public:
	int Get2DADataPtr();
	int Get2DAHeaderPtr();
	int Get2DASize();
	int IsLoaded();
	int OnResourceFreed();
	int OnResourceServiced();
	~CRes2DA();
	CRes2DA();

};
#endif
