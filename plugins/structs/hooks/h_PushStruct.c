
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

#include "NWNXStructs.h"


volatile uintptr_t Hook_Struct_Return;
volatile CGameEffect *Hook_Struct_Last;


void Hook_PushStruct(void)
{
    asm("leave");

    /* duplicate the work originally done */
    asm("mov 0x10(%esi), %eax");
    asm("mov 0xc(%ebp), %edi");
    asm("mov 0x8(%edx), %ecx");

    /* push the struct address onto the stack and pop it into
     * our cached last struct variable */
    asm("pushl (%eax,%edi,4)");
    asm("popl Hook_Struct_Last");

    asm("push Hook_Struct_Return");
    asm("ret");
}


/* vim: set sw=4: */
