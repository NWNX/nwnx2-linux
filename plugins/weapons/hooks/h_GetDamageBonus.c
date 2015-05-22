
/***************************************************************************
    ExaltReplace.c - Implementation of NWN combat replacement functions
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


int Hook_GetDamageBonusAdjustment(CNWSCreatureStats *info, CNWSItem *weapon)
{
    int baseitem, adj = 0;

    if (info == NULL)
        return 0;

    baseitem = (weapon == NULL ? BASE_ITEM_GLOVES : weapon->it_baseitem);

    if (CNWSCreatureStats__GetEpicWeaponSpecialization(info, weapon))
        adj += 4;

    if (Table_WeaponGreaterSpecialization[baseitem] > 0 &&
            CNWSCreatureStats__HasFeat(info, Table_WeaponGreaterSpecialization[baseitem]))
        adj += Table_WeaponOptions[NWNX_WEAPONS_OPT_GRTSPEC_DAM_BONUS];

    if (Table_WeaponLegendarySpecialization[baseitem] > 0 &&
            CNWSCreatureStats__HasFeat(info, Table_WeaponLegendarySpecialization[baseitem]))
        adj += Table_WeaponOptions[NWNX_WEAPONS_OPT_LEGSPEC_DAM_BONUS];

    if (Table_WeaponParagonSpecialization[baseitem] > 0 &&
            CNWSCreatureStats__HasFeat(info, Table_WeaponParagonSpecialization[baseitem]))
        adj += Table_WeaponOptions[NWNX_WEAPONS_OPT_PARSPEC_DAM_BONUS];

    return Local_GetDamageBonusAdjustment(info, weapon, adj);
}


/* vim: set sw=4: */
