
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


void Func_GetEffectSaveModifier (CGameObject *ob, char *value) {
    int i, save, savetype, durtype, val = 0;
    int total_inc_all = 0, total_inc_save = 0, total_inc_savetype = 0;
    int total_dec_all = 0, total_dec_save = 0, total_dec_savetype = 0;
    const CGameEffect *eff;
    const CNWSObject *obj;

    if (ob == NULL                                                 ||
        (obj = ob->vtable->AsNWSObject(ob)) == NULL                ||
        sscanf(value, "%d %d %d", &save, &savetype, &durtype) != 3 ||
        save < 0 || save > 3) {

        snprintf(value, strlen(value), "0");
        return;
    }

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

        if (eff->eff_integers[2] != 0 && eff->eff_integers[2] != savetype)
            continue;

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

    if ((total_inc_all = total_inc_all + total_inc_save + total_inc_savetype) > 20)
        total_inc_all = 20;
    if ((total_dec_all = total_dec_all + total_dec_save + total_dec_savetype) > 20)
        total_dec_all = 20;

#ifdef NWNX_DEFENSES_HG
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

    snprintf(value, strlen(value), "%d", val);
}


/* vim: set sw=4: */
