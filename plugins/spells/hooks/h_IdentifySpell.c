
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


volatile uintptr_t Hook_SPID_Return;

volatile int32_t Hook_SPID_Skill;
volatile int32_t Hook_SPID_Spell;
volatile CNWSCreature *Hook_SPID_Viewer;


__attribute__((noinline))
int Hook_GetIdentifySpellcraftRanks(CNWSCreature *viewer, int32_t spell, int32_t ranks)
{
    if (viewer == NULL || !viewer->cre_is_pc)
        return ranks;

    /* XXX: add sorcerer automatic identification */
    if (spell < 2000)
        return ranks;

#if 0
    if (viewer->cre_stats == NULL                 ||
            !(viewer->cre_stats->cs_age & 0x80000000) ||
            !NWNX_EXALT_GET_ENHANCED(viewer->cre_stats->cs_age))
        return 0;
#endif

    return ranks;
}


void Hook_IdentifySpell(void)
{
    asm("leave");

    /* duplicate the work originally done */
    asm("add $0xf, %ebx");
    asm("add 0xffffff84(%ebp), %eax");

    /* extract the Spellcraft skill, the spell, and the viewer object */
    asm("mov %eax, Hook_SPID_Skill");
    asm("mov 0xc(%ebp), %ecx");
    asm("mov %ecx, Hook_SPID_Spell");
    asm("mov 0xffffff80(%ebp), %ecx");
    asm("mov %ecx, Hook_SPID_Viewer");

    Hook_SPID_Skill = Hook_GetIdentifySpellcraftRanks(
                          (CNWSCreature *)Hook_SPID_Viewer,
                          (int32_t)Hook_SPID_Spell,
                          (int32_t)Hook_SPID_Skill);

    /* the result of Hook_GetIdentifySpellcraftRanks() is in %eax */

    asm("push Hook_SPID_Return");
    asm("ret");
}


/* vim: set sw=4: */
