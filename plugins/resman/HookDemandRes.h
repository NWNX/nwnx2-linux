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
	/* 0x0/0 */ unsigned short Demands;
	/* 0x2/2 */ unsigned short Requests;
	/* 0x4/4 */ unsigned long ID;
	long unk4;				// 0x8
	char* pResData;			// 0xC
	char* pResName;			// 0x10
	unsigned long resSize;	// 0x14
	long loaded;			// 0x18
	char* unk5;				// 0x1C
	char* unk6;				// 0x20
	char* pListElement;		// 0x24
	char* pClass;			// 0x28
/*	long loaded2;			// 0x2C
	unsigned long resSize2;	// 0x30
	char* pResData2;		// 0x34*/
};

struct CResNCS
{
	CResStruct Res;
	int m_bLoaded;
	int m_nNCSNormalSize;
	char *m_pNCSData;
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

struct CExoResMan
{
  /* 0x0/0 */ unsigned long field_0;
  /* 0x4/4 */ unsigned long TotalResourceMemory;
  /* 0x8/8 */ unsigned long FreeMemory;
  /* 0xC/12 */ unsigned long field_C;
  /* 0x10/16 */ void *KeyTable1;
  /* 0x14/20 */ void *KeyTable2;
  /* 0x18/24 */ void *KeyTable3;
  /* 0x1C/28 */ void *KeyTable4;
  /* 0x20/32 */ void *ToBeFreedList;
  /* 0x24/36 */ void *ResList2;
  /* 0x28/40 */ unsigned long field_28;
  /* 0x2C/44 */ unsigned long field_2C;
  /* 0x30/48 */ unsigned long SuspendServicing;
  /* 0x34/52 */ unsigned long field_34;
  /* 0x38/56 */ unsigned long field_38;
  /* 0x3C/60 */ unsigned long field_3C;
  /* 0x44/68 */ char rsvd1[4];
  /* 0x44/68 */ unsigned long field_44;
};

int CExoResMan__FreeChunk(CExoResMan *pResMan);

//void RetrieveResEntryHookProc();
int HookFunctions();

unsigned long FindHookRetrieveResEntry();
int RetrieveResEntry(CExoResMan * pthis, char* resRef, NwnResType resType, void ** v1, void** v2);

//void DemandResHookProc();
unsigned long FindHookDemandRes();
char* DemandRes(CExoResMan * pthis, CResStruct* cRes);

#endif

