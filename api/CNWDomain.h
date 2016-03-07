#ifndef _CNWDOMAIN_H_
#define _CNWDOMAIN_H_
#include "nwndef.h"

class CNWDomain
{
public:
    int GetDescriptionText();
    int GetNameText();
    ~CNWDomain();
    CNWDomain();

    /* 0x0/0 */ unsigned long NameStrref;
    /* 0x4/4 */ unsigned long DescriptionStrref;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ unsigned long field_14;
    /* 0x18/24 */ unsigned long field_18;
    /* 0x1C/28 */ unsigned long field_1C;
    /* 0x20/32 */ unsigned long field_20;
    /* 0x24/36 */ unsigned long field_24;
    /* 0x28/40 */ unsigned long field_28;
    /* 0x2C/44 */ unsigned long field_2C;
    /* 0x30/48 */ unsigned long field_30;
    /* 0x34/52 */ unsigned long field_34;
    /* 0x38/56 */ unsigned long field_38;
    /* 0x3C/60 */ unsigned long field_3C;
    /* 0x40/64 */ unsigned long field_40;
    /* 0x44/68 */ unsigned long field_44;
    /* 0x48/72 */ unsigned long field_48;

};

static_assert_size(CNWDomain, 0x4C);

#endif
