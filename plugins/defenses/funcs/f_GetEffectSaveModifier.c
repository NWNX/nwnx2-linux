
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


void Func_GetEffectSaveModifier(CGameObject *ob, char *value)
{
    int i, save, savetype, saveflag, durtype, val = 0;
    int total_inc_all = 0, total_inc_save = 0, total_inc_savetype = 0;
    int total_dec_all = 0, total_dec_save = 0, total_dec_savetype = 0;
    const CGameEffect *eff;
    const CNWSObject *obj;
    const CNWSCreature *cre;

    if (ob == NULL                                                 ||
            (obj = ob->vtable->AsNWSObject(ob)) == NULL                ||
            sscanf(value, "%d %d %d", &save, &saveflag, &durtype) != 3 ||
            save < 0 || save > 3) {

        snprintf(value, strlen(value), "0");
        return;
    }

    cre      = ob->vtable->AsNWSCreature(ob);
    savetype = (saveflag < 0 ? -saveflag : saveflag) & 0xFF;

    for (i = 0; i < obj->obj_effects_len; i++) {
        if ((eff = obj->obj_effects[i]) == NULL)
            continue;

        if (eff->eff_type != EFFECT_TRUETYPE_SAVING_THROW_INCREASE &&
                eff->eff_type != EFFECT_TRUETYPE_SAVING_THROW_DECREASE)
            continue;

        if (durtype >= 0 && (eff->eff_dursubtype & DURATION_TYPE_MASK) != durtype)
            continue;

        if (eff->eff_integers[1] != 0 && eff->eff_integers[1] != save)
            continue;

        if (eff->eff_integers[2] != 0 && eff->eff_integers[2] != savetype) {
#ifdef NWNX_DEFENSES_HG
            if ((saveflag & 1024) && eff->eff_integers[2] == SAVING_THROW_TYPE_TRAP) {
                /* do nothing; the trap bonus will fall through as a savetype bonus */
            } else
#endif
                continue;
        }

        if (eff->eff_type == EFFECT_TRUETYPE_SAVING_THROW_INCREASE) {
            if (eff->eff_integers[2] != 0)
                total_inc_savetype += eff->eff_integers[0];
            else if (eff->eff_integers[1] != 0)
                total_inc_save     += eff->eff_integers[0];
            else
                total_inc_all      += eff->eff_integers[0];
        } else {
            if (eff->eff_integers[2] != 0)
                total_dec_savetype += eff->eff_integers[0];
            else if (eff->eff_integers[1] != 0)
                total_dec_save     += eff->eff_integers[0];
            else
                total_dec_all      += eff->eff_integers[0];
        }
    }

    if (cre != NULL && cre->cre_stats != NULL) {
        if (savetype == SAVING_THROW_TYPE_POISON &&
                CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_PRESTIGE_POISON_SAVE_1)) {

            total_inc_savetype = total_inc_all + total_inc_save + total_inc_savetype +
                                 (nwn_GetLevelByClass(cre->cre_stats, CLASS_TYPE_ASSASSIN) / 2);
            total_inc_all      = 0;
            total_inc_save     = 0;
        } else {
            if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_SACRED_DEFENSE_1))
                total_inc_all += nwn_GetLevelByClass(cre->cre_stats, CLASS_TYPE_DIVINECHAMPION) / 2;
        }
    }

    if ((total_inc_all = total_inc_all + total_inc_save + total_inc_savetype) > 20)
        total_inc_all = 20;
    if ((total_dec_all = total_dec_all + total_dec_save + total_dec_savetype) > 20)
        total_dec_all = 20;

#ifdef NWNX_DEFENSES_HG
    if (((saveflag & 512) || savetype == SAVING_THROW_TYPE_SPELL) && total_inc_savetype < 25) {
        if (cre != NULL && cre->cre_stats != NULL) {
            total_inc_savetype += CNWSCreatureStats__GetSkillRank(cre->cre_stats, SKILL_SPELLCRAFT, NULL, 0) / 5;

            if (total_inc_savetype > 25)
                total_inc_savetype = 25;
        }
    }

    if (total_inc_savetype > total_inc_all)
        total_inc_all = (total_inc_savetype > 30 ? 30 : total_inc_savetype);
    if (total_inc_save > total_inc_all)
        total_inc_all = (total_inc_save     > 25 ? 25 : total_inc_save);

    if (total_dec_savetype > total_dec_all)
        total_dec_all = (total_dec_savetype > 30 ? 30 : total_dec_savetype);
    if (total_dec_save > total_dec_all)
        total_dec_all = (total_dec_save     > 25 ? 25 : total_dec_save);
#endif

    val = total_inc_all - total_dec_all;

    if (saveflag != 0 && cre != NULL && cre->cre_stats != NULL) {
        switch (savetype) {
            case SAVING_THROW_TYPE_DISEASE:
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_RESIST_DISEASE))
                    val += 4;
                break;

            case SAVING_THROW_TYPE_DEATH:
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_STRONG_SOUL))
                    val += 1;
                break;

            case SAVING_THROW_TYPE_FEAR:
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_FEARLESS))
                    val += 2;
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_RESIST_NATURES_LURE))
                    val += 2;
                break;

            case SAVING_THROW_TYPE_MIND_SPELLS:
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_HARDINESS_VERSUS_ENCHANTMENTS))
                    val += 2;
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_HARDINESS_VERSUS_ILLUSIONS))
                    val += 2;
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_LLIIRAS_HEART))
                    val += 2;
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_STILL_MIND))
                    val += 2;
                break;

            case SAVING_THROW_TYPE_POISON:
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_HARDINESS_VERSUS_POISONS))
                    val += 2;
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_SNAKE_BLOOD))
                    val += 2;
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_RESIST_POISON))
                    val += 4;
                break;
        }

        if (savetype == SAVING_THROW_TYPE_SPELL || (saveflag & 512)) {
            if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_HARDINESS_VERSUS_SPELLS))
                val += 2;
        }

        if (savetype == SAVING_THROW_TYPE_TRAP || (saveflag & 1024)) {
            if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_DENEIRS_EYE))
                val += 2;
            if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_PRESTIGE_DEFENSIVE_AWARENESS_3))
                val += 1;

            if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_UNCANNY_DODGE_1)) {
                if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_UNCANNY_DODGE_6))
                    val += 5;
                else if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_UNCANNY_DODGE_5))
                    val += 4;
                else if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_UNCANNY_DODGE_4))
                    val += 3;
                else if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_UNCANNY_DODGE_3))
                    val += 2;
                else if (CNWSCreatureStats__HasFeat(cre->cre_stats, FEAT_UNCANNY_DODGE_2))
                    val += 1;
            }
        }
    }

    snprintf(value, strlen(value), "%d", val);
}


/* vim: set sw=4: */
