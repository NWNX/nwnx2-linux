/***************************************************************************
    Functions plugin for NWNX - hooks interface
    (c) 2005 virusman (virusman@virusman.ru)

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

#include "typedefs.h"

int HookFunctions();
void InitConstants();

#ifdef __cplusplus
extern "C" {
#endif

void VM_ExecuteCommand(dword nCommandID, int nArgsCount);

int StackPopInteger(int *buf);
int StackPopString(char **buf);
int StackPopObject(dword *buf);
int StackPopFloat(float *buf);
int StackPushInteger(int value);
int StackPushFloat(float value);
int StackPushString(char *value);
int StackPushObject(dword value);

#ifdef __cplusplus
}
#endif


#endif
