#ifndef NWNX_EVENTS_PLUGINLINK_H
#define NWNX_EVENTS_PLUGINLINK_H

#include "typedef.h"

#define NWNX_EVENTS_EVENT "Events/Event"

/**
 * Events/Event
 * Provider: nwnx_events
 *
 * Called whenever nwnx_event fires an event.
 *
 */
typedef struct {
    /* Event ID - See nwnx_events.nss */
    int type;
    /* Event sub ID - See nwnx_events.nss */
    int subtype;
    /* Object running the event. */
    nwobjid object;
    /* Event target object. */
    nwobjid target;
    /* Event item. */
    nwobjid item;
    /* Position event occurred at */
    struct {
        float x, y, z;
    } position;
    /* Set to true to bypass the current event */
    bool bypass;
    /* Integer value to return as result from an event hook.
     * See readme.txt */
    int  result;
}
EventsEvent;

#endif // NWNX_EVENTS_PLUGINLINK_H
