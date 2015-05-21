
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

#include "NWNXWeapons.h"


int Local_GetCriticalMultiplierAdjustment(CNWSCreatureStats *attacker, CNWSItem *weapon, int adj)
{
#ifdef NWNX_WEAPONS_HG
    int rogue;

    if (adj == 0                                                        &&
            weapon != NULL                                                  &&
            attacker->cs_ac_armour_base <= 3                                &&
            (rogue = nwn_GetLevelByClass(attacker, CLASS_TYPE_ROGUE)) >= 35 &&
            CNWSCreatureStats__HasFeat(attacker, FEAT_CRIPPLING_STRIKE)     &&
            !CNWSCreatureStats__HasFeat(attacker, FEAT_INCREASE_MULTIPLIER) &&
            random() % 100 < rogue + 10                                     &&
            (GetIsWeaponLight(attacker, weapon, false)      ||
             weapon->it_baseitem == BASE_ITEM_LIGHTCROSSBOW ||
             weapon->it_baseitem == BASE_ITEM_MORNINGSTAR   ||
             weapon->it_baseitem == BASE_ITEM_SLING))
        return 1;
#endif

    return adj;
}


/* vim: set sw=4: */
