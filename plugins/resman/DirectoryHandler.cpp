#include "NWNXResMan.h"
#include "NwnDefines.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "pluginlink.h"

extern CNWNXResMan resman;

static time_t GetLastModTime(const char *file)
{
    struct stat info;
    if (stat(file, &info) == 0) {
        return info.st_mtim.tv_sec;
    }
    return -1;
}

static int HandleResourceExistsEvent(uintptr_t p)
{
    char resPath[MAXPATH + 17];

    ResManExistsEvent *exists = reinterpret_cast<ResManExistsEvent*>(p);
    const char *ext = strchr(exists->resRefWithExt, '.');
    if (!ext) { return 0; }
    ++ext;
    snprintf(resPath, MAXPATH, "%s/%s/%s", resman.GetSourcePath(), ext, exists->resRefWithExt);
    time_t modtime = GetLastModTime(resPath);

    if (modtime == -1) { return 0; }

    exists->exists = true;
    exists->mtime = std::max(exists->mtime, modtime);

    return 0;
}

static int HandleDemandResourceEvent(uintptr_t p)
{
    char resPath[MAXPATH + 17];

    ResManDemandEvent *event = reinterpret_cast<ResManDemandEvent*>(p);
    const char *ext = strchr(event->resRefWithExt, '.');
    if (!ext) { return 0; }
    ++ext;
    snprintf(resPath, MAXPATH, "%s/%s/%s", resman.GetSourcePath(), ext, event->resRefWithExt);
    time_t modtime = GetLastModTime(resPath);
    if (modtime == -1 || event->minimum_mtime > modtime) {
        return 0;
    }

    FILE *pTemp = fopen(resPath, "rb");
    if (pTemp == NULL) {
        resman.Log(3, "o Skip - Unable to open file: %s\n", resPath);
        return 0;
    }

    fseek(pTemp, 0, SEEK_END);
    unsigned long size = ftell(pTemp);
    fseek(pTemp, 0, SEEK_SET);

    char *pScriptBuffer = new char[size];
    if (fread(pScriptBuffer, size, 1, pTemp) != 1) {
        resman.Log(3, "o Skip - Error reading file: %s\n", resPath);
        delete[] pScriptBuffer;
        pScriptBuffer = NULL;
    }

    fclose(pTemp);

    if (pScriptBuffer) {
        event->mtime = modtime;
        event->pData = (unsigned char*)pScriptBuffer;
        event->size = size;
        return 1;
    }
    return 0;
}

bool RegisterDirectoryHandlers()
{
    bool result = true;

    HANDLE handleResourceExists = HookEvent(EVENT_RESMAN_EXISTS,
        HandleResourceExistsEvent);

    HANDLE handleDemandResource = HookEvent(EVENT_RESMAN_DEMAND,
        HandleDemandResourceEvent);

    return result;
}

