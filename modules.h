/**
 * NWNX PluginLink event and service call system.
 *
 * Code based on a plugin system for Miranda IM: the free IM client
 *   for Microsoft* Windows*.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#pragma once
#define MODULES_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * MAXMODULELABELLENGTH
 *
 * The maximum allowed length of a 'name' parameter. Very likely to change with
 * restructuring modules.c for performance.
*/
#define MAXMODULELABELLENGTH 128

typedef int (*NWNXHOOK)(uintptr_t);
typedef int (*NWNXSERVICE)(uintptr_t);
typedef int (*NWNXSERVICEPARAM)(uintptr_t, uintptr_t);

/**
 * CreateHookableEvent
 *
 * Adds an named event to the list and returns a handle referring to it, or NULL
 * on failure. Will be automatically destroyed on exit, or can be removed from the
 * list earlier using DestroyHookableEvent()
 * Will fail if the given name has already been used
 */
HANDLE CreateHookableEvent(const char *name);

/**
 * DestroyHookableEvent
 * Removes the event hEvent from the list of events. All modules hooked to it are
 * automatically unhooked. NotifyEventHooks() will fail if called with this hEvent
 * again. hEvent must have been returned by CreateHookableEvent()
 * Returns 0 on success, or nonzero if hEvent is invalid
 */
int DestroyHookableEvent(HANDLE hEvent);

/**
 * NotifyEventHooks
 *
 * Calls every module in turn that has hooked hEvent, using the parameter pParam.
 * hEvent must have been returned by CreateHookableEvent()
 * Returns 0 on success
 *   -1 if hEvent is invalid
 *   If one of the hooks returned nonzero to indicate abort, returns that abort
 *       value immediately, without calling the rest of the hooks in the chain.
 */
int NotifyEventHooks(HANDLE hEvent, uintptr_t pParam);

/**
 * NotifyEventHooksNotAbortable
 *
 * This is the same as NotifyEventHooks, except that event listeners cannot
 * abort the call chain.
 */
void NotifyEventHooksNotAbortable(HANDLE hEvent, uintptr_t pParam);

/**
 * SetHookDefaultForHookableEvent
 *
 * Sets a default hook to be called for a event that will be called if
 * no listeners are registered.
 */
int SetHookDefaultForHookableEvent(HANDLE hEvent, NWNXHOOK pfnHook);

/**
 * SetHookInitializer
 *
 * Sets a function to be called when the first (and only first) listener
 * registers to an event.
 */
int SetHookInitializer(HANDLE hEvent, NWNXHOOK pfnInitialize);

/**
 * HookEvent
 *
 * Adds a new hook to the chain 'name', to be called when the hook owner calls
 * NotifyEventHooks(). Will abort() with a nice backtrace if the given hook
 * name is not provided by anything.
 *
 * The type of parameter is defined by the creator of the event when
 * NotifyEventHooks() is called.
 *
 * The return value of hookProc should be 0 to continue processing the other
 * hooks, or nonzero to stop immediately. This abort value is returned to the
 * caller of NotifyEventHooks() and should not be -1 since that is a special
 * return code for NotifyEventHooks() (see above).
 *
 * Note that some events cannot be aborted this way; see
 * NotifyEventHooksNotAbortable().
 */
HANDLE HookEvent(const char *name, NWNXHOOK hookProc);

/**
 * HookEventOptionally
 *
 * The same as HookEvent, except that it will return NULL instead of abort()ing
 * on failure.
 */
HANDLE HookEventOptionally(const char *name, NWNXHOOK hookProc);

/**
 * UnhookEvent
 *
 * Removes a hook from its event chain. It will no longer receive any events.
 * hHook must have been returned by HookEvent() or HookEventMessage().
 * Returns 0 on success or nonzero if hHook is invalid.
*/
int UnhookEvent(HANDLE hHook);

/**
 * GetCurrentEventName
 *
 * Returns the currently running event name, or NULL if not in a event handler.
 *
 * In nested event handlers, only the topmost (current) one is ever returned.
 */
const char *GetCurrentEventName();


/**
 * CreateServiceFunction
 *
 * Adds a new service function called 'name' to the global list and returns a
 * handle referring to it. Service function handles are destroyed automatically
 * on exit, but can be removed from the list earlier using
 * DestroyServiceFunction()
 * Returns NULL if name has already been used. serviceProc is defined by the
 * caller as
 *   int ServiceProc(uintptr_t)
 * where the creator publishes the meaning of the parameter and the return value
 * Service functions must not return CALLSERVICE_NOTFOUND since that would confuse
 * callers of CallService().
*/
HANDLE CreateServiceFunction(const char *name, NWNXSERVICE serviceProc);

/**
 * DestroyServiceFunction
 *
 * Removes the function associated with hService from the global service function
 * list. Modules calling CallService() will fail if they try to call this
 * service's name. hService must have been returned by CreateServiceFunction().
 * Returns 0 on success or non-zero if hService is invalid.
 */
int DestroyServiceFunction(HANDLE hService);

/**
 * CallService
 *
 * Finds and calls the service function 'name' using the parameters wParam and
 * lParam.
 * Returns CALLSERVICE_NOTFOUND if no service function called 'name' has been
 * created, or the value the service function returned otherwise.
*/
#define CALLSERVICE_NOTFOUND      ((int)0x80000000)
int CallService(const char *name, uintptr_t pParam);

/**
 * ServiceExists
 *
 * Finds if a service with the given name exists
 * Returns nonzero if the service was found, and zero if it was not
 */
int ServiceExists(const char *name);

#ifdef  __cplusplus
}
#endif
