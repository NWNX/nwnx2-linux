
/***************************************************************************
    NWNXDefenses.cpp - Implementation of the CNWNXDefenses class.
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

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

#include "NWNXDefenses.h"
#include "DefensesStrCmds.h"
#include "DefensesObjCmds.h"


//////////////////////////////////////////////////////////////////////
// Function Signatures
//////////////////////////////////////////////////////////////////////

#define NWNX_DEFENSES_SIG(NAME, SIG) { #NAME, &NAME, SIG }

static unsigned char *Ref_ArmorCheckPenalty;
static unsigned char *Ref_CheckConcealment;
static unsigned char *Ref_CombatHitDamage;
static unsigned char *Ref_ConfirmCritical;
static unsigned char *Ref_DamageImmunityAlloc;
static unsigned char *Ref_DamageImmunitySet1;
static unsigned char *Ref_DamageImmunitySet2;
static unsigned char *Ref_DeathAttackImmune;
static unsigned char *Ref_TumbleACBonus;
static unsigned char *Ref_PickPocketDC;
static unsigned char *Ref_RDDFireImmunity;
static unsigned char *Ref_SlipperyMind;
static unsigned char *Ref_SneakAttackImmune;

#ifdef NWNX_DEFENSES_HG
static unsigned char *Ref_DamageImmEffect;
static unsigned char *Ref_DamageImmRemove;
static unsigned char *Ref_DamageResEffect;
static unsigned char *Ref_DamageResMessage;
static unsigned char *Ref_DamageVulnEffect;
static unsigned char *Ref_DamageImmItemProp;
#endif

static struct DefenseSignatureTable {
    const char         *name;
    void               *ref;
    const char         *sig;
} Table_DefenseSignatures[] = {
    { NULL, NULL,                                NULL },

    NWNX_DEFENSES_SIG(Ref_ArmorCheckPenalty,     "0F B6 45 F3 8D 14 80 8D 14 50 8B 81 E8 00 00 00 83 7C 90 24 01 75"),
    NWNX_DEFENSES_SIG(Ref_CheckConcealment,      "C7 45 BC 0A 00 00 00 8B 5D C0 85 DB 7F ** 8B 4D"),
    NWNX_DEFENSES_SIG(Ref_CombatHitDamage,       "FF 5A 59 6A 01 50 ** ** ** ** ** 83 C4 10 85 C0 78 36 83 EC"),
    NWNX_DEFENSES_SIG(Ref_ConfirmCritical,       "85 C0 75 ** 83 EC 08 68 80 03 00 00 8B 45 94 FF B0 64|68 0C 00 00 E8"),
    NWNX_DEFENSES_SIG(Ref_DamageImmunityAlloc,   "6A 0D E8 ** ** ** ** 89 83 78 01 00 00 31 D2 83 C4 10 90 8B 83 78 01"),
    NWNX_DEFENSES_SIG(Ref_DamageImmunitySet1,    "53 52 FF 90 BC|C0 00 00 00 0F BE C0 83 C4 0C 8D 04"),
    NWNX_DEFENSES_SIG(Ref_DamageImmunitySet2,    "53 57 FF 90 BC|C0 00 00 00 0F BE C0 83 C4 0C 2B 45"),
    NWNX_DEFENSES_SIG(Ref_DeathAttackImmune,     "53 FF 75 08 0F B6 05 ** ** ** ** 50 8B 45 0C FF B0 64|68 0C **#33 80 03"),
    NWNX_DEFENSES_SIG(Ref_TumbleACBonus,         "6A 01 6A 00 6A 15 01 B5 04 FE FF FF FF 75 08 C6"),
    NWNX_DEFENSES_SIG(Ref_PickPocketDC,          "3C 02 0F 94 C2 4A 83 E2 F6 83 C2 1E 89 95 6C FF"),
    NWNX_DEFENSES_SIG(Ref_RDDFireImmunity,       "55 89 E5 57 56 53 83 EC 18 8B 7D 08 8B 47 0C 57 8B 5D 0C FF 50 38 83 C4 10 85 C0 74 4B 83 EC 0C 8B 47 0C 57"),
    NWNX_DEFENSES_SIG(Ref_SlipperyMind,          "80 7D D3 01 0F 85 B0 00 00 00 83 EC 08 68 03 01 00 00"),
    NWNX_DEFENSES_SIG(Ref_SneakAttackImmune,     "50 FF 75 08 0F B6 05 ** ** ** ** 50 8B 45 0C FF B0 64|68 0C **#33 80 03"),

#ifdef NWNX_DEFENSES_HG
    NWNX_DEFENSES_SIG(Ref_DamageImmEffect,       "31 C0 89 45 F4 8B 45 F8 85 C0 78 08 3B 05 ** ** ** ** 7E 08 A1 ** ** ** ** 89 45 F8 66 8B 43 0A 25 E7"),
    NWNX_DEFENSES_SIG(Ref_DamageImmRemove,       "47 8B 45 E8 3B 78 04 7C 83 57 2B 75 EC 56 0F B7 45 F0"),
    NWNX_DEFENSES_SIG(Ref_DamageResEffect,       "B8 81 FD FF FF E9 ** ** ** ** 8D 76 00 8B 45 F4 85 C0 78 08 3B 05 ** ** ** ** 7E 08 A1"),
    NWNX_DEFENSES_SIG(Ref_DamageResMessage,      "8B 75 18 85 F6 0F 85 CB 02 00 00 83 7D 1C 01 0F"),
    NWNX_DEFENSES_SIG(Ref_DamageVulnEffect,      "B8 9C FF FF FF 89 45 F4 8B 45 F8 85 C0 78 08 3B 05 ** ** ** ** 7E 08 A1 ** ** ** ** 89 45 F8 66 8B 43 0A 25 E7"),
    NWNX_DEFENSES_SIG(Ref_DamageImmItemProp,     "5B 5F 6A 02 56 E8 ** ** ** ** 0F B7 45 C2 83 C4 10 83 F8 0B 0F"),
#endif

    { NULL, NULL,                                 NULL },
};


static void DefensesSearchCallback(int id, void *addr)
{
    nx_log(NX_LOG_NOTICE, 0, "%s (%d) found at %p%s",
           Table_DefenseSignatures[id].name, id, addr,
           (*(void **)Table_DefenseSignatures[id].ref == NULL ? "" : " (duplicate)"));

    *(void **)(Table_DefenseSignatures[id].ref) = addr;
}

static void DefensesSearchSignatures(void)
{
    int i;

    nx_sig_search_t *sig = nx_sig_search_create(DefensesSearchCallback);

    for (i = 1; Table_DefenseSignatures[i].sig != NULL; i++)
        nx_sig_search_add_signature(sig, i, Table_DefenseSignatures[i].sig);

    nx_sig_search_run(sig);
    nx_sig_search_destroy(sig);


    for (i = 1; Table_DefenseSignatures[i].sig != NULL; i++) {
        if (*(void **)Table_DefenseSignatures[i].ref == NULL)
            nx_log(NX_LOG_NOTICE, 0, "%s (%d) not found", Table_DefenseSignatures[i].name, i);
    }
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXDefenses::CNWNXDefenses()
{
    confKey = strdup("DEFENSES");
}


CNWNXDefenses::~CNWNXDefenses()
{
}


char *CNWNXDefenses::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    const struct DefensesStrCommand_s *cmd;

    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    if ((cmd = DefensesStrCommandLookup(Request, strlen(Request))) != NULL)
        cmd->func((CGameObject *)gameObject, Parameters);
    else
        Log(0, "Unrecognized string request: \"%s\" \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
}


unsigned long CNWNXDefenses::OnRequestObject(char *gameObject, char *Request)
{
    unsigned long ret = OBJECT_INVALID;
    const struct DefensesObjCommand_s *cmd;

    Log(1, "ObjReq: \"%s\"\n", Request);

    if ((cmd = DefensesObjCommandLookup(Request, strlen(Request))) != NULL)
        ret = cmd->func((CGameObject *)gameObject);
    else
        Log(0, "Unrecognized object request: \"%s\"\n", Request);

    Log(1, "Return: %08X\n", ret);

    return ret;
}


bool CNWNXDefenses::OnCreate(gline *config, const char *LogDir)
{
    char log[128];

    sprintf(log, "%s/nwnx_defenses.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    /* find hook signatures */
    DefensesSearchSignatures();


    /* replace 'other' and 'tumble' AC bonus functions */
    nx_hook_function((void *)CNWSCreatureStats__GetACNaturalBase,
                     (void *)Hook_GetACNaturalBase, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetTotalACSkillMod,
                     (void *)Hook_GetTumbleACBonus, 5, NX_HOOK_DIRECT);


    /* replace concealment check */
    if (Ref_CheckConcealment != NULL) {
        int found = 0;
        unsigned char *p = Ref_CheckConcealment;
        unsigned char *end = p + 0x200;

        nx_hook_function(p + 7, (void *)Hook_CheckConcealment, 5, NX_HOOK_DIRECT);

        p += 12;

        while (p++ < end) {
            if (*p == 0x7D) {
                nx_hook_enable_write(p, 1);
                *p = 0xEB; /* JMP SHORT */

                found++;
                break;
            }
        }

        if (found) {
            extern volatile uintptr_t Hook_CCONC_ReturnHit, Hook_CCONC_ReturnMiss;

            Hook_CCONC_ReturnHit  = (uintptr_t)p;
            Hook_CCONC_ReturnMiss = (uintptr_t)p + 2;

            nx_log(NX_LOG_INFO, 0, "found concealment check jump reference at %p", p);
        } else
            nx_log(NX_LOG_INFO, 0, "did not find concealment check jump reference before %p", p);
    }


    /* hook hit damage in combat */
    if (Ref_CombatHitDamage != NULL) {
        extern volatile uintptr_t Hook_CHD_Return;

        Hook_CHD_Return = (uintptr_t)(Ref_CombatHitDamage + 6);

        nx_hook_function(Ref_CombatHitDamage + 1, (void *)Hook_CombatHitDamage,
                         5, NX_HOOK_DIRECT);
    }


    /* fix damage immunity stacking */
    if (Ref_DamageImmunityAlloc != NULL &&
            Ref_DamageImmunitySet1  != NULL &&
            Ref_DamageImmunitySet2  != NULL) {

        int i;
        unsigned char *p;

        nx_hook_enable_write(Ref_DamageImmunityAlloc, 33);
        nx_hook_enable_write(Ref_DamageImmunitySet1 - 10, 40);
        nx_hook_enable_write(Ref_DamageImmunitySet2 - 10, 40);

#ifdef NWNX_DEFENSES_HG
        Ref_DamageImmunityAlloc[1]  = 0x30;    /* PUSH 0x30 */
        Ref_DamageImmunityAlloc[32] = 0x30;    /* CMP EDX, 0x30 */

        Ref_DamageImmunitySet1[-6]  = 0x89;    /* MOV EBX <- ESI */
        Ref_DamageImmunitySet1[-5]  = 0xF3;
        Ref_DamageImmunitySet1[-4]  = 0x90;    /* NOP */

        Ref_DamageImmunitySet2[-6]  = 0x89;    /* MOV EBX <- ESI */
        Ref_DamageImmunitySet2[-5]  = 0xF3;
        Ref_DamageImmunitySet2[-4]  = 0x90;    /* NOP */
#else
        Ref_DamageImmunityAlloc[1]  = 0x1A;    /* PUSH 0x1A */
        Ref_DamageImmunityAlloc[32] = 0x1A;    /* CMP EDX, 0x1A */
#endif

        Ref_DamageImmunitySet1[2] = 0x31;      /* XOR EAX, EAX */
        Ref_DamageImmunitySet1[3] = 0xC0;

        Ref_DamageImmunitySet2[2] = 0x31;      /* XOR EAX, EAX */
        Ref_DamageImmunitySet2[3] = 0xC0;

        for (i = 4; i < 11; i++) {
            Ref_DamageImmunitySet1[i] = 0x90;  /* NOP */
            Ref_DamageImmunitySet2[i] = 0x90;  /* NOP */
        }

        p = Ref_DamageImmunitySet1;
        *(unsigned long *)(p + 23) = (unsigned long)Hook_AddDamageImmunity - (unsigned long)(p + 27);

        p = Ref_DamageImmunitySet2;
        *(unsigned long *)(p + 21) = (unsigned long)Hook_AddDamageImmunity - (unsigned long)(p + 25);

        nx_hook_function((void *)CNWSObject__GetDamageImmunity,
                         (void *)Hook_GetDamageImmunity, 5, NX_HOOK_DIRECT);
        nx_hook_function((void *)CNWSObject__SetDamageImmunity,
                         (void *)Hook_SetDamageImmunity, 5, NX_HOOK_DIRECT);
    }


    /* hook saving throw calculation functions */
    if (CNWSCreatureStats__GetFortSavingThrow != NULL) {
        unsigned char *p = (unsigned char *)CNWSCreatureStats__GetFortSavingThrow;
        unsigned char *end = p + 0x200;

        while (p++ < end) {
            if (p[0] == 0x8D && p[1] == 0x65 && p[2] == 0xF4)
                break;
        }

        if (p < end) {
            nx_log(NX_LOG_INFO, 0, "found fortitude saving throw return reference at %p", p);

            nx_hook_function(p, (void *)Hook_GetFortitudeSavingThrow, 5, NX_HOOK_DIRECT);
        } else
            nx_log(NX_LOG_INFO, 0, "did not find fortitude saving throw return reference before %p", p);
    }

    if (CNWSCreatureStats__GetReflexSavingThrow != NULL) {
        unsigned char *p = (unsigned char *)CNWSCreatureStats__GetReflexSavingThrow;
        unsigned char *end = p + 0x200;

        while (p++ < end) {
            if (p[0] == 0x8D && p[1] == 0x65 && p[2] == 0xF4 && p[3] == 0x5B)
                break;
        }

        if (p < end) {
            nx_log(NX_LOG_INFO, 0, "found reflex saving throw return reference at %p", p);

            nx_hook_function(p, (void *)Hook_GetReflexSavingThrow, 5, NX_HOOK_DIRECT);
        } else
            nx_log(NX_LOG_INFO, 0, "did not find reflex saving throw return reference before %p", p);
    }

    if (CNWSCreatureStats__GetWillSavingThrow != NULL) {
        unsigned char *p = (unsigned char *)CNWSCreatureStats__GetWillSavingThrow;
        unsigned char *end = p + 0x200;

        while (p++ < end) {
            if (p[0] == 0x8D && p[1] == 0x65 && p[2] == 0xF4)
                break;
        }

        if (p < end) {
            nx_log(NX_LOG_INFO, 0, "found will saving throw return reference at %p", p);

            nx_hook_function(p, (void *)Hook_GetWillSavingThrow, 5, NX_HOOK_DIRECT);
        } else
            nx_log(NX_LOG_INFO, 0, "did not find will saving throw return reference before %p", p);
    }


    /* hook Pick Pocket DC */
    if (Ref_PickPocketDC != NULL) {
        extern volatile uintptr_t Hook_PPDC_Return;

        Hook_PPDC_Return = (uintptr_t)(Ref_PickPocketDC + 12);

        nx_hook_function(Ref_PickPocketDC, (void *)Hook_PickPocketDC, 5, NX_HOOK_DIRECT);
    }


    /* hook Red Dragon Disciple absolute fire immunity */
    if (Ref_RDDFireImmunity != NULL) {
        int found = 0;
        unsigned char *p = Ref_RDDFireImmunity;
        unsigned char *end = p + 0x200;

        while (p++ < end) {
            if (!found && *p == 0x74) {
                nx_hook_enable_write(p, 1);

                *p    = 0xEB; /* JMP SHORT */
                found = 1;
            }

            if (p[0] == 0x8D && p[1] == 0x65 && p[2] == 0xF4 && p[3] == 0x5B)
                break;
        }
    }


    /* hook Tumble AC bonus */
    if (Ref_TumbleACBonus != NULL) {
        unsigned char *p = Ref_TumbleACBonus;
        unsigned char *end = p + 0x80;

        nx_hook_enable_write(p, 128);

        *(unsigned long *)(p + 23) = (unsigned long)Hook_GetTumbleACBonus -
                                     (unsigned long)(p + 27);

        p += 29;

        while (p++ < end) {
            if (p[0] == 0x88 && p[1] == 0x85 && p[2] == 0xDB && p[3] == 0xFD)
                break;

            *p = 0x90;  /* NOP */
        }
    }


    /* hook Slippery Mind check */
    if (Ref_SlipperyMind != NULL) {
        unsigned char *p = Ref_SlipperyMind;

        nx_hook_enable_write(p, 33);

        p[0]  = 0x0F;  /* MOVZBL EAX <- [EBP+12] */
        p[1]  = 0xB6;
        p[2]  = 0x45;
        p[3]  = 0x0C;

        p[4]  = 0xC1;  /* SHL EAX, 0x10 */
        p[5]  = 0xE0;
        p[6]  = 0x10;

        p[7]  = 0x66;  /* MOVZBW AX <- [EBP-45] */
        p[8]  = 0x0F;
        p[9]  = 0xB6;
        p[10] = 0x45;
        p[11] = 0xD3;

        p[12] = 0x83;  /* SUB ESP, 0x8 */
        p[13] = 0xEC;
        p[14] = 0x08;

        p[15] = 0x90;  /* NOP */
        p[16] = 0x90;  /* NOP */

        p[17] = 0x50;  /* PUSH EAX */

        *(unsigned long *)(p + 28) = (unsigned long)Hook_GetHasSlipperyMind -
                                     (unsigned long)(p + 32);
    }


    /* sneak attack immunity hook */
    if (Ref_SneakAttackImmune != NULL) {
        int i;

        nx_hook_enable_write(Ref_SneakAttackImmune, 96);

        *(unsigned long *)(Ref_SneakAttackImmune + 22) =
            (unsigned long)Hook_GetIsSneakAttackImmune - (unsigned long)(Ref_SneakAttackImmune + 26);

        for (i = 33; i < 94; i++)
            Ref_SneakAttackImmune[i] = 0x90;    /* NOP */
    }


    /* death attack immunity hook */
    if (Ref_DeathAttackImmune != NULL) {
        int i;

        nx_hook_enable_write(Ref_DeathAttackImmune, 96);

        *(unsigned long *)(Ref_DeathAttackImmune + 22) =
            (unsigned long)Hook_GetIsDeathAttackImmune - (unsigned long)(Ref_DeathAttackImmune + 26);

        for (i = 33; i < 94; i++)
            Ref_DeathAttackImmune[i] = 0x90;    /* NOP */
    }


    /* critical confirmation check */
    if (Ref_ConfirmCritical != NULL) {
        unsigned char *p = Ref_ConfirmCritical;

        nx_hook_enable_write(p, 28);

        p[7]  = 0xFF;   /* PUSH DWORD PTR [EBP+8] */
        p[8]  = 0x75;
        p[9]  = 0x08;

        p[10] = 0x90;   /* NOP */
        p[11] = 0x90;   /* NOP */

        *(unsigned long *)(p + 22) = (unsigned long)Hook_ConfirmCritical -
                                     (unsigned long)(p + 26);
    }


    /* armor check penalty check */
    if (Ref_ArmorCheckPenalty != NULL) {
        extern volatile uintptr_t Hook_ACP_Return;

        Hook_ACP_Return = (uintptr_t)(Ref_ArmorCheckPenalty + 38);

        nx_hook_function(Ref_ArmorCheckPenalty + 23, (void *)Hook_GetArmorCheckPenalty, 5, NX_HOOK_DIRECT);
    }


