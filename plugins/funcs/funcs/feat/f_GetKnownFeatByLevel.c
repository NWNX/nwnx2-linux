
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


void Func_GetKnownFeatByLevel(CGameObject *ob, char *value)
{
    int level, idx;
    const CNWSCreature *cre;
    CNWLevelStats *ls;

    if (ob == NULL                                              ||
            (cre = ob->vtable->AsNWSCreature(ob)) == NULL           ||
            cre->cre_stats == NULL                                  ||
            sscanf(value, "%d %d", &level, &idx) != 2               ||
            (ls = nwn_GetLevelStats(cre->cre_stats, level)) == NULL ||
            idx < 0 || idx >= ls->ls_featlist.len) {

        snprintf(value, strlen(value), "-1");
        return;
    }

    snprintf(value, strlen(value), "%d", ls->ls_featlist.data[idx]);
}


/* vim: set sw=4: */
