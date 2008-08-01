/***************************************************************************
    NWN Extender - Hook Demandres function in the server
    Copyright (C) 2005 Ingmar Stieger (papillon@nwnx.org)
    copyright (c) 2006 dumbo (dumbo@nm.ru) & virusman (virusman@virusman.ru)

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

#if !defined(HookDemandRes_h_)
#define HookDemandRes_h_

//#include <string.h>
//#include <stdio.h>
#include "NwnDefines.h"

struct CResStruct
{
	long unk2;				// 0x0
	char id1;				// 0x4
	char id2;				// 0x5
	char id3;				// 0x6
	char id4;				// 0x7
	long unk4;				// 0x8
	char* pResData;			// 0xC
	char* pResName;			// 0x10
	unsigned long resSize;	// 0x14
	long loaded;			// 0x18
	char* unk5;				// 0x1C
	char* unk6;				// 0x20
	char* pListElement;		// 0x24
	char* pClass;			// 0x28
	long loaded2;			// 0x2C
	unsigned long resSize2;	// 0x30
	char* pResData2;		// 0x34
};

struct CResEntry
{
	char* resName1;
	char* resName2;
	char* resName3;
	char* resName4;
	CResStruct* resStruct;
	long unk6; // _04401040;
	long unk7;
};


//void RetrieveResEntryHookProc();
int HookFunctions();

unsigned long FindHookRetrieveResEntry();
int RetrieveResEntry(const int * pthis, char* resRef, NwnResType resType, void ** v1, void** v2);

//void DemandResHookProc();
unsigned long FindHookDemandRes();
char* DemandRes(const int * pthis, CResStruct* cRes);

#endif

