
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


void Func_GetLocalVariableByPosition(CGameObject *ob, char *value)
{
    int idx = atoi(value);
    CNWSScriptVarTable *vt;

    if (ob == NULL || idx < 0) {
        *value = 0;
        return;
    }

    if (ob->type == OBJECT_TYPE_MODULE)
        vt = &(((CNWSModule *)ob)->mod_vartable);
    else if (ob->type == OBJECT_TYPE_AREA)
        vt = &(((CNWSArea *)ob)->area_vartable);
    else
        vt = &(((CNWSObject *)ob)->obj_vartable);

    if (idx >= vt->vt_len) {
        *value = 0;
        return;
    }

    snprintf(value, strlen(value), "%d¬%s", vt->vt_list[idx].var_type, vt->vt_list[idx].var_name.text);
}


/* vim: set sw=4: */
