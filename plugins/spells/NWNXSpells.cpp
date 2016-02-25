
/***************************************************************************
    NWNXSpells.cpp - Implementation of the CNWNXSpells class.
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

#include "NWNXSpells.h"
#include "SpellsStrCmds.h"
#include "SpellsObjCmds.h"


//////////////////////////////////////////////////////////////////////
// Function Signatures
//////////////////////////////////////////////////////////////////////

#define NWNX_SPELLS_SIG(NAME, SIG) { #NAME, &NAME, SIG }


static unsigned char *Ref_CasterAbility1;
static unsigned char *Ref_CasterMemorize1;
static unsigned char *Ref_CasterMemorize2;
static unsigned char *Ref_CasterMemorize3;
static unsigned char *Ref_CasterMemorize4;
static unsigned char *Ref_CasterUnlimBook1;

static unsigned char *Ref_IdentifySpell;
static unsigned char *Ref_SpellSlotLoop;


static struct SpellSignatureTable {
    const char         *name;
    void               *ref;
    const char         *sig;
} Table_SpellSignatures[] = {
    { NULL, NULL,                              NULL },

    NWNX_SPELLS_SIG(Ref_CasterAbility1,        "8A 55 E5 31 C0 3A ** ** ** ** ** 74 08 3A ** ** ** ** ** 75 13 83 EC 0C 0F B6 B7 03"),
    NWNX_SPELLS_SIG(Ref_CasterMemorize1,       "C1 E0 02 29 D0 8B 5D 08 8A 94 C3 B2 01 00 00 3A 15 ** ** ** ** 74 20 3A 15"),
    NWNX_SPELLS_SIG(Ref_CasterMemorize2,       "83 EC 08 0F B6 BD 54 FF FF FF 57 52 E8 ** ** ** ** 83 C4 10 3A ** ** ** ** ** 0F"),
    NWNX_SPELLS_SIG(Ref_CasterMemorize3,       "83 BC D0 54 02 00 00 01 0F 85 ** ** ** ** 8A 45 DA 3A 05 ** ** ** ** 74 24 3A 05"),
    NWNX_SPELLS_SIG(Ref_CasterMemorize4,       "83 C4 10 83 BC D0 54 02 00 00 01 0F 85 ** ** ** ** 3A 1D ** ** ** ** 74 24 3A 1D"),
    NWNX_SPELLS_SIG(Ref_CasterUnlimBook1,      "0F B6 D3 8D 04 D2 C1 E0 02 29 D0 8A 84 C7 B2 01 00 00 3A 05 ** ** ** ** 74 17 52"),

    NWNX_SPELLS_SIG(Ref_IdentifySpell,         "8B 85 78 FF FF FF 0F B6 58 47 56 6A 14 6A 01 FF"),
    NWNX_SPELLS_SIG(Ref_SpellSlotLoop,         "C6 85 E2 FE FF FF 00 8B BB B8 04 00 00 83 C4 10"),

    { NULL, NULL,                              NULL },
};


static void SpellsSearchCallback(int id, void *addr)
{
    nx_log(NX_LOG_NOTICE, 0, "%s (%d) found at %p%s",
           Table_SpellSignatures[id].name, id, addr,
           (*(void **)Table_SpellSignatures[id].ref == NULL ? "" : " (duplicate)"));

    *(void **)(Table_SpellSignatures[id].ref) = addr;
}

static void SpellsSearchSignatures(void)
{
    int i;

    nx_sig_search_t *sig = nx_sig_search_create(SpellsSearchCallback);

    for (i = 1; Table_SpellSignatures[i].sig != NULL; i++)
        nx_sig_search_add_signature(sig, i, Table_SpellSignatures[i].sig);

    nx_sig_search_run(sig);
    nx_sig_search_destroy(sig);


    for (i = 1; Table_SpellSignatures[i].sig != NULL; i++) {
        if (*(void **)Table_SpellSignatures[i].ref == NULL)
            nx_log(NX_LOG_NOTICE, 0, "%s (%d) not found", Table_SpellSignatures[i].name, i);
    }
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXSpells::CNWNXSpells()
{
    confKey = strdup("SPELLS");
}


CNWNXSpells::~CNWNXSpells()
{
}


char *CNWNXSpells::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    const struct SpellsStrCommand_s *cmd;

    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    if ((cmd = SpellsStrCommandLookup(Request, strlen(Request))) != NULL)
        cmd->func((CGameObject *)gameObject, Parameters);
    else
        Log(0, "Unrecognized string request: \"%s\" \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
}


unsigned long CNWNXSpells::OnRequestObject(char *gameObject, char *Request)
{
    unsigned long ret = OBJECT_INVALID;
    const struct SpellsObjCommand_s *cmd;

    Log(1, "ObjReq: \"%s\"\n", Request);

    if ((cmd = SpellsObjCommandLookup(Request, strlen(Request))) != NULL)
        ret = cmd->func((CGameObject *)gameObject);
    else
        Log(0, "Unrecognized object request: \"%s\"\n", Request);

    Log(1, "Return: %08X\n", ret);

    return ret;
}


bool CNWNXSpells::OnCreate(gline *config, const char *LogDir)
{
    char log[128];

    sprintf(log, "%s/nwnx_spells.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    /* find hook signatures */
    SpellsSearchSignatures();


    nx_hook_function((void *)CNWSCreatureStats__GetSpellMinAbilityMet,
                     (void *)Hook_GetSpellMinAbilityMet, 5, NX_HOOK_DIRECT);

