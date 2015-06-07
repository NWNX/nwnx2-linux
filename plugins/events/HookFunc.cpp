/***************************************************************************
    Events plugin for NWNX  - hooks implementation
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

#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <stdarg.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "HookFunc.h"
#include "NWNXEvents.h"
#include "AssemblyHelper.cpp"

extern CNWNXEvents events;
AssemblyHelper asmhelp;

dword pPlayer = 0;
dword oPC = 0;
dword oTarget_b = OBJECT_INVALID;
dword oItem_b = OBJECT_INVALID;
int bBypass_b = 0;
int nEventSubID_b = 0;
dword buffer;


char ActionScriptRunning = 0;
char ConditionalScriptRunning = 0;


unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */

unsigned char d_ret_code_sc[0x20];
unsigned char d_ret_code_pp[0x20];
unsigned char d_ret_code_at[0x20];
unsigned char d_ret_code_ui[0x20];
unsigned char d_ret_code_cn[0x20];
unsigned char d_ret_code_sn[0x20];
unsigned char d_ret_code_cs[0x20];
unsigned char d_ret_code_qc[0x20];
unsigned char d_ret_code_ei[0x20];
unsigned char d_ret_code_ec[0x20];
unsigned char d_ret_code_ep[0x20];
unsigned char d_ret_code_ed[0x20];
unsigned char d_ret_code_us[0x20];
unsigned char d_ret_code_uf[0x20];
unsigned char d_ret_code_tm[0x20];
unsigned char d_ret_code_cz[0x20];
unsigned char d_ret_code_tp[0x20];
unsigned char d_ret_code_pf[0x20];
unsigned char d_ret_code_vc[0x20];
unsigned char d_ret_code_objdest[0x20];

int (*CNWSPlayer__ValidateCharacter)(CNWSPlayer *pPlayer, int *result);
void (*CNWSObject___CNWSObject)(CNWSObject *pObject, int n) = (void (*)(CNWSObject*, int)) 0x081C8E94;
int (*CVirtualMachine__GetRunScriptReturnValue)(CVirtualMachine *pVirtualMachine, int *a2, void **a3) = (int (*)(CVirtualMachine *, int *, void **)) 0x08264324;

unsigned char **pEBP;

void SaveCharHookProc()
{
    asm("pusha");
    if (!events.scriptRun) {
        //Get pPlayer
        asm("mov 0x8(%ebp), %eax");
        asm("mov %eax, pPlayer");

        //asm ("add $4, %edi");
        //asm ("mov %edi, oPC");
        //asm ("sub $4, %edi");
        if (pPlayer)
            events.FireEvent(*((dword *)pPlayer + 0xC), EVENT_TYPE_SAVE_CHAR); //+0x30=game obj ID
    }
    asm("popa");
    asm("leave");
    asm("mov $d_ret_code_sc, %eax");
    asm("jmp *%eax");
}

void PickPocketHookProc()
{
    asm("pusha");
    if (!events.scriptRun) {
        //Get oPC
        asm("mov 0x8(%ebp), %eax");
        asm("mov %eax, oPC");

        //Get oTarget
        asm("mov 0xC(%ebp), %eax");
        asm("mov 0x34(%eax), %eax");
        asm("mov %eax, oTarget_b");
        events.oTarget = oTarget_b;
        //asm ("sub $4, %edi");
        if (oPC)
            bBypass_b = events.FireEvent(*((dword *)oPC + 1), EVENT_TYPE_PICKPOCKET);
    }
    asm("popa");
    asm("leave");
    if (bBypass_b) {
        asm("mov $2, %eax");
        asm("ret");
    }
    asm("mov $d_ret_code_pp, %eax");
    asm("jmp *%eax");
}

