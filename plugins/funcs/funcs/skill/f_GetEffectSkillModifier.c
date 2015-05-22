
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

#include "NWNXFuncs.h"


void Func_GetEffectSkillModifier(CGameObject *ob, char *value)
{
    int i, skill, durtype, ret = 0;
    const CGameEffect *eff;
    const CNWSObject *obj;

    if (ob == NULL                                  ||
            (obj = ob->vtable->AsNWSObject(ob)) == NULL ||
            sscanf(value, "%d %d", &skill, &durtype) != 2) {

        snprintf(value, strlen(value), "0");
        return;
    }

    for (i = 0; i < obj->obj_effects_len; i++) {
        if ((eff = obj->obj_effects[i]) == NULL)
            continue;

        if (eff->eff_type != EFFECT_TRUETYPE_SKILL_INCREASE &&
                eff->eff_type != EFFECT_TRUETYPE_SKILL_DECREASE)
            continue;

        if (durtype >= 0 && (eff->eff_dursubtype & DURATION_TYPE_MASK) != durtype)
            continue;

        if (eff->eff_integers[0] != skill)
            continue;

        if (eff->eff_type == EFFECT_TRUETYPE_SKILL_INCREASE)
            ret += eff->eff_integers[1];
        else
            ret -= eff->eff_integers[1];
    }

    snprintf(value, strlen(value), "%d", ret);
}


/* vim: set sw=4: */
