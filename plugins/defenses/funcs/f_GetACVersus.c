
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

#include "NWNXDefenses.h"


void Func_GetACVersus(CGameObject *ob, char *value)
{
    int ac;
    CGameObject *aob = nwn_GetObjectByStringID(value);
    CNWSCreature *attacker, *target;

    if (ob  == NULL || (target   = ob->vtable->AsNWSCreature(ob)) == NULL  ||
            aob == NULL || (attacker = aob->vtable->AsNWSCreature(ob)) == NULL ||
            attacker->cre_stats == NULL || target->cre_stats == NULL)
        ac = 0;
    else
        ac = CNWSCreatureStats__GetArmorClassVersus(target->cre_stats, attacker, 0);

    snprintf(value, strlen(value), "%d", ac);
}


/* vim: set sw=4: */
