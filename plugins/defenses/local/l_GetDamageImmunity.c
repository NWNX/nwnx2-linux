
/***************************************************************************
    NWNXFuncs.cpp - Implementation of the CNWNXFuncs class.
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include "NWNXDefenses.h"


#ifdef NWNX_DEFENSES_HG
#define NWNX_EXALT_GET_ABSTYPE(P)       ((P >> 12) & 0x0F)

static inline bool Hook_MatchAbsoluteImmunityType(CNWSCreature *cre, int damtypeindex)
{
    if (!(cre->cre_stats->cs_age & 0x80000000))
        return false;

    int abstype = NWNX_EXALT_GET_ABSTYPE(cre->cre_stats->cs_age);

    switch (abstype) {
        case 1:  return (!cre->cre_is_pc && damtypeindex == 0);
        case 2:  return (!cre->cre_is_pc && damtypeindex == 1);
        case 3:  return (!cre->cre_is_pc && damtypeindex == 2);
        case 4:  return (damtypeindex == 4);
        case 5:  return (damtypeindex == 5);
        case 6:  return (damtypeindex == 7);
        case 7:  return (damtypeindex == 11);
        case 8:  return (!cre->cre_is_pc && damtypeindex == 6);
        case 9:  return (!cre->cre_is_pc && damtypeindex == 3);
        case 10: return (!cre->cre_is_pc && damtypeindex == 9);
        case 11: return (!cre->cre_is_pc && damtypeindex == 10);
        case 12: return (!cre->cre_is_pc && 0); /* physical */
        case 13: return (!cre->cre_is_pc && 0); /* elemental */
        case 14: return (!cre->cre_is_pc && 0); /* exotic */
        case 15: return (!cre->cre_is_pc);
        default: return (damtypeindex == 8);
    }

    return false;
}
#endif


int Local_GetDamageImmunity(CNWSCreature *cre, int damtypeindex, int imm)
{
#ifdef NWNX_DEFENSES_HG
    if (cre->obj.obj_type == OBJECT_TYPE_CREATURE && cre->cre_stats != NULL) {
        int rdd = nwn_GetLevelByClass(cre->cre_stats, CLASS_TYPE_DRAGONDISCIPLE);

        /* RDDs receive 10% absolute immunity for every RDD level over 3, to
         * a maximum of 100% at RDD level 13. */
        if (rdd > 3 && Hook_MatchAbsoluteImmunityType(cre, damtypeindex)) {
            int min = (rdd - 3) * 10;

            imm += min;

            if (imm < min)
                imm = min;
        } else if (!cre->cre_is_pc                                    &&
                   CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_DRAGON_IMMUNE_FIRE) &&
                   Hook_MatchAbsoluteImmunityType(cre, damtypeindex)) {

            imm = 100;
        }


        /* Barbarians receive (Str modifier / 2)% physical immunity in
         * legendary levels, and Dwarven Defenders receive (Str modifier)%. */
        if (cre->cre_is_pc                                                &&
                cre->cre_lootable > 40                                        &&
                (damtypeindex == 0 || damtypeindex == 1 || damtypeindex == 2) &&
                (cre->cre_bodybag == CLASS_TYPE_BARBARIAN + 1 ||
                 cre->cre_bodybag == CLASS_TYPE_DWARVENDEFENDER + 1)) {

            int strmod = cre->cre_stats->cs_str_mod;

            if (cre->cre_bodybag == CLASS_TYPE_BARBARIAN + 1)
                strmod /= 2;

            imm += strmod;
        }
    }
#endif

    return imm;
}


/* vim: set sw=4: */
