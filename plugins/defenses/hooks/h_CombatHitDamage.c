
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


static void Hook_AdjustCombatHitDamage (CNWSCreature *target, int16_t *damages) {
#if 0
    int i, parry, reduce;

    if (Hook_CHD_Target == NULL            ||
        Hook_CHD_Target->cre_stats == NULL ||
        Hook_CHD_Target->obj.obj_type != 5)
        return;

    if (!Hook_CHD_Crit)
        return;

    if (CNWSCreatureStats__HasFeat(Hook_CHD_Target->cre_stats, HGFEAT_Y_CRITICAL_REDUCTION) ||
        CNWSCreatureStats__HasFeat(Hook_CHD_Target->cre_stats, HGFEAT_Z_CRITICAL_REDUCTION)) {

        parry = 50;
    } else {
        parry = (CNWSCreatureStats__GetSkillRank(Hook_CHD_Target->cre_stats, SKILL_PARRY, NULL, 0) - 20) / 2;

        if (parry < 1)
            return;
        if (parry > 50)
            parry = 50;
    }

    for (i = 0; i < 13; i++) {
        if (damages[11 + i] >= 5) {
            reduce = (damages[11 + i] * parry) / 100;
            damages[11 + i] -= reduce;
        }
    }
#endif
}

void Hook_CombatHitDamage (void) {
    asm("leave");

    /* duplicate the work originally done */
    asm("pop %edx");
    asm("pop %ecx");
    asm("push $0x1");
    asm("push %eax");

    /* copy the damages out */
    asm("movl %eax, Hook_CHD_Damages");

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

    asm("pusha");
    Hook_AdjustCombatHitDamage((CNWSCreature *)Hook_CHD_Target, (int16_t *)Hook_CHD_Damages);
    asm("popa");

    /* return to the normal combat hit damage call */
    asm("push Hook_CHD_Return");
    asm("ret");
}


/* vim: set sw=4: */
