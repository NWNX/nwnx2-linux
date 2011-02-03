#ifndef _CRESNCS_H_
#define _CRESNCS_H_
#include "nwndef.h"
#include "CRes.h"

class CResNCS
{
public:
	int GetNCSDataPtr();
	int GetNCSSize();
	int IsLoaded();
	int OnResourceFreed();
	int OnResourceServiced();
	~CResNCS();
	CResNCS();

	/* 0x0/0 */ CRes Res;
	/* 0x2C/44 */ unsigned long m_bLoaded;
	/* 0x30/48 */ unsigned long m_nNCSNormalSize;
	/* 0x34/52 */ unsigned long m_pNCSData;
};
#endif
