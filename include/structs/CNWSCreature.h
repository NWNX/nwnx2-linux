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

#ifndef _NX_NWN_STRUCT_CNWSCREATURE_
#define _NX_NWN_STRUCT_CNWSCREATURE_

struct CNWSCreature_s {
    CNWSObject                  obj;

    uint32_t                    cre_ponyride;           /* 01C4 */

    uint16_t                    cre_equipment_index;    /* 01C8 */

    uint16_t                    field_1CA;
    uint32_t                    field_1CC;
    uint32_t                    field_1D0;
    uint32_t                    field_1D4;
    uint32_t                    field_1D8;
    uint32_t                    field_1DC;
    uint32_t                    field_1E0;
    uint32_t                    field_1E4;
    uint32_t                    field_1E8;
    uint32_t                    field_1EC;
    uint32_t                    field_1F0;
    uint32_t                    field_1F4;

    CExoString                  cre_eventhandlers[13];  /* 01F8 */

    uint32_t                    field_260;
    uint32_t                    field_264;
    uint32_t                    field_268;
    uint32_t                    field_26C;
    uint32_t                    field_270;
    uint32_t                    field_274;
    uint32_t                    field_278;
    uint32_t                    field_27C;
    uint32_t                    field_280;
    uint32_t                    field_284;
    uint32_t                    field_288;
    uint32_t                    field_28C;
    uint32_t                    field_290;
    uint32_t                    field_294;
    uint32_t                    field_298;
    uint32_t                    field_29C;
    uint32_t                    field_2A0;
    uint32_t                    field_2A4;
    uint32_t                    field_2A8;
    uint32_t                    field_2AC;
    uint32_t                    field_2B0;
    uint32_t                    field_2B4;
    uint32_t                    field_2B8;
    uint32_t                    field_2BC;
    uint32_t                    field_2C0;
    uint32_t                    field_2C4;

    CNWSQuickbarButton         *cre_quickbar;           /* 02C8 */

    uint32_t                    cre_lootable;           /* 02CC */
    uint32_t                    cre_decaytime;          /* 02D0 */
    uint32_t                    cre_bodybag_id;         /* 02D4 */

    nwn_objid_t                 cre_desired_area;       /* 02D8 */
    Vector                      cre_desired_pos;        /* 02DC */
    uint32_t                    cre_desired_complete;   /* 02E8 */

    CExoArrayList_uint32        cre_aoe_list;           /* 02EC */
    CExoArrayList_uint32        cre_subarea_list;       /* 02F8 */

    nwn_objid_t                 cre_blocked_id;         /* 0304 */
    Vector                     *cre_blocked_pos;        /* 0308 */

    uint32_t                    field_30C;

    uint32_t                    cre_updatecombatinfo;   /* 0310 */
    uint32_t                    cre_charsheetviewers;   /* 0314 */

    uint32_t                    cre_creation_scr_exec;  /* 0318 */

    uint32_t                    cre_last_heart_time_1;  /* 031C */
    uint32_t                    cre_last_heart_time_2;  /* 0320 */

    uint32_t                    field_324;
    uint32_t                    field_328;
    uint32_t                    field_32C;

    nwn_objid_t                 cre_last_trap_detected; /* 0330 */

    uint32_t                    field_334;
    uint32_t                    field_338;
    uint32_t                    field_33C;
    uint32_t                    field_340;

    uint32_t                    cre_excited;            /* 0344 */

    uint32_t                    field_348;
    uint32_t                    field_34C;
    uint32_t                    field_350;
    uint32_t                    field_354;
    uint32_t                    field_358;

    uint32_t                    cre_pending_realization;/* 035C */

    uint32_t                    field_360;
    uint32_t                    field_364;
    uint32_t                    field_368;

    CExoArrayList_uint32        cre_action_queue;       /* 036C */

