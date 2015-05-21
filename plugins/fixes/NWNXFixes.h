/***************************************************************************
    NWNXFixes.h - Interface for the CNWNXFixes class.
    (c) 2007 virusman (virusman@virusman.ru)

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

#ifndef NWNXFixes_h_
#define NWNXFixes_h_

#include <map>
#include <string>
#include "NWNXBase.h"
#include "typedefs.h"

class CNWNXFixes : public CNWNXBase
{
public:
    CNWNXFixes();
    virtual ~CNWNXFixes();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    unsigned long OnRequestObject(char *gameObject, char* Request);
    int GetConfInteger(const char *key);
    bool bHooked;

    StringMap pluginConfig;

    int bHideCharList, bHidePortraits, bHideClasses, bHideDMs;
private:

};

#endif
