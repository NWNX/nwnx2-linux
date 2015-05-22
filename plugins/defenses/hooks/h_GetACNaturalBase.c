
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


int Hook_GetACClassAdjustment(CNWSCreatureStats *stats, int touch)
{
    int adj = 0;

#ifndef NWNX_DEFENSES_HG
    if (!touch) {
        if (CNWSCreatureStats__HasFeat(stats, FEAT_DRAGON_ARMOR)) {
            int rdd = nwn_GetLevelByClass(stats, CLASS_TYPE_DRAGONDISCIPLE);

            switch (rdd) {
                case  0: adj += 0; break;
                case  1: adj += 1; break;
                case  2: adj += 1; break;
                case  3: adj += 1; break;
                case  4: adj += 1; break;
                case  5: adj += 2; break;
                case  6: adj += 2; break;
                case  7: adj += 2; break;
                case  8: adj += 3; break;
                case  9: adj += 3; break;

                default: adj += 4 + ((rdd - 10) / 5); break;
            }
        }

        if (CNWSCreatureStats__HasFeat(stats, FEAT_BONE_SKIN_2)) {
            int pm = nwn_GetLevelByClass(stats, CLASS_TYPE_PALEMASTER) / 4;

            adj += 2 + (pm * 2);
        }
    }
#endif

    return Local_GetACClassAdjustment(stats, touch, adj);
}


int Hook_GetACFeatAdjustment(CNWSCreatureStats *stats, int touch)
{
    int adj = 0;

    if (!touch && CNWSCreatureStats__HasFeat(stats, FEAT_EPIC_ARMOR_SKIN))
        adj += 2;

    return Local_GetACFeatAdjustment(stats, touch, adj);
}


int Hook_GetACWisAdjustment(CNWSCreatureStats *stats, int touch)
{
    int adj = 0;

#ifndef NWNX_DEFENSES_HG
    if (stats->cs_ac_armour_base == 0 &&
            stats->cs_ac_shield_base == 0 &&
            CNWSCreatureStats__HasFeat(stats, FEAT_MONK_AC_BONUS)) {

        int monk = nwn_GetLevelByClass(stats, CLASS_TYPE_MONK);

        adj = (stats->cs_wis_mod > 0 ? stats->cs_wis_mod : 0) + (monk / 5);
    }
#endif

    return Local_GetACWisAdjustment(stats, touch, adj);
}


int Hook_GetACNaturalBase(CNWSCreatureStats *stats, int touch)
{
    int bonus = 0;

    if (stats == NULL)
        return 0;

    if (touch)
        bonus = Local_GetACTouchBase(stats);
    else
        bonus = stats->cs_ac_natural_base;

    bonus += Hook_GetACClassAdjustment(stats,  touch)    +
             Hook_GetACFeatAdjustment(stats,   touch)    +
             Hook_GetACWisAdjustment(stats,    touch)    +
             Local_GetACSkillAdjustment(stats, touch, 0) +
             Local_GetACEquipAdjustment(stats, touch, 0) +
             Local_GetACStrAdjustment(stats,   touch, 0) +
             Local_GetACDexAdjustment(stats,   touch, 0) +
             Local_GetACConAdjustment(stats,   touch, 0) +
             Local_GetACIntAdjustment(stats,   touch, 0) +
             Local_GetACChaAdjustment(stats,   touch, 0);

    return bonus;
}


/* vim: set sw=4: */
