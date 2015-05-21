
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

static volatile uint32_t Hook_GetWeaponAttackType;
static volatile uint32_t Hook_GetMonsterDamageExists;
static volatile uint32_t Hook_GetMonsterDamageReturn;


__attribute__((noinline))
static uint32_t Hook_GetMonsterDamageHandlerReturn(void)
{
    if (Hook_GetMonsterDamageExists)
        return 0x0814AB07;

    if (Hook_GetWeaponAttackType)
        return 0x0814ACA8;

    return 0x0814B049;
}

void Hook_GetMonsterDamageHandler(void)
{
    asm("leave");

    asm("pushl %ebx");
    asm("popl Hook_GetWeaponAttackType");

    asm("pushl %eax");
    asm("popl Hook_GetMonsterDamageExists");

    Hook_GetMonsterDamageReturn = Hook_GetMonsterDamageHandlerReturn();

    asm("pushl %eax");
    asm("ret");
}


/* vim: set sw=4: */
