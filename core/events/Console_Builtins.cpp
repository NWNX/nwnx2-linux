#include "../core.h"

#include "NWNXApi.h"
#include "NWNXBase.h"

extern const std::map<std::string, CNWNXBase*> & GetLoadedLibraries();
extern int GetCoreDebugLevel();
extern void SetCoreDebugLevel(int level);

static int DebugLevel(uintptr_t p)
{
    auto ev = (CoreConsoleInputEvent*) p;

    if (!strcmp("help", ev->command)) {
        printf("debuglevel [level] [plugin]\n");
        printf("\tPrint or set NWNX debug level, either global or per plugin.\n");
    }

    else if (!strcmp("debuglevel", ev->command)) {
        char *arg = strdup(ev->arguments);
        char *level = strtok(arg, " ");

        if (!level) {
            printf("Debuglevels:\n (Core): %d\n", GetCoreDebugLevel());
            for (auto &it : GetLoadedLibraries())
                printf(" %s: %d\n", it.first.c_str(), it.second->GetDebugLevel());

        } else {
            char *plugin = strtok(NULL, "");
            int lv = atoi(level);
            if (lv < 0) lv = 0;

            if (!plugin) {
                SetCoreDebugLevel(lv);
                printf("Core debug level changed to %d\n", lv);

            } else {
                auto it = GetLoadedLibraries().find(plugin);
                if (it != GetLoadedLibraries().end()) {

                    it->second->SetDebugLevel(lv);
                    printf("%s debug level changed to %d\n", plugin, lv);

                } else
                    printf("Plugin %s not loaded\n", plugin);
            }
        }

        free(arg);
        ev->pass = false;
    }
}

void Core_Console_Builtins_Init()
{
    HookEvent(EVENT_CORE_CONSOLE_INPUT, DebugLevel);
}
