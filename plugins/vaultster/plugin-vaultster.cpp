#include "NWNXVaultster.h"

CNWNXVaultster vaultster;

extern "C" {
    CNWNXBase* GetClassObject()
    {
        return &vaultster;
    }
}
