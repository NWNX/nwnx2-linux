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

#ifndef _NX_NWN_STRUCT_CNWRULES_
#define _NX_NWN_STRUCT_CNWRULES_

struct CNWRules_s {
    u_int32_t           ru_spell_range_personal;
    u_int32_t           ru_spell_range_touch;
    u_int32_t           ru_spell_range_short;
    u_int32_t           ru_spell_range_medium;
    u_int32_t           ru_spell_range_long;

    CNWBaseItemArray   *ru_baseitems;

    u_int32_t           ru_xp_level[41];

    CNWSpellArray      *ru_spells;

    u_int32_t           field_C0;
    u_int32_t           field_C4;
    u_int32_t           field_C8;
    u_int32_t           field_CC;

    u_int16_t          *ru_sorted_feats;

    u_int16_t           ru_feats_len;           /* 00D4 */
    u_int16_t           ru_sorted_feats_len;    /* 00D6 */

    u_int8_t            ru_unknown_len;
    u_int8_t            ru_classes_len;         /* 00D9 */
    u_int8_t            ru_races_len;           /* 00DA */
    u_int8_t            ru_skills_len;          /* 00DB */
    u_int8_t            ru_domains_len;         /* 00DC */

    u_int8_t            field_DD;
    u_int8_t            field_DE;
    u_int8_t            field_DF;

    CNWClass           *ru_classes;             /* 00E0 */
    CNWRace            *ru_races;               /* 00E4 */
    CNWSkill           *ru_skills;              /* 00E8 */
    CNWDomain          *ru_domains;             /* 00EC */

    CTwoDimArrays      *ru_2das;                /* 00F0 */

    u_int32_t           ru_difficulty_1;
    u_int32_t           ru_difficulty_2;
    u_int32_t           ru_difficulty_3;
    u_int32_t           ru_difficulty_4;
    u_int32_t           ru_difficulty_5;
    u_int32_t           ru_difficulty_6;
    u_int32_t           ru_difficulty_7;
    u_int32_t           ru_difficulty_8;
    u_int32_t           ru_difficulty_9;

    void               *vtable;                 /* 0118 */
};

#endif /* _NX_NWN_STRUCT_CNWRULES_ */

/* vim: set sw=4: */
