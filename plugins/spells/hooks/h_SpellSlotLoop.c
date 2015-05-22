
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


volatile uintptr_t Hook_SPSL1_Return;
volatile uintptr_t Hook_SPSL2_Return;
volatile uintptr_t Hook_SPSL3_Return;

volatile uint32_t Hook_SpellSlotsSent = 0;


void Hook_SpellSlotLoop1(void)
{
    asm("leave");

    /* record that no spell slots have been sent yet */
    asm("movl $0, Hook_SpellSlotsSent");

    /* return to the normal spell slot loop check */
    asm("push Hook_SPSL1_Return");
    asm("ret");
}


void Hook_SpellSlotLoop2(void)
{
    asm("leave");

    asm("movl Hook_SpellSlotsSent, %esi");

    /* return to the normal spell slot loop check */
    asm("push Hook_SPSL2_Return");
    asm("ret");
}


void Hook_SpellSlotLoop3(void)
{
    asm("leave");

    asm("addl $1, Hook_SpellSlotsSent");
    asm("movl Hook_SpellSlotsSent, %eax");

    /* return to the normal spell slot loop check */
    asm("push Hook_SPSL3_Return");
    asm("ret");
}


/* vim: set sw=4: */
