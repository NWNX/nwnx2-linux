
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


void Func_GetSavingThrowVersus(CGameObject *ob, char *value)
{
    int save, savetype, val, adj;
    nwn_objid_t versus_id;
    CGameObject *versus_ob;
    CNWSObject *versus = NULL;
    CNWSCreature *saver;

    if (sscanf(value, "%d %d %x", &save, &savetype, &versus_id) != 3 ||
            save < 1                                                     ||
            save > 3                                                     ||
            (saver = ob->vtable->AsNWSCreature(ob)) == NULL              ||
            saver->cre_stats == NULL) {

        snprintf(value, strlen(value), "0");
        return;
    }

    if (versus_id != OBJECT_INVALID) {
        versus_ob = nwn_GetObjectByID(versus_id);
        versus    = versus_ob->vtable->AsNWSObject(versus_ob);
    }

    switch (save) {
        case 1:  val = CNWSCreatureStats__GetFortSavingThrow(saver->cre_stats, 1);    break;
        case 2:  val = CNWSCreatureStats__GetReflexSavingThrow(saver->cre_stats, 1);  break;
        default: val = CNWSCreatureStats__GetWillSavingThrow(saver->cre_stats, 1);    break;
    }

    adj = CNWSCreature__GetTotalEffectBonus(saver, 3, versus, 0, 0, save, savetype, -1, -1, 0);

    snprintf(value, strlen(value), "%d", val + adj);
}


/* vim: set sw=4: */
