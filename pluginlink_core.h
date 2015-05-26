#pragma once

/**
 * Event: EVENT_CORE_PLUGINSLOADED
 * Param: NULL
 *
 * Called after all modules have been loaded.
 *
 * Best place to hook events provided by other modules inside plugins.
 */
#define EVENT_CORE_PLUGINSLOADED  "Core/PluginsLoaded"
