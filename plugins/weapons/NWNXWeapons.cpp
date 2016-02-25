
/***************************************************************************
    NWNXWeapons.cpp - Implementation of the CNWNXWeapons class.
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

#include "NWNXWeapons.h"
#include "WeaponsStrCmds.h"
#include "WeaponsObjCmds.h"


//////////////////////////////////////////////////////////////////////
// Function Signatures
//////////////////////////////////////////////////////////////////////

#define NWNX_WEAPONS_SIG(NAME, SIG) { #NAME, &NAME, SIG }

static unsigned char *Ref_ABAbilityModifier;
static unsigned char *Ref_CritConfirmationRoll;
static unsigned char *Ref_EpicWeaponSpecDamage;
static unsigned char *Ref_EpicWeaponSpecMelee;
static unsigned char *Ref_EpicWeaponSpecRanged;
static unsigned char *Ref_OffhandCritMult1;
static unsigned char *Ref_OffhandCritMult2;
static unsigned char *Ref_OffhandCritMult3;
static unsigned char *Ref_OffhandCritMult4;
static unsigned char *Ref_UpdateAttacks;

static struct WeaponSignatureTable {
    const char         *name;
    void               *ref;
    const char         *sig;
} Table_WeaponSignatures[] = {
    { NULL, NULL,                               NULL },

    NWNX_WEAPONS_SIG(Ref_ABAbilityModifier,     "8B 9D 3C FA FF FF 31 FF 85 DB C7 85 F8 F9 FF FF 00 00 00 00"),
    NWNX_WEAPONS_SIG(Ref_CritConfirmationRoll,  "0F B7 C0 C7 47 48 01 00 00 00 88 47 0F 03 45 A0 83 C4 10 3B"),
    NWNX_WEAPONS_SIG(Ref_EpicWeaponSpecDamage,  "83 EC 08 FF B5 54 FD FF FF FF 75 08 E8 ** ** ** ** 31 FF 83 C4 10 85 C0 74 05 BF 04 00 00 00"),
    NWNX_WEAPONS_SIG(Ref_EpicWeaponSpecMelee,   "83 EC 08 53 01 75 E4 57 E8 ** ** ** ** 31 F6 83 C4 10 85 C0 74 05 BE 04 00 00 00"),
    NWNX_WEAPONS_SIG(Ref_EpicWeaponSpecRanged,  "83 EC 08 FF 75 EC 56 E8 ** ** ** ** 01 FB 83 C4 10 31 FF 85 C0 74 05 BF 04 00 00 00"),
    NWNX_WEAPONS_SIG(Ref_OffhandCritMult1,      "66 01 B5 16 FE FF FF 83 EC 08 6A 00 68 FF 00 00 00 68 FF 00 00 00 6A 00"),
    NWNX_WEAPONS_SIG(Ref_OffhandCritMult2,      "83 EC 08 6A 00 68 FF 00 00 00 68 FF 00 00 00 6A 00 6A 00 6A 01 6A 01 50"),
    NWNX_WEAPONS_SIG(Ref_OffhandCritMult3,      "6A 00 68 FF 00 00 00 68 FF 00 00 00 6A 00 6A 00 6A 00 6A 01 50 6A 02 FF 75 08"),
    NWNX_WEAPONS_SIG(Ref_OffhandCritMult4,      "83 C4 10 85 C0 ** ** ** ** 00 00 83 EC 08 52 FF 75 08 ** ** ** ** ** 8B 7D D4 83 C4 10"),
    NWNX_WEAPONS_SIG(Ref_UpdateAttacks,         "8B 45 08 83 EC 08 8B 98 28 04 00 00 6A 00 50 E8 ** ** ** ** 83 C4"),

    { NULL, NULL,                               NULL },
};


static void WeaponsSearchCallback(int id, void *addr)
{
    nx_log(NX_LOG_NOTICE, 0, "%s (%d) found at %p%s",
           Table_WeaponSignatures[id].name, id, addr,
           (*(void **)Table_WeaponSignatures[id].ref == NULL ? "" : " (duplicate)"));

    *(void **)(Table_WeaponSignatures[id].ref) = addr;
}

static void WeaponsSearchSignatures(void)
{
    int i;

    nx_sig_search_t *sig = nx_sig_search_create(WeaponsSearchCallback);

    for (i = 1; Table_WeaponSignatures[i].sig != NULL; i++)
        nx_sig_search_add_signature(sig, i, Table_WeaponSignatures[i].sig);

    nx_sig_search_run(sig);
    nx_sig_search_destroy(sig);


    for (i = 1; Table_WeaponSignatures[i].sig != NULL; i++) {
        if (*(void **)Table_WeaponSignatures[i].ref == NULL)
            nx_log(NX_LOG_NOTICE, 0, "%s (%d) not found", Table_WeaponSignatures[i].name, i);
    }
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXWeapons::CNWNXWeapons()
{
    confKey = strdup("WEAPONS");
}


CNWNXWeapons::~CNWNXWeapons()
{
}


char *CNWNXWeapons::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    const struct WeaponsStrCommand_s *cmd;

    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    if ((cmd = WeaponsStrCommandLookup(Request, strlen(Request))) != NULL)
        cmd->func((CGameObject *)gameObject, Parameters);
    else
        Log(0, "Unrecognized string request: \"%s\" \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
}


unsigned long CNWNXWeapons::OnRequestObject(char *gameObject, char *Request)
{
    unsigned long ret = OBJECT_INVALID;
    const struct WeaponsObjCommand_s *cmd;

    Log(1, "ObjReq: \"%s\"\n", Request);

    if ((cmd = WeaponsObjCommandLookup(Request, strlen(Request))) != NULL)
        ret = cmd->func((CGameObject *)gameObject);
    else
        Log(0, "Unrecognized object request: \"%s\"\n", Request);

    Log(1, "Return: %08X\n", ret);

    return ret;
}


bool CNWNXWeapons::OnCreate(gline *config, const char *LogDir)
{
    char log[128];

    sprintf(log, "%s/nwnx_weapons.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    /* find hook signatures */
    WeaponsSearchSignatures();

    /* replace weapon focus feats */
    nx_hook_function((void *)CNWSCreatureStats__GetWeaponFocus,
                     (void *)Hook_GetWeaponFocus, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetEpicWeaponFocus,
                     (void *)Hook_GetEpicWeaponFocus, 5, NX_HOOK_DIRECT);

    /* replace weapon specialization feats */
    nx_hook_function((void *)CNWSCreatureStats__GetWeaponSpecialization,
                     (void *)Hook_GetWeaponSpecialization, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetEpicWeaponSpecialization,
                     (void *)Hook_GetEpicWeaponSpecialization, 5, NX_HOOK_DIRECT);

    /* replace critical hit feats */
    nx_hook_function((void *)CNWSCreatureStats__GetWeaponImprovedCritical,
                     (void *)Hook_GetWeaponImprovedCritical, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetEpicWeaponOverwhelmingCritical,
                     (void *)Hook_GetEpicWeaponOverwhelmingCritical, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetEpicWeaponDevastatingCritical,
                     (void *)Hook_GetEpicWeaponDevastatingCritical, 5, NX_HOOK_DIRECT);

    /* replace Weapon of Choice feats */
    nx_hook_function((void *)CNWSCreatureStats__GetIsWeaponOfChoice,
                     (void *)Hook_GetIsWeaponOfChoice, 5, NX_HOOK_DIRECT);

    /* replace weapon finesse and monk weapon checks */
    nx_hook_function((void *)CNWSCreatureStats__GetWeaponFinesse,
                     (void *)Hook_GetWeaponFinesse, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetUseMonkAttackTables,
                     (void *)Hook_GetUseMonkAttackTables, 5, NX_HOOK_DIRECT);


    /* hook critical hit range */
    if (CNWSCreatureStats__GetCriticalHitRoll != NULL) {
        unsigned char *p = (unsigned char *)CNWSCreatureStats__GetCriticalHitRoll;
        unsigned char *end = p + 0x200;

        while (p++ < end) {
            if (p[0] == 0x89 && p[1] == 0xF9 && p[2] == 0x8D && p[3] == 0x65)
                break;
        }

        if (p < end) {
            nx_log(NX_LOG_INFO, 0, "found critical range return reference at %p", p);

            nx_hook_function(p, (void *)Hook_GetCriticalRange, 5, NX_HOOK_DIRECT);
        } else
            nx_log(NX_LOG_INFO, 0, "critical range return reference not found before %p", p);
    }


    /* hook critical hit multiplier */
    if (CNWSCreatureStats__GetCriticalHitMultiplier != NULL) {
        unsigned char *p = (unsigned char *)CNWSCreatureStats__GetCriticalHitMultiplier;
        unsigned char *end = p + 0x200;

        while (p++ < end) {
            if (p[0] == 0x8D && p[1] == 0x65 && p[2] == 0xF4 && p[3] == 0x5B)
                break;
        }

        if (p < end) {
            nx_log(NX_LOG_INFO, 0, "found critical multiplier return reference at %p", p);

            nx_hook_function(p, (void *)Hook_GetCriticalMultiplier, 5, NX_HOOK_DIRECT);
        } else
            nx_log(NX_LOG_INFO, 0, "critical multiplier return reference not found before %p", p);
    }


    /* AB ability modifier hook */
    if (Ref_ABAbilityModifier != NULL) {
        int found = 0;
        unsigned char *p = Ref_ABAbilityModifier;
        unsigned char *end = p + 0x200;
        extern volatile uintptr_t Hook_ABAM_Return;

        while (p++ < end) {
            if (*p == 0x74) {
                found++;
                nx_hook_function(p, (void *)Hook_GetABAbilityModifier, 5, NX_HOOK_DIRECT);

                break;
            }
        }

        while (found == 1 && p++ < end) {
            if (*p == 0xEB) {
                found++;
                break;
            }
        }

        if (found == 2) {
            nx_log(NX_LOG_INFO, 0, "found AB ability modifier jump reference at %p", p);

            Hook_ABAM_Return = (uintptr_t)p;
        } else
            nx_log(NX_LOG_INFO, 0, "did not find AB ability modifier jump reference before %p", p);
    }


    /* critical confirmation roll hook */
    if (Ref_CritConfirmationRoll != NULL) {
        extern volatile uintptr_t Hook_CCR_Return;

        Hook_CCR_Return = (uintptr_t)(Ref_CritConfirmationRoll + 10);
        nx_hook_function(Ref_CritConfirmationRoll, (void *)Hook_GetCriticalConfirmationRoll, 5, NX_HOOK_DIRECT);
    }


    /* combat damage bonus hook */
    if (Ref_EpicWeaponSpecDamage != NULL) {
        unsigned char *p = Ref_EpicWeaponSpecDamage;

        nx_hook_enable_write(p, 128);

        *(unsigned long *)(p + 13) = (unsigned long)Hook_GetDamageBonusAdjustment -
                                     (unsigned long)(p + 17);

        p[22] = 0x89;   /* MOV EDI <- EAX */
        p[23] = 0xC7;
        p[24] = 0x90;   /* NOP */
        p[25] = 0x90;   /* NOP */
        p[26] = 0x90;   /* NOP */
        p[27] = 0x90;   /* NOP */
        p[28] = 0x90;   /* NOP */
        p[29] = 0x90;   /* NOP */
        p[30] = 0x90;   /* NOP */
    }


    /* melee damage bonus hook */
    if (Ref_EpicWeaponSpecMelee != NULL) {
        unsigned char *p = Ref_EpicWeaponSpecMelee;

        nx_hook_enable_write(p, 128);

        *(unsigned long *)(p + 9) = (unsigned long)Hook_GetDamageBonusAdjustment -
                                    (unsigned long)(p + 13);

        p[18] = 0x89;   /* MOV ESI <- EAX */
        p[19] = 0xC6;
        p[20] = 0x90;   /* NOP */
        p[21] = 0x90;   /* NOP */
        p[22] = 0x90;   /* NOP */
        p[23] = 0x90;   /* NOP */
        p[24] = 0x90;   /* NOP */
        p[25] = 0x90;   /* NOP */
        p[26] = 0x90;   /* NOP */
    }


    /* ranged damage bonus hook */
    if (Ref_EpicWeaponSpecRanged != NULL) {
        unsigned char *p = Ref_EpicWeaponSpecRanged;

        nx_hook_enable_write(p, 128);

        *(unsigned long *)(p + 8) = (unsigned long)Hook_GetDamageBonusAdjustment -
                                    (unsigned long)(p + 12);

        p[17] = 0x89;   /* MOV EDI <- EAX */
        p[18] = 0xC7;
        p[19] = 0x90;   /* NOP */
        p[20] = 0x90;   /* NOP */
        p[21] = 0x90;   /* NOP */
        p[22] = 0x90;   /* NOP */
        p[23] = 0x90;   /* NOP */
        p[24] = 0x90;   /* NOP */
        p[25] = 0x90;   /* NOP */
        p[26] = 0x90;   /* NOP */
        p[27] = 0x90;   /* NOP */
    }


    /* attacks per round hook */
