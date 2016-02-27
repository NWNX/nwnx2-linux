/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#include "NWNXLib.h"

#define NX_NWN_HOOK(NAME, SIG) { #NAME, &NAME, SIG }


struct {
    char        *name;
    void        *func;
    char        *sig;
} nwn_hooks[] = {
    { NULL, NULL,                                                       NULL },
    NX_NWN_HOOK(CFactionManager__GetFaction,                            "55 89 E5 ** ** ** 8B 55 0C 85 D2 8B 4D 08 78"),
    NX_NWN_HOOK(CGameObjectArray__GetGameObject,                        "55 89 E5 8B 45 0C 56 53 89 C2 89 C3 C1 E8 1F 0F B7 C0 C1 E0 0C"),
    NX_NWN_HOOK(CNetLayer__DisconnectPlayer,                            "55 89 E5 83 EC 14 FF 75 14 6A 01 FF 75 10 FF 75 0C 8B 45 08 FF 30 E8"),
    NX_NWN_HOOK(CNetLayer__SetPlayerPassword,                           "55 89 E5 56 53 83 EC 18 8B 75 0C 56 8D 5D E8 ** ** ** ** 01 00 5A 59 53 8B 45 08 FF 30 E8"),
    NX_NWN_HOOK(CNWBaseItemArray__GetBaseItem,                          "55 89 E5 8B 45 08 8B 48 04 85 C9 8B 55 0C 74 14"),
    NX_NWN_HOOK(CNWClass__IsBonusFeat,                                  "55 89 E5 57 56 53 8B 4D 08 31 D2 66 8B 81 EC 01 **#8 73 28"),
    NX_NWN_HOOK(CNWClass__IsFeatUseable,                                "55 89 E5 56 53 8B 75 0C 83 EC 08 0F B7 C6 50 FF 35"),
    NX_NWN_HOOK(CNWClass__IsGrantedFeat,                                "55 89 E5 57 56 8B 45 10 53 8B 4D 08 8B 7D 0C C6 00 FF 31 D2"),
    NX_NWN_HOOK(CNWClass__IsNormalFeat,                                 "55 89 E5 57 56 53 83 EC 0C 8B 5D 08 31 C9 66 8B 93 EC 01 00"),
    NX_NWN_HOOK(CNWClass__IsSkillClassSkill,                            "55 89 E5 57 56 53 8B 75 0C 8B 15 ** ** ** ** 0F B7 C6 0F B6"),
    NX_NWN_HOOK(CNWClass__IsSkillUseable,                               "55 89 E5 56 53 8B 75 0C 8B 0D ** ** ** ** 0F B7 D6 0F B6 81"),
    NX_NWN_HOOK(CNWSArea__ComputeHeight,                                "55 89 E5 57 56 53 ** ** ** 31 D2 8B 3D ** ** ** ** BB FF FF FF FF 39 FA 89 DE 7D"),
    NX_NWN_HOOK(CNWSArea__TestSafeLocationPoint,                        "55 89 E5 57 56 53 81 EC ** ** ** ** 8B 55 18 D9 42 04 D9 45 0C 8B 45 08"),
    NX_NWN_HOOK(CNWSCombatRound__GetCurrentAttackWeapon,                "55 89 E5 56 53 8B 45 0C 85 C0 8B 75 08 75 0C 83 EC 0C 56 E8"),
    NX_NWN_HOOK(CNWSCreatureClass__AddKnownSpell,                       "55 89 E5 83 EC 08 8A 45 0C 3C 09 8B 4D 08 8B 55 **#14 80"),
    NX_NWN_HOOK(CNWSCreatureClass__RemoveKnownSpell,                    "55 89 E5 83 EC 08 8A 45 0C 3C 09 8B 4D 08 8B 55 **#14 FC"),
    NX_NWN_HOOK(CNWSCreatureStats__AddFeat,                             "55 89 E5 56 53 8B 5D 08 8B 53 04 3B 53 08 8B 75"),
    NX_NWN_HOOK(CNWSCreatureStats__FeatRequirementsMet,                 "55 89 E5 57 56 53 83 EC 24 8B 55 08 8B 42 24 FF 70 04"),
    NX_NWN_HOOK(CNWSCreatureStats__FeatRequirementsMetAfterLevelUp,     "55 89 E5 57 56 53 83 EC 54 8A 45 14 88 45 F3 0F B7 45"),
    NX_NWN_HOOK(CNWSCreatureStats__GetACNaturalBase,                    "55 89 E5 57 56 53 83 EC 28 8B 7D 08 C7 45 EC 00 00 00 00 C7 45 F0 00 00"),
    NX_NWN_HOOK(CNWSCreatureStats__GetArmorClassVersus,                 "55 89 E5 57 56 53 81 EC 8C 02 00 00 8B 7D 0C 85"),
    NX_NWN_HOOK(CNWSCreatureStats__GetAttackModifierVersus,             "55 89 E5 57 56 53 81 EC 54 06 00 00 8B 55 08 8B"),
    NX_NWN_HOOK(CNWSCreatureStats__GetAttacksPerRound,                  "55 89 E5 53 83 EC 0C 6A 00 8B 5D 08 53 E8 ** ** ** ** 83 C4 10"),
    NX_NWN_HOOK(CNWSCreatureStats__GetCHAStat,                          "55 89 E5 56 53 8B 75 08 83 EC 0C 56 E8 ** ** ** ** 0F BE C0 0F B6 8E 02 04"),
    NX_NWN_HOOK(CNWSCreatureStats__GetCONStat,                          "55 89 E5 56 53 8B 75 08 83 EC 0C 56 E8 ** ** ** ** 0F BE C0 0F B6 8E FC 03"),
    NX_NWN_HOOK(CNWSCreatureStats__GetCriticalHitMultiplier,            "55 89 E5 57 56 53 83 EC 0C 83 7D 0C 01 8B 75 08"),
    NX_NWN_HOOK(CNWSCreatureStats__GetCriticalHitRoll,                  "55 89 E5 57 56 53 83 EC 0C 31 FF 83 7D 0C 01 75"),
    NX_NWN_HOOK(CNWSCreatureStats__GetDEXMod,                           "55 89 E5 57 56 53 83 EC 2C 8B 45 0C 48 C7 45 D4 00 00 00 00"),
    NX_NWN_HOOK(CNWSCreatureStats__GetDEXStat,                          "55 89 E5 56 53 8B 75 08 8B 4E 24 66 8B 91 0C 0B 00 00 89 D0 83 E0 06 66"),
    NX_NWN_HOOK(CNWSCreatureStats__GetEffectImmunity,                   "55 89 E5 57 56 53 83 EC 2C 8A 55 0C 88 55 F3 8B 75 08 8B 5E"),
    NX_NWN_HOOK(CNWSCreatureStats__GetEpicWeaponDevastatingCritical,    "55 89 E5 83 EC 08 8B 45 0C 85 C0 8B 55 08 0F 84 **#30 F0 01 00 00"),
    NX_NWN_HOOK(CNWSCreatureStats__GetEpicWeaponFocus,                  "55 89 E5 83 EC 08 8B 45 0C 85 C0 8B 55 08 0F 84 **#30 6C 02 00 00"),
    NX_NWN_HOOK(CNWSCreatureStats__GetEpicWeaponOverwhelmingCritical,   "55 89 E5 83 EC 08 8B 45 0C 85 C0 8B 55 08 0F 84 **#30 C6 02 00 00"),
    NX_NWN_HOOK(CNWSCreatureStats__GetEpicWeaponSpecialization,         "55 89 E5 83 EC 08 8B 45 0C 85 C0 8B 55 08 0F 84 **#30 92 02 00 00"),
    NX_NWN_HOOK(CNWSCreatureStats__GetFavoredEnemyBonus,                "55 89 E5 57 56 53 83 EC 0C 8B 45 0C 8B 80 64|68 0C 00 00 66 8B"),
    NX_NWN_HOOK(CNWSCreatureStats__GetFeatRemainingUses,                "55 89 E5 57 56 53 83 EC 54 8B 45 0C 0F B7 D8 53 FF ** ** ** ** ** 66 89 45 D6 **#0F 63"),
    NX_NWN_HOOK(CNWSCreatureStats__GetFeatTotalUses,                    "55 89 E5 57 56 53 83 EC 54 8B 45 0C 0F B7 D8 53 FF ** ** ** ** ** 66 89 45 D6 **#0F 43"),
    NX_NWN_HOOK(CNWSCreatureStats__GetFortSavingThrow,                  "55 89 E5 57 56 53 83 EC 0C 8B 4D 0C 31 F6 31 FF 85 C9 8B 5D 08 75 ** 83 EC 08 6A 00"),
    NX_NWN_HOOK(CNWSCreatureStats__GetINTStat,                          "55 89 E5 56 53 8B 75 08 83 EC 0C 56 E8 ** ** ** ** 0F BE C0 0F B6 8E FE 03"),
    NX_NWN_HOOK(CNWSCreatureStats__GetIsWeaponOfChoice,                 "55 89 E5 83 EC 08 8B 55 0C 83 FA 6F 8B 45 08 0F"),
    NX_NWN_HOOK(CNWSCreatureStats__GetReflexSavingThrow,                "55 89 E5 57 56 53 83 EC 0C 8B 55 0C 31 FF 85 D2"),
    NX_NWN_HOOK(CNWSCreatureStats__GetSTRStat,                          "55 89 E5 56 53 8B 75 08 83 EC 0C 56 E8 ** ** ** ** 0F BE C0 0F B6 8E F8 03"),
    NX_NWN_HOOK(CNWSCreatureStats__GetSkillRank,                        "55 89 E5 57 56 53 83 EC 0C 8A 45 0C 88 45 F3 8B **#5 3A 81 DB"),
    NX_NWN_HOOK(CNWSCreatureStats__GetSpellMinAbilityMet,               "55 89 E5 57 56 53 8B 75 08 8A 55 0C 3A 96 A1 00 00 00 0F B6 7D 10 B0 FF"),
    NX_NWN_HOOK(CNWSCreatureStats__GetTotalACSkillMod,                  "55 89 E5 53 52 6A 01 6A 00 6A 15 FF 75 08 E8"),
    NX_NWN_HOOK(CNWSCreatureStats__GetUseMonkAttackTables,              "55 89 E5 56 53 83 EC 0C 8B 75 08 FF 76 24 E8 ** ** ** ** 83 C4 10"),
    NX_NWN_HOOK(CNWSCreatureStats__GetWISStat,                          "55 89 E5 56 53 8B 75 08 83 EC 0C 56 E8 ** ** ** ** 0F BE C0 0F B6 8E 00 04"),
    NX_NWN_HOOK(CNWSCreatureStats__GetWeaponFinesse,                    "55 89 E5 56 53 83 EC 08 6A 2A 8B 75 08 56 8B 5D"),
    NX_NWN_HOOK(CNWSCreatureStats__GetWeaponFocus,                      "55 89 E5 83 EC 08 8B 45 0C 85 C0 8B 55 08 0F 84 **#30 5A E9 A3 01"),
    NX_NWN_HOOK(CNWSCreatureStats__GetWeaponImprovedCritical,           "55 89 E5 83 EC 08 8B 45 0C 85 C0 8B 55 08 0F 84 **#30 34 E9 B3 01"),
    NX_NWN_HOOK(CNWSCreatureStats__GetWeaponSpecialization,             "55 89 E5 83 EC 08 8B 45 0C 85 C0 8B 55 08 0F 84 **#30 80 00 00 00"),
    NX_NWN_HOOK(CNWSCreatureStats__GetWillSavingThrow,                  "55 89 E5 57 56 53 83 EC 0C 8B 45 0C 31 F6 31 FF 85 C0 8B 5D 08 75 ** 83 EC 08 6A 00"),
    NX_NWN_HOOK(CNWSCreatureStats__HasFeat,                             "55 89 E5 57 56 53 83 EC 14 8B 55 08 C7 45 F0 00 00 00 00 8B 42 24 FF 70"),
    NX_NWN_HOOK(CNWSCreatureStats__RemoveFeat,                          "55 89 E5 57 56 53 83 EC 0C 8B 7D 08 8B 57 04 31 C0 39 D0 8B 5D 0C"),
    NX_NWN_HOOK(CNWSCreatureStats__SetCHABase,                          "55 89 E5 56 53 8B 75 08 83 EC 0C 8B 45 0C 88 86 02 04"),
    NX_NWN_HOOK(CNWSCreatureStats__SetCONBase,                          "55 89 E5 57 56 53 83 EC 0C 8B 7D 10 8B 75 08 8B"),
    NX_NWN_HOOK(CNWSCreatureStats__SetDEXBase,                          "55 89 E5 53 83 EC 10 8B 5D 08 8B 45 0C 88 83 FA"),
    NX_NWN_HOOK(CNWSCreatureStats__SetINTBase,                          "55 89 E5 56 53 8B 75 08 83 EC 0C 8B 45 0C 88 86 FE 03"),
    NX_NWN_HOOK(CNWSCreatureStats__SetMovementRate,                     "55 89 E5 57 56 53 81 EC ** ** ** ** A1 **#13 83 FA 07"),
    NX_NWN_HOOK(CNWSCreatureStats__SetSTRBase,                          "55 89 E5 56 53 8B 75 08 83 EC 0C 8B 45 0C 88 86 F8 03"),
    NX_NWN_HOOK(CNWSCreatureStats__SetWISBase,                          "55 89 E5 56 53 8B 75 08 83 EC 0C 8B 45 0C 88 86 00 04"),
    NX_NWN_HOOK(CNWSCreature__ComputeSpellRange,                        "55 89 E5 53 83 EC 0C 8B 5D 0C D9 EE 68 ** ** ** ** D9"),
    NX_NWN_HOOK(CNWSCreature__GetFaction,                               "55 89 E5 ** ** ** A1 ** ** ** ** 8B 40 04 8B 55 08 8B 48 04 8B 82 ** 0C 00 00 FF B0 ** 00 00 00"),
    NX_NWN_HOOK(CNWSCreature__GetIsCreatureBumpable,                    "55 89 E5 57 56 53 83 EC 0C 8B 7D 08 C7 45 EC 00 00 00 00 8B 87 38 0B 00"),
    NX_NWN_HOOK(CNWSCreature__GetRelativeWeaponSize,                    "55 89 E5 53 83 EC 0C 8B 45 08 8B 55 0C 8B 98 D8"),
    NX_NWN_HOOK(CNWSCreature__GetTotalEffectBonus,                      "55 89 E5 57 56 53 81 EC A4 04 00 00 8A 4D 20 88 8D 45 FC FF FF"),
    NX_NWN_HOOK(CNWSCreature__RemoveFromArea,                           "55 89 E5 57 56 53 83 EC ** FF 75 08 E8 ** ** ** ** 83 C4 10 85 C0 74 1A"),
    NX_NWN_HOOK(CNWSCreature__SendFeedbackMessage,                      "55 89 E5 57 56 53 83 EC 0C 8B 75 14 85 F6 8B 5D"),
    NX_NWN_HOOK(CNWSCreature__UseItem,                                  "55 89 E5 57 56 53 81 EC ** 00 00 00 8A 45 10 8A 55 14 88 45 ** 88 55 **"),
    NX_NWN_HOOK(CNWSCreature__UseItem,                                  "55 89 E5 57 56 53 83 EC 64 8A 45 10 8A 4D 14 88 45 A7 88 4D A6 FF 75 0C C7 45 A0 00 00 00 00"),
    NX_NWN_HOOK(CNWSFaction__AddMember,                                 "55 89 E5 57 56 53 ** ** ** A1 ** ** ** ** 8B 40 04 FF 75 0C **#19 0C"),
    NX_NWN_HOOK(CNWSFaction__GetLeader,                                 "55 89 E5 57 56 53 ** ** ** A1 ** ** ** ** C7 45 F0 00 00 00 7F 8B 40 04 89 45 EC FF 75 08"),
    NX_NWN_HOOK(CNWSFaction__RemoveMember,                              "55 89 E5 57 56 53 ** ** ** A1 ** ** ** ** 8B 40 04 FF 75 0C **#19 08"),
    NX_NWN_HOOK(CNWSInventory__GetItemInSlot,                           "55 89 E5 53 83 EC 0C 8B 5D 08 FF 75 0C 53 ** ** ** ** ** 83 C4 10 83 F8 11 7F 1D 8B"),
    NX_NWN_HOOK(CNWSItem__GetActiveProperty,                            "55 89 E5 83 EC 08 8B 55 0C 85 D2 8B 45 08 78 18 3B 90 F0 01 00 00 7D 10 05 EC 01 00"),
    NX_NWN_HOOK(CNWSItem__GetPassiveProperty,                           "55 89 E5 83 EC 08 8B 55 0C 85 D2 8B 45 08 78 18 3B 90 Fc 01 00 00 7D 10 05 F8 01 00"),
    NX_NWN_HOOK(CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton,   "55 89 E5 57 56 53 83 EC 68 8B 5D 10 FF 75 0C 88 5D AF"),
    NX_NWN_HOOK(CNWSMessage__WriteGameObjUpdate_UpdateObject,           "55 89 E5 57 56 53 81 EC 78 02 00 00 FF 75 0C 8B"),
    NX_NWN_HOOK(CNWSModule__AddObjectToLimbo,                           "55 89 E5 57 56 53 83 EC ** 8B 75 08 8D 86 10 02 00 00 31 DB 89 45 F0 3B 9E 14 02 00 00"),
    NX_NWN_HOOK(CNWSModule__AddObjectToLimbo,                           "55 89 E5 57 56 53 83 EC 0C 8B 75 08 8D 86 18 02 00 00 31 DB 89 45 F0 3B 9E 1C 02 00 00"),
    NX_NWN_HOOK(CNWSObject__BroadcastSafeProjectile,                    "55 89 E5 57 56 53 81 EC 94 00 00 00 8A 45 30 88 45 83 8A 55 38 8A 45 3C"),
    NX_NWN_HOOK(CNWSObject__GetDamageImmunity,                          "55 89 E5 8A 45 0C 3C 0C 76 06 31 C0 EB 24 89 F6"),
    NX_NWN_HOOK(CNWSObject__GetDamageImmunityByFlags,                   "55 89 E5 57 56 53 83 EC 18 8B 7D 08 8B 47 0C 57 8B 5D 0C FF 50 ** 83 C4 10 85 C0 74 ** 83 EC 0C"),
    NX_NWN_HOOK(CNWSObject__SetDamageImmunity,                          "55 89 E5 56 53 8B 5D 10 83 FB 9C 8B 75 08 8B 45"),
    NX_NWN_HOOK(CServerExoApp__GetClientObjectByObjectId,               "55 89 E5 83 EC 08 8B 45 08 8B 40 04 89 45 08 C9 **#0F 4D 08 0F B6"),
    NX_NWN_HOOK(CServerExoAppInternal__GetAreaByGameObjectID,           "55 89 E5 8D 45 FC ** ** ** 50 8B 55 0C 52 8B 4D 08 FF B1 80 00 01 00 C7 45 FC **#2D FF 50 30"),
    NX_NWN_HOOK(CServerExoAppInternal__GetClientObjectByObjectId,       "55 89 E5 57 56 53 83 EC 0C 8B ** 0C 81 FF 00 00 00 7F"),
    NX_NWN_HOOK(CServerExoAppInternal__GetFactionOfObject,              "55 89 E5 56 53 ** ** ** 8D 45 F4 50 8B 55 0C"),
    NX_NWN_HOOK(CServerExoAppInternal__GetModule,                       "55 89 E5 8D 45 FC 83 EC 0C 8B 55 08 50 FF B2 84 00 01 00 FF B2 80 00 01 00 C7 45 FC 00 00 00 00 E8"),
    NX_NWN_HOOK(CVirtualMachine__RunScript,                             "55 89 E5 57 56 53 83 EC 18 FF 75 0C 8B 7D 10 E8"),
    NX_NWN_HOOK(CWorldTimer__GetWorldTime,                              "55 89 E5 57 56 53 83 EC 0C 8B 55 08 8B 42 08 8B"),

    { NULL, NULL,                                                       NULL },
};