    uint32_t                    field_378;
    uint32_t                    field_37C;
    uint32_t                    field_380;
    uint32_t                    field_384;
    uint32_t                    field_388;
    uint32_t                    field_38C;
    uint32_t                    field_390;
    uint32_t                    field_394;
    uint32_t                    field_398;
    uint32_t                    field_39C;
    uint32_t                    field_3A0;
    uint32_t                    field_3A4;
    uint32_t                    field_3A8;
    uint32_t                    field_3AC;
    uint32_t                    field_3B0;
    uint32_t                    field_3B4;
    uint32_t                    field_3B8;
    uint32_t                    field_3BC;
    uint32_t                    field_3C0;
    uint32_t                    field_3C4;
    uint32_t                    field_3C8;
    uint32_t                    field_3CC;
    uint32_t                    field_3D0;
    uint32_t                    field_3D4;
    uint32_t                    field_3D8;
    uint32_t                    field_3DC;
    uint32_t                    field_3E0;
    uint32_t                    field_3E4;
    uint32_t                    field_3E8;
    uint32_t                    field_3EC;
    uint32_t                    field_3F0;
    uint32_t                    field_3F4;
    uint32_t                    field_3F8;
    uint32_t                    field_3FC;
    uint32_t                    field_400;
    uint32_t                    field_404;
    uint32_t                    field_408;
    uint32_t                    field_40C;
    uint32_t                    field_410;
    uint32_t                    field_414;
    uint32_t                    field_418;
    uint32_t                    field_41C;
    uint32_t                    field_420;
    uint32_t                    field_424;
    uint32_t                    field_428;
    uint32_t                    field_42C;
    uint32_t                    field_430;
    uint32_t                    field_434;
    uint32_t                    field_438;
    uint32_t                    field_43C;
    uint32_t                    field_440;
    uint32_t                    field_444;
    uint32_t                    field_448;
    uint32_t                    field_44C;
    uint32_t                    field_450;
    uint32_t                    field_454;
    uint32_t                    field_458;
    uint32_t                    field_45C;
    uint32_t                    field_460;
    uint32_t                    field_464;
    uint32_t                    field_468;
    uint32_t                    field_46C;
    uint32_t                    field_470;
    uint32_t                    field_474;
    uint32_t                    field_478;
    uint32_t                    field_47C;
    uint32_t                    field_480;

    uint8_t                     cre_ambient_anim_state; /* 0484 */
    uint8_t                     field_485;
    uint8_t                     field_486;
    uint8_t                     field_487;

    uint32_t                    cre_model_type;         /* 0488 */

    uint32_t                    field_48C;

    uint32_t                    cre_automap_tile_data;  /* 0490 */
    CExoArrayList_uint32        cre_automap_areas;      /* 0494 */
    uint32_t                    cre_num_areas;          /* 04A0 */

    uint32_t                    field_4A4;
    uint32_t                    field_4A8;

    uint8_t                     cre_mode_detect;        /* 04AC */
    uint8_t                     cre_mode_stealth;       /* 04AD */
    uint8_t                     cre_mode_defcast;       /* 04AE */

    uint8_t                     cre_mode_combat;        /* 04AF */
    uint8_t                     cre_mode_desired;       /* 04B0 */

    uint8_t                     field_4B1;
    uint8_t                     field_4B2;
    uint8_t                     field_4B3;

    nwn_objid_t                 cre_counterspell_target;/* 04B4 */

    uint8_t                     cre_initiative_roll;    /* 04B8 */
    uint8_t                     field_4B9;
    uint8_t                     field_4BA;
    uint8_t                     field_4BB;

    uint32_t                    cre_initiative_expired; /* 04BC */

    uint32_t                    cre_combat_state;       /* 04C0 */
    uint32_t                    cre_combat_state_timer; /* 04C4 */

    uint32_t                    cre_passive_attack_beh; /* 04C8 */

    uint32_t                    cre_has_arms;           /* 04CC */
    uint32_t                    cre_has_legs;           /* 04D0 */

    uint32_t                    cre_is_disarmable;      /* 04D4 */

    uint32_t                    cre_size;               /* 04D8 */

    float                       cre_pref_attack_dist;   /* 04D4 */
    uint32_t                    cre_weapon_scale;       /* 04E0 */

    nwn_objid_t                 cre_attack_target;      /* 04E4 */
    nwn_objid_t                 cre_attempted_target;   /* 04E8 */

    uint32_t                    field_4EC;
    uint32_t                    field_4F0;
    uint32_t                    field_4F4;

    nwn_objid_t                 cre_attacker;           /* 04F8 */

