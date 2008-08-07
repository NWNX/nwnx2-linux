
/***************************************************************************
    ExaltReplace.c - Implementation of NWN combat replacement functions
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

#include "NWNXWeapons.h"

volatile CNWSCreatureStats *Hook_GetCriticalRange_Creature;
volatile CNWSItem *Hook_GetCriticalRange_Weapon;


static int Hook_GetCriticalRangeAdjustment (CNWSCreatureStats *info, CNWSItem *weapon) {
    int feat = 0;

    if (CNWSCreatureStats__HasFeat(info, FEAT_KI_CRITICAL))
        return 0;

    if (weapon == NULL)
        feat = FEAT_EPIC_OVERWHELMING_CRITICAL_UNARMED;
    else if (weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE)
        feat = Table_WeaponOverwhelmingCritical[weapon->it_baseitem];

    return (feat ? !!CNWSCreatureStats__HasFeat(info, feat) : 0);
}


void Hook_GetCriticalRange (void) {
    asm("leave");

    asm("pushl 0x8(%ebp)");
    asm("popl Hook_GetCriticalRange_Creature");

    asm("movl %ebx, Hook_GetCriticalRange_Weapon");

    Hook_GetCriticalRangeAdjustment(
        (CNWSCreatureStats *)Hook_GetCriticalRange_Creature,
        (CNWSItem *)Hook_GetCriticalRange_Weapon);

    /* the result of Hook_GetCriticalRangeAdjustment() is in %eax */
    asm("addl %eax, %edi");

    /* duplicate the work originally done */
    asm("mov %edi, %ecx");
    asm("lea 0xfffffff4(%ebp), %esp");
    asm("movzbl %cl, %edx");
    asm("mov %esi, %ecx");
    asm("movzbl %cl, %eax");
    asm("pop %ebx");
    asm("add %eax, %edx");
    asm("pop %esi");
    asm("mov $0x15, %eax");
    asm("sub %edx, %eax");
    asm("pop %edi");
    asm("pop %ebp");
    asm("ret");
}


/* vim: set sw=4: */
