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

#ifndef NWNXextend_h_
#define NWNXextend_h_

#include <map>
#include <string>
#include "NWNXBase.h"
#include "NWNXLib.h"

class CNWNXextend : public CNWNXBase
{
public:
    CNWNXextend();
    virtual ~CNWNXextend();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    unsigned long OnRequestObject(char *gameObject, char* Request);
    int GetConfInteger(const char *key);

    int ScriptResult;

private:
    char* pGameObject;
    StringMap pluginConfig;
};

#endif
