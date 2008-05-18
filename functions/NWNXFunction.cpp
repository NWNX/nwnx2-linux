/***************************************************************************
    NWNXFunction.cpp - Implementation of the CNWNXFunction class.
    Copyright (C) 2003 Ingmar Stieger (Papillon)
    email: papillon@blackdagger.com

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

#include <string.h>
#include <stdlib.h>

#include "NWNXFunction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXFunction::CNWNXFunction()
{
	confKey = "FUNCTIONS";
}

CNWNXFunction::~CNWNXFunction()
{
}

void CNWNXFunction::SetLockDC(char* value)
{
	if (*(pGameObject+0x4) == 0x9) // object type placeable
	{
		int iLockDC = atoi(value);
		*(pGameObject+0x210) = iLockDC;
	}
}


void CNWNXFunction::SetStolenFlag(char* value)
{
	if (*(pGameObject+0x4) == 0x6) // object type item
	{
		int iFlag = atoi(value);
		*(pGameObject+0x250) = iFlag;
	}
}

void CNWNXFunction::SetGoldPieceValue(char* value)
{
	if (*(pGameObject+0x4) == 0x6) // object type item
	{
		int iGoldValue = atoi(value);
		*(int*)(pGameObject+0x1F4) = iGoldValue;
	}
}

void CNWNXFunction::SetTag(char* value)
{
    char* tag = (char*)(*(int*)(pGameObject+0x18));

	int iLength;
	int iOrgLength = strlen(tag);
	int iNewLength = strlen(value);

	if (iOrgLength > iNewLength)
		iLength = iNewLength;
	else
		iLength = iOrgLength;

	strncpy(tag, value, iLength);

	*(tag+iLength) = 0x0;
}

void CNWNXFunction::SetArmorAC(char* value)
{
	if (*(pGameObject+0x4) == 0x6) // object type item
	{
		int iAC = atoi(value);
		*(int*)(pGameObject+0x1CC) = iAC;
	}
	// 0x1d4: auch armor class ??
}

void CNWNXFunction::GetArmorAC(char* value)
{
	if (*(pGameObject+0x4) == 0x6) // object type item
	{
		int iAC = *(int*)(pGameObject+0x1CC);
		if (strlen(value) > 1)
			sprintf(value, "%d", iAC);
	}
}

void CNWNXFunction::GetDescription(char* value)
{
	int length = strlen(value);
	char* desc;
	
	if (*(pGameObject+0x4) != 0x6) // object type item	
		return;
	
	desc = (char*)(*(int*)(pGameObject+0x228));
	if (*(desc+4) == 0)
		return;
	desc = (char*)(*(int*)(desc));
	desc = (char*)(*(int*)(desc));
	desc = (char*)(*(int*)(desc+0x8));
	desc = (char*)(*(int*)(desc+0x4));

	int iDescLength = strlen(desc);
	if (iDescLength < length)
	{
		strncpy(value, desc, iDescLength);
		*(value+iDescLength) = 0x0;
	}
	else
	{
		strncpy(value, desc, length);
		*(value+length) = 0x0;
	}
}

void CNWNXFunction::GetIsPickPocketable(char* value)
{
	if (*(pGameObject+0x4) == 0x6) // object type item
	{
		int i = *(int*)(pGameObject+0x248);
		if (strlen(value) > 1)
			sprintf(value, "%d", i);
	}
}

void CNWNXFunction::SetIsPickPocketable(char* value)
{
	if (*(pGameObject+0x4) == 0x6) // object type item
	{
		int i = atoi(value);
		*(int*)(pGameObject+0x248) = i;
	}
}

void CNWNXFunction::SetBodyPart(char *value) 
{
	int bpart,ptype;
	char *next;

	if (*(pGameObject+0x4) == 0x5) // object type creature
	{
		// parse "nPart[!nType]"
		bpart = atoi(value);
		next= strchr(value,'!');
		ptype = next?atoi(next+1):0;

		// bounds checking
		if(bpart<3 || bpart>29)
			return;
		if(ptype<0 || ptype>255)
			return;

		*(pGameObject+0x0c20+bpart) = (char)ptype;
	}
	
}

void CNWNXFunction::GetBodyPart(char *value) 
{
	int bpart;

	if (*(pGameObject+0x4) == 0x5) // object type creature
	{
		// parse "nPart"
		bpart = atoi(value);

		// bounds checking
		if(bpart<3 || bpart>29)
			return;

		sprintf(value,"%d",*(pGameObject+0x0c20+bpart));
	}
	
}

void CNWNXFunction::ObjDump(char *value)
{
	if (*(pGameObject+0x4) == 0x6) // object type item
	{
		int i,j;
		char buf[17];
		char *p= (char*)pGameObject;

		printf("tag: [%s]\n",*(char**)(&p[0x18]));

		for(i=0; i<2048; i+=16) {
			printf("0x%04x:",i);
			for(j=0; j<16; j++) {
				printf(" %02x",(unsigned char)p[i+j]);
				buf[j]= isprint(p[i+j])?p[i+j]:'.';
			}
			buf[j]= 0;
			printf(" - |%s|\n",buf);
		}
	}
}

bool CNWNXFunction::OnCreate(gline *config, const char *LogDir)
{
	char log[128];
	sprintf (log, "%s/nwnx_fn.txt", LogDir);

	// call the base class function
	if (!CNWNXBase::OnCreate(config,log))
		return false;

	return true;
}

char* CNWNXFunction::OnRequest (char *gameObject, char* Request, char* Parameters)
{
	this->pGameObject = gameObject+4;

	Log(2,"Request: \"%s\"\n",Request);
	Log(3,"Params:  \"%s\"\n",Parameters);

	if (strncmp(Request, "SETLOCKDC", 9) == 0) 	
	{
		SetLockDC(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETSTOLENFLAG", 9) == 0) 	
	{
		SetStolenFlag(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETGOLDPIECEVALUE", 17) == 0) 	
	{
		SetGoldPieceValue(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETTAG", 6) == 0) 	
	{
		SetTag(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETARMORAC", 10) == 0) 	
	{
		SetArmorAC(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETARMORAC", 10) == 0) 	
	{
		GetArmorAC(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETDESCRIPTION", 14) == 0) 	
	{
		GetDescription(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETISPICKPOCKETABLE", 19) == 0) 	
	{
		GetIsPickPocketable(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETISPICKPOCKETABLE", 19) == 0) 	
	{
		SetIsPickPocketable(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETBODYPART",11) == 0) 	
	{
		GetBodyPart(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETBODYPART",11) == 0) 	
	{
		SetBodyPart(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "OBJDUMP", 7) == 0)
	{
		ObjDump(Parameters);
		return NULL;
	}
	return NULL;
}