void AttackHookProc()
{
    asm("pusha");
    if (!events.scriptRun) {
        //Get oPC
        asm("mov 0x8(%ebp), %eax");
        asm("mov %eax, oPC");

        //Get oTarget
        asm("mov 0xC(%ebp), %eax");
        asm("mov %eax, oTarget_b");
        events.oTarget = oTarget_b;
        //asm ("sub $4, %edi");

        asm("mov 0x1C(%ebp), %eax");
        asm("mov %eax, nEventSubID_b");
        events.nEventSubID = nEventSubID_b;

        events.Log(2,
                   "Attack: oPC=%08lX, oTarget=%08lX, nSubID=%d\n",
                   *((dword *)oPC + 1), events.oTarget, events.nEventSubID);
        if (oPC)
            bBypass_b = events.FireEvent(*((dword *)oPC + 1), EVENT_TYPE_ATTACK);
    }
    asm("popa");
    asm("leave");
    if (bBypass_b) {
        asm("mov $1, %eax");
        asm("ret");
    }
    asm("mov $d_ret_code_at, %eax");
    asm("jmp *%eax");
}

void UseItemHookProc()
{
    asm("pusha");
    if (!events.scriptRun) {
        //Get oPC
        asm("mov 0x8(%ebp), %eax");
        asm("mov %eax, oPC");

        //Get oTarget
        asm("mov 0x24(%ebp), %eax");
        asm("mov %eax, oTarget_b");
        events.oTarget = oTarget_b;

        //Get vTarget
        asm("mov %ebp, %eax");
        asm("add $0x18, %eax");
        asm("mov %eax, buffer");
        CNWSVector *pvTarget = (CNWSVector *) buffer;
        events.vPosition.X = pvTarget->X;
        events.vPosition.Y = pvTarget->Y;
        events.vPosition.Z = pvTarget->Z;

        //Get oItem
        asm("mov 0xC(%ebp), %eax");
        asm("mov %eax, oItem_b");
        events.oItem = oItem_b;

        //Get the radial
        asm("mov 0x10(%ebp), %eax");
        asm("mov %eax, nEventSubID_b");
        events.nEventSubID = nEventSubID_b;

        events.Log(2,
                   "UseItem: oPC=%08lX, oTarget=%08lX, oItem=%08lX, vTarget=%f/%f/%f, nRadial=%d\n",
                   *((dword *)oPC + 1), events.oTarget, events.oItem, events.vPosition.X,
                   events.vPosition.Y, events.vPosition.Z, events.nEventSubID);
        if (oPC)
            bBypass_b = events.FireEvent(*((dword *)oPC + 1), EVENT_TYPE_USE_ITEM);
    }
    asm("popa");
    asm("leave");
    if (bBypass_b) {
        asm("mov $1, %eax");
        asm("ret");
    }
    asm("mov $d_ret_code_ui, %eax");
    asm("jmp *%eax");
}

void ConversationNodeSelectHookProc()
{
    asm("pusha");
    if (!events.scriptRun) {
        //Get oPC
        asm("mov %ebp, pEBP");
        CNWSDialog *pConversation = *(CNWSDialog **)((char *)pEBP + 0x8);
        events.pConversation = pConversation;
        oPC = pConversation->ConversationWith;

        //Get oTarget
        events.oTarget = pConversation->MeObjID;

        //Get SelectedNode
        events.nSelectedNodeID = *(dword *)((char *)pEBP + 0x14);
        events.nSelectedAbsoluteNodeID = -1;
        try {
            dword nCurrentNode = pConversation->CurrentNodeID;
            if (pConversation->EntryListCount > nCurrentNode) {
                CDialogEntry *pCurrentNode = &pConversation->EntryList[nCurrentNode];
                if (pCurrentNode->RepliesNum > events.nSelectedNodeID) {
                    CDialogEntryReply *pCurrentReply = &pCurrentNode->RepliesList[events.nSelectedNodeID];
                    events.nSelectedAbsoluteNodeID = pCurrentReply->Index;
                }
            }
        } catch (...) {
            events.Log(0, "Caught an exception while trying to get absolute node ID\n");
        }

        events.Log(2, "ConversationNodeSelect: oPC=%08lX, oTarget=%08lX, nSelectedNode=%d, nAbsSelectedNode=%d\n",
                   oPC, events.oTarget, events.nSelectedNodeID, events.nSelectedAbsoluteNodeID);
        //events.FireEvent(oPC, EVENT_TYPE_CONVERSATION_NODE_SELECT);
    }
    asm("popa");
    //asm ("leave");
    asm("mov 0x1C(%ebp), %eax");
    asm("push %eax");
    asm("mov 0x18(%ebp), %eax");
    asm("push %eax");
    asm("mov 0x14(%ebp), %eax");
    asm("push %eax");
    asm("mov 0x10(%ebp), %eax");
    asm("push %eax");
    asm("mov 0xC(%ebp), %eax");
    asm("push %eax");
    asm("mov 0x8(%ebp), %eax");
    asm("push %eax");

    asm("mov $d_ret_code_cn, %eax");
    ActionScriptRunning = 1;
    asm("call *%eax");
    asm("add $0x18, %esp");
    ActionScriptRunning = 0;
}

