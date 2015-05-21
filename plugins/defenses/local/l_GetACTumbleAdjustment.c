
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


int Local_GetACTumbleAdjustment(CNWSCreatureStats *stats, int adj)
{
#ifdef NWNX_DEFENSES_HG
    int other = 0;

    if (CNWSCreatureStats__HasFeat(stats, FEAT_DRAGON_ARMOR))
        other += nwn_GetLevelByClass(stats, CLASS_TYPE_DRAGONDISCIPLE) / 3;

    if (CNWSCreatureStats__HasFeat(stats, FEAT_BONE_SKIN_2)) {
        if (stats->cs_str >= 25 || stats->cs_dex >= 25)
            other += nwn_GetLevelByClass(stats, CLASS_TYPE_PALEMASTER) / 4;
        else
            other += (nwn_GetLevelByClass(stats, CLASS_TYPE_PALEMASTER) / 4) * 2;
    }

    if (other > 0) {
        int max = 12 - other;

        if (max < 6)
            max = 6;

        if (adj > max)
            adj = max;
    }
#endif

    return adj;
}


/* vim: set sw=4: */
