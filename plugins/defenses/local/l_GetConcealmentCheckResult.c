
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


int Local_GetConcealmentCheckResult(CNWSCreature *attacker, CNWSCreature *target, int concealment, int misschance)
{
#ifdef NWNX_DEFENSES_HG
    double conc, lis = 0.0;

    if (attacker == NULL            ||
            target == NULL              ||
            attacker->cre_stats == NULL ||
            target->cre_stats == NULL)
        return 0;

    if (concealment < 1 && misschance < 1)
        return 0;


    if (target->obj.obj_type == OBJECT_TYPE_CREATURE) {
        int sc = 0;

        if (target->cre_is_pc && nwn_GetLevelByClass(target->cre_stats, CLASS_TYPE_FIGHTER) > 20) {
            int parry = CNWSCreatureStats__GetSkillRank(target->cre_stats, SKILL_PARRY, NULL, 0) / 4;

            if (random() % 100 < parry)
                return 100;
        }

        int rogue = nwn_GetLevelByClass(target->cre_stats, CLASS_TYPE_ROGUE);

        if (rogue >= 30) {
            if (nwn_GetKnowsFeat(target->cre_stats, FEAT_EPIC_SELF_CONCEALMENT_50))
                sc = 5;
            else if (nwn_GetKnowsFeat(target->cre_stats, FEAT_EPIC_SELF_CONCEALMENT_40))
                sc = 4;
            else if (nwn_GetKnowsFeat(target->cre_stats, FEAT_EPIC_SELF_CONCEALMENT_30))
                sc = 3;
            else if (nwn_GetKnowsFeat(target->cre_stats, FEAT_EPIC_SELF_CONCEALMENT_20))
                sc = 2;
            else if (nwn_GetKnowsFeat(target->cre_stats, FEAT_EPIC_SELF_CONCEALMENT_10))
                sc = 1;

            if (sc > 0) {
                int percent = 0;

                switch (sc) {
                    case 1:  percent =  5; break;
                    case 2:  percent =  9; break;
                    case 3:  percent = 12; break;
                    case 4:  percent = 14; break;
                    default: percent = 15; break;
                }

                if (percent > rogue - 20)
                    percent = rogue - 20;

                sc = (sc * 10) + ((CNWSCreatureStats__GetSkillRank(target->cre_stats, SKILL_HIDE, NULL, 0) * percent) / 100);
            }
        }

        switch (concealment) {
            case 16:
            case 21:
            case 26:
            case 31:
            case 36:
                /* camouflage / mass camouflage */
                concealment = (concealment - 1) + (CNWSCreatureStats__GetSkillRank(target->cre_stats, SKILL_HIDE, NULL, 0) / 4);
                break;

            case 56: {
                /* assassin concealment */
                int hide = CNWSCreatureStats__GetSkillRank(target->cre_stats, SKILL_HIDE, NULL, 0);

                if (hide > 127)
                    hide = 127;

                concealment = (concealment - 31) + (hide / 3);
            }
            break;
        }

        if (sc > concealment)
            concealment = sc;
    }


    if (concealment > 0) {
        int i, reduction = 0;
        const CGameEffect *eff;

        for (i = 0; i < target->obj.obj_effects_len; i++) {
            if ((eff = target->obj.obj_effects[i]) == NULL)
                continue;

            if (eff->eff_type != EFFECT_TRUETYPE_SPELL_IMMUNITY)
                continue;

            if (eff->eff_integers[0] >= 3220 && eff->eff_integers[0] <= 3229) {
                int effred = eff->eff_integers[0] - 3219;

                if (effred > reduction)
                    reduction = effred;
            }
        }

        if (reduction >= concealment)
            concealment = 1;
        else
            concealment -= reduction;
    }


    /* select the greater of miss chance and concealment (they do not stack) */
    if (misschance > concealment)
        conc = misschance * 0.01;
    else
        conc = concealment * 0.01;


    if (attacker->cre_is_pc) {
        lis = CNWSCreatureStats__GetSkillRank(attacker->cre_stats, SKILL_LISTEN, NULL, 0);

        if (lis < 60.0 && CNWSCreatureStats__HasFeat(attacker->cre_stats, FEAT_BLIND_FIGHT))
            lis = 60.0;
    } else {
        if (CNWSCreatureStats__HasFeat(attacker->cre_stats, FEAT_BLIND_FIGHT))
            lis += 60.0;

        if (CNWSCreatureStats__HasFeat(attacker->cre_stats, FEAT_SKILL_FOCUS_LISTEN))
            lis += 15.0;

        if (CNWSCreatureStats__HasFeat(attacker->cre_stats, FEAT_EPIC_SKILL_FOCUS_LISTEN))
            lis += 30.0;
    }

    if (lis > 0.0) {
        int i;
        const CGameEffect *eff;

        for (i = 0; i < attacker->obj.obj_effects_len; i++) {
            if ((eff = attacker->obj.obj_effects[i]) == NULL)
                continue;

            if (eff->eff_type == EFFECT_TRUETYPE_DEAF) {
                lis *= 0.5;
                break;
            }
        }
    }


    if (!target->cre_is_pc) {
        if (CNWSCreatureStats__HasFeat(attacker->cre_stats, FEAT_SKILL_FOCUS_MOVE_SILENTLY))
            lis -= 15.0;

        if (CNWSCreatureStats__HasFeat(attacker->cre_stats, FEAT_EPIC_SKILL_FOCUS_MOVESILENTLY))
            lis -= 30.0;
    }


    if (lis > 60.0)
        lis = 60.0 + ((lis - 60.0) / 2.0);
    else if (lis < 0.0)
        lis = 0.0;

    /* ensure there are no rounding errors by adding 0.00005 - this hits
     * specifically at 85% concealment */
    concealment = (pow(conc, 1.0 + (lis / 60.0)) + 0.00005) * 1000.0;


    if (random() % 1000 < concealment)
        return concealment / 10;

    return 0;
#endif

    return -1;
}


/* vim: set sw=4: */
