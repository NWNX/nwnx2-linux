#include "NWNXCoreEvents.h"
#include "HookCoreEvents.h"

CNWNXCoreEvents::CNWNXCoreEvents() {
    confKey = strdup("COREEVENTS");
}

CNWNXCoreEvents::~CNWNXCoreEvents() {
}

char* CNWNXCoreEvents::OnRequest (char* gameObject, char* Request, char* Parameters)
{
    return NULL;
}

bool CNWNXCoreEvents::OnCreate (gline *config, const char *LogDir)
{
    char log[128];

    sprintf(log, "%s/nwnx_coreevents.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    HookFunctions();

    return true;
}

/* vim: set sw=4: */