void ConditionalScriptHookProc()
{
    asm("pusha");
    if (!events.scriptRun) {
        //Get structures
        asm("mov %ebp, pEBP");
        CNWSDialog *pConversation = *(CNWSDialog **)((char *)pEBP + 0x8);
        events.pConversation = pConversation;
        dword *pObject = *(dword **)((char *)pEBP + 0xC);
        CDialogReplyEntry *pStartingEntry = *(CDialogReplyEntry **)((char *)pEBP + 0x10);

        //Absolute index. But what is it? Entry, reply or starting entry?
        dword nNodeID = pStartingEntry->Index;
        events.nCurrentAbsoluteNodeID = nNodeID;

        //Identify node type
        try {
            bool bFound = false;
            for (size_t nEntry = 0; nEntry < pConversation->EntryListCount; nEntry++) {
                CDialogEntry* pEntry = &pConversation->EntryList[nEntry];
                for (size_t nReply = 0; nReply < pEntry->RepliesNum; nReply++) {
                    if (&pEntry->RepliesList[nReply] == reinterpret_cast<CDialogEntryReply*>(pStartingEntry)) {
                        events.nNodeType = ReplyNode;
                        events.nCurrentNodeID = nReply;
                        events.Log(2, "Reply: %d\n", nReply);
                        bFound = true;
                        break;
                    }
                }
                if (bFound == true) break;
            }
            if (bFound == false) {
                for (size_t nReply = 0; nReply < pConversation->ReplyListCount; nReply++) {
                    CDialogReply* pReply = &pConversation->ReplyList[nReply];
                    for (size_t nEntry = 0; nEntry < pReply->EntriesNum; nEntry++) {
                        if (&pReply->EntriesList[nEntry] == pStartingEntry) {
                            events.nNodeType = EntryNode;
                            events.nCurrentNodeID = nEntry;
                            events.Log(2, "Entry: %d\n", nEntry);
                            bFound = true;
                            break;
                        }
                    }
                    if (bFound == true) break;
                }
            }
            if (bFound == false) {
                for (size_t nStartingEntry_t = 0; nStartingEntry_t < pConversation->StartingListCount; nStartingEntry_t++) {
                    if (&pConversation->StartingList[nStartingEntry_t] == pStartingEntry) {
                        events.nNodeType = StartingNode;
                        events.nCurrentNodeID = nStartingEntry_t;
                        events.Log(2, "Starting Entry: %d\n", nStartingEntry_t);
                        bFound = true;
                        break;
                    }
                }
            }
            events.Log(2, "ConditionalScript: nNodeID=%d\n", nNodeID);
        } catch (...) {
            events.Log(0, "Caught an exception while trying to get node type\n");
        }
    }
    asm("popa");
    //asm ("leave");
    asm("mov 0x10(%ebp), %eax");
    asm("push %eax");
    asm("mov 0xC(%ebp), %eax");
    asm("push %eax");
    asm("mov 0x8(%ebp), %eax");
    asm("push %eax");
    asm("mov $d_ret_code_cs, %eax");
    ConditionalScriptRunning = 1;
    asm("call *%eax");
    asm("add $0xC, %esp");
    ConditionalScriptRunning = 0;
}

void SendServerToPlayerQuickChatMessageHookProc()
{
    asm("pusha");
    if (!events.scriptRun) {
        //Get oPC
        asm("mov 0xC(%ebp), %eax");
        asm("mov %eax, oPC");

        //Get nSubID
        asm("mov 0x10(%ebp), %eax");
        asm("mov %eax, nEventSubID_b");
        events.nEventSubID = nEventSubID_b;
        //asm ("sub $4, %edi");

        events.Log(2, "QuickChat: oPC=%08lX, nChat=%d\n", oPC, events.nEventSubID);
        if (oPC)
            bBypass_b = events.FireEvent(oPC, EVENT_TYPE_QUICKCHAT);
    }
    asm("popa");
    asm("leave");
    if (bBypass_b) {
        asm("mov $1, %eax");
        asm("ret");
    }
    asm("mov $d_ret_code_qc, %eax");
    asm("jmp *%eax");
}

