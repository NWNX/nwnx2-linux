#ifndef _CNWSRULES_H_
#define _CNWSRULES_H_
#include "nwndef.h"

class CNWSRules
{
public:
    ~CNWSRules();
    CNWSRules();

    /* 0x0/0 */ unsigned long PrimaryRange[5];
    /* 0x14/20 */ void *BaseItemArray;
    /* 0x18/24 */ unsigned long XP[41];
    /* 0xBC/188 */ unsigned long SpellArray;
    /* 0xC0/192 */ unsigned long field_C0;
    /* 0xD4/212 */ char rsvd1[16];
    /* 0xD4/212 */ unsigned long field_D4;
    /* 0x108/264 */ char rsvd2[48];
    /* 0x108/264 */ unsigned long field_108;
    /* 0x10C/268 */ unsigned long field_10C;
    /* 0x110/272 */ unsigned long field_110;
    /* 0x114/276 */ unsigned long field_114;
    /* 0x118/280 */ Base_vtbl<CNWSRules> *vptr;
};
#endif
