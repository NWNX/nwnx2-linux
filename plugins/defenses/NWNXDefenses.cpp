
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


static struct DefenseSignatureTable {
    char       *name;
    void       *ref;
    char       *sig;
} Table_DefenseSignatures[] = {
    { NULL,                                     NULL },

    { NULL,                                     NULL },
};


static void DefensesSearchCallback (int id, void *addr) {
    nx_log(NX_LOG_NOTICE, 0, "%s (%d) found at %p%s",
        Table_DefenseSignatures[id].name, id, addr,
        (*(void **)Table_DefenseSignatures[id].ref == NULL ? "" : " (duplicate)"));

    *(void **)(Table_DefenseSignatures[id].ref) = addr;
}

static void DefensesSearchSignatures (void) {
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

CNWNXDefenses::CNWNXDefenses() {
    confKey = "DEFENSES";
}


CNWNXDefenses::~CNWNXDefenses() {
}


char *CNWNXDefenses::OnRequest (char *gameObject, char *Request, char *Parameters) {
    const struct DefensesStrCommand_s *cmd;

    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    if ((cmd = DefensesStrCommandLookup(Request, strlen(Request))) != NULL)
        cmd->func((CGameObject *)gameObject, Parameters);
    else
        Log(0, "Unrecognized string request: \"%s\" \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
}


unsigned long CNWNXDefenses::OnRequestObject (char *gameObject, char *Request) {
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


bool CNWNXDefenses::OnCreate (gline *config, const char *LogDir) {
    char log[128];

    sprintf(log, "%s/nwnx_defenses.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    /* find hook signatures */
    DefensesSearchSignatures();

    return true;
}

/* vim: set sw=4: */
