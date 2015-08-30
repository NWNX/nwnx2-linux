/***************************************************************************
    NWNX Events - interface for the CNWNXEvents class.
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
#include "HookFunc.h"

#define OBJECT_INVALID                  0x7F000000

#define EVENT_TYPE_ALL                   0
#define EVENT_TYPE_SAVE_CHAR             1
#define EVENT_TYPE_PICKPOCKET            2
#define EVENT_TYPE_ATTACK                3
#define EVENT_TYPE_USE_ITEM              4
#define EVENT_TYPE_QUICKCHAT             5
#define EVENT_TYPE_EXAMINE               6
#define EVENT_TYPE_USE_SKILL             7
#define EVENT_TYPE_USE_FEAT              8
#define EVENT_TYPE_TOGGLE_MODE           9
#define EVENT_TYPE_CAST_SPELL           10
#define EVENT_TYPE_TOGGLE_PAUSE         11
#define EVENT_TYPE_POSSESS_FAMILIAR     12
#define EVENT_TYPE_VALIDATE_CHARACTER   13
#define EVENT_TYPE_DESTROY_OBJECT       14
#define EVENT_TYPE_CREATE_OBJECT        15
#define NUM_EVENT_TYPES                 16

enum eNodeType {StartingNode, EntryNode, ReplyNode};

class CNWNXEvents : public CNWNXBase
{
    HANDLE hEvent;
public:
    CNWNXEvents();
    ~CNWNXEvents();
    bool OnCreate(gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    unsigned long OnRequestObject(char *gameObject, char* Request);
    bool OnRelease();
    int FireEvent(const int pObj, int nEvID);

    char *eventScripts[NUM_EVENT_TYPES];

    char *pGameObject;
    dword nGameObjectID;
    bool bBypass;
    bool scriptRun;
    int nReturnValue;
    int nEventID;
    int nEventSubID;
    dword oTarget;
    dword oItem;
    CNWSDialog *pConversation;
    unsigned int nSelectedNodeID;
    int nSelectedAbsoluteNodeID;
    int nCurrentAbsoluteNodeID;
    int nCurrentNodeID;
    int nNodeType;
    Vector vPosition;
};

#endif
