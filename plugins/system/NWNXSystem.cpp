
/***************************************************************************
    NWNXSystem.cpp - Implementation of the CNWNXSystem class.
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

#include "NWNXSystem.h"
#include "SystemStrCmds.h"
#include "SystemObjCmds.h"


//////////////////////////////////////////////////////////////////////
// Function Signatures
//////////////////////////////////////////////////////////////////////

#define NWNX_SYSTEM_SIG(NAME, SIG) { #NAME, &NAME, SIG }

unsigned char *Ref_TMILimit;

static struct SystemSignatureTable {
    const char         *name;
    void               *ref;
    const char         *sig;
} Table_SystemSignatures[] = {
    { NULL, NULL,                              NULL },

    NWNX_SYSTEM_SIG(Ref_TMILimit,               "8D F7 1D 00 00 8B 55 08 8B 42 08 40 3D FF FF 01"),

    { NULL, NULL,                              NULL },
};


static void SystemSearchCallback(int id, void *addr)
{
    nx_log(NX_LOG_NOTICE, 0, "%s (%d) found at %p%s",
           Table_SystemSignatures[id].name, id, addr,
           (*(void **)Table_SystemSignatures[id].ref == NULL ? "" : " (duplicate)"));

    *(void **)(Table_SystemSignatures[id].ref) = addr;
}

static void SystemSearchSignatures(void)
{
    int i;

    nx_sig_search_t *sig = nx_sig_search_create(SystemSearchCallback);

    for (i = 1; Table_SystemSignatures[i].sig != NULL; i++)
        nx_sig_search_add_signature(sig, i, Table_SystemSignatures[i].sig);

    nx_sig_search_run(sig);
    nx_sig_search_destroy(sig);


    for (i = 1; Table_SystemSignatures[i].sig != NULL; i++) {
        if (*(void **)Table_SystemSignatures[i].ref == NULL)
            nx_log(NX_LOG_NOTICE, 0, "%s (%d) not found", Table_SystemSignatures[i].name, i);
    }
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXSystem::CNWNXSystem()
{
    confKey = strdup("SYSTEM");
}


CNWNXSystem::~CNWNXSystem()
{
}


char *CNWNXSystem::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    const struct SystemStrCommand_s *cmd;

    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    if ((cmd = SystemStrCommandLookup(Request, strlen(Request))) != NULL)
        cmd->func((CGameObject *)gameObject, Parameters);
    else
        Log(0, "Unrecognized string request: \"%s\" \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
}


unsigned long CNWNXSystem::OnRequestObject(char *gameObject, char *Request)
{
    unsigned long ret = OBJECT_INVALID;
    const struct SystemObjCommand_s *cmd;

    Log(1, "ObjReq: \"%s\"\n", Request);

    if ((cmd = SystemObjCommandLookup(Request, strlen(Request))) != NULL)
        ret = cmd->func((CGameObject *)gameObject);
    else
        Log(0, "Unrecognized object request: \"%s\"\n", Request);

    Log(1, "Return: %08X\n", ret);

    return ret;
}


bool CNWNXSystem::OnCreate(gline *config, const char *LogDir)
{
    char log[128];

    sprintf(log, "%s/nwnx_system.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    /* find hook signatures */
    SystemSearchSignatures();

    if (Ref_TMILimit != NULL)
        nx_hook_enable_write(Ref_TMILimit, 16);

    return true;
}

/* vim: set sw=4: */
