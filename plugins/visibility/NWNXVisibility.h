/***************************************************************************
    NWNX Visibility - interface for the CNWNXVisibility class.
    (c) 2007-2010 virusman (virusman@virusman.ru)

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

#ifndef _NWNX_VISIBILITY_H_
#define _NWNX_VISIBILITY_H_

#include "NWNXBase.h"
#include "gline.h"
#include "HookFunc.h"

#include <map>
#include <string>
using namespace std;

enum OverrideType {
    Default,
    AlwaysVisible,
    AlwaysInvisible
};
typedef map< unsigned int, unsigned int, less<unsigned int> > ObjectVisMap;
struct ObjectEntry {
    OverrideType eOverrideType;
    ObjectVisMap vismap;
};
typedef map< unsigned int, ObjectEntry, less<unsigned int> > ObjectsMap;

class CNWNXVisibility : public CNWNXBase
{

public:
    CNWNXVisibility();
    ~CNWNXVisibility();
    bool OnCreate(gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    bool OnRelease();
    int TestVisibility(dword oObject1, dword oObject2, int &nResult);
    ObjectsMap objects;
    char *pGameObject;
    dword nGameObjectID;

protected:
    void SetVisibilityOverride(dword oObject1, OverrideType eOverrideType);
    void SetVisibility(dword oObject1, dword oObject2, unsigned int nValue);
};

#endif
