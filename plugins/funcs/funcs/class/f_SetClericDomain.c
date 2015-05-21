
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


void Func_SetClericDomain(CGameObject *ob, char *value)
{
    int i, dom_idx, dom_val;
    CNWSCreature *cre;

    if (ob == NULL                                      ||
            (cre = ob->vtable->AsNWSCreature(ob)) == NULL   ||
            cre->cre_stats == NULL                          ||
            sscanf(value, "%d %d", &dom_idx, &dom_val) != 2 ||
            dom_idx < 1 || dom_idx > 2) {

        snprintf(value, strlen(value), "-1");
        return;
    }

    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class == CLASS_TYPE_CLERIC) {
            if (dom_idx == 1)
                cre->cre_stats->cs_classes[i].cl_domain_1 = dom_val;
            else
                cre->cre_stats->cs_classes[i].cl_domain_2 = dom_val;

            snprintf(value, strlen(value), "%d", dom_val);
            return;
        }
    }

    snprintf(value, strlen(value), "-1");
}


/* vim: set sw=4: */
