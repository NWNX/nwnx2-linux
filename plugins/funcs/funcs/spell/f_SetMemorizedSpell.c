
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


void Func_SetMemorizedSpell(CGameObject *ob, char *value)
{
    int i, sp_class, sp_level, sp_idx, sp_spell, sp_meta, sp_flags;
    CNWSCreature *cre;
    CNWSStats_Spell *sp;

    if (ob == NULL                                    ||
            (cre = ob->vtable->AsNWSCreature(ob)) == NULL ||
            cre->cre_stats == NULL                        ||
            sscanf(value, "%d %d %d %d %d %d", &sp_class, &sp_level, &sp_idx, &sp_spell, &sp_meta, &sp_flags) != 6 ||
            sp_level < 0 || sp_level > 9 || sp_idx < 0) {

        snprintf(value, strlen(value), "-1");
        return;
    }


    /* find the requested class, then alter the requested memorized spell */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        if (sp_idx >= cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].len)
            break;

        if (sp_spell < 0) {
            if (cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx] != NULL)
                free(cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx]);

            cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx] = NULL;
        } else {
            if ((sp = cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx]) == NULL) {
                if ((sp = calloc(1, sizeof(*sp))) == NULL)
                    break;

                cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx] = sp;
            }

            sp->sp_id     = sp_spell;
            sp->sp_meta   = sp_meta;
            sp->sp_ready  = !!(sp_flags & 1);
            sp->sp_domain = !!(sp_flags & 2);
        }

        return;
    }


    snprintf(value, strlen(value), "-1");
}


/* vim: set sw=4: */