#if 0
    if (Ref_UpdateAttacks != NULL) {
        unsigned char *p = Ref_UpdateAttacks;
        unsigned char *end = p + 0x80;

        nx_hook_enable_write(p, 128);

        *(unsigned long *)(p + 16) = (unsigned long)CNWSCreatureStats__GetAttacksPerRound -
                                     (unsigned long)(p + 20);

        p += 22;

        while (p++ < end) {
            if (p[0] == 0x88 && p[1] == 0x03 && p[2] == 0x83 && p[3] == 0xEC)
                break;

            *p = 0x90;  /* NOP */
        }
    }
#endif


    /* override 'Extra Damage Type' with 'Replace Damage Type' */
#ifdef NWNX_WEAPONS_HG
    {
        nx_hook_enable_write((unsigned char *)0x081A5DB0, 64);

        *((unsigned char *)0x081A5DB3) = 0x8B;
        *((unsigned char *)0x081A5DC3) = 0x8B;
        *((unsigned char *)0x081A5DD3) = 0x8B;
    }
#endif


    /* allow Monster Damage to work on all weapons */
#ifdef NWNX_WEAPONS_HG
    {
        nx_hook_enable_write((unsigned char *)0x0814AADD, 64);

        *((unsigned char *)0x0814AAE3) = 0x31;  /* XOR EBX, EBX */
        *((unsigned char *)0x0814AAE4) = 0xDB;
        *((unsigned char *)0x0814AAE5) = 0x83;  /* CMP EAX, 2   */
        *((unsigned char *)0x0814AAE6) = 0xF8;
        *((unsigned char *)0x0814AAE7) = 0x02;
        *((unsigned char *)0x0814AAE8) = 0x0F;  /* SETA BL      */
        *((unsigned char *)0x0814AAE9) = 0x97;
        *((unsigned char *)0x0814AAEA) = 0xC3;
        *((unsigned char *)0x0814AAEB) = 0x90;  /* NOP          */
        *((unsigned char *)0x0814AB06) = 0x90;  /* NOP          */

        nx_hook_function((unsigned char *)0x0814AB01, (void *)Hook_GetMonsterDamageHandler, 5, NX_HOOK_DIRECT);
    }
