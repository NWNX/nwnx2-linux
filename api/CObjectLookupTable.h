#ifndef _COBJECTLOOKUPTABLE_H_
#define _COBJECTLOOKUPTABLE_H_
#include "nwndef.h"

class CObjectLookupTable
{
public:
    int AddID(unsigned long);
    int GetIDFromIndex(unsigned long);
    int GetIndexFromID(unsigned long);
    int GetUpdate(void *, unsigned long *);
    int Touch(unsigned long);
    int Update(void *, unsigned long);
    ~CObjectLookupTable();
    CObjectLookupTable();

};
#endif
