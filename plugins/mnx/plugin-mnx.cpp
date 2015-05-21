#include "NWNXmnx.h"

CNWNXmnx mnx;

extern "C" {
    CNWNXBase* GetClassObject()
    {
        return &mnx;
    }
}
