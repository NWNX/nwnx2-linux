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

#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "HookChat.h"
#include "NWNXChat.h"

extern CNWNXChat chat;

void *(*CServerExoApp__GetClientObjectByPlayerId)(void *pExoApp, int nPlayerID, char a3);
void (*pRunScript)(void *pScriptMachine, CExoString *script_name, dword ObjID, int arg_4);
dword pServThis = 0;
void *pServer = 0;
void *pServerExo = 0;
dword pList = 0;
dword pScriptThis = 0;
char *pChatThis = 0;
dword * (*pGetPCobj)(dword someObj, dword OID);
int (*pChat)(char * pthis, int mode, int id, char **msg, int to, char * xz);

char scriptRun = 0;
char *lastMsg;
char lastIDs[32];

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */

unsigned char d_ret_code_chat[0x20];
unsigned char d_ret_code_cc[0x20];

unsigned long lastRet;

void ChatHookProc(char * pthis, const int mode, const int id, const char **msg, const int to, const char * xz)
{
	asm ("pusha");
	if(!pChatThis) pChatThis = pthis;
	if (!scriptRun)
		lastRet = chat.Chat(mode, id, msg, to);
	asm ("popa");
	asm ("leave");
	if (!scriptRun && lastRet)
		asm ("ret");
	asm ("mov $d_ret_code_chat, %eax");
	asm ("jmp *%eax");
}

void SendServerToPlayerCCMessageHookProc(void *pMessage, int nPlayerID, char nMessageID, CNWCCMessageData *pMessageData, void *pCombatData)
{
	asm ("pusha");
	if(!pServerExo)
		InitConstants();
	CNWSClient *pPC = (CNWSClient *) CServerExoApp__GetClientObjectByPlayerId(pServerExo, nPlayerID, 0);
	if(pPC){
		dword oPC = pPC->CreatureObjID;
		int nSubtype = nMessageID==11 ? pMessageData->IntList.Array[9] : 0;
		chat.Log(3, "PlayerID=%d, ObjectID=%08lX, MessageID=%d, MessageSubID=%d\n", nPlayerID, oPC, nMessageID, nMessageID==11 ? pMessageData->IntList.Array[9] : 0);
		if (!scriptRun)
			lastRet = chat.CCMessage(oPC, nMessageID, nSubtype, pMessageData);
	}
	asm ("popa");
	asm ("leave");
	if (!scriptRun && lastRet)
		asm ("ret");
	asm ("mov $d_ret_code_cc, %eax");
	asm ("jmp *%eax");
}


// finds the address of the Chat function
// 08067998 - chatMsg : 55 89 e5 57 56 53 81 ec 38 02 00 00 8a 45 0c
// +0x23 - ptr to thisServ = this_script_run+8
unsigned long
FindChat ()
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr)
    {
        if ((ptr[0] == (char) 0x55) &&
            (ptr[1] == (char) 0x89) &&
            (ptr[2] == (char) 0xe5) &&
            (ptr[3] == (char) 0x57) &&
            (ptr[4] == (char) 0x56) &&
            (ptr[5] == (char) 0x53) &&
            (ptr[6] == (char) 0x81) &&
            (ptr[7] == (char) 0xec) &&
            (ptr[8] == (char) 0x38) &&
            (ptr[9] == (char) 0x02) &&
            (ptr[10] == (char) 0x00) &&
            (ptr[11] == (char) 0x00)
            )
            return (unsigned long) ptr;
	else
	    ptr++;
    }
    return 0;
}

// finds the address of the GetPCobjByOID function
// 080AA9CC - GetPCobjByOID : 55 89 E5 57 56 53 83 EC 0C 8B 7D 0C 81 FF 00 00 00 7F
unsigned long
FindGetPCobjByOID ()
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr)
    {
        if ((ptr[0] == (char) 0x55) &&
            (ptr[1] == (char) 0x89) &&
            (ptr[2] == (char) 0xe5) &&
            (ptr[3] == (char) 0x57) &&
            (ptr[4] == (char) 0x56) &&
            (ptr[5] == (char) 0x53) &&
            (ptr[6] == (char) 0x83) &&
            (ptr[7] == (char) 0xec) &&
            (ptr[8] == (char) 0x0c) &&
            (ptr[9] == (char) 0x8b) &&
//            (ptr[10] == (char) 0x7d) &&
            (ptr[11] == (char) 0x0c) &&
            (ptr[12] == (char) 0x81) &&
//            (ptr[13] == (char) 0xff) &&
            (ptr[14] == (char) 0x00) &&
            (ptr[15] == (char) 0x00) &&
            (ptr[16] == (char) 0x00) &&
            (ptr[17] == (char) 0x7f)
            )
            return (unsigned long) ptr;
	else
	    ptr++;
    }
    return 0;
}

