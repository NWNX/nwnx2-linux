#ifndef _CTWODIMARRAYS_H_
#define _CTWODIMARRAYS_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoLinkedList.h"

class CTwoDimArrays
{
public:
    void ClearCached2DAs();
    C2DA * GetCached2DA(CExoString, int);
    unsigned char GetEpicAttackBonus(unsigned char);
    unsigned char GetEpicFortSaveBonus(unsigned char);
    unsigned char GetEpicRefSaveBonus(unsigned char);
    unsigned char GetEpicWillSaveBonus(unsigned char);
    C2DA * GetIPRPCostTable(unsigned char);
    int Load2DArrays();
    int LoadEpicAttacks();
    int LoadEpicSaves();
    int LoadIPRPCostTables();
    int UnLoad2DArrays();
    int UnLoadIPRPCostTables();
    int Update2DACache(CExoLinkedList<C2DA> *, int, C2DA *);
    ~CTwoDimArrays();
    CTwoDimArrays();

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ char EpicAB[60];
    /* 0x40/64 */ char EpicSavesFort[60];
    /* 0x7C/124 */ char EpicSavesWill[60];
    /* 0xB8/184 */ char EpicSavesReflex[60];
    /* 0xF4/244 */ unsigned long field_F4;
    /* 0xF8/248 */ C2DA* appearance;
    /* 0xFC/252 */ C2DA* gender;
    /* 0x100/256 */ C2DA* surfacemat;
    /* 0x104/260 */ C2DA* loadscreens;
    /* 0x108/264 */ C2DA* vfx_persistent;
    /* 0x10C/268 */ C2DA* creaturespeed;
    /* 0x110/272 */ C2DA* doortypes;
    /* 0x114/276 */ C2DA* genericdoors;
    /* 0x118/280 */ C2DA* placeables;
    /* 0x11C/284 */ C2DA* iprp_spells;
    /* 0x120/288 */ C2DA* iprp_lightcost;
    /* 0x124/292 */ C2DA* iprp_color;
    /* 0x128/296 */ C2DA* iprp_meleecost;
    /* 0x12C/300 */ C2DA* itempropdef;
    /* 0x130/304 */ C2DA* itemprops;
    /* 0x134/308 */ C2DA* creaturesize;
    /* 0x138/312 */ C2DA* armor;
    /* 0x13C/316 */ C2DA* portraits;
    /* 0x140/320 */ C2DA* capart;
    /* 0x144/324 */ C2DA* armourtypes;
    /* 0x148/328 */ C2DA* tilecolor;
    /* 0x14C/332 */ C2DA* lightcolor;
    /* 0x150/336 */ C2DA* replacetexture;
    /* 0x154/340 */ C2DA* tailmodel;
    /* 0x158/344 */ C2DA* wingmodel;
    /* 0x15C/348 */ C2DA* cloakmodel;
    /* 0x160/352 */ C2DA* cursors;
    /* 0x164/356 */ C2DA* actions;
    /* 0x168/360 */ C2DA* ambientmusic;
    /* 0x16C/364 */ C2DA* ambientsound;
    /* 0x170/368 */ C2DA* footstepsounds;
    /* 0x174/372 */ C2DA* appearancesndset;
    /* 0x178/376 */ C2DA* weaponsounds;
    /* 0x17C/380 */ C2DA* defaultacsounds;
    /* 0x180/384 */ C2DA* ammunitiontypes;
    /* 0x184/388 */ C2DA* keymap;
    /* 0x188/392 */ C2DA* placeableobjsnds;
    /* 0x18C/396 */ C2DA* damagelevels;
    /* 0x190/400 */ C2DA* effecticons;
    /* 0x194/404 */ C2DA* loadhints;
    /* 0x198/408 */ C2DA* swearfilter;
    /* 0x19C/412 */ C2DA* phenotype;
    /* 0x1A0/416 */ C2DA* statescripts;
    /* 0x1A4/420 */ C2DA* visualeffects;
    /* 0x1A8/424 */ C2DA* traps;
    /* 0x1AC/428 */ C2DA* spellschools;
    /* 0x1B0/432 */ C2DA* poison;
    /* 0x1B4/436 */ C2DA* disease;
    /* 0x1B8/440 */ C2DA* repadjust;
    /* 0x1BC/444 */ C2DA* fractionalcr;
    /* 0x1C0/448 */ C2DA* categories;
    /* 0x1C4/452 */ C2DA* excitedduration;
    /* 0x1C8/456 */ C2DA* restduration;
    /* 0x1CC/460 */ C2DA* encdifficulty;
    /* 0x1D0/464 */ C2DA* iprp_monstcost;
    /* 0x1D4/468 */ C2DA* hen_companion;
    /* 0x1D8/472 */ C2DA* hen_familiar;
    /* 0x1DC/476 */ C2DA* iprp_damagecost;
    /* 0x1E0/480 */ C2DA* skillvsitemcost;
    /* 0x1E4/484 */ C2DA* iprp_bonuscost;
    /* 0x1E8/488 */ C2DA* iprp_srcost;
    /* 0x1EC/492 */ C2DA* iprp_neg5cost;
    /* 0x1F0/496 */ C2DA* iprp_arcspell;
    /* 0x1F4/500 */ C2DA* encumbrance;
    /* 0x1F8/504 */ C2DA* parts_belt;
    /* 0x1FC/508 */ C2DA* parts_bicep;
    /* 0x200/512 */ C2DA* parts_chest;
    /* 0x204/516 */ C2DA* parts_foot;
    /* 0x208/520 */ C2DA* parts_forearm;
    /* 0x20C/524 */ C2DA* parts_hand;
    /* 0x210/528 */ C2DA* parts_legs;
    /* 0x214/532 */ C2DA* parts_neck;
    /* 0x218/536 */ C2DA* parts_pelvis;
    /* 0x21C/540 */ C2DA* parts_shin;
    /* 0x220/544 */ C2DA* parts_shoulder;
    /* 0x224/548 */ C2DA* parts_robe;
    /* 0x228/552 */ C2DA* itemvalue;
    /* 0x22C/556 */ C2DA* packages;
    /* 0x230/560 */ C2DA* xptable;
    /* 0x234/564 */ C2DA* ranges;
    /* 0x238/568 */ C2DA* polymorph;
    /* 0x23C/572 */ C2DA* iprp_onhit;
    /* 0x240/576 */ C2DA* iprp_onhitspell;
    /* 0x244/580 */ C2DA* iprp_onhitdur;
    /* 0x248/584 */ C2DA* damagehitvisual;
    /* 0x24C/588 */ C2DA* iprp_acmodtype;
    /* 0x250/592 */ C2DA* iprp_weightinc;
    /* 0x254/596 */ C2DA* bodybag;
    /* 0x258/600 */ C2DA* iprp_feats;
    /* 0x25C/604 */ CExoLinkedList<C2DA>* Cache1;
    /* 0x260/608 */ unsigned long Cache1Length;
    /* 0x264/612 */ CExoLinkedList<C2DA>* Cache2;
    /* 0x268/616 */ unsigned long Cache2Length;

};

static_assert_size(CTwoDimArrays, 0x26C);

#endif
