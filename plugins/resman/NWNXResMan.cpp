#include "NWNXResMan.h"
#include "pluginlink.h"
#include <stdio.h>

CNWNXResMan::CNWNXResMan()
{
    confKey = "RESOURCEMANAGER";
    warnMissing = false;
    debugCRes = false;
}

CNWNXResMan::~CNWNXResMan()
{
}

bool CNWNXResMan::OnCreate(gline *config, const char *LogDir)
{
    char log[MAXPATH];

    sprintf(log, "%s/nwnx_resman.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    WriteLogHeader();

    hDemandRes = CreateHookableEvent(EVENT_RESMAN_DEMAND);
    hResExists = CreateHookableEvent(EVENT_RESMAN_EXISTS);

    // Must be called after event hooks are created and before
    // hooks.
    LoadConfiguration();
    HookFunctions();

    return true;
}

bool CNWNXResMan::OnRelease()
{
    Log(0, "o Shutdown.\n");
    return true;
}

void* CNWNXResMan::DemandRes(CExoResMan *pResMan, CRes *cRes, const CResRef &resRef, NwnResType resType)
{

    unsigned long size;

    if (strncmp(resRef.m_resRef, "*", 1) == 0 || strncmp(resRef.m_resRef, "default", 7) == 0)
        return NULL;

    if (cRes == NULL) {
        Log(5, "o Request for internal resource = %s (type %X)\n", resRef.GetResRefStr(), resType);
        return NULL;
    }

    const char* resExt = NwnGetResTypeExtension(resType);
    char resrefWithExt[21] = {0};
    strncat(resrefWithExt, resRef.m_resRef, 16);
    strcat(resrefWithExt, ".");
    strcat(resrefWithExt, resExt);

    // Insert entry, or lookup old one...
    std::pair<ResourceMap::iterator, bool> lookup = resFiles.insert(ResourceMap::value_type(resrefWithExt, CResFileInfo()));
    CResFileInfo& fileInfo = lookup.first->second;

    ResManExistsEvent event = { resrefWithExt, 0, false };
    NotifyEventHooksNotAbortable(hResExists, (uintptr_t)&event);

    if (event.exists) {
        fileInfo.latest_mtime = event.mtime;
    } else {
        if (warnMissing && cRes->m_nID == 0xffffffff) {
            Log(0, "WARNING Potential memory leak detected: '%s' wasn't found internally or in resources.\n", resrefWithExt);
        }

        return NULL;
    }


    if (!fileInfo.key) {
        // Areas are assumed to exist, so existance is not checked for, so we got to force it here.
        fileInfo.key = CreateKeyTableEntry(resRef, resType);
    }

    if (fileInfo.key->m_pRes) {
        pResMan->RemoveFromToBeFreedList(fileInfo.key->m_pRes); // Remove res from to be freed list so that at shutdown there are no double frees.
    } else {
        // Track all CRes.
        fileInfo.key->m_pRes = cRes;
    }


    // If the file is a script and the latest reported time is older or equal to the
    // last returned time return a file from the cache.
    if (resType == NwnResType_NCS && fileInfo.key->m_pRes->m_pResource && fileInfo.latest_mtime <= fileInfo.mtime) {
        Log(1, "o Skipping %s... Data: %p\n", resrefWithExt, fileInfo.key->m_pRes->m_pResource);
        if (resType == NwnResType_NCS) {

            // If resources services a file set ID to -1.  This keeps nwserver from getting confused
            // and thinking that it's in an ERF/BIF/etc.
            cRes->m_nID = -1;
            cRes->m_nDemands = 1;
            cRes->field_8 = 0x4;
            cRes->m_status = 2;
            cRes->m_nSize = fileInfo.size;

            if (cRes->vptr) {
                CResNCS *pNCS = (CResNCS*) cRes;
                pNCS->m_bLoaded = 0;
            }
            int (*pServFunc)(CRes * cRes) = (int (*)(CRes * cRes))cRes->vptr->OnResourceServiced;
            Log(5, "Calling CRes*::OnResourceServiced: %08lx\n", pServFunc);
            int nRet = pServFunc(cRes);
            Log(5, "Return value: %d\n", nRet);
            Log(4, "Resulting Structure:\n");
            DumpResStruct(cRes);
        }
        return cRes->m_pResource;
    } else {
        ResManDemandEvent demandResInfo = { resrefWithExt, resType, NULL, 0, fileInfo.mtime, fileInfo.latest_mtime };
        int notifyRet = NotifyEventHooks(hDemandRes, (uintptr_t)&demandResInfo);
        if (!notifyRet) { return NULL; }
        if (demandResInfo.pData && demandResInfo.size) {
            //Log(4, "Got data from Hook, returning (size = %d): %s\n", demandResInfo.size, demandResInfo.pData);
            pScriptBuffer = (char*) demandResInfo.pData;
            fileInfo.size = size = demandResInfo.size;
            fileInfo.mtime = demandResInfo.mtime;

            Log(1, "o Loading external resouce: %s, mtime: %d\n", resrefWithExt, fileInfo.mtime);
            Log(4, "Original Structure:\n");
            DumpResStruct(cRes);

            if (pResMan->TotalAvailableMemory < size) { //not enough memory
                Log(4, "Freeing some memory\n");
                while (1) {
                    if (size <= pResMan->TotalAvailableMemory)
                        break;
                    if (!pResMan->FreeChunk())
                        break;
                }
            }

            if (cRes->m_pResource) {
                free(cRes->m_pResource);
                pResMan->TotalAvailableMemory += cRes->m_nSize;
            } else {
                // resource loaded
                // set resStruct

                cRes->m_nDemands = 1;
                cRes->field_8 = 0x4;
                cRes->m_status = 2;
            }

            // If resources services a file set ID to -1.  This keeps nwserver from getting confused
            // and thinking that it's in an ERF/BIF/etc.
            cRes->m_nID = -1;
            cRes->m_pResource = pScriptBuffer;
            cRes->m_nSize = size;
            pResMan->TotalAvailableMemory -= size;

            // Call server function which sets various data pointers
            if (cRes->vptr) {
                if (resType == NwnResType_NCS) {
                    CResNCS *pNCS = (CResNCS*) cRes;
                    pNCS->m_bLoaded = 0;
                } else if (resType == NwnResType_2DA) {
                    CRes2DA *t = (CRes2DA*) cRes;
                    t->m_bLoaded = 0;
                }

                int (*pServFunc)(CRes * cRes) = (int (*)(CRes * cRes))cRes->vptr->OnResourceServiced;
                Log(5, "Calling CRes*::OnResourceServiced: %08lx\n", pServFunc);
                int nRet = pServFunc(cRes);
                Log(5, "Return value: %d\n", nRet);
            }
            Log(4, "Resulting Structure:\n");
            DumpResStruct(cRes);

            return cRes->m_pResource;
        }
    }

    return NULL;
}

void CNWNXResMan::DumpResStruct(CRes *cRes)
{
    Log(4, "CRes = %p\n", cRes);
    Log(4, "  - m_nDemands = %d\n", cRes->m_nDemands);
    Log(4, "  - m_nRequests = %d\n", cRes->m_nRequests);
    Log(4, "  - m_nID = %08lX\n", cRes->m_nID);
    Log(4, "  - m_pResource = %08lx\n", cRes->m_pResource);
    Log(4, "  - m_nSize = %d\n", cRes->m_nSize);
    if (cRes->m_pKeyEntry) {
        CKeyTableEntry *key = cRes->m_pKeyEntry;
        char buf[17] = {0};
        strncpy(buf, key->m_cResRef.m_resRef, 16);
        Log(4, "  - m_sName = %s\n", buf);
    }
    Log(4, "  - flags = %x\n", cRes->field_8);
    Log(4, "  - m_status = %d\n", cRes->m_status);
    Log(4, "  - m_pKeyEntry = %08lx\n", cRes->m_pKeyEntry);
}

bool CNWNXResMan::ResourceExists(const CResRef &resRef, NwnResType resType, CKeyTableEntry **original)
{
    const char* resExt = NwnGetResTypeExtension(resType);
    if (!resExt) {
        Log(0, "Invalid resource type: %d, resref: %.*s\n", resType, 16, resRef.m_resRef);
        return false;
    }

    char resrefWithExt[21] = {0};
    strncat(resrefWithExt, resRef.m_resRef, 16);
    strcat(resrefWithExt, ".");
    strcat(resrefWithExt, resExt);

    // Insert entry, or lookup old one...
    std::pair<ResourceMap::iterator, bool> lookup = resFiles.insert(ResourceMap::value_type(resrefWithExt, CResFileInfo()));
    CResFileInfo& fileInfo = lookup.first->second;

    ResManExistsEvent event = { resrefWithExt, 0, false };
    NotifyEventHooksNotAbortable(hResExists, (uintptr_t)&event);

    if (event.exists) {
        fileInfo.latest_mtime = event.mtime;

        // To keep nwserver from ketting confused over who owns what key, always
        // create a new CKeyTableEntry.
        if (!fileInfo.key) {
            fileInfo.key = CreateKeyTableEntry(resRef, resType);
            Log(4, "Adding Key: %s, %p\n", resrefWithExt, fileInfo.key);
        }
        if (*original) {
            // If the original has a CRes and we don't lets steal theirs.
            if (!fileInfo.key->m_pRes && (*original)->m_pRes) {
                fileInfo.key->m_pRes = (*original)->m_pRes;
                fileInfo.key->m_pRes->m_pKeyEntry = NULL;
                (*original)->m_pRes = NULL;
            }
        }
        *original = fileInfo.key;
    }
    Log(4, "File: %s, Exists?: %d, mtime: %d\n", resrefWithExt, event.exists, fileInfo.latest_mtime);

    return event.exists;
}

CKeyTableEntry *CNWNXResMan::CreateKeyTableEntry(const CResRef &resRef, NwnResType resType)
{
    CKeyTableEntry *key = new CKeyTableEntry;
    key->m_pRes = NULL;
    key->m_cResRef = CResRef(resRef);
    key->m_nID = -1;
    key->m_nRefCount = 0;
    key->m_nType = resType;
    return key;
}

const char *CNWNXResMan::GetSourcePath()
{
    return m_sourcePath.c_str();
}

void CNWNXResMan::WriteLogHeader()
{
    // write copy information to the log file
    Log(0, "NWNX Resource Manager 2.0 for Linux.\n");
    Log(0, "(c) 2005 by Ingmar Stieger (papillon@nwnx.org)\n");
    Log(0, "(c) 2006 by dumbo (dumbo@nm.ru)\n");
    Log(0, "(c) 2006-2010 by virusman (virusman@virusman.ru)\n");
    Log(0, "(c) 2015 by jmd (jmd2028@gmail.com)\n");
}

void CNWNXResMan::LoadConfiguration()
{
    gline& conf = *nwnxConfig;
    if (conf.exists(confKey)) {
        warnMissing = atoi(conf[confKey]["warn_missing"].c_str());
        Log(0, "o Logging missing resources: %d\n", warnMissing);

        debugCRes = atoi(conf[confKey]["debug_cres"].c_str());
        Log(0, "o Debugging CRes construction and destruction: %d\n", debugCRes);

        m_sourcePath = conf[confKey]["SourcePath"];
        if (m_sourcePath.length() > 0) {
            if (!RegisterDirectoryHandlers()) {
                Log(0, "Unable to load resman directory handlers!\n");
            } else {
                Log(0, "o Directory source path set: %s\n", m_sourcePath.c_str());
            }
        }
    }
}
