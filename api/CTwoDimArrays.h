#ifndef _CTWODIMARRAYS_H_
#define _CTWODIMARRAYS_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoLinkedList.h"

class CTwoDimArrays
{
public:
	int ClearCached2DAs();
	int GetCached2DA(CExoString, int);
	int GetEpicAttackBonus(unsigned char);
	int GetEpicFortSaveBonus(unsigned char);
	int GetEpicRefSaveBonus(unsigned char);
	int GetEpicWillSaveBonus(unsigned char);
	int GetIPRPCostTable(unsigned char);
	int Load2DArrays();
	int LoadEpicAttacks();
	int LoadEpicSaves();
	int LoadIPRPCostTables();
	int UnLoad2DArrays();
	int UnLoadIPRPCostTables();
	int Update2DACache(CExoLinkedList<C2DA> *, int, C2DA *);
	~CTwoDimArrays();
	CTwoDimArrays();

};
#endif
