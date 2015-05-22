
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

#define VALUE_APPEND(P, RET, LEN, ...) \
    do {                                             \
        P += (RET = snprintf(P, LEN, __VA_ARGS__));  \
        if (RET < 0 || (LEN -= RET) <= 0) {          \
            *value = 0;                              \
            return;                                  \
        }                                            \
    } while (0)


void Func_GetAllRemainingFeatUses(CGameObject *ob, char *value)
{
    int i, ret;
    char *p = value;
    size_t len = strlen(value);
    CNWSCreature *cre;
    CNWSStats_FeatUses *fu;

    *value = 0;
    if (ob == NULL || (cre = ob->vtable->AsNWSCreature(ob)) == NULL || cre->cre_stats == NULL)
        return;


    for (i = 0; i < cre->cre_stats->cs_featuses.len; i++) {
        if ((fu = CExoArrayList_ptr_get(&(cre->cre_stats->cs_featuses), i)) == NULL)
            continue;

        VALUE_APPEND(p, ret, len, "%X ", (fu->fu_used << 16) | fu->fu_feat);
    }
}


/* vim: set sw=4: */