    nwn_objid_t                 cre_attempted_spell;    /* 04FC */
    nwn_objid_t                 cre_spell_target;       /* 0500 */

    uint32_t                    cre_last_ammo_warning;  /* 0504 */

    uint32_t                    field_508;
    uint32_t                    field_50C;

    nwn_objid_t                 cre_broadcast_aoo_to;   /* 0510 */

    uint32_t                    field_514;

    uint32_t                    cre_ext_combat_mode;    /* 0518 */

    int32_t                     cre_eff_bon_amt[50];    /* 051C */
    int32_t                     cre_eff_pen_amt[50];    /* 05E4 */

    int32_t                     cre_eff_bon_spid[50];   /* 06AC */
    int32_t                     cre_eff_pen_spid[50];   /* 0774 */

    int32_t                     cre_eff_bon_obj[50];    /* 083C */
    int32_t                     cre_eff_pen_obj[50];    /* 0904 */

    uint32_t                    cre_silent;             /* 09CC */
    uint32_t                    cre_hasted;             /* 09D0 */
    uint32_t                    cre_slowed;             /* 09D4 */
    uint32_t                    cre_taunted;            /* 09D8 */
    uint32_t                    cre_forced_walk;        /* 09DC */

    uint8_t                     cre_vision_type;        /* 09E0 */

    uint8_t                     cre_state;              /* 09E1 */

    uint8_t                     field_9E2;
    uint8_t                     field_9E3;

    uint32_t                    cre_current_spell;      /* 09E4 */

    CExoArrayList_uint32        cre_effect_icons;       /* 09E8 */

    uint32_t                    cre_cutscene_cam_mode;  /* 09F4 */
    float                       cre_cutscene_cam_move;  /* 09F8 */
    uint32_t                    cre_cutscene_invuln;    /* 09FC */
    uint32_t                    cre_cutscene_ghost;     /* 0A00 */

    nwn_objid_t                 cre_last_perceived;     /* 0A04 */
    uint32_t                    cre_last_perc_heard;    /* 0A08 */
    uint32_t                    cre_last_perc_seen;     /* 0A0C */
    uint32_t                    cre_last_perc_inaudible;/* 0A10 */
    uint32_t                    cre_last_perc_vanished; /* 0A14 */

    float                       cre_spot_distance;      /* 0A18 */
    float                       cre_spot_max_distance;  /* 0A1C */
    float                       cre_listen_distance;    /* 0A20 */
    float                       cre_listen_max_distance;/* 0A24 */
    float                       cre_blindsight_distance;/* 0A28 */

    uint8_t                     cre_last_hide_roll;     /* 0A2C */
    uint8_t                     cre_last_movs_roll;     /* 0A2D */
    uint8_t                     cre_last_spot_roll;     /* 0A2E */
    uint8_t                     cre_last_listen_roll;   /* 0A2F */

    CExoArrayList_ptr           cre_percepts;           /* 0A30 */

    nwn_objid_t                 cre_party_inviter;      /* 0A3C */
    uint32_t                    cre_party_invited;      /* 0A40 */
    uint32_t                    cre_party_invite_time_1;/* 0A44 */
    uint32_t                    cre_party_invite_time_2;/* 0A48 */
    CExoArrayList_uint32       *cre_party_invites;      /* 0A4C */

    uint32_t                    field_A50;

    nwn_objid_t                 cre_lock_orientation;   /* 0A54 */

    uint32_t                    cre_counterspell_id;    /* 0A58 */

    uint8_t                     cre_counterspell_class; /* 0A5C */
    uint8_t                     cre_counterspell_meta;  /* 0A5D */
    uint8_t                     cre_counterspell_domain;/* 0A5D */

    uint8_t                     field_A5F;

    CExoArrayList_uint32        cre_spell_identified;   /* 0A60 */

    nwn_objid_t                 cre_item_spell_item;    /* 0A6C */
    uint32_t                    cre_lastspellunreadied; /* 0A70 */
    uint32_t                    cre_item_spell;         /* 0A74 */
    uint32_t                    cre_item_spell_level;   /* 0A78 */
    uint32_t                    cre_item_spell_aoo;     /* 0A7C */

    nwn_objid_t                 cre_sit_object;         /* 0A80 */