void ExamineItemHookProc(void *pMessage, CNWSPlayer *pPlayer, dword nObjID)
{
    if (!events.scriptRun) {
        events.oTarget = nObjID;

        events.Log(2, "ExamineItem: pPlayer=%08lX, oTarget=%08lX\n", pPlayer->m_oidNWSObject, events.oTarget);
        if (pPlayer)
            bBypass_b = events.FireEvent(pPlayer->m_oidNWSObject, EVENT_TYPE_EXAMINE);
    }
    asm("leave");
    /*if(bBypass_b) //don't bypass this or the client will draw an empty dialog box
    {
    	asm("ret");
    }*/
    asm("mov $d_ret_code_ei, %eax");
    asm("jmp *%eax");
}

void ExamineCreatureHookProc(void *pMessage, CNWSPlayer *pPlayer, dword nObjID)
{
    if (!events.scriptRun) {
        events.oTarget = nObjID;

        events.Log(2, "ExamineCreature: pPlayer=%08lX, oTarget=%08lX\n", pPlayer->m_oidNWSObject, events.oTarget);
        if (pPlayer)
            bBypass_b = events.FireEvent(pPlayer->m_oidNWSObject, EVENT_TYPE_EXAMINE);
    }
    asm("leave");
    if (bBypass_b) {
        asm("ret");
    }
    asm("mov $d_ret_code_ec, %eax");
    asm("jmp *%eax");
}

void ExaminePlaceableHookProc(void *pMessage, CNWSPlayer *pPlayer, dword nObjID)
{
    if (!events.scriptRun) {
        events.oTarget = nObjID;

        events.Log(2, "ExaminePlaceable: pPlayer=%08lX, oTarget=%08lX\n", pPlayer->m_oidNWSObject, events.oTarget);
        if (pPlayer)
            bBypass_b = events.FireEvent(pPlayer->m_oidNWSObject, EVENT_TYPE_EXAMINE);
    }
    asm("leave");
    if (bBypass_b) {
        asm("ret");
    }
    asm("mov $d_ret_code_ep, %eax");
    asm("jmp *%eax");
}

void ExamineDoorHookProc(void *pMessage, CNWSPlayer *pPlayer, dword nObjID)
{
    if (!events.scriptRun) {
        events.oTarget = nObjID;

        events.Log(2, "ExamineDoor: pPlayer=%08lX, oTarget=%08lX\n", pPlayer->m_oidNWSObject, events.oTarget);
        if (pPlayer)
            bBypass_b = events.FireEvent(pPlayer->m_oidNWSObject, EVENT_TYPE_EXAMINE);
    }
    asm("leave");
    if (bBypass_b) {
        asm("ret");
    }
    asm("mov $d_ret_code_ed, %eax");
    asm("jmp *%eax");
}

void UseSkillHookProc(CNWSCreature *pCreature, byte nSkill, byte nSubSkill, dword nTargetObjID, Vector vTarget, dword nAreaID, dword nItemObjID, int arg_24)
{
    if (!events.scriptRun) {
        events.nEventSubID = nSkill;
        events.oTarget = nTargetObjID;
        events.vPosition = vTarget;
        events.oItem = nItemObjID;

        events.Log(2,
                   "UseSkill: pCreature=%08lX, oTarget=%08lX, oItem=%08lX, vTarget=%f/%f/%f, nSkill=%d\n",
                   pCreature->ObjectID, events.oTarget, events.oItem, events.vPosition.X,
                   events.vPosition.Y, events.vPosition.Z, events.nEventSubID);
        if (pCreature)
            bBypass_b = events.FireEvent(pCreature->ObjectID, EVENT_TYPE_USE_SKILL);
    }
    asm("leave");
    if (bBypass_b) {
        asm("ret");
    }
    asm("mov $d_ret_code_us, %eax");
    asm("jmp *%eax");
}

