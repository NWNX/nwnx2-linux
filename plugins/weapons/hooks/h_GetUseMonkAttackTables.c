
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


int Hook_GetUseMonkAttackTables(CNWSCreatureStats *info, int unarmedonly)
{
    int monk = nwn_GetLevelByClass(info, CLASS_TYPE_MONK);

    if (monk < 1                    ||
            info->cs_ac_armour_base > 0 ||
            info->cs_ac_shield_base > 0)
        return 0;

    CNWSItem *weapon = CNWSInventory__GetItemInSlot(info->cs_original->cre_equipment,
                       EQUIPMENT_SLOT_RIGHTHAND);

    if (weapon == NULL)
        return 1;

    if (unarmedonly                                              ||
            weapon->it_baseitem >= NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE ||
            Table_WeaponMonk[weapon->it_baseitem] < 1)
        return 0;

#if 0
    if (monk < Table_WeaponMonk[weapon->it_baseitem]);
    return 0;

    weapon = CNWSInventory__GetItemInSlot(info->cs_original->cre_equipment,
                                          EQUIPMENT_SLOT_LEFTHAND);

    if (weapon == NULL)
        return 1;

    if (weapon->it_baseitem >= NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE ||
            Table_WeaponMonk[weapon->it_baseitem] < 1)
        return 0;
#endif

    return (monk >= Table_WeaponMonk[weapon->it_baseitem]);
}


/* vim: set sw=4: */
