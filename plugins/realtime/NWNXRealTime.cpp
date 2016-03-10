/*
 * RealTime - Linux Port of the RealTime NWNX2 plugin by Rob Lobbe
 * Copyright (C) 2016 Nela Melin (nela@tomb.org.uk)
 * 
 * RealTime - Implementation of the RealTime class (for NWNX2)
 * Copyright (C) 2007 Rob Lobbe (Gryphyn, gryphyn@thefold.org)
 *     
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */ 

#include <string.h>
#include <errno.h>

#include "NWNXRealTime.h"
#include "RealTimeStrCmds.h"

CNWNXRealTime::CNWNXRealTime()
{
    /* Store server start time for uptime calculations. */
    if(gettimeofday(&loadTime, NULL) < 0)
        Log(0, "Error: gettimeofday: %s\n", strerror(errno));
}

CNWNXRealTime::~CNWNXRealTime()
{
}

char *CNWNXRealTime::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    const struct RealTimeStrCommand_s *cmd;

    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    if ((cmd = RealTimeStrCommandLookup(Request, strlen(Request))) != NULL)
        cmd->func((CGameObject *)gameObject, Parameters);
    else
        Log(0, "Unrecognized string request: \"%s\" \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
}

bool CNWNXRealTime::OnCreate(gline *config, const char *LogDir)
{
    // call the base class function
    char log[MAX_PATH];
    sprintf(log, "%s/nwnx_realtime.log", LogDir);

    if(!CNWNXBase::OnCreate(config, log))
        return false;

    Log(0, "NWNX RealTime plugin v2.0\n");
    Log(0, "(c) 2016 by Nela Melin\n");
    Log(0, "(c) 2007 by Rob Lobbe(Gryphyn)\n");
    Log(0, "visit us at http://www.nwnx.org\n\n");

    return true;
}

struct timeval CNWNXRealTime::getLoadTime()
{
    return loadTime;
}

struct timeval C_getLoadTime(void)
{
    return RealTime.getLoadTime();
}

