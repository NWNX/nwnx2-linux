#ifndef NWNX_MODULES_H_
#define NWNX_MODULES_H_

/**
 * Event: NWNX/Core/PluginsLoaded
 * Provider: nwnx2
 *
 * Called when all plugins are loaded. Use this to hook your own events
 * that other plugins may provide.
 *
 * Does not provide any event data.
 */

/**
 * Events: NWServer/SCO, NWServer/RCO
 * Provider: nwnx_odbc2
 */
typedef struct
{
	const char* database;
	const char* key;
	char* player;
	unsigned char *pData;
	int size;
}
	SCORCOStruct;

/**
 * Event: NWNX/ResMan/DemandResource
 * Provider: nwnx_resman
 */
typedef struct
{
	char* resref; // "whatever.uti"
	unsigned char *pData;
	int size;
}
	ResManDemandResStruct;

/**
 * Event: NWServer/RunScript
 * Provider: nwnx_coreevents
 *
 * Called whenever anything executes a script by name.
 */
typedef struct
{
	/* The script filename, without extension */
	char* resref;
	/* the object Id which would be OBJECT_SELF in NWScript. */
	unsigned long objectId;
	/* 1 for top-level scripts */
	int recursionLevel;
	/* Set to true to suppress any nwscript by that name from executing. */
	bool suppress;
}
	CoreEventRunScriptStruct;

/**
 * Event: NWServer/MainLoop
 * Provider: nwnx_coreevents
 *
 * Can be used to run some code in the server main loop, which will be
 * executed about 60 times per second.
 *
 * Does not provide any event data.
 */

#endif  // NWNX_MODULES_H_
