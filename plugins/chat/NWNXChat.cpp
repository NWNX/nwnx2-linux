/***************************************************************************
    Chat plugin for NWNX - Implementation of the CNWNXChat class.
    (c) 2005-2006 dumbo (dumbo@nm.ru)
	(c) 2006-2010 virusman (virusman@virusman.ru)

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

#include "NWNXChat.h"
#include "HookChat.h"
#include "pluginlink.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXChat::CNWNXChat()
{
    confKey = "CHAT";
    strcpy(chatScript, "chat_script");
    strcpy(ccScript, "cc_script");
    processNPC = 0;
    ignore_silent = 0;
    maxMsgLen = 1024;
    scriptRun = false;
}

CNWNXChat::~CNWNXChat()
{
}

bool CNWNXChat::OnCreate(gline *config, const char* LogDir)
{
    char log[128];
    bool validate = true, startServer = true;

    // call the base class function
    sprintf(log, "%s/nwnx_chat.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    // write copy information to the log file
    Log(0, "NWNX Chat version 1.0.0 for Linux.\n");
    Log(0, "(c) 2005-2006 by dumbo (dumbo@nm.ru)\n");
    Log(0, "(c) 2006-2010 virusman (virusman@virusman.ru)\n");

    if (nwnxConfig->exists(confKey)) {
        if (nwnxConfig->exists(confKey, "chat_script")) {
            strncpy(chatScript, (*nwnxConfig)[confKey]["chat_script"].c_str(), 16);
            chatScript[16] = 0;
        }
        strncpy(servScript, (*nwnxConfig)[confKey]["server_script"].c_str(), 16);
        if (nwnxConfig->exists(confKey, "cc_script")) {
            strncpy(ccScript, (*nwnxConfig)[confKey]["cc_script"].c_str(), 16);
            ccScript[16] = 0;
        }
        servScript[16] = 0;
        int maxLen = atoi((*nwnxConfig)[confKey]["max_msg_len"].c_str());
        if (maxLen) maxMsgLen = maxLen;
        int logNPC = atoi((*nwnxConfig)[confKey]["processnpc"].c_str());
        if (logNPC) processNPC = logNPC;
        int ignoreS = atoi((*nwnxConfig)[confKey]["ignore_silent"].c_str());
        if (ignoreS) ignore_silent = ignoreS;
    }
    lastMsg = new char[maxMsgLen + 13];
    Log(1, "Settings:\n");
    Log(1, "chat_script: %s\n", chatScript);
    Log(1, "server_script: %s\n", servScript);
    Log(1, "cc_script: %s\n", ccScript);
    Log(1, "max_msg_len: %d\n", maxMsgLen);
    Log(1, "processnpc: %d\n", processNPC);
    Log(1, "ignore_silent: %d\n\n", ignore_silent);

    // Plugin Events
    if (!pluginLink) {
        Log(0, "Plugin link not accessible\n");
    } else {
        Log(0, "Plugin link: %08lX\n", pluginLink);
        hChatMessage = CreateHookableEvent(EVENT_CHAT_MESSAGE);
        hCCMessage = CreateHookableEvent(EVENT_CHAT_CCMESSAGE);
    }

    return (HookFunctions());
}

char *CNWNXChat::SendMessage(char* Parameters)
{
    Log(3, "o SPEAK: %s, OID: %08lX\n", Parameters);
    int oSender, oRecipient, nChannel;
    int nParamLen = strlen(Parameters);
    char *nLastDelimiter = strrchr(Parameters, '\xAC');
    if (!nLastDelimiter || (nLastDelimiter - Parameters) < 0) {
        Log(3, "o nLastDelimiter error\n");
        return "0";
    }
    int nMessageLen = nParamLen - (nLastDelimiter - Parameters) + 1;
    char *sMessage = new char[nMessageLen];
    if (sscanf(Parameters, "%x\xAC%x\xAC%d\xAC", &oSender, &oRecipient, &nChannel) < 3) {
        Log(3, "o sscanf error\n");
        delete[] sMessage;
        return "0";
    }
    strncpy(sMessage, nLastDelimiter + 1, nMessageLen - 1);
    int nRecipientID = g_pAppManager->ServerExoApp->GetPlayerIDByGameObjectID(oRecipient);
    if ((nChannel == 4 || nChannel == 5 || nChannel == 20 || nChannel == 21) &&
            oRecipient <= 0x7F000000) {
        Log(3, "o oRecipient is not a PC\n");
        delete[] sMessage;
        return "0";
    }
    if ((nChannel == 0x6 || nChannel == 0x16) && oSender <= 0x7F000000) {
        Log(3, "o oSender is not a PC - invalid for party channel\n");
        delete[] sMessage;
        return "0";
    }
    if (nChannel != 4 && nChannel != 5 && nChannel != 20 && nChannel != 21)
        nRecipientID = -1;
    Log(3, "o SendMsg(%d, %08lX, '%s', %d)\n", nChannel, oSender, sMessage, nRecipientID);
    int nResult = SendMsg(nChannel, oSender, sMessage, nRecipientID);
    Log(3, "o Return value: %d\n", nResult); //return value for full message delivery acknowledgement
    if (nResult) return "1";
    else return "0";
}

char *CNWNXChat::SendMessageSingle(char* Parameters)
{
    Log(3, "o SENDMSGSINGLE: %s, OID: %08lX\n", Parameters);
    int oSendTo, mode, oSender;

    int nParamLen = strlen(Parameters);
    char *nLastDelimiter = strrchr(Parameters, '\xAC');
    if (!nLastDelimiter || (nLastDelimiter - Parameters) < 0) {
        Log(3, "o nLastDelimiter error\n");
        return "0";
    }
    int nMessageLen = nParamLen - (nLastDelimiter - Parameters) + 1;
    char *sMessage = new char[nMessageLen];
    if (sscanf(Parameters, "%d\xAC%x\xAC%x\xAC", &mode, &oSendTo, &oSender) < 2) {
        Log(3, "o sscanf error\n");
        delete[] sMessage;
        return "0";
    }

    int nRecipientID = oSendTo;

    strncpy(sMessage, nLastDelimiter + 1, nMessageLen - 1);

    Log(3, "o SendMsgSingle(%d, %d, %08lX, '%s', %d)\n", mode, nRecipientID, oSender, sMessage);
    int nResult = SendMsgSingle(mode, nRecipientID, oSender, sMessage);
    Log(3, "o Return value: %d\n", nResult); //return value for full message delivery acknowledgement
    if (nResult) return "1";
    else return "0";
}

char* CNWNXChat::OnRequest(char* gameObject, char* Request, char* Parameters)
{
    if (strncmp(Request, "GETID", 5) == 0) {
        int OID = strtol(Parameters, 0, 16);
        char *LastID = (char *) malloc(32);
        if (!OID)
            strcpy(LastID, "-1");
        else
            sprintf(LastID, "%ld", g_pAppManager->ServerExoApp->GetPlayerIDByGameObjectID(OID));
        Log(3, "o GETID: oID='%s', ID=%s\n", Parameters, LastID);
        return LastID;
    } else if (strncmp(Request, "LOGNPC", 6) == 0) {
        Log(3, "o LOGNPC: %s\n", Parameters);
        processNPC = atoi(Parameters);
        Log(3, "o processNPC = %d\n", processNPC);
    } else if (strncmp(Request, "IGNORESILENT", 12) == 0) {
        Log(3, "o IGNORESILENT: %s\n", Parameters);
        ignore_silent = atoi(Parameters);
        Log(3, "o ignore_silent = %d\n", ignore_silent);
    } else if (strncmp(Request, "SPEAK", 5) == 0) {
        char *sReturn = SendMessage(Parameters);
        strncpy(Parameters, sReturn, strlen(Parameters));
        Parameters[strlen(sReturn)] = 0;
        return NULL;
    } else if (strncmp(Request, "SENDMSGSINGLE", 13) == 0) {
        char *sReturn = SendMessageSingle(Parameters);
        strncpy(Parameters, sReturn, strlen(Parameters));
        Parameters[strlen(sReturn)] = 0;
        return NULL;
    }

    if (!scriptRun) return NULL; // all following cmds - only in chat script

    if (strncmp(Request, "TEXT", 4) == 0) {
        unsigned int length = strlen(lastMsg);
        char *ret = (char *) malloc(length + 1);
        strncpy(ret, lastMsg, length);
        ret[length] = 0;
        return ret;
    } else if (strncmp(Request, "TYPE", 4) == 0) {
        char *ret = (char *) malloc(32);
        sprintf(ret, "%d", messageType);
        return ret;
    } else if (strncmp(Request, "SUBTYPE", 7) == 0) {
        char *ret = (char *) malloc(32);
        sprintf(ret, "%d", messageSubtype);
        return ret;
    }

    else if (strncmp(Request, "LOG", 3) == 0)
        Log(0, "%s", Parameters);
    else if (strncmp(Request, "SUPRESS", 7) == 0) {
        if (atoi(Parameters) == 1)
            supressMsg = 1;
    }
    return NULL;
}

bool CNWNXChat::OnRelease()
{
    delete[] lastMsg;
    Log(0, "o Shutdown.\n");
    return true;
}

int CNWNXChat::Chat(const int mode, const int id, const char *msg, const int to)
{
    if (!msg || !*msg) return 0;   // disable processing of null-string
    int cmode = mode & 0xFF;
    Log(3, "o CHAT: mode=%lX, from_oID=%08lX, msg='%s', to_ID=%08lX\n", cmode, id, msg, to);
    sprintf(lastMsg, "%02d%10d", cmode, to);
    strncat(lastMsg, msg, maxMsgLen);

    ChatMessageEvent event;
    event.suppress = supressMsg = 0;
    event.msg = msg;
    event.to = to;
    event.from = id;
    event.channel = mode;

    if (ignore_silent && (cmode == 0xD || cmode == 0xE)) return 0;
    scriptRun = true;
    if ((processNPC && id != 0x7F000000) || (!processNPC && (unsigned long)id >> 16 == 0x7FFF)) {
        if (NotifyEventHooks(hChatMessage, (uintptr_t)&event)) {
            supressMsg = event.suppress;
        } else {
            RunScript(chatScript, id);
        }
    } else if (cmode == 5 && id == 0x7F000000) {
        if (NotifyEventHooks(hChatMessage, (uintptr_t)&event)) {
            supressMsg = event.suppress;
        } else if (*servScript) {
            RunScript(servScript, 0);
        }
    }
    scriptRun = false;
    return supressMsg;
}

int CNWNXChat::CCMessage(const int objID, const int type, const int subtype,
                         CNWCCMessageData *messageData)
{
    ChatCCMessageEvent event;
    event.suppress = supressMsg = 0;
    event.type = messageType = type;
    event.subtype = messageSubtype = subtype;
    event.to = objID;
    event.msg_data = messageData;

    scriptRun = true;
    if (NotifyEventHooks(hCCMessage, (uintptr_t)&event)) {
        supressMsg = event.suppress;
    } else {
        RunScript(ccScript, objID);
    }
    scriptRun = false;

    return supressMsg;
}
