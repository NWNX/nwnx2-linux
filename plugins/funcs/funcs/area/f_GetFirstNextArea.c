
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


static int Area_Current = 0;
static CNWSModule *Area_Module = NULL;


nwn_objid_t Func_GetFirstArea(CGameObject *ob)
{
    if (Area_Module == NULL) {
        Area_Module = CServerExoAppInternal__GetModule((*NWN_AppManager)->app_server->srv_internal);

        if (Area_Module == NULL)
            return OBJECT_INVALID;
    }

    Area_Current = 0;
    return Func_GetNextArea(ob);
}


nwn_objid_t Func_GetNextArea(CGameObject *ob)
{
    if (Area_Current >= Area_Module->mod_areas_len)
        return OBJECT_INVALID;

    return Area_Module->mod_areas[Area_Current++];
}


/* vim: set sw=4: */
