/***************************************************************************
    Fixes plugin for NWNX  - hooks implementation
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

#include <stdint.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <stdarg.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "FixesHooks.h"
#include "FixesHooksNewApi.h"
#include "NWNXFixes.h"
#include "NWNStructures.h"
#include "AssemblyHelper.cpp"


extern CNWNXFixes fixes;
AssemblyHelper asmhelp;

//Functions:
//Return value: 0 upon success, 1 upon failure
void (*pRunScript)(void *pScriptMachine, CExoString *script_name, dword ObjID, int arg_4);
int (*pGetObjByOID)(void *pObjectClass, dword ObjID, void **buf);
void *(*pGetPlayer)(void *pServerExo4, dword ObjID);
void *(*pGetObjectFactionEntry)(void *pObject);
int (*pGetIsMergeable)(void *pItem1, void *pItem2);
int (*CNWSCreature__DoDamage)(CNWSCreature *a1, unsigned int a2);
int (*CNWSModule__AIUpdate)(void *a1);
int (*CNWSModule__AIUpdate_R)(void *a1);
int (*CNWSCreature_SplitItem)(CNWSCreature *cre, dword *a2, int a3);

//Constants:

void *pServer = 0;
void *pServerExo = 0;
void *pServerExo4 = 0;
void *pObjectClass = 0;
void *pFactionClass = 0;
void *pClientClass = 0;
void *pRules = 0;
void *p2das = 0;

void **pVirtualMachine = (void **) 0x0832F1EC;
//dword pScriptThis = 0;
//dword oPC = 0;

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */
unsigned char d_ret_code_merg[0x20];
unsigned char d_ret_code_dmg[0x20];
unsigned char d_ret_code_mai[0x20];
unsigned char d_ret_code_si[0x20];

unsigned long lastRet;
char scriptRun = 0;
char runLock = 0;

//#################### ENGINE FUNCTIONS ####################

void *GetObjectByID(dword ObjID)
{
    if (!fixes.bHooked) return NULL;
    if (!pServer) InitConstants();
    void *pObject;
    pGetObjByOID(pObjectClass, ObjID, &pObject);
    return pObject;
}

long GetOIDByObj(void *pObject)
{
    return *((dword*)pObject + 0x4);
}

void *GetPlayer(dword ObjID)
{
    if (!fixes.bHooked) return NULL;
    if (!pServer) InitConstants();
    return pGetPlayer(pServerExo4, ObjID);
}

//#################### FUNCTIONS ####################

bool CompareVarLists(CNWObjectVarList *pVarList1, CNWObjectVarList *pVarList2)
{
    if (pVarList1->VarCount == 0 && pVarList2->VarCount == 0)
        return true;

    for (size_t i = 0; i < pVarList1->VarCount; i++) {
        bool bFound = false;
        CNWObjectVarListElement *pVar1 = &pVarList1->VarList[i];

        for (size_t j = 0; j < pVarList2->VarCount; j++) {
            CNWObjectVarListElement *pVar2 = &pVarList2->VarList[j];

            if (pVar1->nVarType == pVar2->nVarType &&
                    strcmp(pVar1->sVarName.Text, pVar2->sVarName.Text) == 0) {

                bFound = true;

                //Compare values
                switch (pVar1->nVarType) {
                    case 1:  //int
                        if ((int)(pVar1->nVarValue) != (int)(pVar2->nVarValue)) {
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: int value '%s' %d != %d\n", pVar1->sVarName.Text,
                                      (int)(pVar1->nVarValue), (int)(pVar2->nVarValue));
#endif
                            return false;
                        }
                        break;

                    case 2:  //float
                        if ((float)(pVar1->nVarValue) != (float)(pVar2->nVarValue)) {
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: float value '%s' %.04f != %.04f\n", pVar1->sVarName.Text,
                                      (float)(pVar1->nVarValue), (float)(pVar2->nVarValue));
#endif
                            return false;
                        }
                        break;

                    case 3:  //string
                        // both pointers are equal or both are null
                        if ((char **)(pVar1->nVarValue) == (char **)(pVar2->nVarValue))
                            break;
                        if ((char **)(pVar1->nVarValue) == NULL || (char **)(pVar2->nVarValue) == NULL) {  //the variable is not set on one of the objects
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: string value '%s' is not set on one of the objects\n", pVar1->sVarName.Text);
#endif
                            return false;
                        }

                        if (*(char **)(pVar1->nVarValue) == *(char **)(pVar2->nVarValue))  //equal pointers
                            break;
                        if (*(char **)(pVar1->nVarValue) == NULL || *(char **)(pVar2->nVarValue) == NULL) { //one of the variables is empty
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: string value '%s' is not set on one of the objects\n", pVar1->sVarName.Text);
#endif
                            return false;
                        }

                        if (strcmp(*(char **)(pVar1->nVarValue), *(char **)(pVar2->nVarValue)) != 0) {  //string values are not equal
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: string value '%s' '%s' != '%s'\n", pVar1->sVarName.Text,
                                      *(char **)(pVar1->nVarValue), *(char **)(pVar2->nVarValue));
#endif
                            return false;
                        }
                        break;

                    case 4:  //object
                        if ((dword)(pVar1->nVarValue) != (dword)(pVar2->nVarValue)) {
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: object value '%s' %08X != %08X\n", pVar1->sVarName.Text,
                                      (dword)(pVar1->nVarValue), (dword)(pVar2->nVarValue));
#endif
                            return false;
                        }
                        break;

                    case 5:  //location
                        break;
                }

                break;
            }
        }

        if (!bFound) {
#ifdef NWNX_FIXES_DEBUG
            fixes.Log(3, "blocking merge: local variable '%s' not found on one of the objects", pVar1->sVarName.Text);
#endif
            return false;
        }
    }

    return true;
}

