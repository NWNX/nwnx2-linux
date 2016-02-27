
/***************************************************************************
    NWNXTweaks.cpp - Implementation of the CNWNXTweaks class.
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

#include "NWNXTweaks.h"
#include "TweaksStrCmds.h"
#include "TweaksObjCmds.h"


//////////////////////////////////////////////////////////////////////
// Function Signatures
//////////////////////////////////////////////////////////////////////

#define NWNX_TWEAKS_SIG(NAME, SIG) { #NAME, &NAME, SIG }


/* define references her e*/


static struct TweakSignatureTable {
    const char         *name;
    void               *ref;
    const char         *sig;
} Table_TweakSignatures[] = {
    { NULL, NULL,                               NULL },

    { NULL, NULL,                               NULL },
};


static void TweaksSearchCallback(int id, void *addr)
{
    nx_log(NX_LOG_NOTICE, 0, "%s (%d) found at %p%s",
           Table_TweakSignatures[id].name, id, addr,
           (*(void **)Table_TweakSignatures[id].ref == NULL ? "" : " (duplicate)"));

    *(void **)(Table_TweakSignatures[id].ref) = addr;
}

static void TweaksSearchSignatures(void)
{
    int i;

    nx_sig_search_t *sig = nx_sig_search_create(TweaksSearchCallback);

    for (i = 1; Table_TweakSignatures[i].sig != NULL; i++)
        nx_sig_search_add_signature(sig, i, Table_TweakSignatures[i].sig);

    nx_sig_search_run(sig);
    nx_sig_search_destroy(sig);


    for (i = 1; Table_TweakSignatures[i].sig != NULL; i++) {
        if (*(void **)Table_TweakSignatures[i].ref == NULL)
            nx_log(NX_LOG_NOTICE, 0, "%s (%d) not found", Table_TweakSignatures[i].name, i);
    }
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXTweaks::CNWNXTweaks()
{
    confKey = strdup("TWEAKS");
}


CNWNXTweaks::~CNWNXTweaks()
{
}


char *CNWNXTweaks::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    const struct TweaksStrCommand_s *cmd;

    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    if ((cmd = TweaksStrCommandLookup(Request, strlen(Request))) != NULL)
        cmd->func((CGameObject *)gameObject, Parameters);
    else
        Log(0, "Unrecognized string request: \"%s\" \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
}


unsigned long CNWNXTweaks::OnRequestObject(char *gameObject, char *Request)
{
    unsigned long ret = OBJECT_INVALID;
    const struct TweaksObjCommand_s *cmd;

    Log(1, "ObjReq: \"%s\"\n", Request);

    if ((cmd = TweaksObjCommandLookup(Request, strlen(Request))) != NULL)
        ret = cmd->func((CGameObject *)gameObject);
    else
        Log(0, "Unrecognized object request: \"%s\"\n", Request);

    Log(1, "Return: %08X\n", ret);

    return ret;
}


bool CNWNXTweaks::OnCreate(gline *config, const char *LogDir)
{
    char log[128];

    sprintf(log, "%s/nwnx_tweaks.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    /* find hook signatures */
    TweaksSearchSignatures();

    /* add the possibility of additional caster classes */
    if (CNWSCreature__SendFeedbackMessage != NULL) {
        uintptr_t p = (uintptr_t)CNWSCreature__SendFeedbackMessage;
        extern volatile uintptr_t Hook_FSFM_Return;

        Hook_FSFM_Return = p + 31;

        nx_hook_function((void *)(p + 25), (void *)Hook_FixSendFeedbackMessage, 5, NX_HOOK_DIRECT);
    }

    return true;
}

/* vim: set sw=4: */
