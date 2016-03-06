#!/bin/bash

# Usage: genplugin.sh PluginName
#
# A simple script to bootstrap new plugins.  Where ever the script
# is run their must be a plugins subdirectory.  For example in the
# main directory of the NWNX repository.

if [ $# -ne 1 ]; then
    echo $0: usage: genplugin.sh PluginName
    exit 1
fi

pname="$1"
dash_case=`echo $pname | sed 's/\(.\)\([A-Z]\)/\1-\2/g' | tr '[:upper:]' '[:lower:]'`
snake_case=`echo $pname | sed 's/\(.\)\([A-Z]\)/\1_\2/g' | tr '[:upper:]' '[:lower:]'`

if [ -d "plugins/$dash_case" ]; then
    echo Directory "plugins/$dash_case" already exists!
    exit 1
fi

if mkdir "plugins/$dash_case"; then
    echo Generating plugin $pname...
else
    echo Unbale to create directory "plugins/$dash_case"!
    exit 1
fi

cat > "plugins/$dash_case/CMakeLists.txt" <<-EOT
include_directories(.)
add_module($snake_case
    NWNX$pname
    plugin-$dash_case
)
EOT

cat > "plugins/$dash_case/plugin-$dash_case.cpp" <<-EOT
#include "NWNX$pname.h"

CNWNX$pname $snake_case;
PLUGINLINK *pluginLink = 0;

PLUGININFO pluginInfo = {
    sizeof(PLUGININFO),
    "NWNX $pname",
    PLUGIN_MAKE_VERSION(1, 0, 0, 0),
    "",
    "$(git config user.name)",
    "$(git config user.email)",
    "(c) $(git config user.name)",
    "",
    0		//not transient
};

extern "C" PLUGININFO* GetPluginInfo(DWORD nwnxVersion)
{
    return &pluginInfo;
}

extern "C" int InitPlugin(PLUGINLINK *link)
{
    pluginLink = link;
    return 0;
}

extern "C"
CNWNXBase* GetClassObject()
{
    return &$snake_case;
}
EOT

cat > "plugins/$dash_case/pluginlink.h" <<-EOT
#pragma once
EOT

cat > "plugins/$dash_case/NWNX$pname.h" <<-EOT
#pragma once

#include "NWNXBase.h"
#include "NWNXApi.h"
#include "pluginlink.h"

class CNWNX$pname : public CNWNXBase
{
public:
    CNWNX$pname();
    virtual ~CNWNX$pname();

    virtual bool OnCreate(gline *config, const char* LogDir) override;
    virtual bool OnRelease() override;
    virtual char* OnRequest(char* gameObject, char* Request, char* Parameters) override;
    virtual nwobjid OnRequestObject(char* gameObject, char* Request) override;
};
EOT

cat > "plugins/$dash_case/NWNX$pname.cpp" <<-EOT
#include "NWNX$pname.h"

CNWNX$pname::CNWNX$pname()
{
    confKey = "${pname^^}";
}

CNWNX$pname::~CNWNX$pname()
{
}

bool CNWNX$pname::OnCreate(gline *config, const char* LogDir)
{
    char log[128];
    // call the base class function
    sprintf(log, "%s/nwnx_$snake_case.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    return true;
}

bool CNWNX$pname::OnRelease()
{
    return true;
}

char* CNWNX$pname::OnRequest(char* gameObject, char* Request, char* Parameters)
{
    Log(2, "Request: \"%s\"\n", Request);
    Log(2, "Params:  \"%s\"\n", Parameters);

    return nullptr;
}

nwobjid CNWNX$pname::OnRequestObject(char* gameObject, char* Request)
{
    Log(2, "ObjRequest: \"%s\"\n", Request);
    return OBJECT_INVALID;
}
EOT