void UseFeatHookProc(CNWSCreature *pCreature, unsigned short nFeat, unsigned short nSubFeat, dword nTargetObjID, dword nAreaID, CNWSVector *pvTarget)
{
    if (!events.scriptRun) {
        events.nEventSubID = nFeat;
        events.oTarget = nTargetObjID;
        if (pvTarget) {
            events.vPosition.X = pvTarget->X;
            events.vPosition.Y = pvTarget->Y;
            events.vPosition.Z = pvTarget->Z;
        }

        events.Log(2,
                   "UseFeat: pCreature=%08lX, oTarget=%08lX, oItem=%08lX, vTarget=%f/%f/%f, nFeat=%d\n",
                   pCreature->ObjectID, events.oTarget, events.oItem, events.vPosition.X,
                   events.vPosition.Y, events.vPosition.Z, events.nEventSubID);
        if (pCreature)
            bBypass_b = events.FireEvent(pCreature->ObjectID, EVENT_TYPE_USE_FEAT);
    }
    asm("leave");
    if (bBypass_b) {
        asm("ret");
    }
    asm("mov $d_ret_code_uf, %eax");
    asm("jmp *%eax");
}

void ToggleModeHookProc(CNWSCreature *pCreature, byte nMode)
{
    if (!events.scriptRun) {
        events.nEventSubID = nMode;

        events.Log(2, "ToggleMode: pCreature=%08lX, nMode=%d\n", pCreature->ObjectID, events.nEventSubID);
        if (pCreature)
            bBypass_b = events.FireEvent(pCreature->ObjectID, EVENT_TYPE_TOGGLE_MODE);
    }
    asm("leave");
    if (bBypass_b) {
        asm("ret");
    }
    asm("mov $d_ret_code_tm, %eax");
    asm("jmp *%eax");
}

void CastSpellHookProc(CNWSCreature *pCreature,
                       int nSpell,
                       signed int nClassIndex,
                       char nDomainLevel,
                       char nMetaMagic,
                       int a6,
                       CNWSVector vTarget,
                       signed int oTarget,
                       int bTargeted,
                       int a12,
                       int a13,
                       char nProjectilePathType,
                       signed int bInstantSpell,
                       int a16,
                       char a17,
                       char a18)
{
    asm("pusha");
    if (!events.scriptRun) {
        events.oTarget = oTarget;
        events.vPosition.X = vTarget.X;
        events.vPosition.Y = vTarget.Y;
        events.vPosition.Z = vTarget.Z;

        //Get spell id, metamagic, and class index
        events.nEventSubID = nSpell;
        events.nEventSubID |= (nMetaMagic & 0xFF) << 16;
        events.nEventSubID |= (nClassIndex & 0x07) << 24;
        // instant cast flag
        events.nEventSubID |= (!!bInstantSpell) << 27;

        events.Log(2,
                   "CastSpell: oPC=%08lX, oTarget=%08lX, vTarget=(%f/%f/%f), nSpellId=%d, nMetaMagic=%d, nClassIndex=%d, nFlags=%d\n",
                   pCreature->ObjectID, oTarget, vTarget.X, vTarget.Y,
                   vTarget.Z, (events.nEventSubID & 0xFFFF), ((events.nEventSubID >> 16) & 0xFF),
                   ((events.nEventSubID >> 24) & 0x07), ((events.nEventSubID >> 27) & 0x0F)),
                   bBypass_b = events.FireEvent(pCreature->ObjectID, EVENT_TYPE_CAST_SPELL);
    }
    asm("popa");
    asm("leave");
    if (bBypass_b) {
        asm("mov $1, %eax");
        asm("ret");
    }
    asm("mov $d_ret_code_cz, %eax");
    asm("jmp *%eax");
}


void TogglePauseHookProc(void *pThis, unsigned char unknown, int state)
{
    if (!events.scriptRun) {
        events.nEventSubID = state;
        bBypass_b = events.FireEvent(0, EVENT_TYPE_TOGGLE_PAUSE);
    }
    asm("leave");
    if (bBypass_b) {
        asm("ret");
    }
    asm("mov $d_ret_code_tp, %eax");
    asm("jmp *%eax");
}