static void nwn_hook_callback(int id, void *addr)
{
    nx_log(NX_LOG_NOTICE, 0, "%s (%d) found at %p%s",
           nwn_hooks[id].name, id, addr,
           (*(void **)(nwn_hooks[id].func) == NULL ? "" : " (duplicate)"));

    *(void **)(nwn_hooks[id].func) = addr;
}


static void nwn_hook_data(void)
{
    unsigned char *p = (unsigned char *)NX_NWN_SEARCH_START, *end = p + 0x8000;

    while (p < end && !(*p == 0x89 && *(p + 1) == 0x1C && *(p + 2) == 0x24 && *(p + 3) == 0xE8))
        p++;

    if (p < end) {
        void *data = *((void **)(p += 10)) - 20;

        nx_log(NX_LOG_NOTICE, 0, "server data segment location found at %p (%p)", p, data);

        NWN_ClientServerMode = data;
        NWN_ExoBase          = data + 4;
        NWN_ExoResMan        = data + 8;
        NWN_VirtualMachine   = data + 12;
        NWN_ScriptCompiler   = data + 16;
        NWN_AppManager       = data + 20;
        NWN_TlkTable         = data + 24;
        NWN_Rules            = data + 28;
        NWN_ExitProgram      = data + 32;
        NWN_ProcessCommand   = data + 36;
        NWN_Interactive      = data + 40;
    } else
        nx_log(NX_LOG_NOTICE, 0, "server data segment location not found");

    /* XXX: these will only work for NWN 1.69 */
    NWN_DebugCombat  = (int32_t *)0x832FBE8;
    NWN_DebugSaves   = (int32_t *)0x832FBEC;
    NWN_DebugSpeed   = (int32_t *)0x832FBF0;
    NWN_DebugHitDice = (int32_t *)0x832FBF4;
}


void nwn_hook_init(void)
{
    int i;

    nwn_hook_data();

    nx_sig_search_t *sig = nx_sig_search_create(nwn_hook_callback);

    for (i = 1; nwn_hooks[i].sig != NULL; i++)
        nx_sig_search_add_signature(sig, i, nwn_hooks[i].sig);

    nx_sig_search_run(sig);
    nx_sig_search_destroy(sig);


    for (i = 1; nwn_hooks[i].sig != NULL; i++) {
        if (*(void **)nwn_hooks[i].func == NULL)
            nx_log(NX_LOG_NOTICE, 0, "%s (%d) not found", nwn_hooks[i].name, i);
    }
}

/* vim: set sw=4: */
