#ifndef _CNWSPELL_H_
#define _CNWSPELL_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CResRef.h"

class CNWSpell
{
public:
    int GetSpellHasSomaticComponent();
    int GetSpellHasVerbalComponent();
    unsigned char GetSpellLevel(unsigned char);
    int GetSpellNameText();
    unsigned long GetSubRadialSpell(unsigned char);
    int SetSubRadialSpellCount(unsigned char);
    int SetSubRadialSpell(unsigned char, unsigned long);
    ~CNWSpell();
    CNWSpell();

    /* 0x0/0 */ CExoString Label;
    /* 0x8/8 */ unsigned long Name;
    /* 0xC/12 */ unsigned long SpellDesc;
    /* 0x10/16 */ CResRef IconResRef;
    /* 0x20/32 */ unsigned long field_20;
    /* 0x24/36 */ unsigned long Range;
    /* 0x28/40 */ unsigned long field_28;
    /* 0x2C/44 */ CExoString Component;
    /* 0x34/52 */ unsigned long TargetType;
    /* 0x38/56 */ CExoString ImpactScript;
    /* 0x40/64 */ char field_40[8];
    /* 0x48/72 */ unsigned long ConjureTime;
    /* 0x4C/76 */ unsigned short ConjureAnimation;
    /* 0x4E/78 */ CResRef ConjureVisuals[3];
    /* 0x7E/126 */ CResRef ConjSoundMale;
    /* 0x8E/142 */ CResRef ConjSoundFemale;
    /* 0x9E/158 */ CResRef ConjSoundVFX;
    /* 0xAE/174 */ unsigned short CastAnimation;
    /* 0xB0/176 */ unsigned long CastTime;
    /* 0xB4/180 */ CResRef CastVisuals[3];
    /* 0xE4/228 */ CResRef CastSound;
    /* 0xF4/244 */ unsigned long field_F4;
    /* 0xF8/248 */ unsigned long field_F8;
    /* 0xFC/252 */ unsigned long field_FC;
    /* 0x100/256 */ unsigned long field_100;
    /* 0x104/260 */ unsigned long field_104;
    /* 0x108/264 */ unsigned long field_108;
    /* 0x10C/268 */ unsigned long field_10C;
    /* 0x110/272 */ unsigned long field_110;
    /* 0x114/276 */ unsigned long field_114;
    /* 0x118/280 */ unsigned long field_118;
    /* 0x11C/284 */ unsigned long field_11C;
    /* 0x120/288 */ unsigned long field_120;
    /* 0x124/292 */ unsigned long field_124;
    /* 0x128/296 */ unsigned long Innate;
    /* 0x12C/300 */ unsigned long field_12C;
    /* 0x130/304 */ unsigned long field_130;
    /* 0x134/308 */ unsigned long UseConcentration;
    /* 0x138/312 */ unsigned long nSpellID;
    /* 0x13C/316 */ unsigned long field_13C;
    /* 0x140/320 */ unsigned long field_140;
    /* 0x144/324 */ unsigned long field_144;
    /* 0x148/328 */ unsigned long field_148;
    /* 0x14C/332 */ char Metamagic;
    /* 0x150/336 */ char rsvd1[3];
    /* 0x150/336 */ unsigned long field_150;
    /* 0x154/340 */ unsigned long field_154;
    /* 0x158/344 */ unsigned long field_158;
    /* 0x15C/348 */ unsigned long field_15C;
};
#endif