#ifdef NWNX_DEFENSES_HG
    /* damage immunity effect hook */
    if (Ref_DamageImmEffect != NULL) {
        nx_hook_enable_write(Ref_DamageImmEffect, 32);

        Ref_DamageImmEffect[12] = 0x3D;         /* CMP EAX, 0x7FFFFFFF */
        Ref_DamageImmEffect[13] = 0xFF;
        Ref_DamageImmEffect[14] = 0xFF;
        Ref_DamageImmEffect[15] = 0xFF;
        Ref_DamageImmEffect[16] = 0x7F;
        Ref_DamageImmEffect[17] = 0x90;         /* NOP */
    }

    if (Ref_DamageImmRemove != NULL) {
        nx_hook_enable_write(Ref_DamageImmRemove, 32);

        Ref_DamageImmRemove[14] = 0x8B;         /* MOV EAX <- DWORD PTR [EBP-16] */
        Ref_DamageImmRemove[15] = 0x45;
        Ref_DamageImmRemove[16] = 0xF0;
        Ref_DamageImmRemove[17] = 0x90;         /* NOP */
    }

    if (Ref_DamageResEffect != NULL) {
        nx_hook_enable_write(Ref_DamageResEffect, 32);

        Ref_DamageResEffect[20] = 0x3D;         /* CMP EAX, 0x7FFFFFFF */
        Ref_DamageResEffect[21] = 0xFF;
        Ref_DamageResEffect[22] = 0xFF;
        Ref_DamageResEffect[23] = 0xFF;
        Ref_DamageResEffect[24] = 0x7F;
        Ref_DamageResEffect[25] = 0x90;         /* NOP */
    }

    /* damage vulnerability effect hook */
    if (Ref_DamageVulnEffect != NULL) {
        nx_hook_enable_write(Ref_DamageVulnEffect, 32);

        Ref_DamageVulnEffect[15] = 0x3D;        /* CMP EAX, 0x7FFFFFFF */
        Ref_DamageVulnEffect[16] = 0xFF;
        Ref_DamageVulnEffect[17] = 0xFF;
        Ref_DamageVulnEffect[18] = 0xFF;
        Ref_DamageVulnEffect[19] = 0x7F;
        Ref_DamageVulnEffect[20] = 0x90;        /* NOP */
    }

    /* damage immunity item property hook */
    if (Ref_DamageImmItemProp != NULL) {
        nx_hook_enable_write(Ref_DamageImmItemProp, 40);

        Ref_DamageImmItemProp[17] = 0x51;       /* PUSH ECX */
        Ref_DamageImmItemProp[18] = 0x89;       /* MOV ECX <- EAX */
        Ref_DamageImmItemProp[19] = 0xC1;
        Ref_DamageImmItemProp[20] = 0xBE;       /* MOV ESI <- 0x1 */
        Ref_DamageImmItemProp[21] = 0x01;
        Ref_DamageImmItemProp[22] = 0x00;
        Ref_DamageImmItemProp[23] = 0x00;
        Ref_DamageImmItemProp[24] = 0x00;
        Ref_DamageImmItemProp[25] = 0xD3;       /* SHL ESI, CL */
        Ref_DamageImmItemProp[26] = 0xE6;
        Ref_DamageImmItemProp[27] = 0x59;       /* POP ECX */
        Ref_DamageImmItemProp[28] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[29] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[30] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[31] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[32] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[33] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[34] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[35] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[36] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[37] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[38] = 0x90;       /* NOP */
        Ref_DamageImmItemProp[39] = 0x90;       /* NOP */
    }

    /* damage resistance effect hook */
    if (Ref_DamageResMessage != NULL) {
        extern uintptr_t Hook_DR_Return;

        Hook_DR_Return = (uintptr_t)(Ref_DamageResMessage + 5);
        nx_hook_function(Ref_DamageResMessage, (void *)Hook_DamageResistanceMessage, 5, NX_HOOK_DIRECT);
    }


    /* fix saving throw bonus/penalty on items */
    {
        nx_hook_enable_write((unsigned char *)0x81B0450, 32);
        *((unsigned char *)0x81B045D) = 0x02;

        nx_hook_enable_write((unsigned char *)0x81B04F0, 32);
        *((unsigned char *)0x81B04FD) = 0x02;

        nx_hook_enable_write((unsigned char *)0x81B0590, 32);
        *((unsigned char *)0x81B059D) = 0x15;

        nx_hook_enable_write((unsigned char *)0x81B0630, 32);
        *((unsigned char *)0x81B063D) = 0x15;
    }
#endif

    return true;
}

/* vim: set sw=4: */
