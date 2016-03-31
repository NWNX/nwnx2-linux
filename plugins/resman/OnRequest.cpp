#include "NWNXResMan.h"

char* CNWNXResMan::OnRequest(char* gameObject, char* Request, char* Parameters)
{

    if (0 == strncmp(Request, "GetKeyEntry", 11)) {
        const char* base = strtok(Parameters, ".");
        if (!base)
            return strdup("-1");

        const char* ext = strtok(NULL, " ");
        if (!ext)
            return strdup("-2");

        CResRef resRef(base);

        NwnResType resType = NwnGetResTypeFromExtension(ext);
        if (resType == NwnResType_Unknown)
            return strdup("-3");

        CExoKeyTable* keyTable = nullptr;
        CKeyTableEntry* keyTableEntry = nullptr;
        bool ret = g_pExoResMan->GetKeyEntry(resRef, resType,
                                             &keyTable, &keyTableEntry);

        char* sret;
        if (ret && keyTable != nullptr)
            asprintf(&sret, "%d %s", ret, keyTable->Name.CStr());
        else
            asprintf(&sret, "0");

        return sret;
    }

    return NULL;
}
