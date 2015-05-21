
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


int Local_GetDamageBonusAdjustment(CNWSCreatureStats *attacker, CNWSItem *weapon, int adj)
{
#ifdef NWNX_WEAPONS_HG
    if (attacker->cs_original != NULL && attacker->cs_original->cre_is_pc) {
        int i, j, bit_bonus = 0, dice_bonus = 0;
        int str_bonus = 0, dex_bonus = 0, con_bonus = 0;
        int int_bonus = 0, wis_bonus = 0, cha_bonus = 0;
        int skill_bonus = 0, misc_bonus[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        const CGameEffect *eff;
        const CNWSCreature *cre = attacker->cs_original;

        for (i = 0; i < cre->obj.obj_effects_len; i++) {
            if ((eff = cre->obj.obj_effects[i]) == NULL)
                continue;

            if (eff->eff_type != EFFECT_TRUETYPE_SPELL_IMMUNITY)
                continue;

            if (eff->eff_integers[0] == 746) {
                bit_bonus |= 2;
            } else if (eff->eff_integers[0] == 747) {
                bit_bonus |= 8;
            } else if (eff->eff_integers[0] == 748) {
                int pct = eff->eff_integers[2];
                if (pct <= 0 || pct >= 255)
                    pct = 100;

                switch (eff->eff_integers[1]) {
                    case 1: str_bonus = (attacker->cs_str_mod > 0 ? ((attacker->cs_str_mod * pct) / 100) : 0); break;
                    case 3: con_bonus = (attacker->cs_con_mod > 0 ? ((attacker->cs_con_mod * pct) / 100) : 0); break;
                    case 4: int_bonus = (attacker->cs_int_mod > 0 ? ((attacker->cs_int_mod * pct) / 100) : 0); break;
                    case 5: wis_bonus = (attacker->cs_wis_mod > 0 ? ((attacker->cs_wis_mod * pct) / 100) : 0); break;
                    case 6: cha_bonus = (attacker->cs_cha_mod > 0 ? ((attacker->cs_cha_mod * pct) / 100) : 0); break;

                    case 2:
                        dex_bonus = CNWSCreatureStats__GetDEXMod(attacker, 0);
                        if (dex_bonus <= 0)
                            dex_bonus = 0;
                        else
                            dex_bonus = (dex_bonus * pct) / 100;
                        break;

                    default:
                        if (eff->eff_integers[1] >= 100 && eff->eff_integers[1] <= 127) {
                            j = (CNWSCreatureStats__GetSkillRank(attacker, eff->eff_integers[1] - 100, NULL, 0) * pct) / 100;
                            if (j > skill_bonus)
                                skill_bonus = j;
                        }
                        break;
                }
            } else if (eff->eff_integers[0] == 749 && eff->eff_integers[1] > 0 && eff->eff_integers[2] > 0) {
                dice_bonus = eff->eff_integers[1];

                for (j = 0; j < eff->eff_integers[1]; j++)
                    dice_bonus += random() % eff->eff_integers[2];
            } else if (eff->eff_integers[0] == 750 && eff->eff_integers[2] >= 0 && eff->eff_integers[2] <= 7) {
                if (eff->eff_integers[1] > misc_bonus[eff->eff_integers[2]])
                    misc_bonus[eff->eff_integers[2]] = eff->eff_integers[1];
            }
        }

        adj += (bit_bonus + dice_bonus + skill_bonus +
                str_bonus + dex_bonus + con_bonus +
                int_bonus + wis_bonus + cha_bonus +
                misc_bonus[0] + misc_bonus[1] + misc_bonus[2] + misc_bonus[3] +
                misc_bonus[4] + misc_bonus[5] + misc_bonus[6] + misc_bonus[7]);
    }
#endif

    return adj;
}


/* vim: set sw=4: */
