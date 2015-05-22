
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


int Hook_GetIsDeathAttackImmune(CNWSCreatureStats *target, uint8_t immtype, CNWSCreature *attacker)
{
    int ret = Local_GetIsDeathAttackImmune(target, immtype, attacker);

    if (ret == 0)
        return 0;

    if (ret > 0 || CNWSCreatureStats__GetEffectImmunity(target, IMMUNITY_TYPE_SNEAK_ATTACK, attacker))
        return 1;

    if (!Table_DefenseOptions[NWNX_DEFENSES_OPT_DEATHATT_IGNORE_CRIT_IMM] &&
            CNWSCreatureStats__GetEffectImmunity(target, IMMUNITY_TYPE_CRITICAL_HIT, attacker))
        return 1;

    if (CNWSCreatureStats__HasFeat(target, FEAT_DEATHLESS_MASTERY))
        return 1;

    return 0;
}


/* vim: set sw=4: */
