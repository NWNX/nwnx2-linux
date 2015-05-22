#ifndef _CTWODIMARRAYS_H_
#define _CTWODIMARRAYS_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoLinkedList.h"

class CTwoDimArrays
{
public:
    void ClearCached2DAs();
    C2DA * GetCached2DA(CExoString, int);
    unsigned char GetEpicAttackBonus(unsigned char);
    unsigned char GetEpicFortSaveBonus(unsigned char);
    unsigned char GetEpicRefSaveBonus(unsigned char);
    unsigned char GetEpicWillSaveBonus(unsigned char);
    C2DA * GetIPRPCostTable(unsigned char);
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
