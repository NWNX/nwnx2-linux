#pragma once

/**
 * Event: EVENT_RESMAN_DEMANDRES
 * Param: ResManDemandResEvent
 */
#define EVENT_RESMAN_DEMANDRES "ResMan/DemandRes"

typedef struct {
    char* resref; // "whatever.uti"
    unsigned char *pData;
    int size;
}
ResManDemandResEvent;
