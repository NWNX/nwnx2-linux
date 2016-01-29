#include "NWNXArelithOptimizationsObjCache.hpp"
#include "NWNXApi.h"
#include "hooks/CGameObjectArray.hpp"

NWNXArelithOptimizationsObjCache::NWNXArelithOptimizationsObjCache()
{
    confKey = "ARELITH_OPTIMIZATIONS_OBJCACHE";
}

NWNXArelithOptimizationsObjCache::~NWNXArelithOptimizationsObjCache()
{
    Hooks::CGameObjectArray::Unhook();
}

bool NWNXArelithOptimizationsObjCache::OnCreate(gline* config, const char* logDir)
{
    char logBuffer[128];
    sprintf(logBuffer, "%s/nwnx_arelith_optimizations_objcache.txt", logDir);

    if (!CNWNXBase::OnCreate(config, logBuffer))
    {
        return false;
    }

    Log(0, "NWNX Arelith Optimizations (ObjCache) loaded  \n");
    Log(0, "http://www.arelith.com                        \n");
    Log(0, "(c) Scholar Midnight 2016                     \n");
    Log(0, "----------------------------                  \n");

    Hooks::CGameObjectArray::Hook();

    return true;
}

char* NWNXArelithOptimizationsObjCache::OnRequest(char* gameObject, char* request, char* params)
{
    return nullptr;
}