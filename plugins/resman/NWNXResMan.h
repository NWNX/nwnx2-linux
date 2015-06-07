#ifndef NWNX_RESMAN_H
#define NWNX_RESMAN_H

#include <string>
#include <unordered_map>

#include "NWNXBase.h"
#include "NwnDefines.h"
#include "api/all.h"

#define MAXPATH 512

int HookFunctions();
bool RegisterDirectoryHandlers();

struct CResFileInfo {
    CResFileInfo() : size(0), mtime(0), latest_mtime(0), key(NULL) {}
    off_t size;
    time_t mtime;
    time_t latest_mtime;
    CKeyTableEntry *key;
};

typedef std::unordered_map<std::string, CResFileInfo> ResourceMap;

class CNWNXResMan : public CNWNXBase
{
    void WriteLogHeader();
    void LoadConfiguration();

public:
    CNWNXResMan();
    virtual ~CNWNXResMan();
    bool OnCreate(gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    bool OnRelease();

    void *DemandRes(CExoResMan *pResMan, CRes* cRes, const CResRef& resRef, NwnResType resType);
    void DumpResStruct(CRes *cRes);
    bool ResourceExists(const CResRef& resRef, NwnResType resType, CKeyTableEntry **original);
    CKeyTableEntry *CreateKeyTableEntry(const CResRef& resRef, NwnResType resType);
    const char* GetSourcePath();
    bool debugCRes;
private:
    char *pScriptBuffer;
    bool warnMissing;
    HANDLE hDemandRes;
    HANDLE hResExists;
    ResourceMap resFiles;
    std::string m_sourcePath;
};

#endif // NWNX_RESMAN_H
