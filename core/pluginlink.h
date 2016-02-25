#pragma once

#include "typedef.h"
#include "ipc/Signal.h"

/**
 * Event: CorePluginsLoaded
 * Param: None
 * Abortable: No
 *
 * Called after all plugins have been loaded.
 *
 * Best place to hook events provided by other modules inside plugins.
 */
using CorePluginsLoaded = Signal<
     // No Params.
>;

/**
 * Event: CoreModuleLoading
 * Param: Module name.
 * Abortable: No
 *
 * Called when a new module is loading, either on startup or
 * via the interactive commands.
 */
using CoreModuleLoading = Signal<
    const char* // Module Name.
>;

/**
 * Event: CoreModuleLoaded
 * Param: None
 * Abortable: No
 *
 * Called after a new module was loaded successfully, just
 * before the first scripts run.
 */
using CoreModuleLoaded = Signal<
     // No Params.
>;

/**
 * Event: CoreRunScript
 * Abortable: No
 * Initializer: On Demand
 *
 * Called whenever anything executes a script by name.
 */
using CoreRunScript = Signal<
    const char*,   // The script filename, without extension
    const nwobjid, // the object Id which would be OBJECT_SELF in NWScript.
    const int,     // 1 for top-level scripts
    bool&,         // Set to true to suppress any nwscript by that name from executing.
    int&           // Set the return value for conditional scripts. -1 for none, 0 for false,
                   // 1 for true.
>;

/**
 * Event: CoreRunScriptAfter
 * Abortable: No
 * Initializer: On Demand
 *
 * Called after a RunScript was handled, either by the VM or some plugin.
 */
using CoreRunScriptAfter = Signal<
    const char*,   // The script filename, without extension
    const nwobjid, // the object Id which would be OBJECT_SELF in NWScript.
    const int,     // 1 for top-level scripts
    bool&,         // Set to true to suppress any nwscript by that name from executing.
    int&           // Set the return value for conditional scripts. -1 for none, 0 for false,
                   // 1 for true.
>;

/**
 * Event: CoreRunScriptSituation
 * Abortable: No
 * Initializer: On Demand
 */
using CoreRunScriptSituation = Signal<
    char*,    // The script filename, without extension
    uint32_t, // A plugin specific id.
    nwobjid,  // the object Id which would be OBJECT_SELF in NWScript.
    bool&     // Set to true to suppress any nwscript by that name from executing.
>;

/**
 * Event: CoreRunScriptSituationAfter
 * Abortable: No
 * Initializer: On Demand
 */
using CoreRunScriptSituationAfter = Signal<
    char*,    // The script filename, without extension
    uint32_t, // A plugin specific id.
    nwobjid,  // the object Id which would be OBJECT_SELF in NWScript.
    bool&     // Set to true to suppress any nwscript by that name from executing.
>;

/**
 * Event: CoreMainloopBefore
 * Abortable: No
 * Initializer: Always
 *
 * Can be used to run some code in the server main loop, which will be
 * executed about 60 times per second.
 *
 * Called before the main loop.
 */
using CoreMainloopBefore = Signal<
    // No parameters.
>;

/**
 * Event: CoreMainloopAfter
 * Abortable: No
 * Initializer: Always
 *
 * Can be used to run some code in the server main loop, which will be
 * executed about 60 times per second.
 *
 * Called after the mainloop.
 */
using CoreMainloopAfter = Signal<
    // No parameters.
>;

/**
 * Event: CoreCNWSObjectCreated
 * Abortable: No
 * Initializer: On Demand
 *
 * Called whenever a new CNWSObject is created, no matter the source.
 * (This includes while loading the module!)
 *
 * Does not trigger forareas and the module itself.
 *
 * object is guaranteed to be a CNWSObject*.
 */
using CoreCNWSObjectCreated = Signal<
    const void *, // CNWSObject*
    const nwobjid // Request object ID.
>;

/**
 * Event: CoreCNWSObjectDestroyed
 * Abortable: No
 * Initializer: On Demand
 *
 * Called whenever a CNWSObject is destroyed, no matter the source.
 * (This includes while unloading the module!).
 *
 * Does not trigger forareas and the module itself.
 *
 * object is guaranteed to be a CNWSObject*.
 */
using CoreCNWSObjectDestroyed = Signal<
    const void * // CNWSObject*
>;

/**
 * Event: CoreConsoleInput
 * Abortable: No
 * Initializer: Always
 *
 * Called for input on the server console.
 * This event runs in the nwserver main loop.
 *
 * Set param pass to false to stop nwserver from handling the command.
 *
 * Hint: If you want to output help for your command, just printf it to stdout
 * in the following format when command matches "help":
 *
 *     printf("wobbit <count>");
 *     printf("\tSpawn <count> wobbits.");
 *
 * Your text will be added to the bottom of the output.
 */
using CoreConsoleInput = Signal<
    const char *,
    const char *,
    bool&
>;