#if 0
    /* always have Spellcraft fail for extended spells */
    if (Ref_IdentifySpell != NULL) {
        extern volatile uintptr_t Hook_SPID_Return;

        nx_hook_enable_write(Ref_IdentifySpell, 48);

        nx_hook_function((void *)(Ref_IdentifySpell + 29),
                         (void *)Hook_IdentifySpell, 5, NX_HOOK_DIRECT);

        *(Ref_IdentifySpell + 34) = 0x90;
        Hook_SPID_Return          = (uintptr_t)(Ref_IdentifySpell + 35);
    }
#endif


#ifdef NWNX_SPELLS_HG
    /* override spell range calculations */
    if (CNWSCreature__ComputeSpellRange != NULL) {
        extern volatile uintptr_t Hook_SPR_Return;
        unsigned char *p = (unsigned char *)CNWSCreature__ComputeSpellRange;

        if (p[205] == 0xD9 && p[206] == 0x5D) {
            Hook_SPR_Return = (uintptr_t)(p + 205);

            nx_hook_function((void *)(p + 10), (void *)Hook_ComputeSpellRange, 5, NX_HOOK_DIRECT);

            nx_log(NX_LOG_INFO, 0, "found spell range pop reference at %p", p + 205);
        } else
            nx_log(NX_LOG_INFO, 0, "did not find spell range pop reference at %p", p + 205);
    }
#endif


#if 0
    /* override spell levels for classes */
    /* XXX: clean this up */
    if (1) {
        extern volatile uintptr_t Hook_CSL_ReturnCheck, Hook_CSL_ReturnDone;
        unsigned char *p = (unsigned char *)0x081D8923;

        nx_hook_function((void *)p, (void *)Hook_GetSpellLevel, 7, NX_HOOK_DIRECT);

        Hook_CSL_ReturnCheck = 0x081D892D;
        Hook_CSL_ReturnDone  = 0x081D8977;
    }
