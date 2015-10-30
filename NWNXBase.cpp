/***************************************************************************
    NWNX Base class - Library for custom expansions
    Copyright (C) 2003 Ingmar Stieger (Papillon, papillon@blackdagger.com) and
	Jeroen Broekhuizen (nwnx@jengine.nl)

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

#include "NWNXBase.h"
#include <stdarg.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXBase::CNWNXBase()
{
    // m_hFile = INVALID_HANDLE_VALUE;
    m_fFile = NULL;
    debuglevel = 0;
}

CNWNXBase::~CNWNXBase()
{
    // The OnRelease function is always called before
    // an instance is deleted
    OnRelease();
}

bool CNWNXBase::OnCreate(gline *config, const char* LogFile)
{
    // save pointer to config data
    nwnxConfig = config;

    // generic config options
    BaseConf();

    // try to open the log file
    m_fFile = fopen(LogFile, "w");
    return (m_fFile != NULL);
}

bool CNWNXBase::OnRelease()
{
    // close the log file
    int ret;
    if (m_fFile)
        ret = fclose(m_fFile);
    return (ret == 0);
}

unsigned long CNWNXBase::OnRequestObject(char *gameObject, char* Request)
{
    return 0x7F000000;
}

void CNWNXBase::Log(int priority, const char *pcMsg, ...)
{
    va_list argList;
    char acBuffer[2048];

    if (m_fFile && priority <= debuglevel) {
        // build up the string
        va_start(argList, pcMsg);
        vsnprintf(acBuffer, 2047, pcMsg, argList);
        acBuffer[2047] = 0;
        va_end(argList);

        // log string in file
        fputs(acBuffer, m_fFile);
        fflush(m_fFile);
    }
}

int CNWNXBase::ParamLog(int priority, const char *msg, char *Parameters)
{
    // record it for posterity
    Log(priority, msg);

    // if it fits, shove it in.
    if (strlen(Parameters) >= strlen(msg)) {
        strcpy(Parameters, msg);
        // success
        return 1;
    }

    // not enough room
    return 0;
}

int CNWNXBase::SetDebugLevel(int level)
{
    int temp = debuglevel;

    //printf("[%s] SetDebugLevel(%d) called.  Current value=%d\n",
    //	   confKey,level,temp);

    if (level != debuglevel) {
        debuglevel = level;
        Log(0, "* debuglevel changed to %d from %d\n", debuglevel, temp);
    }

    return temp;
}

int CNWNXBase::GetDebugLevel()
{
    return debuglevel;
}

void CNWNXBase::BaseConf()
{

    if (confKey == NULL || !nwnxConfig->exists(confKey))
        return;

    if (nwnxConfig->exists(confKey, "debuglevel")) {
        SetDebugLevel(atoi((char*)((*nwnxConfig)[confKey]["debuglevel"].c_str())));
    }
}
