/***************************************************************************
    Chat plugin for NWNX - interface for the CNWNXChat class.
    (c) 2005-2006 dumbo (dumbo@nm.ru)
	(c) 2006-2007 virusman (virusman@virusman.ru)

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

#ifndef _NWNX_CHAT_H_
#define _NWNX_CHAT_H_

#include "NWNXBase.h"
#include "api/all.h"
#include "HookChat.h"

class CNWNXChat : public CNWNXBase
{
    HANDLE hChatMessage;
    HANDLE hCCMessage;
    char *lastMsg;
public:
    CNWNXChat();
    ~CNWNXChat();
    bool OnCreate(gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    bool OnRelease();
    bool supressMsg;
    int maxMsgLen;
    int processNPC;
    int ignore_silent;
    int messageType;
    int messageSubtype;
    char chatScript[17];
    char servScript[17];
    char ccScript[17];
    int Chat(const int mode, const int id, const char *msg, const int to);
    int CCMessage(const int objID, const int type, const int subtype, CNWCCMessageData* messageData);
    bool scriptRun;

protected:
    char *SendMessage(char* Parameters);
    char *SendMessageSingle(char* Parameters);
};

#endif
