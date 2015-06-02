/***************************************************************************
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

#include "NWNXextend.h"
#include "Hooks.h"

extern CNWNXextend extend;

static int16_t confMaxDexterityBonus_ip;
static int16_t confIneffectiveUMD_ip;

volatile CNWSCreature *pCreature;
volatile CNWSCreatureStats *pCreatureStats;


void hook_ExamineCR_NPC_Only()
{
    asm("leave");

    asm("push %eax");
    asm("movl -0xd0(%ebp),%eax");
    asm("movl %eax, pCreature");
    asm("pop %eax");

    if (*((uint8_t*)(*NWN_AppManager)->app_server->srv_internal->field_1000C + 0x114) == 0 || (pCreature == NULL || pCreature->cre_is_pc)) {
        // Supress CR
        asm("push $0x8073d7c");
    } else {
        asm("push $0x08073d1e");
    }

    asm("ret");
}

int (*C2DA__GetINTEntry)(C2DA *, int, int, int *);
int (*C2DA__GetCExoStringEntry)(C2DA *, int, int, CExoString *);

volatile CExoString *GMPCR_pString;
volatile C2DA *GMPCR_p2DA;
volatile int GMPCR_p1, GMPCR_p2, GMPCR_row;

__attribute__((noinline))
static uint8_t Local_GetMeetsPrestigeClassRequirements()
{
    if (strncmp(GMPCR_pString->text, "SKILL", 5) == 0) {
        return 1;
    } else if (strncmp(GMPCR_pString->text, "SPECIALIST", 10) == 0) {
        int spec;
        if (C2DA__GetINTEntry((C2DA *)GMPCR_p2DA, GMPCR_row, GMPCR_p1, &spec)) {
            int i;
            for (i = 0; i < pCreatureStats->cs_classes_len; i++) {
                if (pCreatureStats->cs_classes[i].cl_class == CLASS_TYPE_WIZARD) {
                    if (pCreatureStats->cs_classes[i].cl_specialist == spec) {
                        return 2;
                    }
                    break;
                }
            }
            return 3;
        }
    } else if (strncmp(GMPCR_pString->text, "DIVSPELL", 8) == 0) {
        int lvl;
        if (C2DA__GetINTEntry((C2DA *)GMPCR_p2DA, GMPCR_row, GMPCR_p1, &lvl)) {
            int i;
            for (i = 0; i < pCreatureStats->cs_classes_len; i++) {
                if (pCreatureStats->cs_classes[i].cl_class == CLASS_TYPE_DRUID ||
                        pCreatureStats->cs_classes[i].cl_class == CLASS_TYPE_CLERIC ||
                        pCreatureStats->cs_classes[i].cl_class == CLASS_TYPE_PALADIN ||
                        pCreatureStats->cs_classes[i].cl_class == CLASS_TYPE_RANGER) {

                    int splslots = pCreatureStats->cs_classes[i].cl_spells_max[lvl];

                    if (splslots == 0)
                        splslots = pCreatureStats->cs_classes[i].cl_spells_mem[lvl].len;
                    if (splslots > 0) {
                        return 2;
                    }
                    break;
                }

            }
            return 3;
        }
    } else if (strncmp(GMPCR_pString->text, "RACENOT", 7) == 0) {
        int race;
        if (C2DA__GetINTEntry((C2DA *)GMPCR_p2DA, GMPCR_row, GMPCR_p1, &race)) {
            if (race == pCreatureStats->cs_race) {
                return 3;
            }
        }
        return 2;
    } else if (strncmp(GMPCR_pString->text, "SCRIPT", 6) == 0) {
        CExoString *script = (CExoString *) malloc(sizeof(CExoString));
        script->text = NULL;
        script->len = 0;
        if (script != NULL) {
            if (C2DA__GetCExoStringEntry((C2DA *)GMPCR_p2DA, GMPCR_row, GMPCR_p1, script)) {
                extend.ScriptResult = 0;
                nwn_ExecuteScript(script->text, pCreatureStats->cs_original->obj.obj_id);
                if (extend.ScriptResult) {
                    return 3;
                }
            }
            free(script);
        }
    }
    return 0;
}

void Hook_GetMeetsPrestigeClassRequirements(void)
{
    asm("leave");

    asm("movl 0x8(%ebp),%esi");
    asm("movl %esi, pCreatureStats");

    asm("lea -0xa8(%ebp),%esi");
    asm("movl %esi, GMPCR_pString");

    asm("lea -0x58(%ebp),%esi");
    asm("movl %esi, GMPCR_p2DA");

    asm("movl -0xbc(%ebp),%esi");
    asm("movl %esi, GMPCR_p1");

    asm("movl -0xc0(%ebp),%esi");
    asm("movl %esi, GMPCR_p2");

    asm("movl -0xdc(%ebp),%esi");
    asm("movl %esi, GMPCR_row");

    switch (Local_GetMeetsPrestigeClassRequirements()) {
        case 1: // SKILL
            asm("push $0x081588e2");
            break;
        case 2: // CONTINUE
            asm("push $0x08158fb6");
            break;
        case 3: // REQ NOT MET
            asm("movl $0x0,-0xb4(%ebp)");
            asm("push $0x08158fb6");
            break;
        default:
            asm("push $0x08158930");
            break;
    }

    asm("ret");
}

volatile CNWMessage *WGOU_pMsg;
volatile CNWSPlayer *WGOU_pPlayer;
volatile CNWSObject *WGOU_pObject;

__attribute__((noinline))
static void Local_PercentPartyHP()
{
    CNWSCreature *pTarget = WGOU_pObject->obj_vtable->AsNWSCreature((void *)WGOU_pObject);
    uint8_t assoc = 0;
    if (pTarget != NULL) {
        if (pTarget->cre_master_id != OBJECT_INVALID && nwn_GetPlayerByID(pTarget->cre_master_id) == WGOU_pPlayer) {
            assoc = 1;
        }
    }
    if (!assoc && nwn_GetPlayerByID(WGOU_pObject->obj_id) != WGOU_pPlayer && (int) * ((char*)WGOU_pPlayer + 0x74) != 2) {
        int p = (int)((float)WGOU_pObject->obj_vtable->GetCurrentHitPoints((void *)WGOU_pObject, 1) / (float)WGOU_pObject->obj_vtable->GetMaxHitPoints((void *)WGOU_pObject, 1) * 100);
        if (p > 100) p = 100;
        else if (p < 0) p = 0;
        CNWMessage__WriteSHORT((CNWMessage *)WGOU_pMsg, p, 16); /* CurrentHP */
        CNWMessage__WriteSHORT((CNWMessage *)WGOU_pMsg, 100, 16); /* MaxHP */
        CNWMessage__WriteSHORT((CNWMessage *)WGOU_pMsg, 0, 16); /* TempHP */
        CNWMessage__WriteSHORT((CNWMessage *)WGOU_pMsg, 100, 16); /* MaxHP */
    } else {
        CNWMessage__WriteSHORT((CNWMessage *)WGOU_pMsg, WGOU_pObject->obj_vtable->GetCurrentHitPoints((void *)WGOU_pObject, 1), 16); /* CurrentHP */
        CNWMessage__WriteSHORT((CNWMessage *)WGOU_pMsg, WGOU_pObject->obj_hp_max, 16); /* MaxHP */
        CNWMessage__WriteSHORT((CNWMessage *)WGOU_pMsg, WGOU_pObject->obj_hp_temp, 16); /* TempHP */
        CNWMessage__WriteSHORT((CNWMessage *)WGOU_pMsg, WGOU_pObject->obj_vtable->GetMaxHitPoints((void *)WGOU_pObject, 1), 16); /* MaxHP */
    }
}

