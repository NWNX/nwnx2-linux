#include "NWNXStatsd.h"

CNWNXStatsd Statsd;

extern "C" CNWNXBase *GetClassObject()
{
    return &Statsd;
}
