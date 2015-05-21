/***************************************************************************
    NWNXLua.h - Interface for the CNWNXLua class.
    (c) 2010 pardik (d.paroli@tiscali.it)

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

#ifndef NWNXLua_h_
#define NWNXLua_h_

#include "NWNXBase.h"
#include "typedefs.h"
#include "NWNStructures.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#ifdef __cplusplus
}
#endif

class CNWNXLua : public CNWNXBase
{
public:
    CNWNXLua();
    ~CNWNXLua();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    //unsigned long OnRequestObject (char *gameObject, char* Request);
    bool OnRelease();
    void Event(char *value);
    void Token(char *value);
    char *Eval(char *value);
    int WriteSCO(char* database, char* key, char* player, int flags, unsigned char * pData, int size);
    unsigned char* ReadSCO(char* database, char* key, char* player, int* arg4, int* size);

    bool bHooked;
    lua_State *LuaInstance;
    //int nError;

    char *rco_method;
    char *sco_method;
    char *event_method;
    char *token_method;

private:

};
#endif
