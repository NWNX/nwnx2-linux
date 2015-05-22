
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


void Func_BroadcastProjectile(CGameObject *ob, char *value)
{
    int spell, projtime;
    nwn_objid_t target_id;
    Vector target_loc;
    CNWSObject *obj;

    if (ob == NULL                                  ||
            (obj = ob->vtable->AsNWSObject(ob)) == NULL ||
            sscanf(value, "%x %f %f %f %d %d", &target_id, &(target_loc.x), &(target_loc.y), &(target_loc.z), &spell, &projtime) != 6) {
        snprintf(value, strlen(value), "0");
        return;
    }

    if (spell < 0)
        CNWSObject__BroadcastSafeProjectile(obj, obj->obj_id, target_id, obj->obj_position, target_loc, projtime, 0, 0, 0, -spell);
    else
        CNWSObject__BroadcastSafeProjectile(obj, obj->obj_id, target_id, obj->obj_position, target_loc, projtime, 6, spell, 0, 0);

    snprintf(value, strlen(value), "%d", spell);
}


/* vim: set sw=4: */
