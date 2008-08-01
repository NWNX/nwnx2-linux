/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#ifndef _NX_NWN_STRUCT_CTWODIMARRAYS_
#define _NX_NWN_STRUCT_CTWODIMARRAYS_

struct CTwoDimArrays_s {
    u_int32_t           field_000;

    int8_t              tda_epic_ab[60];        /* 0004 */

    int8_t              tda_epic_save_fort[60]; /* 0040 */
    int8_t              tda_epic_save_will[60]; /* 007C */
    int8_t              tda_epic_save_ref[60];  /* 00B8 */

    u_int32_t           field_0F4;

    C2DA               *tda_appearance;         /* 00F8 */
    C2DA               *tda_gender;             /* 00FC */
    C2DA               *tda_surfacemat;         /* 0100 */
    C2DA               *tda_loadscreens;        /* 0104 */
    C2DA               *tda_vfx_persistent;     /* 0108 */
    C2DA               *tda_creaturespeed;      /* 010C */
    C2DA               *tda_doortypes;          /* 0110 */
    C2DA               *tda_genericdoors;       /* 0114 */
    C2DA               *tda_placeables;         /* 0118 */
    C2DA               *tda_iprp_spells;        /* 011C */
    C2DA               *tda_iprp_lightcost;     /* 0120 */
    C2DA               *tda_iprp_color;         /* 0124 */
    C2DA               *tda_iprp_meleecost;     /* 0128 */
    C2DA               *tda_itempropdef;        /* 012C */
    C2DA               *tda_itemprops;          /* 0130 */
    C2DA               *tda_creaturesize;       /* 0134 */
    C2DA               *tda_armor;              /* 0138 */
    C2DA               *tda_portraits;          /* 013C */
    C2DA               *tda_capart;             /* 0140 */
    C2DA               *tda_armourtypes;        /* 0144 */
    C2DA               *tda_tilecolor;          /* 0148 */
    C2DA               *tda_lightcolor;         /* 014C */
    C2DA               *tda_replacetexture;     /* 0150 */
    C2DA               *tda_tailmodel;          /* 0154 */
    C2DA               *tda_wingmodel;          /* 0158 */
    C2DA               *tda_cloakmodel;         /* 015C */
    C2DA               *tda_cursors;            /* 0160 */
    C2DA               *tda_actions;            /* 0164 */
    C2DA               *tda_ambientmusic;       /* 0168 */
    C2DA               *tda_ambientsound;       /* 016C */
    C2DA               *tda_footstepsounds;     /* 0170 */
    C2DA               *tda_appearancesndset;   /* 0174 */
    C2DA               *tda_weaponsounds;       /* 0178 */
    C2DA               *tda_defaultacsounds;    /* 017C */
    C2DA               *tda_ammunitiontypes;    /* 0180 */
    C2DA               *tda_keymap;             /* 0184 */
    C2DA               *tda_placeableobjsnds;   /* 0188 */
    C2DA               *tda_damagelevels;       /* 018C */
    C2DA               *tda_effecticons;        /* 0190 */
    C2DA               *tda_loadhints;          /* 0194 */
    C2DA               *tda_swearfilter;        /* 0198 */
    C2DA               *tda_phenotype;          /* 019C */
    C2DA               *tda_statescripts;       /* 01A0 */
    C2DA               *tda_visualeffects;      /* 01A4 */
    C2DA               *tda_traps;              /* 01A8 */
    C2DA               *tda_spellschools;       /* 01AC */
    C2DA               *tda_poison;             /* 01B0 */
    C2DA               *tda_disease;            /* 01B4 */
    C2DA               *tda_repadjust;          /* 01B8 */
    C2DA               *tda_fractionalcr;       /* 01BC */
    C2DA               *tda_categories;         /* 01C0 */
    C2DA               *tda_excitedduration;    /* 01C4 */
    C2DA               *tda_restduration;       /* 01C8 */
    C2DA               *tda_encdifficulty;      /* 01CC */
    C2DA               *tda_iprp_monstcost;     /* 01D0 */
    C2DA               *tda_hen_companion;      /* 01D4 */
    C2DA               *tda_hen_familiar;       /* 01D8 */
    C2DA               *tda_iprp_damagecost;    /* 01DC */
    C2DA               *tda_skillvsitemcost;    /* 01E0 */
    C2DA               *tda_iprp_bonuscost;     /* 01E4 */
    C2DA               *tda_iprp_srcost;        /* 01E8 */
    C2DA               *tda_iprp_neg5cost;      /* 01EC */
    C2DA               *tda_iprp_arcspell;      /* 01F0 */
    C2DA               *tda_encumbrance;        /* 01F4 */
    C2DA               *tda_parts_belt;         /* 01F8 */
    C2DA               *tda_parts_bicep;        /* 01FC */
    C2DA               *tda_parts_chest;        /* 0200 */
    C2DA               *tda_parts_foot;         /* 0204 */
    C2DA               *tda_parts_forearm;      /* 0208 */
    C2DA               *tda_parts_hand;         /* 020C */
    C2DA               *tda_parts_legs;         /* 0210 */
    C2DA               *tda_parts_neck;         /* 0214 */
    C2DA               *tda_parts_pelvis;       /* 0218 */
    C2DA               *tda_parts_shin;         /* 021C */
    C2DA               *tda_parts_shoulder;     /* 0220 */
    C2DA               *tda_parts_robe;         /* 0224 */
    C2DA               *tda_itemvalue;          /* 0228 */
    C2DA               *tda_packages;           /* 022C */
    C2DA               *tda_xptable;            /* 0230 */
    C2DA               *tda_ranges;             /* 0234 */
    C2DA               *tda_polymorph;          /* 0238 */
    C2DA               *tda_iprp_onhit;         /* 023C */
    C2DA               *tda_iprp_onhitspell;    /* 0240 */
    C2DA               *tda_iprp_onhitdur;      /* 0244 */
    C2DA               *tda_damagehitvisual;    /* 0248 */
    C2DA               *tda_iprp_acmodtype;     /* 024C */
    C2DA               *tda_iprp_weightinc;     /* 0250 */
    C2DA               *tda_bodybag;            /* 0254 */
    C2DA               *tda_iprp_feats;         /* 0258 */

    CExoLinkedList     *tda_cache_1;            /* 025C */
    int32_t            *tda_cache_1_len;        /* 0260 */

    CExoLinkedList     *tda_cache_2;            /* 0264 */
    int32_t            *tda_cache_2_len;        /* 0268 */
};

#endif /* _NX_NWN_STRUCT_CTWODIMARRAYS_ */

/* vim: set sw=4: */
