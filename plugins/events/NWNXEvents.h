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

enum eNodeType {StartingNode, EntryNode, ReplyNode};

class CNWNXEvents : public CNWNXBase
{

public:
	CNWNXEvents();
	~CNWNXEvents();
	bool OnCreate(gline *config, const char* LogDir);
	char* OnRequest(char* gameObject, char* Request, char* Parameters);
	unsigned long OnRequestObject (char *gameObject, char* Request);
	bool OnRelease();
	int FireEvent(const int pObj, int nEvID);
	//int supressMsg;
    char eventScript[17];
	char *pGameObject;
	dword nGameObjectID;
	bool bBypass;
	int nEventID;
	int nEventSubID;
	dword oTarget;
	dword oItem;
	int nRadial;
	CNWSDialogClass *pConversation;
	int nSelectedNodeID;
	int nSelectedAbsoluteNodeID;
	int nCurrentAbsoluteNodeID;
	int nCurrentNodeID;	
	int nNodeType;
	CNWSVector vPosition;

protected:
};

#define OBJECT_INVALID 0x7F000000
#define EVENT_SAVE_CHAR 1
#define EVENT_PICKPOCKET 2
#define EVENT_ATTACK 3
#define EVENT_USE_ITEM 4
#define EVENT_QUICKCHAT 5
#define EVENT_EXAMINE 6
#define EVENT_USE_SKILL 7
#define EVENT_USE_FEAT 8
#define EVENT_TOGGLE_MODE 9

#endif
