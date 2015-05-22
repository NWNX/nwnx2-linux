
/***************************************************************************
    NWNXStructs.cpp - Implementation of the CNWNXStructs class.
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

extern volatile CGameEffect *Hook_Struct_Last;
static nwn_objid_t Struct_Creator = OBJECT_INVALID;


void Func_GetCreatorRequest(CGameObject *ob, char *value)
{
    CGameEffect *eff = (CGameEffect *)Hook_Struct_Last;

    Struct_Creator = eff->eff_creator;
}


nwn_objid_t Func_GetCreator(CGameObject *ob)
{
    return Struct_Creator;
}


/* vim: set sw=4: */
