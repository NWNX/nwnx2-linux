
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

#include "NWNXWeapons.h"


volatile uintptr_t Hook_OHCM1_Return;
volatile uintptr_t Hook_OHCM2_Return;
volatile uintptr_t Hook_OHCM3_Return;
volatile uintptr_t Hook_OHCM4_Return;
volatile int Hook_OHCM3_Offhand = 0;

void Hook_OffhandCritMult1(void)
{
    asm("leave");

    /* push the correct offhand value on the stack */
    asm("pushl 0x10(%ebp)");

    /* duplicate the work originally done */
    asm("push $0xff");

    /* return to the normal critical multiplier check */
    asm("push Hook_OHCM1_Return");
    asm("ret");
}

void Hook_OffhandCritMult2(void)
{
    asm("leave");

    /* push the correct offhand value on the stack */
    asm("pushl 0x10(%ebp)");

    /* duplicate the work originally done */
    asm("push $0xff");

    /* return to the normal critical multiplier check */
    asm("push Hook_OHCM2_Return");
    asm("ret");
}

void Hook_OffhandCritMult3(void)
{
    asm("leave");

    /* push the correct offhand value on the stack */
    asm("pushl Hook_OHCM3_Offhand");
    asm("movl $0, Hook_OHCM3_Offhand");

    /* duplicate the work originally done */
    asm("push $0xff");

    /* return to the normal critical multiplier check */
    asm("push Hook_OHCM3_Return");
    asm("ret");
}

void Hook_OffhandCritMult4(void)
{
    asm("leave");

    /* push the correct offhand value on the stack */
    asm("pushl 0xffffffcc(%ebp)");
    asm("popl Hook_OHCM3_Offhand");

    /* duplicate the work originally done */
    asm("sub $0x8,%esp");
    asm("push %edx");
    asm("pushl 0x8(%ebp)");

    /* return to the normal critical multiplier check */
    asm("push Hook_OHCM4_Return");
    asm("ret");
}


/* vim: set sw=4: */
