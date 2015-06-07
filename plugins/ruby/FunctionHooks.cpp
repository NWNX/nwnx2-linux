/***************************************************************************
    Ruby plugin for NWNX  - hooks implementation
    (c) 2008-2013 virusman (virusman@virusman.ru)

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

#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <time.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "FunctionHooks.h"
#include "NWNXRuby.h"
#include "api/all.h"

extern CNWNXRuby ruby;

int StackPopInteger(int *buf)
{
    return g_pVirtualMachine->StackPopInteger(buf);
}

int StackPopFloat(float *buf)
{
    return g_pVirtualMachine->StackPopFloat(buf);
}

int StackPopString(char **buf)
{
    CExoString *str = (CExoString *) malloc(sizeof(CExoString));
    str->Text = NULL;
    str->Length = 0;
    int retval = g_pVirtualMachine->StackPopString(str);
    if (!str->Text)
        *buf = "";
    else
        *buf = str->Text;
    free(str);
    return retval;
}

int StackPopVector(Vector *buf)
{
    return g_pVirtualMachine->StackPopVector(buf);
}

int StackPopObject(dword *buf)
{
    return g_pVirtualMachine->StackPopObject(buf);
}

int StackPopEngineStructure(dword nStructType, void **buf)
{
    return g_pVirtualMachine->StackPopEngineStructure(nStructType, buf);
}

int StackPushInteger(int value)
{
    return g_pVirtualMachine->StackPushInteger(value);
}

int StackPushFloat(float value)
{
    return g_pVirtualMachine->StackPushFloat(value);
}

int StackPushString(char *value)
{
    return g_pVirtualMachine->StackPushString(value);
}

int StackPushVector(Vector value)
{
    return g_pVirtualMachine->StackPushVector(value);
}

int StackPushObject(dword value)
{
    return g_pVirtualMachine->StackPushObject(value);
}

int StackPushEngineStructure(dword nStructType, void *value)
{
    return g_pVirtualMachine->StackPushEngineStructure(nStructType, value);
}

dword GetObjectSelf()
{
    g_pVirtualMachine->ObjectID[g_pVirtualMachine->RecursionLevel];
}

void VM_ExecuteCommand(dword nCommandID, int nArgsCount)
{
    g_pVirtualMachine->m_pCmdImplementer->ExecuteCommand(nCommandID, nArgsCount);
}