void Hook_WriteGameObjUpdate_PercentPartyHP(void)
{
    asm("leave");

    asm("movl 0x8(%ebp),%eax");
    asm("movl %eax,WGOU_pMsg");

    asm("movl 0xC(%ebp),%eax");
    asm("movl %eax,WGOU_pPlayer");

    asm("movl 0x10(%ebp),%eax");
    asm("movl %eax,WGOU_pObject");

    Local_PercentPartyHP();

    asm("push $0x08073244");
    asm("ret");
}

__attribute__((noinline))
static void Local_HideArea()
{
    CGameObject *pPlayerGameObject = CNWSPlayer__GetGameObject((CNWSPlayer *)WGOU_pPlayer);
    CNWSObject *pPlayerObject;

    if (pPlayerGameObject != NULL && pPlayerGameObject->vtable != NULL) {
        pPlayerObject = pPlayerGameObject->vtable->AsNWSObject(pPlayerGameObject);
    }
    //
    if (*((char*)WGOU_pPlayer + 0x74) != 2 && (pPlayerObject == NULL || (pPlayerObject != NULL && pPlayerObject->obj_area_id !=  WGOU_pObject->obj_area_id))) {
        CNWSMessage__WriteOBJECTIDServer((CNWSMessage *)WGOU_pMsg, OBJECT_INVALID);
    } else {
        CNWSMessage__WriteOBJECTIDServer((CNWSMessage *)WGOU_pMsg, WGOU_pObject->obj_area_id);
    }

}

