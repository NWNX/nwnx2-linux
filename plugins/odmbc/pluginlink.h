#pragma once

#include "core/ipc/Signal.h"

/**
 * Event: ODBCRCOEvent
 */
using ODBCRCOEvent = Signal<
    const char*,      // database
    const char*,      // key
    char*,            // player
    unsigned char **, // pData
    int&              // size
>;

/**
 * Event: EVENT_ODBC_SCO
 * Param: ODBCSCORCOEvent
 */
#define EVENT_ODBC_SCO "ODBC/SCO"
using ODBCSCOEvent = Signal<
    const char*,     // database
    const char*,     // key
    char*,           // player
    unsigned char *, // pData
    int              // size
>;
