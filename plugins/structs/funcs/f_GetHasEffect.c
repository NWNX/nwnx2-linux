
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

#include "NWNXStructs.h"


static int GetHasEffect(const CNWSObject *obj, const nwn_objid_t eff_creator,
                        const int eff_spellid, const int eff_type, const int eff_int0)
{
    int i;
    const CGameEffect *eff;

    for (i = 0; i < obj->obj_effects_len; i++) {
        if ((eff = obj->obj_effects[i]) == NULL)
            continue;

        if (eff_creator != OBJECT_INVALID && eff->eff_creator != eff_creator)
            continue;

        if (eff_spellid >= 0 && eff->eff_spellid != eff_spellid)
            continue;

        if (eff_type >= 0 && eff->eff_type != eff_type)
            continue;

        if (eff_int0 != 0 && eff->eff_integers[0] != eff_int0)
            continue;

        return 1;
    }

    return 0;
}

void Func_GetHasEffect(CGameObject *ob, char *value)
{
    int eff_spellid, eff_type, eff_int0;
    nwn_objid_t eff_creator;
    const CNWSObject *obj;

    if (ob == NULL                                  ||
            (obj = ob->vtable->AsNWSObject(ob)) == NULL ||
            sscanf(value, "%x %d %d %d", &eff_creator, &eff_spellid, &eff_type, &eff_int0) != 4) {

        snprintf(value, strlen(value), "0");
        return;
    }

    snprintf(value, strlen(value), "%d", GetHasEffect(obj, eff_creator, eff_spellid, eff_type, eff_int0));
}


/* vim: set sw=4: */
