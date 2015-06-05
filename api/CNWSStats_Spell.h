#ifndef _CNWSSTATS_SPELL_H_
#define _CNWSSTATS_SPELL_H_
#include "nwndef.h"

class CNWSStats_Spell
{
public:
    CNWSStats_Spell();

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ char field_8;
    /* 0xC/12 */ char rsvd1[3];
    /* 0xC/12 */ unsigned long field_C;
};
#endif
