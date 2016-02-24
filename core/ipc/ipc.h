#pragma once

#include "IPCManager.h"

/**
 * Macro: SignalRegister
 *
 * A helper macro that wraps IPCManager::SignalRegister.
 *
 * Parameters:
 *
 *     type - A Signal<...> type.  The name of the signal is the stringified type paramter.
 *            Due to that it's important to name your type with a typedef or using directive.
 *     ...  - While technically a vararg parameter there are only two optional parameters:
 *            1. A boolean indicating whether the Signal is abortable. (Default: true)
 *            2. A function of type `void()` that is called when the first observer connects.
 *               (Default: null function)
 *
 * Example:
 *
 *     using MySignal = Signal<CGameObject*, bool>;
 *     SignalRegister(MySignal, false); // Not abortable
 *
 */
#define SignalRegister(type, ...) \
    g_IPCMgr->SignalRegister<type>(#type, ##__VA_ARGS__)

/**
 * Macro: SignalConnect
 *
 * Connect an observer to a Signal.  Multiple calls to SignalConnect will
 * replace the function called by the Signal.
 *
 * Parameters:
 *
 *     type - A Signal<...> type.  Usually defined in plugin's pluginlink.h
 *     name - Something to identify the observer.  The confKey is resonable.
 *            this is only to facilitate disconnecting if so desired.
 *     func - A function that satisfies Signal<...>::function_type.
 *
 * Returns:
 *
 * true is the observer was connected, false if not.  A false return value
 * would typically mean no such signal was registered.
 *
 */
#define SignalConnect(type, name, func) \
    g_IPCMgr->Connect<type>(#type, name, func)

/**
 * Macro: SignalDisconnect
 *
 * Disconnect an observer from a Signal.
 *
 * Parameters:
 *
 *     type - A Signal<...> type.  Usually defined in plugin's pluginlink.h
 *     name - Something to identify the observer.  The confKey is resonable.
 *
 * Returns:
 *
 * true is the observer was disconnected, false if not.  A false return value
 * would typically mean no such signal was registered.
 *
 */
#define SignalDisconnect(type, name) \
    g_IPCMgr->Disconnect<type>(#type, name)

/**
 * Macro: ServiceRegister
 *
 * A helper macro that wraps IPCManager::ServiceRegister.
 *
 * Parameters:
 *
 *     type - A Service<...> type.  The name of the service is derived from the type
 *            name by concatinating "type" + "()".  Due to that it's important to name
 *            your type with a typedef or using directive.
 *     func - A function that matches the expected type of your Service<...>::function_type.
 *
 * Example:
 *
 *     using MyService = Service<const char*, bool, nwobjid>;
 *     ServiceRegister(MyService, some_function);
 *
 */
#define ServiceRegister(type, func) \
    g_IPCMgr->ServiceRegister<type>(#type "()", func)

/**
 * Macro: ServiceCall
 *
 * A helper macro that wraps IPCManager::ServiceCall.
 *
 * Parameters:
 *
 *     type - A Service<...> type.  Usually defined in plugin's pluginlink.h
 *     ... - A list of parameters exepected by Service<...>::function_type.
 *
 * Returns:
 *
 *     true if the service exists and was called, false if not.
 *
 * Notes:
 *
 * Since a Service::function_type has a defacto return type of void the only way
 * to communcate results to callers is via output parameters.
 *
 * Example:
 *
 *     // From pluginlink.h
 *     using TheirService = Service<const char*, bool, nwobjid>;
 *     // Your code
 *     ServiceCall(TheirService, "Hello World", true, OBJECT_INVALID);
 *
 */
#define ServiceCall(type, ...) \
    g_IPCMgr->ServiceCall(#type "()", ##__VA_ARGS__)

#define ServiceExists(name) \
    g_IPCMgr->ServiceExists(name)

/**
 * Macro: ServiceRegisterObjectRequest
 *
 * A helper macro that wraps IPCManager::ServiceRegisterObjectRequest, which itself
 * is just a wrapper around RegisterService.
 *
 * Parameters:
 *
 *     name - The name of the request.  Must follow traditional "NWNX!<plugin>!<function name>" standards.
 *     func - A function that matches the expected type of your Service<CGameObject*, char*, nwobjid&>::function_type.
 *
 * Example:
 *
 *     bool Func_MyObjectRequest(CGameObject* obj, char* params, nwobjid& id) {
 *         id = OBJECT_INVALID
 *         return true;
 *     }
 *
 *     ServiceRegisterObjectRequest("NWNX!MYPLUGIN!MYOBJECTREQUEST", Func_MyObjectRequest);
 *
 */
#define ServiceRegisterObjectRequest(name, func) \
    g_IPCMgr->ServiceRegisterObjectRequest(name, func);

/**
 * Macro: ServiceRegisterStringRequest
 *
 * A helper macro that wraps IPCManager::ServiceRegisterStringRequest, which itself
 * is just a wrapper around ServiceRegister.
 *
 * Parameters:
 *
 *     name - The name of the request.  Must follow traditional "NWNX!<plugin>!<function name>" standards.
 *     func - A function that matches the expected type of your Service<CGameObject*, char*, char**>::function_type.
 *
 * Example:
 *
 *     bool Func_MyStringRequest(CGameObject* obj, char* params, char** ouput) {
 *         snprintf(params, strlen(params), "1");
 *         return true;
 *     }
 *
 *     ServiceRegisterStringRequest("NWNX!MYPLUGIN!MYSTRINGREQUEST", Func_MyStringRequest);
 *
 */
#define ServiceRegisterStringRequest(name, func) \
    g_IPCMgr->ServiceRegisterStringRequest(name, func)