#endif


    /* add the possibility of additional caster classes */
    if (Ref_CasterAbility1 != NULL) {
        extern volatile uintptr_t Hook_SCA1_Return;

        Hook_SCA1_Return = (uintptr_t)(Ref_CasterAbility1 + 37);

        nx_hook_function((void *)(Ref_CasterAbility1 + 5), (void *)Hook_GetCasterClassAbility1, 5, NX_HOOK_DIRECT);
    }

    if (Ref_CasterMemorize1 != NULL) {
        extern volatile uintptr_t Hook_SCM1_Return;

        Hook_SCM1_Return = (uintptr_t)(Ref_CasterMemorize1 + 53);

        nx_hook_function((void *)(Ref_CasterMemorize1 + 15), (void *)Hook_GetIsMemorizationCasterClass1, 5, NX_HOOK_DIRECT);
    }

    if (Ref_CasterMemorize2 != NULL) {
        extern volatile uintptr_t Hook_SCM2_Return;

        Hook_SCM2_Return = (uintptr_t)(Ref_CasterMemorize2 + 126);

        nx_hook_function((void *)(Ref_CasterMemorize2 + 20), (void *)Hook_GetIsMemorizationCasterClass2, 5, NX_HOOK_DIRECT);
    }

    if (Ref_CasterMemorize3 != NULL) {
        extern volatile uintptr_t Hook_SCM3_Return;

        Hook_SCM3_Return = (uintptr_t)(Ref_CasterMemorize3 + 47);

        nx_hook_function((void *)(Ref_CasterMemorize3 + 17), (void *)Hook_GetIsMemorizationCasterClass3, 5, NX_HOOK_DIRECT);
    }

    if (Ref_CasterMemorize4 != NULL) {
        extern volatile uintptr_t Hook_SCM4_Return;

        Hook_SCM4_Return = (uintptr_t)(Ref_CasterMemorize4 + 47);

        nx_hook_function((void *)(Ref_CasterMemorize4 + 17), (void *)Hook_GetIsMemorizationCasterClass4, 5, NX_HOOK_DIRECT);
    }

    if (Ref_CasterUnlimBook1 != NULL) {
        extern volatile uintptr_t Hook_SCU1_Return;

        Hook_SCU1_Return = (uintptr_t)(Ref_CasterUnlimBook1 + 24);

        nx_hook_function((void *)(Ref_CasterUnlimBook1 + 18), (void *)Hook_GetIsUnlimitedBookCasterClass1, 5, NX_HOOK_DIRECT);
    }


    /* fix 255 spell slot loop bug */
    if (Ref_SpellSlotLoop != NULL) {
        unsigned char *p = Ref_SpellSlotLoop;
        unsigned char *end = p + 0x200;
        extern volatile uintptr_t Hook_SPSL1_Return, Hook_SPSL2_Return, Hook_SPSL3_Return;

        nx_hook_function(p, (void *)Hook_SpellSlotLoop1, 5, NX_HOOK_DIRECT);
        Hook_SPSL1_Return = (uintptr_t)(p + 7);

        while (p++ < end) {
            if (p[0] == 0x0F && p[1] == 0xB6 && p[2] == 0xB5 && p[3] == 0xE2) {
                nx_log(NX_LOG_INFO, 0, "found spell slot loop reference #2 at %p", p);

                nx_hook_function(p, (void *)Hook_SpellSlotLoop2, 5, NX_HOOK_DIRECT);
                Hook_SPSL2_Return = (uintptr_t)(p + 7);

                break;
            }
        }

        if (p >= end)
            nx_log(NX_LOG_INFO, 0, "did not find spell slot loop reference #2 before %p", p);

        while (p++ < end) {
            if (p[0] == 0xFE && p[1] == 0x85 && p[2] == 0xE2 && p[3] == 0xFE) {
                nx_log(NX_LOG_INFO, 0, "found spell slot loop reference #3 at %p", p);

                nx_hook_function(p, (void *)Hook_SpellSlotLoop3, 5, NX_HOOK_DIRECT);
                Hook_SPSL3_Return = (uintptr_t)(p + 13);

                break;
            }
        }

        if (p >= end)
            nx_log(NX_LOG_INFO, 0, "did not find spell slot loop reference #3 before %p", p);
    }

    return true;
}

/* vim: set sw=4: */
