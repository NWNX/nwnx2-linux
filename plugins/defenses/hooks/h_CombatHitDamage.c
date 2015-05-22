
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

volatile uintptr_t Hook_CHD_Return;
static volatile uint32_t Hook_CHD_Crit;
static volatile int16_t *Hook_CHD_Damages;
static volatile CNWSCreature *Hook_CHD_Target;
static volatile CNWSCreature *Hook_CHD_Attacker;


__attribute__((noinline))
static void Hook_AdjustCombatHitDamage(CNWSCreature *target, int16_t *damages, int crit)
{
    Local_AdjustCombatHitDamage((CNWSCreature *)Hook_CHD_Attacker, target, damages, crit);
}

void Hook_CombatHitDamage(void)
{
    asm("leave");

    /* duplicate the work originally done */
    asm("pop %edx");
    asm("pop %ecx");
    asm("push $0x1");
    asm("push %eax");

    /* copy the damages out */
    asm("movl %eax, Hook_CHD_Damages");

    /* get the attacker */
    asm("movl 0x8(%ebp), %eax");
    asm("movl %eax, Hook_CHD_Attacker");

    /* get the target object */
    asm("sub $0xc, %esp");
    asm("mov 0xc(%ebp), %edx");
    asm("mov 0xc(%edx), %eax");
    asm("push %edx");
    asm("call *0x38(%eax)");

    asm("movl %eax, Hook_CHD_Target");
    asm("add $0x10, %esp");

    /* get whether or not the last hit was a critical */
    asm("pushl 0xffffffc8(%ebp)");
    asm("popl Hook_CHD_Crit");

    Hook_AdjustCombatHitDamage(
        (CNWSCreature *)Hook_CHD_Target,
        (int16_t *)Hook_CHD_Damages, Hook_CHD_Crit);

    /* return to the normal combat hit damage call */
    asm("push Hook_CHD_Return");
    asm("ret");
}


/* vim: set sw=4: */
