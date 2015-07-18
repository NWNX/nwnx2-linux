#pragma once

#include "typedef.h"

/**
 * Event: EVENT_CORE_PLUGINSLOADED
 * Param: NULL
 * Abortable: No
 *
 * Called after all modules have been loaded.
 *
 * Best place to hook events provided by other modules inside plugins.
 */
#define EVENT_CORE_PLUGINSLOADED "Core/PluginsLoaded"

/**
 * Event: EVENT_CORE_RUNSCRIPT
 * Param: CoreRunScriptEvent
 * Abortable: No
 * Initializer: On Demand
 *
 * Called whenever anything executes a script by name.
 */
#define EVENT_CORE_RUNSCRIPT "Core/RunScript"

struct CoreRunScriptEvent {
	/* The script filename, without extension */
	const char* resref;
	/* the object Id which would be OBJECT_SELF in NWScript. */
	const nwobjid objectId;
	/* 1 for top-level scripts */
	const int recursionLevel;
	/* Set to true to suppress any nwscript by that name from executing. */
	bool suppress;
	/* Set the return value for conditional scripts. -1 for none, 0 for false,
	 * 1 for true. */
	int returnValue;
};

/**
 * Event: EVENT_CORE_RUNSCRIPT_AFTER
 * Param: CoreRunScriptEvent
 * Abortable: No
 * Initializer: On Demand
 *
 * Called after a RunScript was handled, either by the VM or some plugin.
 */
#define EVENT_CORE_RUNSCRIPT_AFTER "Core/RunScriptAfter"

/**
 * Event: EVENT_CORE_RUNSCRIPT_SITUATION
 * Param: CoreRunScriptSituationEvent
 * Abortable: No
 * Initializer: On Demand
 */
#define EVENT_CORE_RUNSCRIPT_SITUATION "Core/RunScriptSituation"

struct CoreRunScriptSituationEvent {
	/* The script filename, without extension */
	char* marker;
	uint32_t token;
	/* the object Id which would be OBJECT_SELF in NWScript. */
	nwobjid objectId;
	/* Set to true to suppress any nwscript by that name from executing. */
	bool suppress;
};

/**
 * Event: EVENT_CORE_RUNSCRIPT_SITUATION_AFTER
 * Param: CoreRunScriptSituationEvent
 * Abortable: No
 * Initializer: On Demand
 */
#define EVENT_CORE_RUNSCRIPT_SITUATION_AFTER "Core/RunScriptSituationAfter"

/**
 * Event: EVENT_CORE_MAINLOOP_BEFORE
 * Param: NULL
 * Abortable: No
 * Initializer: Always
 *
 * Can be used to run some code in the server main loop, which will be
 * executed about 60 times per second.
 *
 * Called before the main loop.
 */
#define EVENT_CORE_MAINLOOP_BEFORE "Core/MainLoopBefore"

/**
 * Event: EVENT_CORE_MAINLOOP_AFTER
 * Param: NULL
 * Abortable: No
 * Initializer: Always
 *
 * Can be used to run some code in the server main loop, which will be
 * executed about 60 times per second.
 *
 * Called after the mainloop.
 */
#define EVENT_CORE_MAINLOOP_AFTER "Core/MainLoopAfter"

/**
 * Event: EVENT_CORE_OBJECT_CREATED
 * Param: ObjectCreatedEvent
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
#define EVENT_CORE_OBJECT_CREATED "Core/CNWSObject/Created"
struct ObjectCreatedEvent {
	const void *object;
    const nwobjid requestedId;
};

/**
 * Event: EVENT_CORE_OBJECT_DESTROYED
 * Param: ObjectDestroyedEvent
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
#define EVENT_CORE_OBJECT_DESTROYED "Core/CNWSObject/Destroyed"
struct ObjectDestroyedEvent {
	const void *object;
};
