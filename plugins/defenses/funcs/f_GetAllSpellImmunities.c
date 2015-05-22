
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


#define VALUE_APPEND(P, RET, LEN, ...) \
    do {                                             \
        P += (RET = snprintf(P, LEN, __VA_ARGS__));  \
        if (RET < 0 || (LEN -= RET) <= 0) {          \
            *value = 0;                              \
            return;                                  \
        }                                            \
    } while (0)


void Func_GetAllSpellImmunities(CGameObject *ob, char *value)
{
    int i, ret;
    char *p = value;
    size_t len = strlen(value);
    const CGameEffect *eff;
    const CNWSObject *obj;

    *value = 0;
    if (ob == NULL || (obj = ob->vtable->AsNWSObject(ob)) == NULL)
        return;

    for (i = 0; i < obj->obj_effects_len; i++) {
        if ((eff = obj->obj_effects[i]) == NULL)
            continue;

        if (eff->eff_type == EFFECT_TRUETYPE_SPELL_LEVEL_ABSORPTION) {
            if (eff->eff_integers[1] <= 0) {
                if (eff->eff_integers[2] == 0)
                    VALUE_APPEND(p, ret, len, "<%d ", eff->eff_integers[0]);
                else
                    VALUE_APPEND(p, ret, len, "*%d<%d ", eff->eff_integers[2], eff->eff_integers[0]);
            } else {
                if (eff->eff_integers[2] == 0)
                    VALUE_APPEND(p, ret, len, "#%d<%d ", eff->eff_integers[1], eff->eff_integers[0]);
                else
                    VALUE_APPEND(p, ret, len, "#%d*%d<%d ", eff->eff_integers[1], eff->eff_integers[2], eff->eff_integers[0]);
            }
        } else if (eff->eff_type == EFFECT_TRUETYPE_SPELL_IMMUNITY)
            VALUE_APPEND(p, ret, len, "%d ", eff->eff_integers[0]);
    }
}


/* vim: set sw=4: */
