
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


int Local_GetACEquipAdjustment(CNWSCreatureStats *stats, int touch, int adj)
{
#ifdef NWNX_DEFENSES_HG
    if (!touch) {
        int i;

        /* Insurmountable Protection feats */
        for (i = 3105; i <= 3109; i++) {
            if (CNWSCreatureStats__HasFeat(stats, i))
                adj += 2;
        }

        /* cap shield AC for large/tower shields */
        if (stats->cs_ac_shield_base > 1 && stats->cs_ac_armour_base < 6) {
            int dex = CNWSCreatureStats__GetDEXMod(stats, 1);

            if (stats->cs_ac_shield_base == 3) {
                if (dex > (11 - stats->cs_ac_armour_base))
                    adj -= dex - (11 - stats->cs_ac_armour_base);
            } else if (stats->cs_ac_shield_base == 2) {
                if (dex > (18 - stats->cs_ac_armour_base))
                    adj -= dex - (18 - stats->cs_ac_armour_base);
            }
        }
    }

#endif

    return adj;
}


/* vim: set sw=4: */
