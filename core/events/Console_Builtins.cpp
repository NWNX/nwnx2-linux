#include "../core.h"
#include "../core/ipc/ipc.h"
#include "NWNXApi.h"
#include "NWNXBase.h"

extern const std::map<std::string, CNWNXBase*> & GetLoadedLibraries();
extern const int GetCoreDebugLevel();
extern void SetCoreDebugLevel(int level);

static bool DebugLevel(const char *command, const char *arguments, bool& pass)
{
    if (!strcmp("help", command)) {
        printf("debuglevel [level] [plugin]\n");
        printf("\tPrint or set NWNX debug level, either global or per plugin.\n");
    }

    else if (!strcmp("debuglevel", command)) {
        char *arg = strdup(arguments);
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
        pass = false;
    }
    return false;
}

void Core_Console_Builtins_Init()
{
    SignalConnect(CoreConsoleInput, "CORE", DebugLevel);
}
