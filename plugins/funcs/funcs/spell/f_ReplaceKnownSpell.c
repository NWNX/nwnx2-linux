
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


void Func_ReplaceKnownSpell(CGameObject *ob, char *value)
{
    int i, j, k, sp_class, sp_id, sp_new;
    CNWSCreature *cre;

    if (ob == NULL                                    ||
            (cre = ob->vtable->AsNWSCreature(ob)) == NULL ||
            cre->cre_stats == NULL                        ||
            sscanf(value, "%d %d %d", &sp_class, &sp_id, &sp_new) != 3) {

        snprintf(value, strlen(value), "-1");
        return;
    }


    /* Iterate their class list, matching the requested class, then iterate the spells
     * known list for that class. If the spell is found, remove it. */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        for (j = 0; j < 10; j++) {
            k = CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[j]), sp_id);

            if (k > 0) {
                cre->cre_stats->cs_classes[i].cl_spells_known[j].data[k - 1] = sp_new;

                snprintf(value, strlen(value), "%d", j);
                return;
            }
        }
    }


    snprintf(value, strlen(value), "-1");
}


/* vim: set sw=4: */
