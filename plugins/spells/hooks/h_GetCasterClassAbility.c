
/***************************************************************************
    Replace.c - Implementation of NWN combat replacement functions
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


volatile uintptr_t Hook_SCA1_Return;

static volatile CNWSCreatureStats *Hook_SCA_Stats;
static volatile int Hook_SCA_Value, Hook_SCA_Class;
static volatile int Hook_SCA_Ability, Hook_SCA_Modifier;


__attribute__((noinline))
static int Hook_GetCasterClassAbility (CNWSCreatureStats *stats, int cl) {
    int abil;

    if (cl < 0 || cl > 255)
        cl = 255;

    switch (abil = Table_SpellAbilities[cl] - 1) {
        case ABILITY_STRENGTH:
            Hook_SCA_Ability  = CNWSCreatureStats__GetSTRStat(stats);
            Hook_SCA_Modifier = stats->cs_str_mod;
            break;

        case ABILITY_DEXTERITY:
            Hook_SCA_Ability  = CNWSCreatureStats__GetDEXStat(stats);
            Hook_SCA_Modifier = stats->cs_dex_mod;
            break;

        case ABILITY_CONSTITUTION:
            Hook_SCA_Ability  = CNWSCreatureStats__GetCONStat(stats);
            Hook_SCA_Modifier = stats->cs_con_mod;
            break;

        case ABILITY_INTELLIGENCE:
            Hook_SCA_Ability  = CNWSCreatureStats__GetINTStat(stats);
            Hook_SCA_Modifier = stats->cs_int_mod;
            break;

        case ABILITY_WISDOM:
            Hook_SCA_Ability  = CNWSCreatureStats__GetWISStat(stats);
            Hook_SCA_Modifier = stats->cs_wis_mod;
            break;

        case ABILITY_CHARISMA:
            Hook_SCA_Ability  = CNWSCreatureStats__GetCHAStat(stats);
            Hook_SCA_Modifier = stats->cs_cha_mod;
            break;

        default:
            Hook_SCA_Ability  = 0;
            Hook_SCA_Modifier = 0;
            abil = -1;
            break;
    }

    return abil;
}


void Hook_GetCasterClassAbility1 (void) {
    asm("leave");

    asm("movzbl %dl, %eax");
    asm("movl %eax, Hook_SCA_Class");
    asm("movl %edi, Hook_SCA_Stats");

    Hook_SCA_Value = Hook_GetCasterClassAbility(
        (CNWSCreatureStats *)Hook_SCA_Stats, Hook_SCA_Class);

    asm("movl Hook_SCA_Ability, %eax");
    asm("movl Hook_SCA_Modifier, %esi");

    asm("push Hook_SCA1_Return");
    asm("ret");
}


/* vim: set sw=4: */
