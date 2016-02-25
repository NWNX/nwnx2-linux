#ifndef NWNX_EVENTS_PLUGINLINK_H
#define NWNX_EVENTS_PLUGINLINK_H

#include "typedef.h"
#include "core/ipc/Signal.h"

/**
 * Events/Event
 * Provider: nwnx_events
 *
 * Called whenever nwnx_event fires an event.
 *
 */
struct EventPosition {
    float x, y, z;
};

using EventsEvent = Signal<
    /* Event ID - See nwnx_events.nss */
    int,
    /* Event sub ID - See nwnx_events.nss */
    int,
    /* Object running the event. */
    nwobjid,
    /* Event target object. */
    nwobjid,
    /* Event item. */
    nwobjid,
    /* Position event occurred at */
    EventPosition,
    /* Set to true to bypass the current event */
    bool&,
    /* Integer value to return as result from an event hook.
     * See readme.txt */
    int&
>;

#endif // NWNX_EVENTS_PLUGINLINK_H
