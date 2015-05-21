
/***************************************************************************
    SpellsReplace.c - Implementation of NWN combat replacement functions
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

#include "NWNXSpells.h"


int Hook_GetSpellMinAbilityMet(CNWSCreatureStats *stats, int clpos, int level)
{
    int abil, val;
    uint8_t cl;

    if (clpos >= stats->cs_classes_len)
        cl = 255;
    else
        cl = stats->cs_classes[clpos].cl_class;

    if ((abil = Table_SpellAbilities[cl] - 1) < -1)
        return 1;

    switch (abil) {
        case ABILITY_STRENGTH:     val = stats->cs_str; break;
        case ABILITY_DEXTERITY:    val = stats->cs_dex; break;
        case ABILITY_CONSTITUTION: val = stats->cs_con; break;
        case ABILITY_INTELLIGENCE: val = stats->cs_int; break;
        case ABILITY_WISDOM:       val = stats->cs_wis; break;
        case ABILITY_CHARISMA:     val = stats->cs_cha; break;
        default: return 0;
    }

    /* XXX: read these out of the rules table */
    switch (stats->cs_race) {
        case RACIAL_TYPE_DWARF:
            if (abil == ABILITY_CONSTITUTION)
                val += 2;
            else if (abil == ABILITY_CHARISMA)
                val -= 2;
            break;

        case RACIAL_TYPE_ELF:
            if (abil == ABILITY_DEXTERITY)
                val += 2;
            else if (abil == ABILITY_CONSTITUTION)
                val -= 2;
            break;

        case RACIAL_TYPE_GNOME:
            if (abil == ABILITY_CONSTITUTION)
                val += 2;
            else if (abil == ABILITY_STRENGTH)
                val -= 2;
            break;

        case RACIAL_TYPE_HALFLING:
            if (abil == ABILITY_DEXTERITY)
                val += 2;
            else if (abil == ABILITY_STRENGTH)
                val -= 2;
            break;

        case RACIAL_TYPE_HALFORC:
            if (abil == ABILITY_STRENGTH)
                val += 2;
            else if (abil == ABILITY_INTELLIGENCE || abil == ABILITY_CHARISMA)
                val -= 2;
            break;
    }

    return (val >= level + 10);
}


/* vim: set sw=4: */
