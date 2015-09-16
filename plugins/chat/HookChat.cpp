/***************************************************************************
    Chat plugin for NWNX  - hooks implementation
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

#include "nx_devel.h"
#include "nx_hook.h"
#include "HookChat.h"
#include "NWNXChat.h"

extern CNWNXChat chat;

int (*CNWSMessage__SendServerToPlayerChatMessage)(CNWSMessage *, uint8_t, uint32_t, CExoString, uint32_t, CExoString const *);
int (*CNWSMessage__SendServerToPlayerCCMessage)(CNWSMessage *, uint32_t, uint8_t, CNWCCMessageData *, CNWSCombatAttackData *);

void SendServerToPlayerChatMessage_hook(CNWSMessage *pthis, uint8_t mode, uint32_t id, CExoString msg, uint32_t to, CExoString const *xz)
{
    bool suppress = false;
    if (!chat.scriptRun)
        suppress = chat.Chat(mode, id, msg.Text, to);

    if (!chat.scriptRun && suppress)
        return;

    CNWSMessage__SendServerToPlayerChatMessage(pthis, mode, id, msg, to, xz);
}

void SendServerToPlayerCCMessage_hook(CNWSMessage *pMessage, uint32_t nPlayerID, uint8_t nMessageID,
                                      CNWCCMessageData *pMessageData, CNWSCombatAttackData *pCombatData)
{
    bool suppress = false;
    CNWSClient *client = g_pAppManager->ServerExoApp->GetClientObjectByPlayerId(nPlayerID, 0);
    if (client) {
        CNWSPlayer *player = reinterpret_cast<CNWSPlayer *>(client);
        dword oPC = player->m_oidPCObject;
        int nSubtype = nMessageID == 11 ? pMessageData->IntList.Array[9] : 0;
        chat.Log(3, "PlayerID=%d, ObjectID=%08lX, MessageID=%d, MessageSubID=%d\n", nPlayerID, oPC, nMessageID, nMessageID == 11 ? pMessageData->IntList.Array[9] : 0);
        if (!chat.scriptRun)
            suppress = chat.CCMessage(oPC, nMessageID, nSubtype, pMessageData);
    }
    if (!chat.scriptRun && suppress)
        return;

    CNWSMessage__SendServerToPlayerCCMessage(pMessage, nPlayerID, nMessageID, pMessageData, pCombatData);
}

void RunScript(char * sname, int ObjID)
{
    CExoString script(sname);
    g_pVirtualMachine->RunScript(&script, ObjID, 1);
}

int SendMsg(const int mode, const int id, char *msg, const int to)
{
    CNWSMessage *pMessage = reinterpret_cast<CNWSMessage *>(g_pAppManager->ServerExoApp->GetNWSMessage());
    CExoString xz;
    CExoString m(msg);
    pMessage->SendServerToPlayerChatMessage(mode, id, m, to, xz);
    return 1;
}

int SendMsgSingle(int mode, int conn, int speaker, char *msg)
{

    CNWSMessage *pMessage = reinterpret_cast<CNWSMessage *>(g_pAppManager->ServerExoApp->GetNWSMessage());
    // printf("in SendMsgTalk: %d %x '%s'; pServThis=%p pMessage=%p pChatThis=%p\n", conn, speaker, msg, pServThis, pMessage, pChatThis);
    if (!pMessage) {
        printf("pMessage is nil? wtf.\n");
        return 0;
    }
    CExoString str;

    str.Text = strdup(msg);
    str.Length = strlen(msg);
    switch (mode) {
        // Talk
        case 1: return pMessage->SendServerToPlayerChat_Talk(conn, speaker, str);
        // Shout
        case 2: return pMessage->SendServerToPlayerChat_Shout(conn, speaker, str);
        // Whisper
        case 3: return pMessage->SendServerToPlayerChat_Whisper(conn, speaker, str);
        // Private
        case 4: return pMessage->SendServerToPlayerChat_Tell(conn, speaker, str);
        // Server_Msg
        case 5: return pMessage->SendServerToPlayerChat_ServerTell(conn, str);
        // Party
        case 6: return pMessage->SendServerToPlayerChat_Party(conn, speaker, str);
        // Talk_DM
        case 17: return pMessage->SendServerToPlayerChat_DM_Talk(conn, speaker, str);
        // Whisper_DM
        case 19: return pMessage->SendServerToPlayerChat_DM_Whisper(conn, speaker, str);
        default:
            // Unsupported.
            return 0;
    }

}

int HookFunctions()
{
    NX_HOOK(CNWSMessage__SendServerToPlayerChatMessage,
            0x0806839C,
            SendServerToPlayerChatMessage_hook,
            5);

    NX_HOOK(CNWSMessage__SendServerToPlayerCCMessage,
            0x08078AB8,
            SendServerToPlayerCCMessage_hook,
            5);
    return 1;
}


