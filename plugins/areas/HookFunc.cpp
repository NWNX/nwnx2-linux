/***************************************************************************
    Events plugin for NWNX  - hooks implementation
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

#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <stdarg.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "HookFunc.h"
#include "NWNXAreas.h"
#include "AssemblyHelper.cpp"

extern CNWNXAreas areas;
AssemblyHelper asmhelp;


void (*CNWSArea__CNWSArea)(void *pArea, CResRef res, int a3, dword ObjID);
void (*CNWSArea__LoadArea)(void *pArea, int flag);
void (*CExoArrayList__Add)(void *pArray, dword nObjID);

dword pServThis = 0;
dword pScriptThis = 0;

CResRef *CResRef____as(CResRef *res, char *str)
{
	memset(res->ResRef, 0, 0x10);
	strncpy(res->ResRef, str, 0x10);
	return res;
}

void NWNXCreateArea(void *pModule, char *sResRef)
{
	CResRef res;
	CResRef____as(&res, sResRef);
	void *pArea = malloc(0x210);
	areas.Log(0, "Creating area '%s'", sResRef);
	CNWSArea__CNWSArea(pArea, res, 0, OBJECT_INVALID);
	areas.Log(0, "Loading area '%s'", sResRef);
	CNWSArea__LoadArea(pArea, 0);
	dword nAreaID = *((dword *)pArea+0x32);
	areas.Log(0, "AreaID=%08lX", nAreaID);
	void *pArray = ((dword *)pModule+0x7);
	CExoArrayList__Add(pArray, nAreaID);
	areas.nLastAreaID = nAreaID;
}

int HookFunctions()
{
	dword org_SaveChar = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC B8 00 00 00 FF 75 08 C7 85 74");
	if (org_SaveChar)
	{
		pServThis = *(dword*)(org_SaveChar + 0x3C);
		pScriptThis = pServThis - 8;
	}

	*(dword*)&CNWSArea__CNWSArea = 0x080CBD30;
	*(dword*)&CNWSArea__LoadArea = 0x080CDFDC;
	*(dword*)&CExoArrayList__Add = 0x0805EEE0;
	

	return (org_SaveChar && pServThis && pScriptThis);
}


