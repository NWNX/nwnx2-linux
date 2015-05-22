
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


void Func_GetMeetsFeatRequirements(CGameObject *ob, char *value)
{
    int ret;
    const CNWSCreature *cre;

    if (ob == NULL || (cre = ob->vtable->AsNWSCreature(ob)) == NULL || cre->cre_stats == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }

    if (*value == '>') {
        int i, fr_feat, fr_class, fr_ability;
        char buf[512], *p, *end;
        uint16_t ls_feat;
        uint8_t ls_skills[SKILL_LAST + 1] = { [0] = 0 };
        CNWLevelStats ls = {
            .ls_featlist.data  = &ls_feat,
            .ls_featlist.len   = 1,
            .ls_featlist.alloc = 1,
            .ls_skilllist      = ls_skills
        };

        if (sscanf(value, ">%d %d %d %510s", &fr_feat, &fr_class, &fr_ability, buf) != 4 ||
                strlen(buf) < (SKILL_LAST * 2)) {
            snprintf(value, strlen(value), "0");
            return;
        }

        if (fr_ability < 0 || fr_ability > 5)
            fr_ability = 6;

        ls_feat       = fr_feat;
        ls.ls_class   = fr_class;
        ls.ls_ability = fr_ability;
        ls.ls_hp      = 1;

        for (i = 0, p = buf; p != NULL && *p != 0 && i <= SKILL_LAST; i++, p = end)
            ls_skills[i] = strtol(p + 1, &end, 10);

        ret = CNWSCreatureStats__FeatRequirementsMetAfterLevelUp(cre->cre_stats, fr_feat, &ls, 0);
    } else {
        CExoArrayList_uint16 taken = { .data = NULL, .len = 0, .alloc = 0 };
        ret = CNWSCreatureStats__FeatRequirementsMet(cre->cre_stats, atoi(value), &taken);

        if (taken.data != NULL) {
            free(taken.data);
            taken.data = NULL;
        }
    }

    snprintf(value, strlen(value), "%d", !!ret);
}


/* vim: set sw=4: */