    uint32_t                    cre_steal_anim_played;  /* 0A84 */
    uint32_t                    cre_steal_detected;     /* 0A88 */

    uint32_t                    cre_heal_anim_played;   /* 0A8C */
    uint32_t                    cre_trap_anim_played;   /* 0A90 */
    uint32_t                    cre_unlock_anim_played; /* 0A94 */
    uint32_t                    cre_lock_anim_played;   /* 0A98 */
    uint32_t                    cre_drop_anim_played;   /* 0A9C */
    uint32_t                    cre_pickup_anim_played; /* 0AA0 */
    uint32_t                    cre_taunt_anim_played;  /* 0AA4 */

    uint32_t                    field_AA8;
    uint32_t                    field_AAC;
    uint32_t                    field_AB0;
    uint32_t                    field_AB4;

    uint32_t                    cre_facing_done;        /* 0AB8 */

    uint32_t                    cre_ammo_mag_arrows;    /* 0ABC */
    uint32_t                    cre_ammo_mag_bolts;     /* 0AC0 */
    uint32_t                    cre_ammo_mag_bullets;   /* 0AC4 */

    uint32_t                    field_AC8;

    CNWSCombatRound            *cre_combat_round;       /* 0ACC */

    uint32_t                    field_AD0;

    uint32_t                    cre_barter;             /* 0AD4 */
    uint32_t                    cre_gold;               /* 0AD8 */
    uint32_t                    cre_is_pc;              /* 0ADC */

    uint16_t                    cre_soundset;           /* 0AE0 */
    uint16_t                    field_AE2;              /* 0AE2 */
    uint32_t                    cre_footstep;           /* 0AE4 */

    uint8_t                     cre_bodybag;            /* 0AE8 */

    uint8_t                     field_AE9;
    uint8_t                     field_AEA;
    uint8_t                     field_AEB;

    uint32_t                    cre_is_intransit;       /* 0AEC */
    uint32_t                    cre_is_poisoned;        /* 0AF0 */
    uint32_t                    cre_is_diseased;        /* 0AF4 */
    uint32_t                    cre_is_immortal;        /* 0AF8 */
    uint32_t                    cre_is_nopermdeath;     /* 0AFC */

    CExoString                  cre_display_name;       /* 0B00 */
    uint32_t                    cre_display_name_update;/* 0B08 */

    uint16_t                    cre_aistate;            /* 0B0C */   /* 0x06 = helpless; 0x01 = alive; 0x04 = free will */
    uint16_t                    cre_aistate_action;     /* 0B0E */

    nwn_objid_t                 cre_aistate_actee;      /* 0B10 */

    uint32_t                    field_B14;

    uint16_t                    cre_aistate_activities; /* 0B18 */   /* 0x08 = dialogue; 0x10 = resting */

    uint16_t                    field_B1A;

    uint32_t                    cre_activity_locked;    /* 0B1C */

    uint32_t                    field_B20;

    float                       cre_drivemode_factor;   /* 0B24 */

    uint8_t                     cre_walk_animation;     /* 0B28 */
    uint8_t                     field_B29;
    uint8_t                     field_B2A;
    uint8_t                     field_B2B;

    uint32_t                    cre_drivemode;          /* 0B2C */

    uint32_t                    cre_jumped_recently;    /* 0B30 */

    nwn_objid_t                 cre_master_id;          /* 0B34 */

    CExoArrayList_uint32       *cre_associates;         /* 0B38 */

    uint32_t                    cre_associate_type;     /* 0B3C */   /* 3 = familiar; 7 or 8 = dm */
    uint32_t                    cre_associate_command;  /* 0B40 */

    uint32_t                    cre_summoned_acomp;     /* 0B44 */
    uint32_t                    cre_summoned_famil;     /* 0B48 */

    uint32_t                    field_B4C;
    uint32_t                    field_B50;
    uint32_t                    field_B54;
    uint32_t                    field_B58;

    CExoArrayList_uint32       *cre_reputation_personal;/* 0B5C */
    CExoArrayList_uint32       *cre_reputation;         /* 0B60 */

    CExoArrayList_uint32       *cre_pvp;                /* 0B64 */

