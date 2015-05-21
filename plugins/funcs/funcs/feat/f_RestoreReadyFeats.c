
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


void Func_RestoreReadyFeats(CGameObject *ob, char *value)
{
    int i, fu_feat, fu_used, fu_pct = 0, ret = 0;
    long val;
    char *end, *p = value;
    CNWSCreature *cre;
    CNWSStats_FeatUses *fu;

    if (ob == NULL || (cre = ob->vtable->AsNWSCreature(ob)) == NULL || cre->cre_stats == NULL) {
        snprintf(value, strlen(value), "-1");
        return;
    }

    if (*p == '%') {
        fu_pct = strtol(p + 1, &end, 10);
        p      = end;
    }

    if (strlen(p) == 0 || (strlen(p) == 1 && *p == ' ')) {
        for (i = 0; i < cre->cre_stats->cs_featuses.len; i++) {
            if ((fu = CExoArrayList_ptr_get(&(cre->cre_stats->cs_featuses), i)) != NULL) {
                fu_used = CNWSCreatureStats__GetFeatTotalUses(cre->cre_stats, fu->fu_feat);

                if (fu_pct > 0) {
                    if (fu_used == 1)
                        fu_used = !!(random() % 100 < fu_pct);
                    else
                        fu_used -= (fu_used * fu_pct) / 100;
                }

                if (fu_used < 0)
                    fu_used = 0;
                else if (fu_used > 100)
                    fu_used = 100;

                fu->fu_used = fu_used;
            }
        }

        snprintf(value, strlen(value), "0");
        return;
    }


    /* XXX: the below is O(n**2); find a way to optimize it */
    while (*p) {
        if (*p == ' ') {
            p++;
        } else {
            val     = strtol(p, &end, 16);
            p       = end + 1;
            fu_feat = val & 0xFFFF;
            fu_used = (val >> 16) & 0xFF;

            for (i = 0; i < cre->cre_stats->cs_featuses.len; i++) {
                if ((fu = CExoArrayList_ptr_get(&(cre->cre_stats->cs_featuses), i)) != NULL && fu->fu_feat == fu_feat) {
                    fu->fu_used = fu_used;
                    break;
                }
            }

            ret++;
        }
    }

    snprintf(value, strlen(value), "%d", ret);
}


/* vim: set sw=4: */