#endif


    /* fix offhand critical multiplier bug */
    if (Ref_OffhandCritMult1 != NULL && Ref_OffhandCritMult2 != NULL &&
            Ref_OffhandCritMult3 != NULL && Ref_OffhandCritMult4 != NULL) {

        extern volatile uintptr_t Hook_OHCM1_Return;
        extern volatile uintptr_t Hook_OHCM2_Return;
        extern volatile uintptr_t Hook_OHCM3_Return;
        extern volatile uintptr_t Hook_OHCM4_Return;

        Hook_OHCM1_Return = (uintptr_t)(Ref_OffhandCritMult1 + 16);

        nx_hook_enable_write(Ref_OffhandCritMult1, 18);

        Ref_OffhandCritMult1[10] = 0x68;
        Ref_OffhandCritMult1[15] = 0xC3;
        Ref_OffhandCritMult1[16] = 0x90;

        *((unsigned long *)(Ref_OffhandCritMult1 + 11)) =
            (unsigned long)Hook_OffhandCritMult1;


        Hook_OHCM2_Return = (uintptr_t)(Ref_OffhandCritMult2 + 9);

        nx_hook_enable_write(Ref_OffhandCritMult2, 12);

        Ref_OffhandCritMult2[3] = 0x68;
        Ref_OffhandCritMult2[8] = 0xC3;
        Ref_OffhandCritMult2[9] = 0x90;

        *((unsigned long *)(Ref_OffhandCritMult2 + 4)) =
            (unsigned long)Hook_OffhandCritMult2;


        Hook_OHCM3_Return = (uintptr_t)(Ref_OffhandCritMult3 + 6);

        nx_hook_enable_write(Ref_OffhandCritMult3, 12);

        Ref_OffhandCritMult3[0] = 0x68;
        Ref_OffhandCritMult3[5] = 0xC3;
        Ref_OffhandCritMult3[6] = 0x90;

        *((unsigned long *)(Ref_OffhandCritMult3 + 1)) =
            (unsigned long)Hook_OffhandCritMult3;


        Hook_OHCM4_Return = (uintptr_t)(Ref_OffhandCritMult4 + 17);

        nx_hook_enable_write(Ref_OffhandCritMult4, 20);

        Ref_OffhandCritMult4[11] = 0x68;
        Ref_OffhandCritMult4[16] = 0xC3;
        Ref_OffhandCritMult4[17] = 0x90;

        *((unsigned long *)(Ref_OffhandCritMult4 + 12)) =
            (unsigned long)Hook_OffhandCritMult4;
    }

    return true;
}

/* vim: set sw=4: */
