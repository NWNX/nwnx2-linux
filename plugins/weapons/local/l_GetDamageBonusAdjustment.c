
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


int Local_GetDamageBonusAdjustment (CNWSCreatureStats *attacker, CNWSItem *weapon, int adj) {
#ifdef NWNX_WEAPONS_HG
    if (attacker->cs_original != NULL && attacker->cs_original->cre_is_pc) {
        int i, bonus = 0;
        const CGameEffect *eff;
        const CNWSCreature *cre = attacker->cs_original;

        for (i = 0; i < cre->obj.obj_effects_len; i++) {
            if ((eff = cre->obj.obj_effects[i]) == NULL)
                continue;

            if (eff->eff_type != EFFECT_TRUETYPE_SPELL_IMMUNITY)
                continue;

            if (eff->eff_integers[0] == 746)
                bonus |= 2;
            else if (eff->eff_integers[0] == 747)
                bonus |= 8;
        }

        adj += bonus;
    }
#endif

    return adj;
}


/* vim: set sw=4: */
