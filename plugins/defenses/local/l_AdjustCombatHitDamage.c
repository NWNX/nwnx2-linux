
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

void Local_AdjustCombatHitDamage(CNWSCreature *attacker, CNWSCreature *target, int16_t *damages, int crit)
{
#ifdef NWNX_DEFENSES_HG

#define HGFEAT_Y_CRITICAL_REDUCTION               3000
#define HGFEAT_Z_CRITICAL_REDUCTION               3280

    int i, parry, reduce;

    if (target == NULL            ||
            target->cre_stats == NULL ||
            target->obj.obj_type != 5)
        return;

    if (!crit)
        return;

    if (CNWSCreatureStats__HasFeat(target->cre_stats, HGFEAT_Y_CRITICAL_REDUCTION) ||
            CNWSCreatureStats__HasFeat(target->cre_stats, HGFEAT_Z_CRITICAL_REDUCTION)) {

        parry = 50;
    } else {
        parry = (CNWSCreatureStats__GetSkillRank(target->cre_stats, SKILL_PARRY, NULL, 0) - 20) / 2;

        if (parry < 1)
            return;
        if (parry > 50)
            parry = 50;
    }

    for (i = 0; i < 13; i++) {
        if (damages[11 + i] >= 5) {
            reduce = (damages[11 + i] * parry) / 100;
            damages[11 + i] -= reduce;
        }
    }
#endif
}


/* vim: set sw=4: */
