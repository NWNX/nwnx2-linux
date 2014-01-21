/***************************************************************************
    NWNXProfiler.cpp - Implementation of the CNWNXProfiler class.
    Copyright (C) 2003 Ingmar Stieger (Papillon, papillon@blackdagger.com)
    Linux port - (c) virusman (virusman@virusman.ru)

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

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <pthread.h>
#include <stddef.h>

#include "NWNXProfiler.h"
#include "HookRunScript.h"

#define MAX_CALLDEPTH 128
extern char  scriptName[MAX_CALLDEPTH][17];
extern int   iCallDepth;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXProfiler::CNWNXProfiler()
{
    confKey = "PROFILER";
    log_scriptparts = 1;
}

CNWNXProfiler::~CNWNXProfiler()
{
    // write last few samples to log file
    Release();
}

bool CNWNXProfiler::OnCreate(gline *config, const char* LogDir)
{
    // call the base class function
    char log[128];
    sprintf(log, "%s/nwnx_profiler.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    LoadConfiguration();
    HookRunScript();
    return true;
}

char* CNWNXProfiler::OnRequest(char* gameObject, char* Request, char* Parameters)
{

    if (strncmp(Request, "CURRENTSCRIPT", 13) == 0) {
        return strdup(scriptName[iCallDepth]);
    }

    if (strncmp(Request, "STACK", 5) == 0) {
        char* stack = new char[128 * 17];
        stack[0] = 0x0;
        for (int i = 0; i <= iCallDepth; i++) {
            if (i > 0) strcat(stack, ":");
            strcat(stack, scriptName[iCallDepth - i]);
        }
        return stack;
    }

    return NULL;
}

void CNWNXProfiler::LoadConfiguration()
{
    m_LogLevel = debuglevel;
    if (nwnxConfig->exists(confKey, "scriptparts")) {
        log_scriptparts = atoi((char*)((*nwnxConfig)[confKey]["scriptparts"].c_str()));
    }
}

void CNWNXProfiler::WriteLogHeader()
{
    Log(0, "NWNX Profiler V.1.61\n");
    Log(0, "(c) 2005 by Ingmar Stieger (papillon@nwnx.org)\n");
    Log(0, "(c) 2006-2009 by virusman (virusman@virusman.ru)\n");
    Log(0, "visit us at http://www.nwnx.org\n\n");
    Log(0, "* Updated entries are marked with a * symbol\n");
    Log(0, "* Log level: ");
    if (debuglevel > 1) {
        Log(0, "Script callstack will be logged.\n");
    } else {
        Log(0, "Only overall statistics will be logged.\n");
    }
    Log(0, "* Separate script parts logging: %d\n", log_scriptparts);
}
