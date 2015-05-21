
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


volatile uintptr_t Hook_ACP_Return;
volatile int Hook_ACP_Penalty;
volatile uint8_t Hook_ACP_Skill;
volatile CNWSCreatureStats *Hook_ACP_Stats;


__attribute__((noinline))
static int Hook_GetArmorCheckPenaltyAdjustment(CNWSCreatureStats *stats, uint8_t skill)
{
    int acp_armor, acp_shield;

    if (stats == NULL)
        return 0;

    acp_armor  = stats->cs_acp_armor;
    acp_shield = stats->cs_acp_shield;

    return Local_GetArmorCheckPenaltyAdjustment(stats, skill, acp_armor, acp_shield);
}

void Hook_GetArmorCheckPenalty(void)
{
    asm("leave");

    /* copy creature being checked out */
    asm("movl %edi, Hook_ACP_Stats");

    asm("mov 0xc(%ebp), %al");
    asm("mov %al, Hook_ACP_Skill");

    Hook_ACP_Penalty = Hook_GetArmorCheckPenaltyAdjustment(
                           (CNWSCreatureStats *)Hook_ACP_Stats, (uint8_t)Hook_ACP_Skill);

    /* the result of Hook_GetArmorCheckPenaltyAdjustment() is in %eax */
    asm("pushl Hook_ACP_Return");
    asm("ret");
}


/* vim: set sw=4: */
