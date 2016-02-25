#include "NWNXResMan.h"
#include "NwnDefines.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "pluginlink.h"
#include "core/ipc/ipc.h"

extern CNWNXResMan resman;

static time_t GetLastModTime(const char *file)
{
    struct stat info;
    if (stat(file, &info) == 0) {
        return info.st_mtim.tv_sec;
    }
    return -1;
}

static bool HandleResourceExistsEvent(const char* resRefWithExt, time_t& mtime, bool& exists)
{
    char resPath[MAXPATH + 17];

    const char *ext = strchr(resRefWithExt, '.');
    if (!ext) { return 0; }
    ++ext;
    snprintf(resPath, MAXPATH, "%s/%s/%s", resman.GetSourcePath(), ext, resRefWithExt);
    time_t modtime = GetLastModTime(resPath);

    if (modtime == -1) { return false; }

    exists = true;
    mtime = std::max(mtime, modtime);

    return false;
}

static bool HandleDemandResourceEvent(const char* resRefWithExt,
                                      unsigned int resType,
                                      unsigned char** data,
                                      int& size,
                                      time_t& mtime,
                                      const time_t minimum_mtime
)
{
    char resPath[MAXPATH + 17];

    const char *ext = strchr(resRefWithExt, '.');
    if (!ext) { return 0; }
    ++ext;
    snprintf(resPath, MAXPATH, "%s/%s/%s", resman.GetSourcePath(), ext, resRefWithExt);
    time_t modtime = GetLastModTime(resPath);
    if (modtime == -1 || minimum_mtime > modtime) {
        return false;
    }

    FILE *pTemp = fopen(resPath, "rb");
    if (pTemp == NULL) {
        resman.Log(3, "o Skip - Unable to open file: %s\n", resPath);
        return false;
    }

    fseek(pTemp, 0, SEEK_END);
    size = ftell(pTemp);
    fseek(pTemp, 0, SEEK_SET);

    char *pScriptBuffer = new char[size];
    if (fread(pScriptBuffer, size, 1, pTemp) != 1) {
        resman.Log(3, "o Skip - Error reading file: %s\n", resPath);
        delete[] pScriptBuffer;
        pScriptBuffer = NULL;
        size = 0;
    }

    fclose(pTemp);

    if (pScriptBuffer) {
        mtime = modtime;
        *data = (unsigned char*)pScriptBuffer;
        return true;
    }
    return false;
}

bool RegisterDirectoryHandlers()
{
    bool result = true;

    SignalConnect(ResManExistsEvent, "RESMAN", HandleResourceExistsEvent);
    SignalConnect(ResManDemandEvent, "RESMAN", HandleDemandResourceEvent);

    return result;
}

