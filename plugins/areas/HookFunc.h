/***************************************************************************
    Events plugin for NWNX - hooks interface
    (c) 2006 virusman (virusman@virusman.ru)

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

#if !defined(HookFunc_h_)
#define HookFunc_h_

#include "typedefs.h"
#include "NWNStructures.h"
#include "CExoLinkedList.h"
#include "CExoLocString.h"
#include <stdint.h>
#include "nx_hook.h"

int HookFunctions();

void CreateAreaListItem(void *pAreaList, char* sAreaResRef);
int LoadAreaNum(void *pModule, int nAreaNum);
void AddAreaToAllCreatures(dword nAreaID);
void NWNXCreateArea(void *pModule, char *sResRef);
void NWNXDestroyArea(void *pModule, dword nAreaID);
void NWNXSetAreaName(CNWSArea *pArea, char *sNewName);
void AddAreaToCreature(CNWSModule *pModule, CNWSCreature *pObject, dword nAreaID);

void InitConstants();

#endif
