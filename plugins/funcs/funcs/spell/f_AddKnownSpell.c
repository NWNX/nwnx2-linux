
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


void Func_AddKnownSpell(CGameObject *ob, char *value)
{
    int i, sp_class, sp_level, sp_id;
    CNWSCreature *cre;

    if (ob == NULL                                    ||
            (cre = ob->vtable->AsNWSCreature(ob)) == NULL ||
            cre->cre_stats == NULL                        ||
            sscanf(value, "%d %d %d", &sp_class, &sp_level, &sp_id) != 3 ||
            sp_level < 0 || sp_level > 9) {

        snprintf(value, strlen(value), "-1");
        return;
    }


    /* find the requested class and level, then add the new spell */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].alloc < 1) {
            cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len  = 0;
            cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].data = NULL;
        }

        CExoArrayList_uint32_add(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id);

        snprintf(value, strlen(value), "%d", cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len);
        return;
    }


    snprintf(value, strlen(value), "-1");
}


/* vim: set sw=4: */
