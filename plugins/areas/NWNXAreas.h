#pragma once

#include "NWNXBase.h"
#include "NWNXApi.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stddef.h>
#include <unistd.h>

#include <string>
#include <future>
#include <cassert>

#include "gline.h"

#include "pluginlink.h"

#include "funcs/Funcs.h"

class CNWNXAreas : public CNWNXBase
{

public:
    CNWNXAreas();
    bool OnCreate(gline* config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    unsigned long OnRequestObject(char* gameObject, char* Request);
};

extern CNWNXAreas areas;

// Older NWNX releases have broken offsets for CNWSModule that
// resulted in memory corruption. Yay fun times!
static_assert(offsetof(CNWSModule, AreaIdList) == 0x38,
              "Your CNWSModule definition is outdated. "
              "Compiling against this will corrupt memory and make your server crash.");

static_assert(offsetof(CNWSModule, TURDList) == 0x4c,
              "Your CNWSModule definition is outdated. "
              "Compiling against this will corrupt memory and make your server crash.");