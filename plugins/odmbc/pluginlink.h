#pragma once

/**
 * Event: EVENT_ODBC_RCO
 * Param: ODBCSCORCOEvent
 */
#define EVENT_ODBC_RCO "ODBC/RCO"

/**
 * Event: EVENT_ODBC_SCO
 * Param: ODBCSCORCOEvent
 */
#define EVENT_ODBC_SCO "ODBC/SCO"

typedef struct {
    const char* database;
    const char* key;
    char* player;
    unsigned char *pData;
    int size;
}
ODBCSCORCOEvent;