void Hook_WriteGameObjUpdate_HideArea(void)
{
    asm("leave");

    asm("movl 0x8(%ebp),%eax");
    asm("movl %eax,WGOU_pMsg");

    asm("movl 0xC(%ebp),%eax");
    asm("movl %eax,WGOU_pPlayer");

    asm("movl 0x10(%ebp),%eax");
    asm("movl %eax,WGOU_pObject");

    Local_HideArea();

    asm("push $0x8073104");
    asm("ret");
}


volatile int GDM_acb, GDM_acbmb;

__attribute__((noinline))
static int Local_GetDEXMod_ipMaxDexBonusMod()
{
    GDM_acbmb = 0;
    if (pCreatureStats != NULL) {
        CNWSItem *pItem_1 = CNWSInventory__GetItemInSlot(pCreatureStats->cs_original->cre_equipment, EQUIPMENT_SLOT_CHEST);
        if (pItem_1 != NULL) {
            if (CNWSItem__GetPropertyByTypeExists(pItem_1, confMaxDexterityBonus_ip, 0)) {
                CNWItemProperty *IP;
                for (size_t i = 0; i < pItem_1->field_1FC; i++) {
                    IP = CNWSItem__GetPassiveProperty(pItem_1, i);
                    if (IP != NULL && IP->ip_type == confMaxDexterityBonus_ip) {
                        if (IP->ip_cost_value != 9) {
                            GDM_acbmb = IP->ip_cost_value - 9;
                        } else {
                            GDM_acbmb = 100 - GDM_acb;
                        }
                    }
                }
            }
        }
    }
    GDM_acb += GDM_acbmb;
    if (GDM_acb > pCreatureStats->cs_dex_mod) {
        GDM_acb = pCreatureStats->cs_dex_mod;
    }
    return GDM_acb;
}

void Hook_GetDEXMod_ipMaxDexBonusMod_0x081518e9(void)
{
    asm("leave");

    asm("mov -0x2c(%ebp),%eax");
    asm("mov %eax, GDM_acb");
    asm("mov 0x8(%ebp),%ecx");
    asm("mov %ecx, pCreatureStats");

    if (GDM_acb > 0) {
        Local_GetDEXMod_ipMaxDexBonusMod();
        asm("push $0x08151934");
        asm("ret");
    }

    asm("push $0x8151904");
    asm("ret");
}

__attribute__((noinline))
static int Local_CheckUseMagicDeviceSkill(CNWSCreature *pCreature, CNWSItem *pItem, int arg)
{
    if (CNWSItem__GetPropertyByTypeExists(pItem, confIneffectiveUMD_ip, 0)) {
        return 0;
    }
    return 1;
}

