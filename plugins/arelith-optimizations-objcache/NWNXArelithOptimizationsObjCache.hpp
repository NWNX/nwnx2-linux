#ifndef NWNX_ARELITH_OPTIMIZATIONS_OBJCACHE_HPP_
#define NWNX_ARELITH_OPTIMIZATIONS_OBJCACHE_HPP_

#include "NWNXBase.h"

class NWNXArelithOptimizationsObjCache final : public CNWNXBase
{
public:
    NWNXArelithOptimizationsObjCache();
    virtual ~NWNXArelithOptimizationsObjCache();
    bool OnCreate(gline* config, const char* logDir) override;
    char* OnRequest(char* gameObject, char* request, char* params) override;
};

#endif // NWNX_ARELITH_OPTIMIZATIONS_OBJCACHE_HPP_