void PossessFamiliarHookProc(CNWSCreature *pCreature)
{
    if (!events.scriptRun) {
        bBypass_b = events.FireEvent(pCreature->ObjectID, EVENT_TYPE_POSSESS_FAMILIAR);
    }
    asm("leave");
    if (bBypass_b) {
        asm("ret");
    }
    asm("mov $d_ret_code_pf, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer__ValidateCharacter_hook(CNWSPlayer *pPlayer, int *result)
{
    if (!events.scriptRun) {
        CNWSCreature *pCreature = reinterpret_cast<CNWSCreature*>(pPlayer->GetGameObject());
        if (pCreature)
            bBypass_b = events.FireEvent(pCreature->ObjectID, EVENT_TYPE_VALIDATE_CHARACTER);
    }
    if (bBypass_b) {
        if (events.nReturnValue) {
            *result = 0;
            return events.nReturnValue;
        } else {
            *result = 1;
            return 0;
        }
    } else
        return CNWSPlayer__ValidateCharacter(pPlayer, result);
}

void CNWSObject___CNWSObject_hook(CNWSObject *pObject, int n)
{
    events.Log(2, "Object destructor: %08lx\n", pObject);
    if (pObject)
        events.FireEvent(pObject->ObjectID, EVENT_TYPE_DESTROY_OBJECT);
    asm("leave");
    asm("mov $d_ret_code_objdest, %eax");
    asm("jmp *%eax");
}

int GetRunScriptReturnValue()
{
    int type, value;

    if (CVirtualMachine__GetRunScriptReturnValue(g_pVirtualMachine, &type, (void **)&value) && type == 3)
        return value;
    else
        return 0;
}

void RunScript(char * sname, int ObjID) {
    CExoString script_name;
    /* Have to dupe with new API or something that shouldn't will
     * be deleted. */
    script_name.Text = strdup(sname);
    script_name.Length = strlen(sname);
    g_pVirtualMachine->RunScript(&script_name, ObjID, 1);
}

void
d_enable_write(unsigned long location)
{
    char *page;
    page = (char *) location;
    page = (char *)(((int) page + PAGESIZE - 1) & ~(PAGESIZE - 1));
    page -= PAGESIZE;

    if (mprotect(page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
        perror("mprotect");
}

int intlen = -1;

void
d_redirect(long from, long to, unsigned char *d_ret_code, long len = 0)
{
    // enable write to code pages
    d_enable_write(from);
    // copy orig code stub to our "ret_code"
    len = len ? len : sizeof(d_jmp_code) - 1; // - trailing 0x00
    intlen = len;
    memcpy((void *) d_ret_code, (const void *) from, len);
    // make ret code
    *(long *)(d_jmp_code + 1) = from + len;
    memcpy((char *) d_ret_code + len, (const void *) d_jmp_code, 6);
    // make hook code
    *(long *)(d_jmp_code + 1) = to;
    memcpy((void *) from, (const void *) d_jmp_code, 6);
}

void hook_function(long from, long to, unsigned char *d_ret_code, long len = 0)
{
    if (from)
        d_redirect(from, to, d_ret_code, len);
}

void PrintHookInfo(dword function_addr, char *function_name)
{
    if (function_addr)
        events.Log(0, "! %s hooked at %x.\n", function_name, function_addr);
    else
        events.Log(0, "X Could not find %s function or hook failed: %x\n", function_name, function_addr);

}

int HookFunctions(bool enableUnsafe)
{
    dword org_SaveChar = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC B8 00 00 00 FF 75 08 C7 85 74");
    dword org_PickPocket = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC B4 00 00 00  6A 00 8D 75 C8 56 C7 45");
    dword org_Attack = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 18 8B 7D 08 57 E8 ** ** ** ** 83 C4 10 FF 75 0C");
    dword org_UseItem = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC F4 00 00 00 FF 75 0C");
    dword org_ConvSelect = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC AC 00 00 00 8B 75 18 85 F6 8B 7D 08");
    //dword org_ConvShow = asmhelp.FindFunctionBySignature("55 89 E5 56 53 83 EC 10 8B 5D 08 8B 53 40 85 D2");
    dword org_ConditionalScript = asmhelp.FindFunctionBySignature("55 89 E5 56 53 83 EC 28 ** ** ** ** ** 8B 75 10 56");
    dword org_SendServerToPlayerQuickChatMessage = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 78 8B 45 10 66 89 45 9E  C7 45 94 01 00 00 00 C7 45 90 00 00 00 00");
    dword org_ExamineItem = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC ** 00 00 00 8B 5D 0C C7 85 68 FF FF FF 00 00 00 00 8B 03 89 85 64 FF FF FF");
    if (!org_ExamineItem)
        org_ExamineItem = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC  88 00 00 00 8B 5D 0C C7 45 98 00 00 00 00 8B 03 89 45 94");
    dword org_ExamineCreature = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC D8 00 00 00 8B 45 0C C7 85 38 FF FF FF 00 00 00 00 8B 00 89 85 34 FF FF FF");
    if (!org_ExamineCreature)
        org_ExamineCreature = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 78 8B 45 0C C7 45 98 00 00 00 00 8B 00 89 45 94");
    dword org_ExaminePlaceable = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 5C 8B 45 0C 8B 00 6A 01 50 68 80 00 00 00 8B 5D 10 89 45 A8 FF 75 08 +65 FF 52 54");
    if (!org_ExaminePlaceable)
        org_ExaminePlaceable = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 45 0C 8B 38 6A 01 57 68 80 00 00 00 8B 75 08 8B 5D 10 56 +61 FF 52 54");
    dword org_ExamineDoor = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 5C 8B 45 0C 8B 00 6A 01 50 68 80 00 00 00 8B 5D 10 89 45 A8 FF 75 08 +65 FF 52 20");
    if (!org_ExamineDoor)
        org_ExamineDoor = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 45 0C 8B 38 6A 01 57 68 80 00 00 00 8B 75 08 8B 5D 10 56 +61 FF 52 20");
    dword org_UseSkill = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC 9C 00 00 00 8A 45 0C 88 85 67 FF FF FF 8A 45 10 8B 5D 08 88 85 66 FF FF FF");
    dword org_UseFeat = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC C4 00 00 00 8B 45 10 66 89 85 72 FF FF FF 0F B7 45 0C 50 8B 55 08");
    dword org_ToggleMode = asmhelp.FindFunctionBySignature("55 89 E5 53 83 EC 10 8B 5D 08 8A 45 0C 53 88 45 FB E8 ** ** ** ** 83 C4 10 85 C0 0F 85 63 03 00 00");
    dword org_CastSpell = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC 1C 01 00 00 8A 45 3C");
    dword org_TogglePause = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 4C 8A 45 0C 88 45 D3 8B 75 08 8B 86 18 00 01 00 89 45 CC 8A 96 A0 00 01 00 31 C0 84 55 D3 0F 95 C0 3B 45 10 0F 84 47 03 00 00 83 7D 10 01 75 4C 0A 55 D3 83 EC 0C 88 96 A0 00 01 00 FF B6 68 00 01 00 E8 ** ** ** ** 83 C4 10 F6 86 A0 00 01 00 02 B0 02 75 09 8A 86 A0 00 01 00");
    dword org_PossessFamiliar = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 20 6A 01 6A 03 FF 75 08 E8 ** ** ** ** 83 C4 10 3D 00 00 00 7F 0F 84 01 03 00 00 83 EC 08 6A 00 FF 75 08 C7 45 F0 00 00 00 00 E8 ** ** ** ** 83 C4 10 85 C0 74 19 83 EC 18 6A 01 FF 75 08 E8 ** ** ** ** 83 C4 14 50 E8 ** ** ** ** 83 C4 10 8B 45 08 81 78 58 00 00 00 7F 74 0C");
    dword org_ValidateCharacter = 0x080580BC;
    CNWSObject___CNWSObject = (void (*)(CNWSObject*, int)) 0x081C8E94;
    CVirtualMachine__GetRunScriptReturnValue = (int (*)(CVirtualMachine *, int *, void **)) 0x08264324;

    hook_function(org_SaveChar, (unsigned long)SaveCharHookProc, d_ret_code_sc, 12);
    hook_function(org_PickPocket, (unsigned long)PickPocketHookProc, d_ret_code_pp, 12);
    hook_function(org_Attack, (unsigned long)AttackHookProc, d_ret_code_at, 9);
    hook_function(org_UseItem, (unsigned long)UseItemHookProc, d_ret_code_ui, 12);
    hook_function(org_ConvSelect, (unsigned long)ConversationNodeSelectHookProc, d_ret_code_cn, 12);
    hook_function(org_ConditionalScript, (unsigned long)ConditionalScriptHookProc, d_ret_code_cs, 8);
    hook_function(org_SendServerToPlayerQuickChatMessage, (unsigned long)SendServerToPlayerQuickChatMessageHookProc, d_ret_code_qc, 9);
    hook_function(org_ExamineItem, (unsigned long)ExamineItemHookProc, d_ret_code_ei, 12);
    hook_function(org_ExamineCreature, (unsigned long)ExamineCreatureHookProc, d_ret_code_ec, 12);
    hook_function(org_ExaminePlaceable, (unsigned long)ExaminePlaceableHookProc, d_ret_code_ep, 12);
    hook_function(org_ExamineDoor, (unsigned long)ExamineDoorHookProc, d_ret_code_ed, 12);
    hook_function(org_UseSkill, (unsigned long)UseSkillHookProc, d_ret_code_us, 12);
    hook_function(org_UseFeat, (unsigned long)UseFeatHookProc, d_ret_code_uf, 12);
    hook_function(org_ToggleMode, (unsigned long)ToggleModeHookProc, d_ret_code_tm, 10);
    hook_function(org_CastSpell, (unsigned long)CastSpellHookProc, d_ret_code_cz, 12);
    hook_function(org_TogglePause, (unsigned long)TogglePauseHookProc, d_ret_code_tp, 9);
    hook_function(org_PossessFamiliar, (unsigned long)PossessFamiliarHookProc, d_ret_code_pf, 9);
    hook_function(org_ValidateCharacter, (unsigned long)CNWSPlayer__ValidateCharacter_hook, d_ret_code_vc, 12);
    *(dword*)&CNWSPlayer__ValidateCharacter = (dword)&d_ret_code_vc;
    if (enableUnsafe) {
        hook_function((dword)CNWSObject___CNWSObject, (unsigned long)CNWSObject___CNWSObject_hook, d_ret_code_objdest, 9);
        *(dword*)&CNWSObject___CNWSObject = (dword)&d_ret_code_objdest;
    }

    PrintHookInfo(org_SaveChar, "SaveChar");
    PrintHookInfo(org_PickPocket, "ActPickPocket");
    PrintHookInfo(org_Attack, "ActAttack");
    PrintHookInfo(org_UseItem, "UseItem");
    PrintHookInfo(org_ConvSelect, "ConversationNodeSelect");
    PrintHookInfo(org_ConditionalScript, "ConditionalScript");
    PrintHookInfo(org_SendServerToPlayerQuickChatMessage, "SendServerToPlayerQuickChatMessage");
    PrintHookInfo(org_ExamineItem, "ExamineItem");
    PrintHookInfo(org_ExamineCreature, "ExamineCreature");
    PrintHookInfo(org_ExaminePlaceable, "ExaminePlaceable");
    PrintHookInfo(org_ExamineDoor, "ExamineDoor");
    PrintHookInfo(org_UseSkill, "UseSkill");
    PrintHookInfo(org_UseFeat, "UseFeat");
    PrintHookInfo(org_ToggleMode, "ToggleMode");
    PrintHookInfo(org_CastSpell, "CastSpell");
    PrintHookInfo(org_TogglePause, "TogglePause");
    PrintHookInfo(org_PossessFamiliar, "PossessFamiliar");
    PrintHookInfo(org_ValidateCharacter, "ValidateCharacter");

    return (org_SaveChar && org_PickPocket && org_Attack && org_UseItem &&
            org_ConvSelect && org_ConditionalScript &&
            org_ExamineItem && org_ExamineCreature && org_ExaminePlaceable &&
            org_ExamineDoor && org_UseSkill && org_UseFeat &&
            org_ToggleMode && org_CastSpell &&
            org_TogglePause && org_PossessFamiliar &&
            org_SendServerToPlayerQuickChatMessage);
}


