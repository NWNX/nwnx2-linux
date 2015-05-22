#ifndef _CNWSBARTER_H_
#define _CNWSBARTER_H_
#include "nwndef.h"

class CNWSBarter
{
public:
    int AddItem(unsigned long, unsigned char &, unsigned char &);
    void CleanUp();
    unsigned char GetState();
    int MoveItem(unsigned long, unsigned char &, unsigned char &);
    int PullItemOut(unsigned long);
    int RemoveItem(unsigned long, unsigned char &, unsigned char &);
    void Reset(unsigned long, int);
    int SetListAccepted(int);
    int SetListLocked(int);
    ~CNWSBarter();
    CNWSBarter(CNWSCreature *);

    /* 0x0/0 */ unsigned long ItemRepository;
    /* 0x4/4 */ unsigned long LUOInventory;
    /* 0x8/8 */ unsigned long LUOInventory2;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ unsigned long field_14;
    /* 0x18/24 */ unsigned long field_18;
    /* 0x1C/28 */ unsigned long Creature1;
    /* 0x20/32 */ void *Creature2;
    /* 0x24/36 */ unsigned long field_24;
};
#endif
