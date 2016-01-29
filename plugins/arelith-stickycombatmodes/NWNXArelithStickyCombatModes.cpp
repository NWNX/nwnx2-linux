#include "NWNXArelithStickyCombatModes.hpp"
#include "NWNXApi.h"

#include "hooks/CNWSCreature__ToggleMode.hpp"
#include "hooks/CNWSCreature__SetCombatMode.hpp"

NWNXArelithStickyCombatModes::NWNXArelithStickyCombatModes()
{
    confKey = "ARELITH_STICKYCOMBATMODES";
}

NWNXArelithStickyCombatModes::~NWNXArelithStickyCombatModes()
{
    Hooks::CNWSCreature__ToggleMode::Unhook();
    Hooks::CNWSCreature__SetCombatMode::Unhook();
}

bool NWNXArelithStickyCombatModes::OnCreate(gline* config, const char* logDir)
{
    char logBuffer[128];
    sprintf(logBuffer, "%s/nwnx_arelith_StickyCombatModes.txt", logDir);

    if (!CNWNXBase::OnCreate(config, logBuffer))
    {
        return false;
    }

    Log(0, "NWNX Arelith StickyCombatModes loaded \n");
    Log(0, "http://www.arelith.com                \n");
    Log(0, "(c) Scholar Midnight 2016             \n");
    Log(0, "----------------------------          \n");

    Hooks::CNWSCreature__ToggleMode::Hook();
    Hooks::CNWSCreature__SetCombatMode::Hook();

    return true;
}

char* NWNXArelithStickyCombatModes::OnRequest(char* gameObject, char* request, char* params)
{
    return nullptr;
}