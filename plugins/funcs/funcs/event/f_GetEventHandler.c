
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


void Func_GetEventHandler(CGameObject *ob, char *value)
{
    int ev;

    if (ob == NULL                                    ||
            (ev = atoi(value)) < 0) {
        *value = 0;
        return;
    }

    CExoString *handlers = NULL;
    int ev_count = 0;

    if (ob->vtable->AsNWSCreature(ob)) {
        handlers = (CExoString *)&ob->vtable->AsNWSCreature(ob)->cre_eventhandlers;
        ev_count = 13;
    } else if (ob->vtable->AsNWSPlaceable(ob)) {
        handlers = (CExoString *)&ob->vtable->AsNWSPlaceable(ob)->plc_event_scripts;
        ev_count = 16;
    }

    if (!handlers || ev >= ev_count || handlers[ev].text == NULL)
        *value = 0;
    else
        snprintf(value, strlen(value), "%s", handlers[ev].text);
}


/* vim: set sw=4: */
