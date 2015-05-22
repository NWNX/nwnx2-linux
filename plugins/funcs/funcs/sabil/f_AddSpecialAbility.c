
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

struct CExoArrayList_SA_s; typedef struct CExoArrayList_SA_s CExoArrayList_SA;
NX_NWN_CEXOARRAYLIST(SA, CNWSStats_SpecAbil);


void Func_AddSpecialAbility(CGameObject *ob, char *value)
{
    int i, sa_spell, sa_level, sa_flags;
    CExoArrayList_SA *sa;
    CNWSStats_SpecAbil sa_new;
    CNWSCreature *cre;

    if (ob == NULL                                    ||
            (cre = ob->vtable->AsNWSCreature(ob)) == NULL ||
            cre->cre_stats == NULL                        ||
            (sa = cre->cre_stats->cs_specabil) == NULL    ||
            sscanf(value, "%d %d %d", &sa_spell, &sa_level, &sa_flags) != 3) {

        snprintf(value, strlen(value), "-1");
        return;
    }

    memset(&sa_new, 0, sizeof(sa_new));
    sa_new.sa_id    = sa_spell;
    sa_new.sa_level = sa_level;
    sa_new.sa_flags = sa_flags;

    for (i = 0; i < sa->len; i++) {
        if (sa->data[i].sa_id < 0) {
            sa->data[i] = sa_new;
            break;
        }
    }

    if (i >= sa->len)
        CExoArrayList_SA_add(sa, sa_new);

    snprintf(value, strlen(value), "%d", sa->len);
}


/* vim: set sw=4: */