void RunScript(char * sname, int ObjID)
{
    CExoString script_name;
    script_name.Text = sname;
    script_name.Length = strlen(sname);
    scriptRun = 1;
    pRunScript(*pVirtualMachine, &script_name, ObjID, 1);
    scriptRun = 0;
}

//#################### HOOKED FUNCTIONS ####################

int GetIsMergeableHookProc(void *pItem1, void *pItem2)
{
    asm("mov 0xC(%ebp), %eax");
    asm("push %eax");
    asm("mov 0x8(%ebp), %eax");
    asm("push %eax");
    asm("mov $d_ret_code_merg, %eax");
    asm("call *%eax");
    asm("add $0x8, %esp");
    asm("movl %eax, lastRet");
    if (fixes.bHooked && lastRet) {
        //Check local vars
        CNWObjectVarList *pVarList1 = (CNWObjectVarList*)((char*)pItem1 + 0x10 + 0x4 + 0xD8);
        CNWObjectVarList *pVarList2 = (CNWObjectVarList*)((char*)pItem2 + 0x10 + 0x4 + 0xD8);
        if (!pVarList1 && !pVarList2) return 1;
        if (!pVarList1 || !pVarList2) {
#ifdef NWNX_FIXES_DEBUG
            fixes.Log(3, "blocking merge: one object has a variable list and the other does not\n");
#endif
            return 0;
        }
        return (CompareVarLists(pVarList1, pVarList2) && CompareVarLists(pVarList2, pVarList1));
        //return lastRet;
    } else return lastRet;
}

void PlayerListNoDMHook()
{
    CNWSCreature *cre;

    // code overwritten by hook
    asm("test %edi,%edi");
    asm("jz suppressresponse");

    // put eax (CNWSCreature*) in cre so we can work with it
    asm("mov %%eax,%0" : "=r"(cre));

    // obvious enough: if DM, don't list
    if (cre->CreatureStats->IsDM) {
        asm("jmp suppressresponse");
    }
    // DMs are also PCs, but they've been handled above, so this is mortal PCs only
    else if (cre->CreatureStats->IsPC) {
        asm("jmp sendresponse");
    }
    // 7 is DM possess, 8 is DM possess full powers, 0x7fffffff is WTF
    else if (cre->MasterID == 7 || cre->MasterID == 8 || cre->MasterID == 0x7fffffff) {
        fixes.Log(4, "* NoDMHook Suppress (cre_master_id): %08lX\n", cre->MasterID);
        asm("jmp suppressresponse");
    } else {
        fixes.Log(4, "* NoDMHook Send (default): %08lX\n", cre->MasterID);
    }

    asm("sendresponse:");
    asm("pop %ebp"); // remove cre from stack
    asm("pop %ebp"); // restore stack that gcc screwed up with function prologue
    asm("mov $0x0807e4b3, %eax");
    asm("jmp *%eax");
    asm("suppressresponse:");
    asm("pop %ebp"); // remove cre from stack
    asm("pop %ebp"); // restore stack that gcc screwed up with function prologue
    asm("mov $0x0807e641, %eax");
    asm("jmp *%eax");
}

