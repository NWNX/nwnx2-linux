/***************************************************************************
    NWNXnocharlist.cpp - Implementation of the CNWNXnocharlist class.
    (c) 2007 virusman (virusman@virusman.ru)

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
#include <string>
#include <stdlib.h>

#include "NWNXnocharlist.h"
#include "nocharlistHooks.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXnocharlist::CNWNXnocharlist()
{
	confKey = "nocharlist";
	bHooked = 0;
}

CNWNXnocharlist::~CNWNXnocharlist()
{
}


bool CNWNXnocharlist::OnCreate(gline *config, const char *LogDir)
{
	char log[128];
	sprintf (log, "%s/nwnx_nocharlist.txt", LogDir);

	// call the base class function
	if (!CNWNXBase::OnCreate(config,log))
		return false;
	Log(0,"NWNX NoCharList for Linux\n");
	Log(0,"Copyright 2008 Zebranky\n");
	Log(0,"visit us at http://www.nwnx.org\n\n");
	if (FindHookFunctions())
	{
		bHooked=1;
		Log(0,"* Module loaded successfully.\n");
	}		
	else
	{
		bHooked=0;
		Log(0,"* Module loaded successfully.\n");
		Log(0,"* Signature recognition failed. Some functions will be disabled.\n");
		//return false;
	}

	return true;
}

char* CNWNXnocharlist::OnRequest (char *gameObject, char* Request, char* Parameters)
{
	return NULL;
}

unsigned long CNWNXnocharlist::OnRequestObject (char *gameObject, char* Request)
{
	return OBJECT_INVALID;
}
