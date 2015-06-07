
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


void Func_ModifySkillRankByLevel(CGameObject *ob, char *value)
{
    int level, skill, val;
    CNWSCreature *cre;
    CNWLevelStats *ls;

    if (ob == NULL                                              ||
            (cre = ob->vtable->AsNWSCreature(ob)) == NULL           ||
            cre->cre_stats == NULL                                  ||
            sscanf(value, "%d %d %d", &level, &skill, &val) != 3    ||
            skill < 0 || skill > SKILL_LAST                         ||
            (ls = nwn_GetLevelStats(cre->cre_stats, level)) == NULL) {

        snprintf(value, strlen(value), "-1");
        return;
    }

    ls->ls_skilllist[skill] += val;

    val = cre->cre_stats->cs_skills[skill] + val;
    if (val < 0) val = 0;
    if (val > 127) val = 127;
    cre->cre_stats->cs_skills[skill] = val;

    snprintf(value, strlen(value), "%d", val);
}


/* vim: set sw=4: */
