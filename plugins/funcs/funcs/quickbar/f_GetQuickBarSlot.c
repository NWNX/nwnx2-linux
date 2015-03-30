
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


void Func_GetQuickBarSlot (CGameObject *ob, char *value) {
    int slot;
    const CNWSCreature *cre;

    if (ob == NULL                                    ||
        (cre = ob->vtable->AsNWSCreature(ob)) == NULL ||
        !cre->cre_is_pc                               ||
        cre->cre_quickbar == NULL                     ||
        (slot = atoi(value)) < 0 || slot >= 36) {

        snprintf(value, strlen(value), "-1");
        return;
    }

    snprintf(value, strlen(value), "%d %d %d %d %d", slot,
        cre->cre_quickbar[slot].qb_type,
        cre->cre_quickbar[slot].qb_class,
        cre->cre_quickbar[slot].qb_id,
        cre->cre_quickbar[slot].qb_metamagic);
}


/* vim: set sw=4: */
