#pragma once

/**
 * Event: EVENT_RESMAN_DEMAND
 * Param: ResManDemandEvent
 */
#define EVENT_RESMAN_DEMAND "ResMan/Demand"

typedef struct {
    const char* resRefWithExt; // "whatever.uti"
    unsigned int restype;
    unsigned char *pData;
    int size;
    time_t mtime;
    const time_t minimum_mtime;
} ResManDemandEvent;

/**
 * Event: EVENT_RESMAN_EXISTS
 * Param: ResManExistsEvent
 */
#define EVENT_RESMAN_EXISTS "ResMan/Exists"

typedef struct {
    const char* resRefWithExt;
    time_t mtime;
    bool exists;
} ResManExistsEvent;
