
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


void Func_GetCorpseDecayTime(CGameObject *oObject, char *sValue)
{
    CNWSCreature *oCreature;

    if (
        oObject == NULL                                               ||
        (oCreature = oObject->vtable->AsNWSCreature(oObject)) == NULL ||
        oCreature->cre_stats == NULL
    ) {
        snprintf(sValue, strlen(sValue), "0");
        return;
    }

    snprintf(sValue, strlen(sValue), "%d", oCreature->cre_decaytime);
}


/* vim: set sw=4: */