int Hook_CheckUseMagicDeviceSkill(CNWSCreature *pCreature, CNWSItem *pItem, int arg)
{
    if (Local_CheckUseMagicDeviceSkill(pCreature, pItem, arg)) {
        asm("push   %edi");
        asm("push   %esi");
        asm("push   %ebx");
        asm("push $0x08111732");
        asm("ret");
    }

    return 0;
}


int InitHooks()
{
    *(unsigned long*)&CNWMessage__WriteSHORT = 0x80c3ddc;
    *(unsigned long*)&CNWSMessage__WriteOBJECTIDServer = 0x8052434;
    *(unsigned long*)&CNWSPlayer__GetGameObject = 0x0805e8b8;
    *(unsigned long*)&C2DA__GetINTEntry = 0x082bd77c;
    *(unsigned long*)&C2DA__GetCExoStringEntry = 0x082bedbc;

    *(unsigned long*)&CNWSItem__GetPropertyByTypeExists = 0x081a2a6c;

    if (extend.GetConfInteger("examine_cr_npc_only")) {
        /* EXAMINE CR ON NPC ONLY */
        nx_hook_function((void *)0x08073d15, (void *)hook_ExamineCR_NPC_Only, 8, NX_HOOK_DIRECT);
        extend.Log(0, "Examine CR on NPC Only : ENABLED\n");
    } else {
        extend.Log(0, "Examine CR on NPC Only : DISABLED\n");
    }


    /* Party Display */
    if (extend.GetConfInteger("party_percentage_hp")) {
        nx_hook_function((void *)0x080731d3, (void *)Hook_WriteGameObjUpdate_PercentPartyHP, 6, NX_HOOK_DIRECT);
        extend.Log(0, "Party Precentage HP : ENABLED\n");
    } else {
        extend.Log(0, "Party Precentage HP : DISABLED\n");
    }

    if (extend.GetConfInteger("party_hide_areas")) {
        nx_hook_function((void *)0x080730f0, (void *)Hook_WriteGameObjUpdate_HideArea, 6, NX_HOOK_DIRECT);
        extend.Log(0, "Party Hide Area : ENABLED\n");
    } else {
        extend.Log(0, "Party Hide Area : DISABLED\n");
    }

    if ((confMaxDexterityBonus_ip = extend.GetConfInteger("maxdexbonus_ip")) > 0) {
        nx_hook_function((void *)0x081518e9, (void *)Hook_GetDEXMod_ipMaxDexBonusMod_0x081518e9, 5, NX_HOOK_DIRECT);
        extend.Log(0, "Max Dexterity Bonus ItemProperty : ENABLED (Property: %d)\n", confMaxDexterityBonus_ip);
    } else {
        extend.Log(0, "Max Dexterity Bonus ItemProperty : DISABLED\n");
    }

    if ((confIneffectiveUMD_ip = extend.GetConfInteger("ineffective_umd_ip")) > 0) {
        nx_hook_function((void *)0x0811172c, (void *)Hook_CheckUseMagicDeviceSkill, 5, NX_HOOK_DIRECT);
        extend.Log(0, "Ineffective Use Magical Device ItemProperty : ENABLED (Property: %d)\n", confIneffectiveUMD_ip);
    } else {
        extend.Log(0, "Ineffective Use Magical Device ItemProperty : DISABLED\n");
    }

    if ((extend.GetConfInteger("equip_unidentified"))) {
        /* Allow to equip unidentified items */
        nx_hook_function((void *)0x80ffa5a, (void *)0x80ffa8c, 6, NX_HOOK_DIRECT);
        extend.Log(0, "Allow to Equip Unidentified items : ENABLED\n");
    } else {
        extend.Log(0, "Allow to Equip Unidentified items : DISABLED\n");
    }

    /* GetMeetsPrestigeClassRequirements */
    nx_hook_function((void *)0x081588c7, (void *)Hook_GetMeetsPrestigeClassRequirements, 8, NX_HOOK_DIRECT);

    return true;
}
