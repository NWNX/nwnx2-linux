
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


volatile uintptr_t Hook_SCM1_Return;
volatile uintptr_t Hook_SCM2_Return;
volatile uintptr_t Hook_SCM3_Return;
volatile uintptr_t Hook_SCM4_Return;
static volatile int Hook_SCM_Class;


__attribute__((noinline))
int Hook_GetIsMemorizationCasterClass(int cl)
{
    /* XXX: add a table for this */
    return !!Local_GetIsMemorizationCasterClass(cl);
}


void Hook_GetIsMemorizationCasterClass1(void)
{
    asm("leave");

    asm("movzbl %dl, %eax");
    asm("movl %eax, Hook_SCM_Class");

    Hook_SCM_Class = Hook_GetIsMemorizationCasterClass(Hook_SCM_Class);

    /* The result of Hook_GetIsMemorizationCasterClass() is in %eax */
    asm("cmp $0x1, %eax");

    asm("push Hook_SCM1_Return");
    asm("ret");
}


void Hook_GetIsMemorizationCasterClass2(void)
{
    asm("leave");

    asm("movzbl %al, %eax");
    asm("movl %eax, Hook_SCM_Class");

    Hook_SCM_Class = Hook_GetIsMemorizationCasterClass(Hook_SCM_Class);

    /* The result of Hook_GetIsMemorizationCasterClass() is in %eax */
    asm("cmp $0x1, %eax");

    asm("push Hook_SCM2_Return");
    asm("ret");
}


void Hook_GetIsMemorizationCasterClass3(void)
{
    asm("leave");

    asm("movzbl %al, %eax");
    asm("movl %eax, Hook_SCM_Class");

    Hook_SCM_Class = Hook_GetIsMemorizationCasterClass(Hook_SCM_Class);

    /* The result of Hook_GetIsMemorizationCasterClass() is in %eax */
    asm("cmp $0x1, %eax");

    asm("push Hook_SCM3_Return");
    asm("ret");
}


void Hook_GetIsMemorizationCasterClass4(void)
{
    asm("leave");

    asm("movzbl %bl, %eax");
    asm("movl %eax, Hook_SCM_Class");

    Hook_SCM_Class = Hook_GetIsMemorizationCasterClass(Hook_SCM_Class);

    /* The result of Hook_GetIsMemorizationCasterClass() is in %eax */
    asm("cmp $0x1, %eax");

    asm("push Hook_SCM4_Return");
    asm("ret");
}


/* vim: set sw=4: */
