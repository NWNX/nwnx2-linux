
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


void Func_RestoreReadySpells(CGameObject *ob, char *value)
{
    int sp_class = -1, sp_level = 0, sp_len = 0, sp_idx = 0, sp_pct = 0, ret = 0;
    long val;
    char *end, *p = value;
    CNWSCreature *cre;
    CNWSStats_Spell *sp;

    if (ob == NULL || (cre = ob->vtable->AsNWSCreature(ob)) == NULL || cre->cre_stats == NULL) {
        snprintf(value, strlen(value), "-1");
        return;
    }

    if (*p == '%') {
        sp_pct = strtol(p + 1, &end, 10);
        p      = end;
    }

    if (strlen(p) == 0 || (strlen(p) == 1 && *p == ' ')) {
        for (sp_class = 0; sp_class < cre->cre_stats->cs_classes_len; sp_class++) {
            for (sp_level = 0; sp_level <= 9; sp_level++) {
                if (sp_pct > 100) {
                    long max, add_pct = sp_pct - 100;

                    val = cre->cre_stats->cs_classes[sp_class].cl_spells_left[sp_level];
                    max = cre->cre_stats->cs_classes[sp_class].cl_spells_max[sp_level];

                    if ((val += (max * add_pct) / 100) > max)
                        val = max;

                    cre->cre_stats->cs_classes[sp_class].cl_spells_left[sp_level] = val;

                    for (sp_idx = 0; sp_idx < cre->cre_stats->cs_classes[sp_class].cl_spells_mem[sp_level].len; sp_idx++) {
                        if ((random() % 100) >= add_pct)
                            continue;

                        if ((sp = CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[sp_class].cl_spells_mem[sp_level]), sp_idx)) != NULL)
                            sp->sp_ready = 1;
                    }
                } else if (sp_pct > 0) {
                    val = cre->cre_stats->cs_classes[sp_class].cl_spells_left[sp_level];

                    if ((val = (val * sp_pct) / 100) > cre->cre_stats->cs_classes[sp_class].cl_spells_max[sp_level])
                        val = cre->cre_stats->cs_classes[sp_class].cl_spells_max[sp_level];

                    cre->cre_stats->cs_classes[sp_class].cl_spells_left[sp_level] = val;

                    for (sp_idx = 0; sp_idx < cre->cre_stats->cs_classes[sp_class].cl_spells_mem[sp_level].len; sp_idx++) {
                        if ((random() % 100) < sp_pct)
                            continue;

                        if ((sp = CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[sp_class].cl_spells_mem[sp_level]), sp_idx)) != NULL)
                            sp->sp_ready = 0;
                    }
                } else {
                    cre->cre_stats->cs_classes[sp_class].cl_spells_left[sp_level] = 0;

                    for (sp_idx = 0; sp_idx < cre->cre_stats->cs_classes[sp_class].cl_spells_mem[sp_level].len; sp_idx++) {
                        if ((sp = CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[sp_class].cl_spells_mem[sp_level]), sp_idx)) != NULL)
                            sp->sp_ready = 0;
                    }
                }
            }
        }

        snprintf(value, strlen(value), "0");
        return;
    }

    while (*p) {
        if (*p == '*') {
            while (sp_class >= 0 && sp_idx < sp_len) {
                if ((sp = CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[sp_class].cl_spells_mem[sp_level]), sp_idx)) != NULL)
                    sp->sp_ready = 0;
                sp_idx++;
            }

            val      = strtol(p + 1, &end, 10);
            sp_class = val >> 8;
            sp_level = val & 0xFF;
            sp_len   = cre->cre_stats->cs_classes[sp_class].cl_spells_mem[sp_level].len;
            sp_idx   = 0;
            p        = end + 1;

            if (sp_class >= cre->cre_stats->cs_classes_len) {
                snprintf(value, strlen(value), "-1");
                return;
            }
        } else if (*p == ' ') {
            p++;
        } else if (sp_class >= 0 && *p == '#') {
            val = strtol(p + 1, &end, 10);
            cre->cre_stats->cs_classes[sp_class].cl_spells_left[sp_level] = val;
            p = end + 1;
        } else if (sp_class >= 0) {
            val = strtol(p, &end, 16);
            p   = end + 1;

            if (sp_idx < sp_len) {
                sp = CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[sp_class].cl_spells_mem[sp_level]), sp_idx);

                if (sp != NULL && (val < 0 || !(val & 0x1000000) || sp->sp_id != (val & 0xFFFF)))
                    sp->sp_ready = 0;

                ret++;
                sp_idx++;
            }
        }
    }

    while (sp_class >= 0 && sp_idx < sp_len) {
        if ((sp = CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[sp_class].cl_spells_mem[sp_level]), sp_idx)) != NULL)
            sp->sp_ready = 0;
        sp_idx++;
    }


    snprintf(value, strlen(value), "%d", ret);
}


/* vim: set sw=4: */
