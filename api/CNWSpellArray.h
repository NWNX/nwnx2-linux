#ifndef _CNWSPELLARRAY_H_
#define _CNWSPELLARRAY_H_
#include "nwndef.h"

class CNWSpellArray
{
public:
    CNWSpell * GetSpell(int) const;
    void Load();
    ~CNWSpellArray();
    CNWSpellArray();
    int operator[](int) const;

    /* 0x0/0 */ unsigned long SpellsLength;
    /* 0x4/4 */ CNWSpell *Spells;
};
#endif
