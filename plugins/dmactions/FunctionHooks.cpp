/***************************************************************************
    KZ plugin for NWNX

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

#include "NWNXdmactions.h"
#include "FunctionHooks.h"
#include "CExoLocString.h"

extern CNWNXdmactions dmactions;

volatile uintptr_t
buffer_DMActivity_DM = 0,
buffer_DMActivity_Target = 0,
buffer_DMActivity_param1 = 0,
buffer_DMActivity_param2 = 0;

volatile uint16_t
buffer_DMActivity_TargetsCount = 0,
buffer_DMActivity_TargetsCurrent = 0;

volatile uint32_t
Ret_Address = 0;

void hook_DMActivity_GiveLevel(void)
{
    asm("leave");

    asm("pushl  0xc(%ebp)");
    asm("popl   buffer_DMActivity_DM");

    asm("pushl  -0x788(%ebp)");
    asm("popl   buffer_DMActivity_Target");
    asm("mov    %esi,buffer_DMActivity_param1");

    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    CGameObject *pTarget = (CGameObject *)buffer_DMActivity_Target;
    dword pDMObj;
    bool bPrevent = 0;
    if (pDM != NULL && pTarget != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0) {
        dmactions.oTarget1 = pTarget->id;
        dmactions.nParam1 = (int)buffer_DMActivity_param1;
        bPrevent = dmactions.FireAction(pDMObj, DM_ACTION_GIVE_LEVEL);
    }
    if (bPrevent) {
        asm("push $0x0818bec9");
    } else {
        asm("sub  $0xc,%esp");
        asm("mov  -0x788(%ebp),%eax");

        asm("push $0x0818c7d4");
    }
    asm("ret");
}

void hook_DMActivity_GiveXP(void)
{
    asm("leave");

    asm("pushl  0xc(%ebp)");
    asm("popl   buffer_DMActivity_DM");

    asm("pushl  -0x784(%ebp)");
    asm("popl   buffer_DMActivity_Target");

    asm("mov    %ebx,buffer_DMActivity_param1");

    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    CGameObject *pTarget = (CGameObject *)buffer_DMActivity_Target;
    dword pDMObj;
    bool bPrevent = 0;
    if (pDM != NULL && pTarget != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0 && pTarget->id != 0) {
        dmactions.oTarget1 = pTarget->id;
        dmactions.nParam1 = (int)buffer_DMActivity_param1;
        bPrevent = dmactions.FireAction(pDMObj, DM_ACTION_GIVE_XP);
    }
    if (bPrevent) {
        asm("push $0x0818bec9");
    } else {
        asm("sub  $0xc,%esp");
        asm("mov  -0x784(%ebp),%eax");

        asm("push $0x0818c6f4");
    }
    asm("ret");
}

void hook_DMActivity_GiveGold(void)
{
    asm("leave");

    asm("pushl  0xc(%ebp)");
    asm("popl   buffer_DMActivity_DM");

    asm("pushl  -0x78c(%ebp)");
    asm("popl   buffer_DMActivity_Target");

    asm("mov    %esi,buffer_DMActivity_param1");

    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    CGameObject *pTarget = (CGameObject *)buffer_DMActivity_Target;
    dword pDMObj;
    bool bPrevent = 0;
    if (pDM != NULL && pTarget != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0) {
        dmactions.oTarget1 = pTarget->id;
        dmactions.nParam1 = (int)buffer_DMActivity_param1;
        bPrevent = dmactions.FireAction(pDMObj, DM_ACTION_GIVE_GOLD);
    }

    if (bPrevent) {
        asm("push $0x0818bec9");
    } else {
        asm("mov  -0x78c(%ebp),%eax");
        asm("mov  0xc(%eax),%edx");

        asm("push $0x0818c8d7");
    }
    asm("ret");
}

volatile float buffer_DMActivity_height;

__attribute__((noinline))
static int local_DMActivity_CreateItem_OnArea()
{
    Vector *vPos = (Vector *)buffer_DMActivity_param2;
    CNWSArea *pArea = (CNWSArea *)buffer_DMActivity_param1;
    CNWSItem *pItem = (CNWSItem *)buffer_DMActivity_Target;
    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    dword pDMObj;
    if (pDM != NULL && pItem != NULL && pArea != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0) {
        dmactions.oTarget1 = pArea->field_C8;
        dmactions.oTarget2 = pItem->obj.obj_id;
        dmactions.vPos.x = vPos->x;
        dmactions.vPos.y = vPos->y;
        dmactions.vPos.z = buffer_DMActivity_height;
        if (dmactions.FireAction(pDMObj, DM_ACTION_CREATE_ITEM_ON_AREA)) {
            return 0;
        }
    }
    return 1;
}

void hook_DMActivity_CreateItem_OnArea(void)
{
    asm("leave");

    asm("movl 0xc(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_DM");

    asm("mov %ebx, buffer_DMActivity_Target");

    asm("movl -0x7f0(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_param1");

    asm("movl -0x7f4(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_param2");

    asm("fstps  (buffer_DMActivity_height)");

    if (local_DMActivity_CreateItem_OnArea()) {
        asm("fld  (buffer_DMActivity_height)");
        asm("fstps  (%esp)");
        asm("pushl  -0x114(%ebp)");
        asm("pushl  -0x118(%ebp)");
        asm("pushl  -0x7f0(%ebp)");
        asm("push   %ebx");
        asm("push   $0x0818a1b5");
    } else {
        asm("push $0x818daf7");
    }
    asm("ret");
}


__attribute__((noinline))
static int local_DMActivity_CreateItem_OnCreature()
{
    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    CNWSItem *pItem = (CNWSItem *)buffer_DMActivity_param1;
    CNWSCreature *pTarget = (CNWSCreature *)buffer_DMActivity_Target;
    dword pDMObj;
    if (pDM != NULL && pItem != NULL && pTarget != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0) {
        CNWSObject *pItemObject = &pItem->obj;
        CNWSObject *pTargetObject = &pTarget->obj;
        if (pItemObject != NULL && pTargetObject != NULL) {
            dmactions.oTarget1 = pTargetObject->obj_id;
            dmactions.oTarget2 = pItemObject->obj_id;
            if (dmactions.FireAction(pDMObj, DM_ACTION_CREATE_ITEM_ON_OBJECT)) {
                return 0;
            }
        }
    }
    return 1;
}

void hook_DMActivity_CreateItem_OnCreature(void)
{
    asm("leave");

    asm("movl 0xc(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_DM");

    asm("movl -0x7ac(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_param1");

    asm("movl -0x890(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_Target");

    if (local_DMActivity_CreateItem_OnCreature()) {
        asm("push   $0x1");
        asm("push   $0x0");
        asm("push   $0xff");
        asm("push   $0xff");
        asm("push   $0x7f000000");
        asm("push   $0x7f000000");
        asm("lea    -0x7ac(%ebp),%eax");
        asm("push   %eax");
        asm("pushl  -0x890(%ebp)");
        asm("push   $0x0818d252");
    } else {
        asm("push   $0x0818daf7");
    }

    asm("ret");
}

__attribute__((noinline))
static int local_DMActivity_CreateItem_OnPlaceable()
{
    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    CNWSItem *pItem = (CNWSItem *)buffer_DMActivity_param1;
    CNWSPlaceable *pTarget = (CNWSPlaceable *)buffer_DMActivity_Target;
    dword pDMObj;
    if (pDM != NULL && pItem != NULL && pTarget != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0) {
        CNWSObject *pItemObject = &pItem->obj;
        CNWSObject *pTargetObject = &pTarget->obj;
        if (pItemObject != NULL && pTargetObject != NULL) {
            dmactions.oTarget1 = pTargetObject->obj_id;
            dmactions.oTarget2 = pItemObject->obj_id;
            if (dmactions.FireAction(pDMObj, DM_ACTION_CREATE_ITEM_ON_OBJECT)) {
                return 0;
            }
        }
    }
    return 1;
}

void hook_DMActivity_CreateItem_OnPlaceable(void)
{
    asm("leave");

    asm("movl 0xc(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_DM");

    asm("movl -0x7b0(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_param1");

    asm("movl -0x894(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_Target");

    if (local_DMActivity_CreateItem_OnPlaceable()) {
        asm("push   $0x1");
        asm("push   $0xff");
        asm("push   $0xff");
        asm("push   $0x7f000000");
        asm("lea    -0x7b0(%ebp),%eax");
        asm("push   %eax");
        asm("pushl  -0x894(%ebp)");
        asm("push   $0x0818d31b");
    } else {
        asm("push $0x818daf7");
    }

    asm("ret");
}

__attribute__((noinline))
static void local_DMActivity_Heal()
{
    if (buffer_DMActivity_Target != 0) {
        nwn_objid_t dm_objid = (nwn_objid_t)CNWSPlayer__GetPCObject((CNWSPlayer *)buffer_DMActivity_DM);
        CNWSObject *pTargetObject = (CNWSObject *)buffer_DMActivity_Target;
        if (dm_objid != 0 && pTargetObject != NULL) {
            dmactions.oTarget1 = pTargetObject->obj_id;
            dmactions.nCount = buffer_DMActivity_TargetsCount;
            dmactions.nCurrent = buffer_DMActivity_TargetsCurrent;
            if (dmactions.FireAction(dm_objid, DM_ACTION_HEAL_CREATURE)) {
                Ret_Address = 0x8188f6d;
            }
        }
    }
}

void hook_DMActivity_Heal(void)
{
    asm("leave");

    asm("pushl 0xc(%ebp)");
    asm("popl buffer_DMActivity_DM");

    asm("push -0x7cc(%ebp)");
    asm("pop buffer_DMActivity_TargetsCount");

    asm("mov %edi, buffer_DMActivity_TargetsCurrent");

    asm("mov %eax,buffer_DMActivity_Target");

    Ret_Address = 0x08188e7f;
    local_DMActivity_Heal();

    asm("push Ret_Address");
    asm("ret");
}

__attribute__((noinline))
static int local_DMActivity_Rest()
{
    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    CNWSObject *pTargetObject = (CNWSObject *)buffer_DMActivity_Target;
    dword pDMObj;

    if (pDM !=  NULL && pTargetObject != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0) {
        dmactions.oTarget1 = pTargetObject->obj_id;
        dmactions.nCount = buffer_DMActivity_TargetsCount;
        dmactions.nCurrent = buffer_DMActivity_TargetsCurrent;
        if (dmactions.FireAction(pDMObj, DM_ACTION_REST_CREATURE)) {
            return 0;
        }
    }
    return 1;
}

void hook_DMActivity_Rest(void)
{
    asm("leave");

    asm("pushl 0xc(%ebp)");
    asm("popl buffer_DMActivity_DM");

    asm("mov %edi, buffer_DMActivity_TargetsCount");

    asm("mov %esi, buffer_DMActivity_TargetsCurrent");

    asm("mov -0x6cc(%ebp),%edx");
    asm("mov %edx,buffer_DMActivity_Target");

    asm("mov %eax, %edx");

    if (local_DMActivity_Rest()) {
        asm("push %edx");
        asm("push $0x0");
        asm("push $0x0");
        asm("push $0x08188d6f");
    } else {
        asm("push $0x08188d87");
    }

    asm("ret");
}

void hook_DMActivity_RunScript(CVirtualMachine *pVM, CExoString *pScript, unsigned long TargetOID, int arg)
{
    if (TargetOID > 0) {
        snprintf(dmactions.sParam1, 32, "%s", pScript->text);
        if (!dmactions.FireAction(TargetOID, DM_ACTION_RUNSCRIPT)) {
            CVirtualMachine__RunScript(pVM, pScript, TargetOID, arg);
        }
    }
}

__attribute__((noinline))
static int local_DMActivity_CreatePlaceable()
{
    Vector *vPos = (Vector *)buffer_DMActivity_param2;
    CNWSArea *pArea = (CNWSArea *)buffer_DMActivity_param1;
    CNWSPlaceable *pPlaceable = (CNWSPlaceable *)buffer_DMActivity_Target;
    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    dword pDMObj;
    if (pDM != NULL && pPlaceable != NULL && pArea != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0) {
        dmactions.oTarget1 = pPlaceable->obj.obj_id;
        dmactions.oTarget2 = pArea->field_C8;
        dmactions.vPos.x = vPos->x;
        dmactions.vPos.y = vPos->y;
        dmactions.vPos.z = vPos->z;
        if (dmactions.FireAction(pDMObj, DM_ACTION_CREATE_PLACEABLE)) {
            return 0;
        }
    }
    return 1;
}

void hook_DMActivity_CreatePlaceable(void)
{
    asm("leave");

    asm("movl 0xc(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_DM");

    asm("movl %ebx,buffer_DMActivity_Target");

    asm("movl -0x858(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_param1");

    asm("movl -0x85c(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_param2");

    if (local_DMActivity_CreatePlaceable()) {
        asm("fstps  (%esp)");
        asm("pushl  -0x3f4(%ebp)");
        asm("pushl  -0x3f8(%ebp)");
        asm("pushl  -0x858(%ebp)");
        asm("push   %ebx");
        asm("push   $0x0818bc76");
    } else {
        asm("push $0x818daf7");
    }

    asm("ret");
}

__attribute__((noinline))
static int local_DMActivity_SpawnCreature()
{
    Vector *vPos = (Vector *)buffer_DMActivity_param2;
    CNWSArea *pArea = (CNWSArea *)buffer_DMActivity_param1;
    CNWSCreature *pCreature = (CNWSCreature *)buffer_DMActivity_Target;
    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    dword pDMObj;
    if (pDM != NULL && pCreature != NULL && pArea != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0) {
        dmactions.oTarget1 = pCreature->obj.obj_id;
        dmactions.oTarget2 = pArea->field_C8;
        dmactions.vPos.x = vPos->x;
        dmactions.vPos.y = vPos->y;
        dmactions.vPos.z = vPos->z;
        if (dmactions.FireAction(pDMObj, DM_ACTION_SPAWN_CREATURE)) {
            return 0;
        }
    }
    return 1;
}

void hook_DMActivity_SpawnCreature(void)
{
    asm("leave");

    asm("movl 0xc(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_DM");

    asm("movl %ebx,buffer_DMActivity_Target");

    asm("movl -0x7e4(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_param1");

    asm("movl -0x7e8(%ebp),%eax");
    asm("movl %eax,buffer_DMActivity_param2");

    if (local_DMActivity_SpawnCreature()) {
        asm("fstps  (%esp)");
        asm("pushl  -0xc4(%ebp)");
        asm("pushl  -0xc8(%ebp)");
        asm("pushl  -0x7e4(%ebp)");
        asm("push   %ebx");
        asm("push   $0x08189ef7");
    } else {
        asm("push $0x818daf7");
    }

    asm("ret");
}

__attribute__((noinline))
static int local_DMActivity_ToggleInvulnerability()
{
    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    CNWSObject *pTargetObject = (CNWSObject *)buffer_DMActivity_Target;
    dword pDMObj;

    if (pDM !=  NULL && pTargetObject != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0) {
        dmactions.oTarget1 = pTargetObject->obj_id;
        dmactions.nCount = buffer_DMActivity_TargetsCount;
        dmactions.nCurrent = buffer_DMActivity_TargetsCurrent;
        if (dmactions.FireAction(pDMObj, DM_ACTION_TOGGLE_INVULNERABILITY)) {
            return 0;
        }
    }
    return 1;
}

void hook_DMActivity_ToggleInvulnerability(void)
{
    asm("leave");

    asm("test %ecx,%ecx");
    asm("jne skipdm_inv");

    asm("pushl 0xc(%ebp)");
    asm("popl buffer_DMActivity_DM");

    asm("mov %edi, buffer_DMActivity_TargetsCount");

    asm("mov %esi, buffer_DMActivity_TargetsCurrent");

    asm("mov -0x6c4(%ebp),%edx");
    asm("mov %edx,buffer_DMActivity_Target");

    if (local_DMActivity_ToggleInvulnerability()) {
        asm("push $0x08188afe");
    } else {
        asm("push $0x8188b35");
    }

    asm("ret");

    asm("skipdm_inv:");
    asm("push $0x8188b35");
    asm("ret");
}

__attribute__((noinline))
static int local_DMActivity_ToggleImmortality()
{
    CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
    CNWSObject *pTargetObject = (CNWSObject *)buffer_DMActivity_Target;
    dword pDMObj;

    if (pDM !=  NULL && pTargetObject != NULL && (pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM)) != 0) {
        dmactions.oTarget1 = pTargetObject->obj_id;
        dmactions.nCount = buffer_DMActivity_TargetsCount;
        dmactions.nCurrent = buffer_DMActivity_TargetsCurrent;
        if (dmactions.FireAction(pDMObj, DM_ACTION_TOGGLE_IMMORTALITY)) {
            return 0;
        }
    }
    return 1;
}

void hook_DMActivity_ToggleImmortality(void)
{
    asm("leave");

    asm("test %ecx,%ecx");
    asm("jne skipdm_imm");

    asm("pushl 0xc(%ebp)");
    asm("popl buffer_DMActivity_DM");

    asm("mov %edi, buffer_DMActivity_TargetsCount");

    asm("mov %esi, buffer_DMActivity_TargetsCurrent");

    asm("mov -0x6c8(%ebp),%edx");
    asm("mov %edx,buffer_DMActivity_Target");

    if (local_DMActivity_ToggleImmortality()) {
        asm("push $0x08188c36");
    } else {
        asm("push $0x8188c6d");
    }

    asm("ret");

    asm("skipdm_imm:");
    asm("push $0x8188c6d");
    asm("ret");
}

void hook_DMActivity_MessageAll(void)
{
    asm("pushl 0xc(%ebp)");
    asm("popl buffer_DMActivity_DM");

    asm("push 0x10(%ebp)");
    asm("pop buffer_DMActivity_param1");

    asm("push   %ebp");
    asm("mov    %esp,%ebp");
    asm("push   %edi");
    asm("push   %esi");
    asm("push   %ebx");

    asm("leave");

    bool bPrevent = 0;
    if (buffer_DMActivity_DM > 0) {
        CNWSPlayer *pDM = (CNWSPlayer *)buffer_DMActivity_DM;
        nwn_objid_t pDMObj = (nwn_objid_t)CNWSPlayer__GetPCObject(pDM);
        if (pDMObj) {
            dmactions.nParam1 = (int)buffer_DMActivity_param1;
            bPrevent = dmactions.FireAction(pDMObj, DM_ACTION_MESSAGE_TYPE);
        }
    }

    if (bPrevent) {
        asm("push $0x0818e905");
    } else {
        asm("push $0x081882ea");
    }
    asm("ret");
}


int FindFunctions()
{
    *(dword*)&CNWSPlayer__GetPCObject = 0x0805ee30;
    *(dword*)&CNWSItem__RemoveFromArea = 0x081a669c;

    *(dword*)&CNWMessage__ReadDWORD = 0x080c36cc;
    *(dword*)&CNWMessage__MessageReadOverflow = 0x080c3a64;
    *(dword*)&CNWSMessage__ReadOBJECTIDServer = 0x08052d84;

    /* DM ACTIVITY HOOKS */

    unsigned char *pDM = (unsigned char *)0x0818c7cb;// GiveLevel
    nx_hook_enable_write(pDM, 8);
    memset((void *)pDM, '\x90', 8);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_GiveLevel - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x0818c6eb; // GiveXP
    nx_hook_enable_write(pDM, 8);
    memset((void *)pDM, '\x90', 8);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_GiveXP - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x0818c8ce;// GiveGold
    nx_hook_enable_write(pDM, 6);
    memset((void *)pDM, '\x90', 8);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_GiveGold - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x0818a19f; // Create Item On Location
    nx_hook_enable_write(pDM, 9);
    memset((void *)pDM, '\x90', 9);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_CreateItem_OnArea - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x0818d22d; // Create Item On Creature
    nx_hook_enable_write(pDM, 37);
    memset((void *)pDM, '\x90', 37);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_CreateItem_OnCreature - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x0818d2fd; // Create Item On Placeable
    nx_hook_enable_write(pDM, 24);
    memset((void *)pDM, '\x90', 24);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_CreateItem_OnPlaceable - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x08188e77; // Heal Creature
    nx_hook_enable_write(pDM, 8);
    memset((void *)pDM, '\x90', 8);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_Heal - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x08188d6a; // Rest Creature
    nx_hook_enable_write(pDM, 5);
    memset((void *)pDM, '\x90', 5);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_Rest - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x081860c8; // Cheat - RunScript
    nx_hook_enable_write(pDM, 5);
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_RunScript - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x0818bc60; // Create Placeable
    nx_hook_enable_write(pDM, 9);
    memset((void *)pDM, '\x90', 9);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_CreatePlaceable - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x08189ee1; // Spawn Creature
    nx_hook_enable_write(pDM, 9);
    memset((void *)pDM, '\x90', 9);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_SpawnCreature - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x08188af1; // Toggle Invulnerability
    nx_hook_enable_write(pDM, 9);
    memset((void *)pDM, '\x90', 9);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_ToggleInvulnerability - (uint32_t)(pDM + 5);

    pDM = (unsigned char *)0x08188c29; // Toggle Immortality
    nx_hook_enable_write(pDM, 9);
    memset((void *)pDM, '\x90', 9);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_ToggleImmortality - (uint32_t)(pDM + 5);


    pDM = (unsigned char *)0x081882e4; // HandlePlayerToServerDungeonMasterMessage
    nx_hook_enable_write(pDM, 5);
    memset((void *)pDM, '\x90', 5);
    pDM[0] = '\xE9';
    *((uint32_t *)(pDM + 1)) = (uint32_t)hook_DMActivity_MessageAll - (uint32_t)(pDM + 5);

    return true;
}
