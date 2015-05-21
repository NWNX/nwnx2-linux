/***************************************************************************
    NWNXReset.cpp - Implementation of the CNWNXReset class.
    Copyright (C) 2005 Fay Smith (Asmodae)
    Copyright (C) 2006 virusman (virusman@virusman.ru)

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
#include <signal.h>
#include <unistd.h>

#include "NWNXReset.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXReset::CNWNXReset()
{
    confKey = "RESETPLUGIN";
}

CNWNXReset::~CNWNXReset()
{
}

bool CNWNXReset::OnCreate(gline *config, const char *LogDir)
{
    char log[128];
    sprintf(log, "%s/nwnx_reset.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;
    Log(0, "NWNX Reset Plugin V.0.1.\n");
    Log(0, "By virusman (virusman@virusman.ru) \n");
    Log(0, "Based on the Win32 version (c) 2005 by Fay Smith (Asmodae)\n");
    Log(0, "visit us at http://www.avlis.org\n");
    return true;
}

char* CNWNXReset::OnRequest(char *gameObject, char* Request, char* Parameters)
{
    if (strncmp(Request, "SHUTDOWN", 8) == 0) {
        Log(0, "* NWNXResetPlugin - Got request: %s.\n", Request);
        int nPid = getpid();
        kill(nPid, SIGTERM);
    }
    return NULL;
}
