#ifndef _CNWITEM_H_
#define _CNWITEM_H_
#include "nwndef.h"

class CNWItem
{
public:
    int GetBaseItemID();
    int GetLayeredTextureColor(unsigned char);
    int SetBaseItemID(unsigned long);
    int SetLayeredTextureColor(unsigned char, unsigned char);

protected:
    ~CNWItem();
    CNWItem();

public:
    /* 0x0/0 */ unsigned char LayeredTextureColor[6];
    /* 0x6/6 */ unsigned short field_6;
    /* 0x8/8 */ unsigned long BaseItem;
    /* 0xC/12 */ Base_vtbl<CNWItem> *vptr;
};
#endif
