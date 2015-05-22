
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


bool GetIsWeaponLight(CNWSCreatureStats *info, CNWSItem *weapon, bool finesse)
{
    int rel;

    if (GetIsUnarmedWeapon(weapon))
        return true;

    if (info->cs_original == NULL                        ||
            info->cs_original->cre_size < CREATURE_SIZE_TINY ||
            info->cs_original->cre_size > CREATURE_SIZE_HUGE)
        return false;

    if (finesse                                                 &&
            weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE &&
            Table_WeaponFinesseSize[weapon->it_baseitem] > 0        &&
            info->cs_original->cre_size >= Table_WeaponFinesseSize[weapon->it_baseitem])
        return true;

    rel = CNWSCreature__GetRelativeWeaponSize(info->cs_original, weapon);

    /* ensure Small beings can finesse Small weapons still */
    if (finesse && info->cs_original->cre_size < 3)
        return (rel <= 0);

    return (rel < 0);
}


/* vim: set sw=4: */
