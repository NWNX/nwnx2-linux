/***************************************************************************
    NWNX Optimizations - Implementation of the CNWNXOptimizations class.
    (c) 2010 virusman (virusman@virusman.ru)

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

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/param.h>
#include <limits.h>

#include "NWNXOptimizations.h"
#include "HookFunc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXOptimizations::CNWNXOptimizations()
{
    confKey = "OPTIMIZATIONS";
}

CNWNXOptimizations::~CNWNXOptimizations()
{
}

bool CNWNXOptimizations::OnCreate(gline *config, const char* LogDir)
{
    char log[128];
    bool validate = true, startServer = true;

    // call the base class function
    sprintf(log, "%s/nwnx_optimizations.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    // write copy information to the log file
    Log(0, "NWNX Optimizations version 1.0 for Linux.\n");
    Log(0, "(c) 2010 by virusman (virusman@virusman.ru)\n");

    return (HookFunctions());
}

char* CNWNXOptimizations::OnRequest(char* gameObject, char* Request, char* Parameters)
{
    Log(2, "Request: \"%s\"\n", Request);
    Log(2, "Params:  \"%s\"\n", Parameters);

    return NULL;
}

bool CNWNXOptimizations::OnRelease()
{
    Log(0, "o Shutdown.\n");
    return true;
}
