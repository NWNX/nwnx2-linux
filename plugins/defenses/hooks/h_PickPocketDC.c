
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

volatile uintptr_t Hook_PPDC_Return;
static volatile int Hook_PPDC_ExtraDC = 0;
static volatile CNWSCreature *Hook_PPDC_Thief, *Hook_PPDC_Victim;


__attribute__((noinline))
static int Hook_GetPickPocketDCAdjustment(CNWSCreature *thief, CNWSCreature *victim)
{
    return Local_GetPickPocketDCAdjustment(thief, victim);
}


void Hook_PickPocketDC(void)
{
    asm("leave");

    /* duplicate the work originally done */
    asm("cmp $0x2, %al");
    asm("sete %dl");
    asm("dec %edx");
    asm("and $0xfffffff6, %edx");
    asm("add $0x1e, %edx");

    /* get the thief and victim */
    asm("pushl 0xffffff74(%ebp)");
    asm("popl Hook_PPDC_Victim");

    asm("pushl 0x8(%ebp)");
    asm("popl Hook_PPDC_Thief");

    Hook_PPDC_ExtraDC = Hook_GetPickPocketDCAdjustment(
                            (CNWSCreature *)Hook_PPDC_Thief,
                            (CNWSCreature *)Hook_PPDC_Victim);

    /* the result of Hook_GetPickPocketDCAdjustment() is in %eax */
    asm("add %eax, %edx");

    /* return to the normal pick pocket check */
    asm("push Hook_PPDC_Return");
    asm("ret");
}


/* vim: set sw=4: */
