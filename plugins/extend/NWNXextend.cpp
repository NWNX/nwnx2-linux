/***************************************************************************
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

#include "NWNXextend.h"
#include "Hooks.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXextend::CNWNXextend()
{
    confKey = strdup("EXTEND");
}

CNWNXextend::~CNWNXextend()
{
}

bool CNWNXextend::OnCreate(gline *config, const char *LogDir)
{
    char log[128];
    sprintf(log, "%s/nwnx_extend.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;
    Log(0, "NWNX extend v0.1.5 by pZv!, 2010\n");
    Log(0, "Visit http://www.nwnx.org\n\n");

    pluginConfig = (*nwnxConfig)[confKey];

    if (!InitHooks()) {
        Log(0, "* Failed to initialize hooks.\n");
        return false;
    }

    Log(0, "* Module loaded successfully.\n");

    return true;
}

char* CNWNXextend::OnRequest(char *gameObject, char* Request, char* Parameters)
{
    this->pGameObject = gameObject + 4;

    Log(2, "(S) Request: \"%s\"\n", Request);
    Log(3, "(S) Params:  \"%s\"\n", Parameters);

    if (strncmp(Request, "RESULT", 6) == 0) {
        this->ScriptResult = atoi(Parameters);
        return NULL;
    }

    return NULL;
}

unsigned long CNWNXextend::OnRequestObject(char *gameObject, char* Request)
{
    this->pGameObject = gameObject + 4;

    Log(2, "(O) Request: \"%s\"\n", Request);

    return OBJECT_INVALID;
}

int CNWNXextend::GetConfInteger(const char *key)
{
    return atoi(pluginConfig[key].c_str());
}
