
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


void Func_GetAllMemorizedSpells(CGameObject *ob, char *value)
{
    int i, j, k, ret, sp_save, sp_len;
    char *p = value;
    size_t len = strlen(value);
    CNWSCreature *cre;
    CNWSStats_Spell *sp;

    *value = 0;
    if (ob == NULL || (cre = ob->vtable->AsNWSCreature(ob)) == NULL || cre->cre_stats == NULL)
        return;


    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        for (j = 0; j <= 9; j++) {
            if ((sp_len = cre->cre_stats->cs_classes[i].cl_spells_max[j]) < 1) {
                if ((sp_len = cre->cre_stats->cs_classes[i].cl_spells_mem[j].len) < 1)
                    continue;
            }

            VALUE_APPEND(p, ret, len, "*%d ", (i << 8) | (j & 0xFF));

            if (cre->cre_stats->cs_classes[i].cl_class == CLASS_TYPE_BARD ||
                    cre->cre_stats->cs_classes[i].cl_class == CLASS_TYPE_SORCERER) {

                VALUE_APPEND(p, ret, len, "#%d ", cre->cre_stats->cs_classes[i].cl_spells_left[j]);
                continue;
            }

            for (k = 0; k < sp_len; k++) {
                if ((sp = CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[i].cl_spells_mem[j]), k)) != NULL)
                    sp_save = ((!!sp->sp_domain) << 25) | ((!!sp->sp_ready) << 24) | ((sp->sp_meta & 0xFF) << 16) | (sp->sp_id & 0xFFFF);
                else
                    sp_save = 0xFFFFFF;

                VALUE_APPEND(p, ret, len, "%X ", sp_save);
            }
        }
    }
}


/* vim: set sw=4: */
