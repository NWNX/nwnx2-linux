#pragma once

#include "core/ipc/Signal.h"

/**
 * Event: ResManDemandEvent
 */
using ResManDemandEvent = Signal<
    const char*,     // ResRef with extension.  E,g. "whatever.uti"
    unsigned int,    // Resource Type
    unsigned char**, // pData;
    int&,            // size;
    time_t&,         // mtime;
    const time_t     // minimum_mtime;
>;

/**
 * Event: ResManExistsEvent
 */
using ResManExistsEvent = Signal<
    const char*, // ResRef with extension.  E,g. "whatever.uti"
    time_t&,     // Last Modification Time
    bool&        // Set to true if resource exists.
>;
