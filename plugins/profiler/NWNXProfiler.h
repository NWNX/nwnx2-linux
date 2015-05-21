/***************************************************************************
    NWNXProfiler.h - Interface for the CNWNXProfiler class.
    Copyright (C) 2003 Ingmar Stieger (Papillon)
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

#ifndef _NWNX_PROFILER_H_
#define _NWNX_PROFILER_H_

#include "NWNXBase.h"
#include "HookRunScript.h"

#include "hash.h"

class CNWNXProfiler : public CNWNXBase
{

public:
    CNWNXProfiler();
    virtual ~CNWNXProfiler();
    bool OnCreate(gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    void LoadConfiguration();
    void WriteLogHeader();

    enum ELogLevel {logNothing, logStats, logCallstack};
    int	m_LogLevel;
    int log_scriptparts;

};

#endif
