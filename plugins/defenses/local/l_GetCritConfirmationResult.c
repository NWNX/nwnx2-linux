
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


int Local_GetCritConfirmationResult(CNWSCreature *attacker, CNWSCreatureStats *target)
{
#ifdef NWNX_DEFENSES_HG
    int pm, pct = 0;

    if (target == NULL)
        return 0;

    pm = nwn_GetLevelByClass(target, CLASS_TYPE_PALEMASTER);

    if (pm > 10)
        pct = (pm - 10) * 10;

    if (target->cs_race == RACIAL_TYPE_HALFORC &&
            target->cs_appearance >= 1498 &&
            (target->cs_appearance <= 1500 || target->cs_appearance == 1504)) {

        int str = target->cs_str_mod * 2;

        if (str > 90)
            str = 90;
        if (str > pct)
            pct = str;
    }

    if (pct > 0)
        return (random() % 100 < pct);

    return 0;
#endif

    return -1;
}


/* vim: set sw=4: */
