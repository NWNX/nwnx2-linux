/***************************************************************************
    NWNX Names - interface for the CNWNXNames class.
    (c) 2006 virusman (virusman@virusman.ru)

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

#ifndef _NWNX_EVENTS_H_
#define _NWNX_EVENTS_H_

#include "NWNXBase.h"
#include "gline.h"
#include "HookFunc.h"
#include "CCustomNames.h"

class CNWNXNames : public CNWNXBase
{

public:
    CNWNXNames();
    ~CNWNXNames();
    bool OnCreate(gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    bool OnRelease();
    int supressMsg;
    char eventScript[17];
    int logDebug;
    CCustomNames Names;
    char *pGameObject;
    dword nGameObjectID;
    FILE *PacketData;

protected:
    void InitPlayerList(char *value);
    void EnableDisableNames(char *value);
    char *GetDynamicName(char *value);
    void SetDynamicName(char *value);
    void UpdateDynamicName(char *value);
    void UpdatePlayerList(char *value);
    void DeleteDynamicName(char *value);
    void ClearPlayerList(char *value);
};

#endif