int CNWSCreature__DoDamage_hook(CNWSCreature *a1, unsigned int a2)
{
    fixes.Log(3, "DoDamage: %08lX, %d, Current: %d\n", a1->Object.ObjectID, a2, a1->Object.HitPoints);
    if (a1->IsPC && a1->Object.HitPoints > 0 && (int)a2 > a1->Object.HitPoints + 5) {
        a2 = a1->Object.HitPoints + 5;
        int ret = CNWSCreature__DoDamage(a1, a2);
        fixes.Log(3, "Running script...\n");
        RunScript("vir_oncdamage", a1->Object.ObjectID);
        return ret;
    }
    return CNWSCreature__DoDamage(a1, a2);
}

int CNWSModule__AIUpdate_hook(void *a1)
{
    int ret = CNWSModule__AIUpdate_R(a1);
    if (ret == 1 && !runLock) {
        runLock = 1;
        int ret2 = CNWSModule__AIUpdate(a1);
        runLock = 0;
        fixes.Log(3, "CNWSModule__AIUpdate: %d\n", ret2);
        return ret2;
    }
    return ret;
}

int CNWSCreature_SplitItem_hook(CNWSCreature *cre, dword *a2, int a3)
{
	if (cre == NULL)
		return 0;
	return CNWSCreature_SplitItem(cre, a2, a3);
}

//#################### HOOK ####################

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

