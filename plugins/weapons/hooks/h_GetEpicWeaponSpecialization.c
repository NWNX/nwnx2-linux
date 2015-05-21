
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


int Hook_GetEpicWeaponSpecialization(CNWSCreatureStats *info, CNWSItem *weapon)
{
    int feat = 0;

    if (weapon == NULL)
        feat = Table_WeaponEpicSpecialization[BASE_ITEM_GLOVES];
    else if (weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE)
        feat = Table_WeaponEpicSpecialization[weapon->it_baseitem];

    return (feat ? CNWSCreatureStats__HasFeat(info, feat) : 0);
}


/* vim: set sw=4: */
