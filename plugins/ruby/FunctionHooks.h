/***************************************************************************
    Ruby plugin for NWNX - hooks interface
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

#ifndef FunctionHooks_h_
#define FunctionHooks_h_

#include "NWNStructures.h"

#define ENGINE_STRUCTURE_EFFECT 0
#define ENGINE_STRUCTURE_EVENT 1
#define ENGINE_STRUCTURE_LOCATION 2
#define ENGINE_STRUCTURE_TALENT 3
#define ENGINE_STRUCTURE_ITEMPROPERTY 4

#ifdef __cplusplus
extern "C" {
#endif

void VM_ExecuteCommand(dword nCommandID, int nArgsCount);

int StackPopInteger(int *buf);
int StackPopFloat(float *buf);
int StackPopString(char **buf);
int StackPopVector(Vector *buf);
int StackPopObject(dword *buf);
int StackPopEngineStructure(dword nStructType, void **buf);

int StackPushInteger(int value);
int StackPushFloat(float value);
int StackPushString(char *value);
int StackPushVector(Vector value);
int StackPushObject(dword value);
int StackPushEngineStructure(dword nStructType, void *value);

dword GetObjectSelf();

#ifdef __cplusplus
}
#endif


#endif
