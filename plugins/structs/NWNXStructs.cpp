
/***************************************************************************
    NWNXStructs.cpp - Implementation of the CNWNXStructs class.
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

#include "NWNXStructs.h"
#include "StructsStrCmds.h"
#include "StructsObjCmds.h"


//////////////////////////////////////////////////////////////////////
// Function Signatures
//////////////////////////////////////////////////////////////////////

#define NWNX_STRUCTS_SIG(NAME, SIG) { #NAME, &NAME, SIG }

static unsigned char *Ref_PushStruct;

static struct StructSignatureTable {
    const char         *name;
    void               *ref;
    const char         *sig;
} Table_StructSignatures[] = {
    { NULL, NULL,                               NULL },

    NWNX_STRUCTS_SIG(Ref_PushStruct,            "8B 46 10 8B 7D 0C 8B 4A 08 FF 34 B8 0F BE 04 1F"),

    { NULL, NULL,                               NULL },
};


static void StructsSearchCallback(int id, void *addr)
{
    nx_log(NX_LOG_NOTICE, 0, "%s (%d) found at %p%s",
           Table_StructSignatures[id].name, id, addr,
           (*(void **)Table_StructSignatures[id].ref == NULL ? "" : " (duplicate)"));

    *(void **)(Table_StructSignatures[id].ref) = addr;
}

static void StructsSearchSignatures(void)
{
    int i;

    nx_sig_search_t *sig = nx_sig_search_create(StructsSearchCallback);

    for (i = 1; Table_StructSignatures[i].sig != NULL; i++)
        nx_sig_search_add_signature(sig, i, Table_StructSignatures[i].sig);

    nx_sig_search_run(sig);
    nx_sig_search_destroy(sig);


    for (i = 1; Table_StructSignatures[i].sig != NULL; i++) {
        if (*(void **)Table_StructSignatures[i].ref == NULL)
            nx_log(NX_LOG_NOTICE, 0, "%s (%d) not found", Table_StructSignatures[i].name, i);
    }
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXStructs::CNWNXStructs()
{
    confKey = strdup("STRUCTS");
}


CNWNXStructs::~CNWNXStructs()
{
}


char *CNWNXStructs::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    const struct StructsStrCommand_s *cmd;

    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    if ((cmd = StructsStrCommandLookup(Request, strlen(Request))) != NULL)
        cmd->func((CGameObject *)gameObject, Parameters);
    else
        Log(0, "Unrecognized string request: \"%s\" \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
}


unsigned long CNWNXStructs::OnRequestObject(char *gameObject, char *Request)
{
    unsigned long ret = OBJECT_INVALID;
    const struct StructsObjCommand_s *cmd;

    Log(1, "ObjReq: \"%s\"\n", Request);

    if ((cmd = StructsObjCommandLookup(Request, strlen(Request))) != NULL)
        ret = cmd->func((CGameObject *)gameObject);
    else
        Log(0, "Unrecognized object request: \"%s\"\n", Request);

    Log(1, "Return: %08X\n", ret);

    return ret;
}


bool CNWNXStructs::OnCreate(gline *config, const char *LogDir)
{
    char log[128];

    sprintf(log, "%s/nwnx_structs.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    /* find hook signatures */
    StructsSearchSignatures();

    if (Ref_PushStruct != NULL) {
        unsigned char *p = Ref_PushStruct;
        extern volatile uintptr_t Hook_Struct_Return;

        nx_hook_function(p, (void *)Hook_PushStruct, 5, NX_HOOK_DIRECT);

        Hook_Struct_Return = (uintptr_t)(p + 9);
    }

    return true;
}

/* vim: set sw=4: */
