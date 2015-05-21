
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


int Hook_GetWeaponFinesse(CNWSCreatureStats *info, CNWSItem *weapon)
{
    if (!CNWSCreatureStats__HasFeat(info, FEAT_WEAPON_FINESSE))
        return 0;

    return GetIsWeaponLight(info, weapon, true);
}


/* vim: set sw=4: */
