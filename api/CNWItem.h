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
    ~CNWItem();
    CNWItem();

};
#endif
