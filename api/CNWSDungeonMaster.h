#ifndef _CNWSDUNGEONMASTER_H_
#define _CNWSDUNGEONMASTER_H_
#include "nwndef.h"
#include "CNWSPlayer.h"

class CNWSDungeonMaster : public CNWSPlayer
{
public:
    CNWSDungeonMaster * AsNWSDungeonMaster();
    void PossessCreature(unsigned long, unsigned char);
    ~CNWSDungeonMaster();
    CNWSDungeonMaster(unsigned long);

    /* 0x98/152 */ unsigned long field_98;
    /* 0x9C/156 */ char field_9C;
    /* 0xA0/160 */ char rsvd1[3];
    /* 0xA0/160 */ unsigned long field_A0;
    /* 0xA4/164 */ unsigned long field_A4;
};
#endif
