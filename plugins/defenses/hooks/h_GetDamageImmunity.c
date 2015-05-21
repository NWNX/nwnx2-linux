
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


int8_t Hook_GetDamageImmunity(CNWSCreature *cre, int damtypeindex)
{
    int imm;

    if (cre->obj.obj_damage_immunities == NULL || damtypeindex < 0 || damtypeindex > DAMAGE_TYPE_LAST)
        return 0;
    imm = cre->obj.obj_damage_immunities[damtypeindex];

#ifndef NWNX_DEFENSES_HG
    if (damtypeindex == 8                         &&
            cre->obj.obj_type == OBJECT_TYPE_CREATURE &&
            cre->cre_stats != NULL                    &&
            CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_DRAGON_IMMUNE_FIRE))
        imm = 100;
#endif

    imm = Local_GetDamageImmunity(cre, damtypeindex, imm);

    if (imm > 100)
        return 100;
    if (imm < -100)
        return -100;

    return imm;
}


/* vim: set sw=4: */