int FindHookFunctions()
{
    *(dword*)&pGetObjByOID = asmhelp.FindFunctionBySignature("55 89 E5 8B 45 0C 56 53 89 C2 89 C3 C1 E8 1F 0F B7 C0 C1 E0 0C");
    fixes.Log(2, "GetObjByOID: %08lX\n", pGetObjByOID);
    *(dword*)&pGetPlayer = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B ** 0C 81 FF 00 00 00 7F");
    fixes.Log(2, "GetPlayer: %08lX\n", pGetPlayer);
    *(dword*)&pGetObjectFactionEntry = asmhelp.FindFunctionBySignature("55 89 E5 ** ** ** A1 ** ** ** ** 8B 40 04 8B 55 08 8B 48 04 8B 82 64 0C 00 00 FF B0 88 00 00 00");
    if (!pGetObjectFactionEntry)
        *(dword*)&pGetObjectFactionEntry = asmhelp.FindFunctionBySignature("55 89 E5 ** ** ** A1 ** ** ** ** 8B 40 04 8B 55 08 8B 48 04 8B 82 68 0C 00 00 FF B0 90 00 00 00");
    fixes.Log(2, "GetObjectFactionEntry: %08lX\n", pGetObjectFactionEntry);
    *(dword*)&pGetIsMergeable = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 7D 08 8B 97 E4 01 00 00 85 D2 0F 84 ** ** ** ** 8B 45 0C");
    fixes.Log(2, "GetIsMergeable: %08lX\n", pGetIsMergeable);
    char *pSplitItem_Copy = (char *) asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 7D 0C 85 FF 8B 75 08 7E 08 3B BE ** 02 00 00 7C 05");
    fixes.Log(2, "SplitItem_Copy: %08lX\n", pSplitItem_Copy);
    char *pBuyItem = (char *) asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 14 8A 45 14 88 45 EF 8B 45 0C FF 70 08 8B 75 08 56 0F B6 7D 18 E8");
    fixes.Log(2, "BuyItem: %08lX\n", pBuyItem);
    char *pMergeItems_RemoveItem = (char *) asmhelp.FindFunctionBySignature("89 C3 83 C4 10 85 DB 0F 84 8A 00 00 00 50 6A 01 FF B5 28 FE FF FF 53 E8");
    fixes.Log(2, "MergeItems_RemoveItem: %08lX\n", pMergeItems_RemoveItem);

    char *pAIActionDialogObject_middle = (char *) asmhelp.FindFunctionBySignature("83 EC 08 8B 55 08 A1 ** ** ** ** FF 72 04 FF 70 04 E8 ** ** ** ** 8B 55  08 89 85 54 FF FF FF 8B 42 0C 89 14 24 FF 50 38 83 C4 10 85 C0 0F 84 85 02 00 00");
    fixes.Log(2, "AIActionDialogObject_middle: %08lX\n", pAIActionDialogObject_middle);
    char *pGetDead = (char *) asmhelp.FindFunctionBySignature("55 89 E5 56 53 83 EC 0C 8B 5D 08 8B 43 0C 53 FF 50 38 83 C4 10 85 C0 74 5B 83 EC 0C 8B 43 0C 53 FF 50 38 8B 90 DC 0A 00 00 83 C4 10 31 F6 85 D2 75 10 83 EC 0C 50 E8");
    fixes.Log(2, "GetDead: %08lX\n", pGetDead);
    char *pGetIsPCDying = (char *) 0x081d5498;
    fixes.Log(2, "GetIsPCDying: %08lX\n", pGetIsPCDying);
    char *pAIActionJumpToPoint = (char *) 0x08100BA4;
    fixes.Log(2, "AIActionJumpToPoint: %08lX\n", pAIActionJumpToPoint);
    *(dword*)&CNWSCreature__DoDamage = 0x0812E998;
    fixes.Log(2, "CNWSCreature__DoDamage: %08lX\n", CNWSCreature__DoDamage);
    *(dword*)&CNWSModule__AIUpdate = 0x081B3DEC;
    fixes.Log(2, "CNWSModule__AIUpdate: %08lX\n", CNWSModule__AIUpdate);
    char *pAdjustReputation_middle = (char *) 0x081084C3;

    *(dword*)&CNWSCreature_SplitItem = 0x0811A1D0;
	fixes.Log(2, "CNWSCreature_SplitItem: %08lX\n", CNWSCreature_SplitItem);
    
    *(dword*)&pRunScript = 0x08261F94;

    if (pSplitItem_Copy && fixes.GetConfInteger("copy_vars")) {
        fixes.Log(2, "copy_vars = 1\n");
        d_enable_write((dword) pSplitItem_Copy);
        if (pSplitItem_Copy[0x3F] == 0x6A) pSplitItem_Copy[0x40] = 0x1;
        else fixes.Log(2, "Couldn't patch the SplitItem_Copy function\n");
    }

    if (pBuyItem && fixes.GetConfInteger("copy_vars")) {
        d_enable_write((dword) pBuyItem);
        if (pBuyItem[0x60] == 0x6A) pBuyItem[0x61] = 0x1;
        else fixes.Log(2, "Couldn't patch the BuyItem function\n");
    }

    if (pMergeItems_RemoveItem && fixes.GetConfInteger("copy_vars")) {
        d_enable_write((dword) pMergeItems_RemoveItem);
        if (pMergeItems_RemoveItem[0xE] == 0x6A) pMergeItems_RemoveItem[0xF] = 0x0;
        else fixes.Log(2, "Couldn't patch the MergeItems_RemoveItem function\n");
    }

    if (pAIActionDialogObject_middle && fixes.GetConfInteger("keep_hidden_in_conversation")) {
        fixes.Log(2, "keep_hidden_in_conversation = 1\n");
        d_enable_write((dword) pAIActionDialogObject_middle);
        if (pAIActionDialogObject_middle[0x65] == 0x6A && pAIActionDialogObject_middle[0x66] == 0x00) {
            pAIActionDialogObject_middle[0x6F] = 0x90;
            pAIActionDialogObject_middle[0x70] = 0x90;
            pAIActionDialogObject_middle[0x71] = 0x90;
            pAIActionDialogObject_middle[0x72] = 0x90;
            pAIActionDialogObject_middle[0x73] = 0x90;
        } else fixes.Log(2, "Couldn't patch the AIActionDialogObject function\n");
    }

    if (pGetIsMergeable && fixes.GetConfInteger("compare_vars")) {
        fixes.Log(2, "compare_vars = 1\n");
        d_redirect((unsigned long)pGetIsMergeable, (unsigned long)GetIsMergeableHookProc, d_ret_code_merg, 9);
    }

    if (pGetIsMergeable && fixes.GetConfInteger("damage_tweak")) {
        fixes.Log(2, "damage_tweak = 1\n");
        d_redirect((unsigned long)CNWSCreature__DoDamage, (unsigned long)CNWSCreature__DoDamage_hook, d_ret_code_dmg, 9);
        *(dword*)&CNWSCreature__DoDamage = (dword)&d_ret_code_dmg;
    }

    if (CNWSModule__AIUpdate) {
        d_redirect((unsigned long)CNWSModule__AIUpdate, (unsigned long)CNWSModule__AIUpdate_hook, d_ret_code_mai, 9);
        *(dword*)&CNWSModule__AIUpdate_R = (dword)&d_ret_code_mai;
    }
    
    if (CNWSCreature_SplitItem)
	{
		d_redirect((unsigned long)CNWSCreature_SplitItem, (unsigned long)CNWSCreature_SplitItem_hook, d_ret_code_si, 9);
        *(dword*)&CNWSCreature_SplitItem = (dword)&d_ret_code_si;
	}

    if (pGetDead && fixes.GetConfInteger("hp_limit")) {
        d_enable_write((dword) pGetDead);
        d_enable_write((dword) pGetIsPCDying);
        char hpLimit = (char)fixes.GetConfInteger("hp_limit");
        if (hpLimit > 0) hpLimit = -10;
        fixes.Log(2, "HP limit = %d\n", hpLimit);
        pGetDead[0x6D] = hpLimit;
        pGetIsPCDying[0x79] = hpLimit;
    }

    //Allow to move dead PCs
    if (pAIActionJumpToPoint) {
        d_enable_write((dword) pAIActionJumpToPoint);
        pAIActionJumpToPoint[0x18] = 0x90;
        pAIActionJumpToPoint[0x19] = 0x90;
        pAIActionJumpToPoint[0x29] = 0x90;
        pAIActionJumpToPoint[0x2A] = 0x90;
    }

    if (pAdjustReputation_middle[0] == 0x56) {
        d_enable_write((dword) pAdjustReputation_middle);
        pAdjustReputation_middle[0] = 0xFF;
        pAdjustReputation_middle[1] = 0xB0;
        pAdjustReputation_middle[2] = 0x90;
        pAdjustReputation_middle[3] = 0;
        pAdjustReputation_middle[4] = 0;
        pAdjustReputation_middle[5] = 0;
        pAdjustReputation_middle[6] = 0x56;
    } else fixes.Log(2, "Couldn't patch the AdjustReputation function\n");

    // begin cap hooks
    int cap_ability_inc = fixes.GetConfInteger("cap_ability_inc");
    char* cap_ability_inc_h1 = (char*)0x08134a63;
    char* cap_ability_inc_h2 = (char*)0x08134a6c;
    int cap_ability_dec = fixes.GetConfInteger("cap_ability_dec");
    char* cap_ability_dec_h1 = (char*)0x08134a76;
    char* cap_ability_dec_h2 = (char*)0x08134a7f;
    int cap_atkbonus_inc = fixes.GetConfInteger("cap_atkbonus_inc");
    char* cap_atkbonus_inc_h1 = (char*)0x0813290f;
    char* cap_atkbonus_inc_h2 = (char*)0x0813291f;
    int cap_atkbonus_dec = fixes.GetConfInteger("cap_atkbonus_dec");
    char* cap_atkbonus_dec_h1 = (char*)0x08132922;
    char* cap_atkbonus_dec_h2 = (char*)0x0813292b;
    int cap_skill_inc = fixes.GetConfInteger("cap_skill_inc");
    char* cap_skill_inc_h1 = (char*)0x08135053;
    char* cap_skill_inc_h2 = (char*)0x0813505c;
    int cap_skill_dec = fixes.GetConfInteger("cap_skill_dec");
    char* cap_skill_dec_h1 = (char*)0x08135066;
    char* cap_skill_dec_h2 = (char*)0x0813506f;

    if (cap_ability_inc > 0) {
        if (cap_ability_inc > 255) cap_ability_inc = 255;
        d_enable_write((dword)cap_ability_inc_h1);
        d_enable_write((dword)cap_ability_inc_h2);
        *cap_ability_inc_h1 = (char)cap_ability_inc;
        *cap_ability_inc_h2 = (uint8_t)cap_ability_inc;
        fixes.Log(2, "Ability increase cap changed to %d\n", cap_ability_inc);
    }
    if (cap_ability_dec > 0) {
        if (cap_ability_dec > 255) cap_ability_dec = 255;
        d_enable_write((dword)cap_ability_dec_h1);
        *cap_ability_dec_h1 = (uint8_t)cap_ability_dec;
        *cap_ability_dec_h2 = (uint8_t)cap_ability_dec;
        fixes.Log(2, "Ability decrease cap changed to %d\n", cap_ability_dec);
    }
    if (cap_atkbonus_inc > 0) {
        if (cap_atkbonus_inc > 255) cap_atkbonus_inc = 255;
        d_enable_write((dword)cap_atkbonus_inc_h1);
        *cap_atkbonus_inc_h1 = (uint8_t)cap_atkbonus_inc;
        *cap_atkbonus_inc_h2 = (uint8_t)cap_atkbonus_inc;
        fixes.Log(2, "AB increase cap changed to %d\n", cap_atkbonus_inc);
    }
    if (cap_atkbonus_dec > 0) {
        if (cap_atkbonus_dec > 255) cap_atkbonus_dec = 255;
        d_enable_write((dword)cap_atkbonus_dec_h1);
        *cap_atkbonus_dec_h1 = (uint8_t)cap_atkbonus_dec;
        *cap_atkbonus_dec_h2 = (uint8_t)cap_atkbonus_dec;
        fixes.Log(2, "AB decrease cap changed to %d\n", cap_atkbonus_dec);
    }
    if (cap_skill_inc > 0) {
        if (cap_skill_inc > 255) cap_skill_inc = 255;
        d_enable_write((dword)cap_skill_inc_h1);
        *cap_skill_inc_h1 = (uint8_t)cap_skill_inc;
        *cap_skill_inc_h2 = (uint8_t)cap_skill_inc;
        fixes.Log(2, "Skill increase cap changed to %d\n", cap_skill_inc);
    }
    if (cap_skill_dec > 0) {
        if (cap_skill_dec > 255) cap_skill_dec = 255;
        d_enable_write((dword)cap_skill_dec_h1);
        *cap_skill_dec_h1 = (uint8_t)cap_skill_dec;
        *cap_skill_dec_h2 = (uint8_t)cap_skill_dec;
        fixes.Log(2, "Skill decrease cap changed to %d\n", cap_skill_dec);
    }
    // end cap hooks

    HookFunctions_NewApi();

    if (!(pGetIsMergeable && pSplitItem_Copy && pBuyItem && pMergeItems_RemoveItem)) {
        fixes.Log(2, "Some of the functions could not be found\n");
        return false;
    }
    fixes.Log(2, "All functions set\n");
    return true;
}

void InitConstants()
{
    if (!pGetIsMergeable) return;
    //Constants
    dword *ppServer = *(dword**)((char *)pGetObjectFactionEntry + 0x7);
    //fixes.Log(2, "ppServer=%08lX", ppServer);
    //*(dword*)&ppServer = 0x083281D4;
    *(dword*)&pServer = *ppServer;
    *(dword*)&pRules = *(ppServer + 2);
    *(dword*)&p2das = *(dword*)((char*)pRules + 0xF0);
    *(dword*)&pServerExo = *(dword*)((char*)pServer + 0x4);
    *(dword*)&pServerExo4 = *(dword*)((char*)pServerExo + 0x4);


    //Äà, ÿ çíàþ, ÿ èçâðàùåíåö!
    *(dword*)&pObjectClass = *(dword*)(*(dword*)((char*)pServerExo + 0x4) + 0x10080);
    *(dword*)&pFactionClass = *(dword*)(*(dword*)((char*)pServerExo + 0x4) + 0x10074);
    *(dword*)&pClientClass = *(dword*)(*(dword*)((char*)pServerExo + 0x4) + 0x10060);

}

