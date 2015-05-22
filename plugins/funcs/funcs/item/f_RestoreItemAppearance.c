
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


void Func_RestoreItemAppearance(CGameObject *ob, char *value)
{
    int idx, val, ch;
    CNWSItem *item;

    if (ob == NULL                                 ||
            (item = ob->vtable->AsNWSItem(ob)) == NULL ||
            strspn(value, "0123456789ABCDEF") != 56) {

        snprintf(value, strlen(value), "-1");
        return;
    }

    for (idx = 0; idx < 28; idx++) {
        ch = value[(idx * 2) + 2];
        value[(idx * 2) + 2] = 0;
        val = strtol(value + (idx * 2), NULL, 16);
        value[(idx * 2) + 2] = ch;

        if (idx < 6)
            item->it_color[idx] = val;
        else
            item->it_model[idx - 6] = val;
    }

    snprintf(value, strlen(value), "0");
}


/* vim: set sw=4: */
