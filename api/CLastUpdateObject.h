#ifndef _CLASTUPDATEOBJECT_H_
#define _CLASTUPDATEOBJECT_H_
#include "nwndef.h"
#include "nwnstructs.h"

class CLastUpdateObject
{
public:
    void InitializeQuickbar();
    ~CLastUpdateObject();
    CLastUpdateObject();

    /* 0x0/0 */ CNWSCreatureAppearanceInfo AppearanceInfo;
    /* 0x40/64 */ unsigned long field_40;
    /* 0x44/68 */ unsigned short field_44;
    /* 0x46/70 */ unsigned short field_46;
    /* 0x48/72 */ unsigned long field_48;
};
#endif
