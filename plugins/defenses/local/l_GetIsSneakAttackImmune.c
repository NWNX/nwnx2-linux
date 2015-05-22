
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


int Local_GetIsSneakAttackImmune(CNWSCreatureStats *target, uint8_t immtype, CNWSCreature *attacker)
{
#ifdef NWNX_DEFENSES_HG
    int rogue = nwn_GetLevelByClass(attacker->cre_stats, CLASS_TYPE_ROGUE);

    if (rogue >= 40                                  &&
            attacker->cre_stats->cs_ac_armour_base <= 3  &&
            !CNWSCreatureStats__HasFeat(target, FEAT_DEATHLESS_MASTERY)) {

        if (rogue > 40)
            return 0;
        if (rogue == 40 && CNWSCreatureStats__HasFeat(attacker->cre_stats, FEAT_CRIPPLING_STRIKE))
            return 0;
    }
#endif

    return -1;
}


/* vim: set sw=4: */
