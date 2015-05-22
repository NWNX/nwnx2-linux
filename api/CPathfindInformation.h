#ifndef _CPATHFINDINFORMATION_H_
#define _CPATHFINDINFORMATION_H_
#include "nwndef.h"

class CPathfindInformation
{
public:
    void ComputeStepTolerance();
    void CreateFirstTileFValueAlternatives(int);
    void DeleteFirstTileFValueAlternatives();
    void FlipStartEndPoints();
    void FlipTempEndPoints();
    int GetFirstTileFValueAlternatives(int, int *, int *, CPathfindInfoIntraTileSuccessors **);
    void Initialize();
    void ResetAtEndOfPath();
    void ResetGridSearchData();
    void ResetInterAreaPathSearchData();
    void ResetInterAreaSearchData();
    void ResetInterTileSearchData();
    int ResetIntraTileSearchData();
    void ResetWayPointData();
    void SetFirstTileFValueAlternatives(int, int, int, CPathfindInfoIntraTileSuccessors *);
    void Shutdown();
    ~CPathfindInformation();
    CPathfindInformation();

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long someobjid;
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
    /* 0x4C/76 */ unsigned long field_4C;
    /* 0x50/80 */ unsigned long field_50;
    /* 0x54/84 */ unsigned long field_54;
    /* 0x58/88 */ unsigned long field_58;
    /* 0x5C/92 */ unsigned long field_5C;
    /* 0x60/96 */ unsigned long field_60;
    /* 0x64/100 */ unsigned long field_64;
    /* 0x68/104 */ unsigned long field_68;
    /* 0x6C/108 */ unsigned long field_6C;
    /* 0x70/112 */ unsigned long field_70;
    /* 0x74/116 */ unsigned long field_74;
    /* 0x78/120 */ unsigned long field_78;
    /* 0x7C/124 */ unsigned long field_7C;
    /* 0x80/128 */ unsigned long field_80;
    /* 0x84/132 */ unsigned long field_84;
    /* 0x88/136 */ unsigned long field_88;
    /* 0x8C/140 */ unsigned long field_8C;
    /* 0x90/144 */ unsigned long field_90;
    /* 0x94/148 */ unsigned long field_94;
    /* 0x98/152 */ unsigned long field_98;
    /* 0x9C/156 */ unsigned long field_9C;
    /* 0xA0/160 */ unsigned long field_A0;
    /* 0xA4/164 */ unsigned long field_A4;
    /* 0xA8/168 */ unsigned long field_A8;
    /* 0xAC/172 */ unsigned long field_AC;
    /* 0xB0/176 */ unsigned long field_B0;
    /* 0xB4/180 */ unsigned long field_B4;
    /* 0xB8/184 */ unsigned long field_B8;
    /* 0xBC/188 */ unsigned long field_BC;
    /* 0xC0/192 */ unsigned long field_C0;
    /* 0xC4/196 */ unsigned long field_C4;
    /* 0xC8/200 */ unsigned long field_C8;
    /* 0xCC/204 */ unsigned long field_CC;
    /* 0xD0/208 */ unsigned long field_D0;
    /* 0xD4/212 */ unsigned long field_D4;
    /* 0xD8/216 */ unsigned long field_D8;
    /* 0xDC/220 */ unsigned long field_DC;
    /* 0xE0/224 */ unsigned long field_E0;
    /* 0xE4/228 */ unsigned long field_E4;
    /* 0xE8/232 */ unsigned long field_E8;
    /* 0xEC/236 */ unsigned long field_EC;
    /* 0xF0/240 */ unsigned long field_F0;
    /* 0xF4/244 */ unsigned long field_F4;
    /* 0xF8/248 */ unsigned long field_F8;
};
#endif
