#ifndef _CNWBASEITEMARRAY_H_
#define _CNWBASEITEMARRAY_H_
#include "nwndef.h"

class CNWBaseItemArray
{
public:
    CNWBaseItem * GetBaseItem(int) const;
    void Load();
    ~CNWBaseItemArray();
    CNWBaseItemArray();

    /* 0x0/0 */ unsigned long ItemCount;
    /* 0x4/4 */ void *ItemArray;
};
#endif
