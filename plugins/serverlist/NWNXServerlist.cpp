
/***************************************************************************
    NWNXServerlist.cpp - Implementation of the CNWNXServerlist class.
    Copyright (C) 2013 virusman

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

#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/mman.h>

#include <dlfcn.h>

#include <limits.h>             /* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "NWNXServerlist.h"
#include "ServerlistHooks.h"

//////////////////////////////////////////////////////////////////////
// Hooks
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXServerlist::CNWNXServerlist()
{
    confKey = "SERVERLIST";
}

CNWNXServerlist::~CNWNXServerlist()
{
}

bool CNWNXServerlist::OnCreate(gline *config, const char *LogDir)
{
    char log[128];

    sprintf(log, "%s/nwnx_serverlist.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;
    HookFunctions();

    return true;
}

char *CNWNXServerlist::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    Log(1, "Request: \"%s\"\n", Request);
    Log(1, "Params:  \"%s\"\n", Parameters);

    return NULL;
}

