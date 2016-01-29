#ifndef NWNX_ARELITH_STICKYCOMBATMODES_HPP_
#define NWNX_ARELITH_STICKYCOMBATMODES_HPP_

#include "NWNXBase.h"

class NWNXArelithStickyCombatModes final : public CNWNXBase
{
public:
    NWNXArelithStickyCombatModes();
    virtual ~NWNXArelithStickyCombatModes();
    bool OnCreate(gline* config, const char* logDir) override;
    char* OnRequest(char* gameObject, char* request, char* params) override;
};

#endif // NWNX_ARELITH_STICKYCOMBATMODES_HPP_