
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


void Hook_SetDamageImmunity(CNWSCreature *cre, int damtype, int percent)
{
    int idx = 0;

    if (cre->obj.obj_damage_immunities == NULL)
        return;

    while (damtype && !(damtype & 1)) {
        idx++;
        damtype >>= 1;
    }

    if (idx >= DAMAGE_TYPE_LAST)
        return;

    if (percent < -20000)
        percent = -20000;
    else if (percent > 20000)
        percent = 20000;

    cre->obj.obj_damage_immunities[idx] = percent;
}


/* vim: set sw=4: */