    nwn_objid_t                 cre_encounter_obj;      /* 0B68 */
    uint32_t                    cre_encounter_already;  /* 0B6C */

    CNWSInventory              *cre_equipment;          /* 0B70 */
    CItemRepository            *cre_inventory;          /* 0B74 */

    uint16_t                    cre_inventory_index;    /* 0B78 */
    uint16_t                    cre_container_index;    /* 0B7A */

    nwn_objid_t                 cre_current_container;  /* 0B7C */

    uint32_t                    cre_equipped_weight;    /* 0B80 */
    uint32_t                    cre_calc_npc_weight;    /* 0B84 */
    uint32_t                    cre_encumbrance_state;  /* 0B88 */
    uint32_t                    cre_last_pickup_failed; /* 0B8C */
    uint32_t                    cre_total_weight;       /* 0B90 */

    uint32_t                    field_B94;
    uint32_t                    field_B98;
    uint32_t                    field_B9C;
    uint32_t                    field_BA0;
    uint32_t                    field_BA4;
    uint32_t                    field_BA8;
    uint32_t                    field_BAC;
    uint32_t                    field_BB0;
    uint32_t                    field_BB4;
    uint32_t                    field_BB8;
    uint32_t                    field_BBC;
    uint32_t                    field_BC0;
    uint32_t                    field_BC4;
    uint32_t                    field_BC8;
    uint32_t                    field_BCC;
    uint32_t                    field_BD0;
    uint32_t                    field_BD4;
    uint32_t                    field_BD8;

    char                        cre_poly_portrait[16];  // if polymorphed, creature's portrait while polymorphed
    uint16_t                    cre_poly_unknown_1;     /* 0BEC */
    uint16_t                    cre_poly_unknown_2;     /* 0BEE */

    uint32_t                    cre_is_poly;            // is creature currently polymorphed ?
    uint16_t                    cre_poly_pre_appear;    // if polymorphed, creature's [pre-poly] appearance
    uint8_t                     cre_poly_pre_str;       // if polymorphed, creature's [pre-poly] strength
    uint8_t                     cre_poly_pre_con;       // if polymorphed, creature's [pre-poly] consitution
    uint8_t                     cre_poly_pre_dex;       // if polymorphed, creature's [pre-poly] dexterity

    uint8_t                     field_BF9;				/* 0BF9 */

    uint8_t                     cre_poly_pre_race;      // if polymorphed, creature's [pre-poly] race

    uint8_t                     field_BFB;				/* 0BFB */

    int16_t                     cre_poly_pre_hp;        // if polymorphed, creature's [pre-poly] hit points
    uint32_t                    cre_poly_spellid_1;     // if polymorphed, creature's 1st spell-like ability
    uint32_t                    cre_poly_spellid_2;     // if polymorphed, creature's 2nd spell-like ability
    uint32_t                    cre_poly_spellid_3;     // if polymorphed, creature's 3rd spell-like ability
    uint64_t                    cre_poly_acbonus;       // if polymorphed, creature's [pre-poly] armour class
    uint64_t                    cre_poly_hpbonus;       // if polymorphed, creature's [pre-poly] hit point bonus

    uint8_t                     cre_poly_hasprepolycp;  /* 0C1C */

    uint8_t                     field_C1D;
    uint8_t                     field_C1E;
    uint8_t                     field_C1F;

    uint32_t                    cre_is_polymorphing;    /* 0C20 */
    uint32_t                    cre_poly_locked;        /* 0C24 */

    uint32_t                    cre_appearance;         /* 0C28 */

    uint32_t                    field_C2C;
    uint32_t                    field_C30;
    uint32_t                    field_C34;
    uint32_t                    field_C38;
    uint32_t                    field_C3C;
    uint32_t                    field_C40;
    uint32_t                    field_C44;
    uint32_t                    field_C48;
    uint32_t                    field_C4C;
    uint32_t                    field_C50;
    uint32_t                    field_C54;
    uint32_t                    field_C58;
    uint32_t                    field_C5C;
    uint32_t                    field_C60;
    uint32_t                    field_C64;

    CNWSCreatureStats          *cre_stats;              /* 0C68 */
};

#endif /* _NX_NWN_STRUCT_CNWSCREATURE_ */

/* vim: set sw=4: */
