
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


volatile uintptr_t Hook_CSL_ReturnCheck;
volatile uintptr_t Hook_CSL_ReturnDone;
volatile CNWSpell *Hook_CSL_Spell;
volatile int32_t Hook_CSL_Class;
volatile int8_t Hook_CSL_Level;


__attribute__((noinline))
static int8_t Hook_GetClassSpellLevel(CNWSpell *spell, int32_t class)
{
    int id = spell - (*NWN_Rules)->ru_spells->spa_spells;

    switch (class) {
        case CLASS_TYPE_ASSASSIN: switch (id) {
            }
            break;

        case CLASS_TYPE_BLACKGUARD: switch (id) {
                case  433: return 3;
                case  434: return 4;
            }
            break;
    }

    return -2;
}


void Hook_GetSpellLevel(void)
{
    asm("leave");

    asm("movl 0x8(%ebp), %eax");
    asm("movl %eax, Hook_CSL_Spell");

    asm("movzbl 0xc(%ebp), %edx");
    asm("movl %edx, Hook_CSL_Class");

    Hook_CSL_Level = Hook_GetClassSpellLevel(
                         (CNWSpell *)Hook_CSL_Spell, (int32_t)Hook_CSL_Class);

    if (Hook_CSL_Level == -2) {
        /* duplicate the work originally done */
        asm("movzbl 0xc(%ebp), %edx");
        asm("cmp $0xa, %edx");
        asm("movl 0x8(%ebp), %eax");
        asm("pushl Hook_CSL_ReturnCheck");
    } else {
        asm("mov Hook_CSL_Level, %al");
        asm("pushl Hook_CSL_ReturnDone");
    }

    asm("ret");
}


/* vim: set sw=4: */