// 0824AA5C - runScript : 55 89 e5 57 56 53 83 ec 18 ff 75 0c e8 eb
unsigned long
FindRunScript()
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr)
    {
		if ((ptr[0] == (char) 0x55) &&
			(ptr[1] == (char) 0x89) &&
			(ptr[2] == (char) 0xe5) &&
			(ptr[3] == (char) 0x57) &&
			(ptr[4] == (char) 0x56) &&
			(ptr[5] == (char) 0x53) &&
			(ptr[6] == (char) 0x83) &&
			(ptr[7] == (char) 0xec) &&
			(ptr[8] == (char) 0x18) &&
 			(ptr[9] == (char) 0xFF) &&
 			(ptr[10] == (char) 0x75) &&
 			(ptr[11] == (char) 0x0C) &&
 			(ptr[12] == (char) 0xE8) &&
 			(ptr[0x3B] == (char) 0x84) &&
 			(ptr[0x3C] == (char) 0x01) &&
 			(ptr[0x3D] == (char) 0x00)
			)
            return (unsigned long) ptr;
	else
	    ptr++;
    }
	ptr = (char *) start_addr;
    while (ptr < (char *) end_addr)
    {
		if ((ptr[0] == (char) 0x55) &&
			(ptr[1] == (char) 0x89) &&
			(ptr[2] == (char) 0xe5) &&
			(ptr[3] == (char) 0x57) &&
			(ptr[4] == (char) 0x56) &&
			(ptr[5] == (char) 0x53) &&
			(ptr[6] == (char) 0x83) &&
			(ptr[7] == (char) 0xec) &&
			(ptr[8] == (char) 0x18) &&
 			(ptr[9] == (char) 0xFF) &&
 			(ptr[10] == (char) 0x75) &&
 			(ptr[11] == (char) 0x0C) &&
 			(ptr[12] == (char) 0x8B) &&
 			(ptr[13] == (char) 0x7D) &&
 			(ptr[14] == (char) 0x10) &&
 			(ptr[15] == (char) 0xE8) &&
 			(ptr[0x38] == (char) 0x8B) &&
 			(ptr[0x39] == (char) 0x45) &&
 			(ptr[0x3A] == (char) 0x08)
			)
            return (unsigned long) ptr;
	else
	    ptr++;
    }
    return 0;
}

void RunScript(char * sname, int ObjID)
{
	CExoString script_name;
	script_name.Text = sname;
	script_name.Length = strlen(sname);
	scriptRun = 1;
	pRunScript(*(dword **)pScriptThis, &script_name, ObjID, 1);
	scriptRun = 0;
}

int SendMsg(const int mode, const int id, char *msg, const int to)
{
	if(pChatThis)
	{
		char xz=0;
		return pChat(pChatThis, mode, id, &msg, to, &xz);
	}
	return 0;
}

unsigned long * GetPCobj(dword OID)
{
  asm("movl pServThis, %eax");
  asm("mov (%eax), %eax");
  asm("mov 4(%eax), %eax");
  asm("mov 4(%eax), %eax");
  asm("mov %eax, pList");
  return pGetPCobj(pList, OID);
}

unsigned long GetID(dword OID)
{
	dword * pcObj = GetPCobj(OID);
	if(!pcObj) return 0x7F000000;
	return *(pcObj);
}

void
d_enable_write (unsigned long location)
{
    char *page;
    page = (char *) location;
    page = (char *) (((int) page + PAGESIZE - 1) & ~(PAGESIZE - 1));
    page -= PAGESIZE;

    if (mprotect (page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
	perror ("mprotect");
}

int intlen = -1;

void
d_redirect (long from, long to, unsigned char *d_ret_code, long len=0)
{
    // enable write to code pages
    d_enable_write (from);
    // copy orig code stub to our "ret_code"
    len = len ? len : sizeof(d_jmp_code)-1; // - trailing 0x00
    intlen = len;
    memcpy ((void *) d_ret_code, (const void *) from, len);
    // make ret code
    *(long *)(d_jmp_code + 1) = from + len;
    memcpy ((char *) d_ret_code + len, (const void *) d_jmp_code, 6);
    // make hook code
    *(long *)(d_jmp_code + 1) = to;
    memcpy ((void *) from, (const void *) d_jmp_code, 6);
}

int HookFunctions()
{
  dword org_Chat = FindChat();
  dword org_Run  = FindRunScript();
  dword org_Get  = FindGetPCobjByOID();
  dword org_SendServerToPlayerCCMessage = 0x08078AB8;
  if (org_Chat)
	{
      pServThis = *(dword*)(org_Chat + 0x23);
	  //pChatThis = *(dword*)(pServThis + 0x4);
      pScriptThis = pServThis - 8;
      d_redirect (org_Chat, (unsigned long)ChatHookProc, d_ret_code_chat, 12);
	  *(dword*)&pChat = org_Chat;
	}

	if (org_SendServerToPlayerCCMessage)
	{
		d_redirect (org_SendServerToPlayerCCMessage, (unsigned long)SendServerToPlayerCCMessageHookProc, d_ret_code_cc, 12);
	}

	*(dword*)&CServerExoApp__GetClientObjectByPlayerId = 0x080B24D0;


	if (org_Run) {
		*(dword*)&pRunScript = org_Run;
  }
	if (org_Get) {
		*(dword*)&pGetPCobj = org_Get;
  }

	if (org_Chat)
		chat.Log(0, "! ChatProc hooked at %x.\n", org_Chat);
	else
		chat.Log(0, "X Could not find Chat function or hook failed: %x\n", org_Chat);

	if (org_Run)
		chat.Log(0, "! RunProc located at %x.\n", org_Run);
	else
		chat.Log(0, "X Could not find Run function: %x\n", org_Run);

	return (org_Chat && org_Run && org_Get && pServThis && pScriptThis);
}

void InitConstants()
{
	*(dword*)&pServer = *(dword*)pServThis;
	*(dword*)&pServerExo = *(dword*)((char*)pServer+0x4);
}


