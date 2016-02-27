#include "commonheaders.h"
#include "modules.h"

#include <execinfo.h>

// list of hooks

typedef struct {
    NWNXHOOK pfnHook;
    HINSTANCE hOwner;
    HWND hwnd;
    UINT message;
}
THookSubscriber;

typedef struct {
    char name[ MAXMODULELABELLENGTH ];
    int  id;
    int  subscriberCount;
    THookSubscriber* subscriber;
    NWNXHOOK pfnHook;
    int inintialized;
    NWNXHOOK pfnInitialize;
}
THook;

static struct {
    THook** items;
    int count, limit, increment;
    FSortFunc sortFunc;
}
hooks;

// list of services

typedef struct {
    DWORD nameHash;
    HINSTANCE hOwner;
    NWNXSERVICE pfnService;
    int isParam;
    uintptr_t pParam;
    char name[1];
}
TService;

static struct {
    TService** items;
    int count, limit, increment;
    FSortFunc sortFunc;
}
services;

// other static variables

//static CRITICAL_SECTION csHooks,csServices;
static DWORD  mainThreadId;
static int    hookId = 1;
static HANDLE hMainThread;
static HANDLE hMissingService;

HINSTANCE GetInstByAddress(void* codePtr)
{
    return NULL;
}

static int LoadDefaultModules(void)
{
    int *disableDefaultModule = 0;

    return 0;
}

static int compareServices(const TService* p1, const TService* p2)
{
    if (p1->nameHash == p2->nameHash)
        return 0;

    return (p1->nameHash > p2->nameHash) ? 1 : -1;
}

static int compareHooks(const THook* p1, const THook* p2)
{
    return strcmp(p1->name, p2->name);
}

int InitialiseModularEngine(void)
{
    services.sortFunc = (FSortFunc) compareServices;
    services.increment = 100;

    hooks.sortFunc = (FSortFunc) compareHooks;
    hooks.increment = 50;

    //InitializeCriticalSection(&csHooks);
    //InitializeCriticalSection(&csServices);

    //mainThreadId=GetCurrentThreadId();
    //DuplicateHandle(GetCurrentProcess(),GetCurrentThread(),GetCurrentProcess(),&hMainThread,THREAD_SET_CONTEXT,FALSE,0);

    hMissingService = CreateHookableEvent(ME_SYSTEM_MISSINGSERVICE);
    return LoadDefaultModules();
}

void DestroyModularEngine(void)
{
    int i;
    //EnterCriticalSection( &csHooks );
    for (i = 0; i < hooks.count; i++) {
        if (hooks.items[i]->subscriberCount)
            free(hooks.items[i]->subscriber);
        free(hooks.items[i]);
    }
    List_Destroy((SortedList*)&hooks);
    //LeaveCriticalSection( &csHooks );
    //DeleteCriticalSection( &csHooks );

    //EnterCriticalSection( &csServices );
    for (i = 0; i < services.count; i++)
        free(services.items[i]);

    List_Destroy((SortedList*)&services);
    //LeaveCriticalSection( &csServices );
    //DeleteCriticalSection( &csServices );
    //CloseHandle( hMainThread );
}

#if __GNUC__
#define NOINLINEASM
#endif

DWORD NameHashFunction(const char *szStr)
{
#if defined _M_IX86 && !defined _NUMEGA_BC_FINALCHECK && !defined NOINLINEASM
    __asm {
        xor   edx, edx
        xor   eax, eax
        mov   esi, szStr
        mov   al, [esi]
        dec   esi
        xor   cl, cl
        lph_top:	 //only 4 of 9 instructions in here don't use AL, so optimal pipe use is impossible
        xor   edx, eax
        inc   esi
        and   cl, 31
        movzx eax, byte ptr [esi]
        add   cl, 5
        test  al, al
        rol   eax, cl		 //rol is u-pipe only, but pairable
        //rol doesn't touch z-flag
        jnz   lph_top  //5 clock tick loop. not bad.

        xor   eax, edx
    }
#else
    DWORD hash=0;
    int i;
    int shift=0;
    for (i=0; szStr[i]; i++) {
        hash ^= szStr[i] << shift;
        if (shift > 24) hash ^= (szStr[i] >> (32 - shift)) & 0x7F;
        shift = (shift + 5) & 0x1F;
    }
    return hash;
#endif
}

///////////////////////////////HOOKS

HANDLE CreateHookableEvent(const char *name)
{
    THook* ret;
    int    idx;

    if (name == NULL)
        return NULL;

    //EnterCriticalSection( &csHooks );
    if (List_GetIndex((SortedList*)&hooks, (void*)name, &idx)) {
        //LeaveCriticalSection( &csHooks );
        return NULL;
    }

    ret = (THook*)malloc(sizeof(THook));
    strncpy(ret->name, name, sizeof(ret->name)); ret->name[ MAXMODULELABELLENGTH - 1 ] = 0;
    ret->id = hookId++;
    ret->subscriberCount = 0;
    ret->subscriber = NULL;
    ret->pfnHook = NULL;
    ret->inintialized = 0;
    ret->pfnInitialize = NULL;
    List_Insert((SortedList*)&hooks, ret, idx);

    //LeaveCriticalSection( &csHooks );
    return (HANDLE)ret;
}

int DestroyHookableEvent(HANDLE hEvent)
{
    int idx;
    THook* p;

    //EnterCriticalSection( &csHooks );
    if ((idx = List_IndexOf((SortedList*)&hooks, hEvent)) == -1) {
        //LeaveCriticalSection(&csHooks);
        return 1;
    }
    p = hooks.items[idx];
    if (p->subscriberCount) {
        free(p->subscriber);
        p->subscriber = NULL;
        p->subscriberCount = 0;
    }
    List_Remove((SortedList*)&hooks, idx);
    free(p);

    //LeaveCriticalSection( &csHooks );
    return 0;
}

int SetHookDefaultForHookableEvent(HANDLE hEvent, NWNXHOOK pfnHook)
{
    THook* p = (THook*)hEvent;

    //EnterCriticalSection(&csHooks);
    if (List_IndexOf((SortedList*)&hooks, hEvent) != -1)
        p->pfnHook = pfnHook;
    //LeaveCriticalSection(&csHooks);
    return 0;
}

static char* currentEventName;

const char *GetCurrentEventName()
{
    return currentEventName;
}

int SetHookInitializer(HANDLE hEvent, NWNXHOOK pfnInitialize)
{
    THook* p = (THook*)hEvent;
    if (List_IndexOf((SortedList*)&hooks, hEvent) != -1)
        p->pfnInitialize = pfnInitialize;

    return 0;
}

int CallHookSubscribers(HANDLE hEvent, uintptr_t pParam, bool abortable)
{
    int i, returnVal = 0;
    THook* p = (THook*)hEvent;

    //EnterCriticalSection( &csHooks );
    if (List_IndexOf((SortedList*)&hooks, p) == -1) {
        //LeaveCriticalSection( &csHooks );
        return -1;
    }

    char *oldCurrentEventName = currentEventName;

    currentEventName = p->name;

    // NOTE: We've got the critical section while all this lot are called. That's mostly safe, though.
    for (i = 0; i < p->subscriberCount; i++) {
        if (p->subscriber[i].pfnHook != NULL) {
            returnVal = p->subscriber[i].pfnHook(pParam);
            if (abortable && returnVal)
                break;
        }
        /*else if ( p->subscriber[i].hwnd != NULL ) {
        	returnVal = SendMessage( p->subscriber[i].hwnd, p->subscriber[i].message, wParam, lParam );
        	if ( returnVal )
        		break;
        }*/
    }

    // check for no hooks and call the default hook if any
    if (p->subscriberCount == 0 && p->pfnHook != 0)
        returnVal = p->pfnHook(pParam);

    currentEventName = oldCurrentEventName;

    //LeaveCriticalSection(&csHooks);
    return returnVal;
}

int NotifyEventHooks(HANDLE hEvent, uintptr_t pParam)
{
    return CallHookSubscribers(hEvent, pParam, true);
}

void NotifyEventHooksNotAbortable(HANDLE hEvent, uintptr_t pParam)
{
	CallHookSubscribers(hEvent, pParam, false);
}

HANDLE HookEventOptionally(const char* name, NWNXHOOK hookProc)
{
    int idx;
    THook* p;
    HANDLE ret;

    //EnterCriticalSection( &csHooks );
    if (!List_GetIndex((SortedList*)&hooks, (void*)name, &idx)) {

#ifdef _DEBUG
        //OutputDebugStringA("Attempt to hook: \t");
        //OutputDebugStringA(name);
        //OutputDebugStringA("\n");
#endif
        //LeaveCriticalSection(&csHooks);
        return NULL;
    }

    p = hooks.items[ idx ];
    p->subscriber = (THookSubscriber*)realloc(p->subscriber,
                    sizeof(THookSubscriber) * (p->subscriberCount + 1));
    p->subscriber[ p->subscriberCount ].pfnHook = hookProc;
    p->subscriber[ p->subscriberCount ].hOwner  = GetInstByAddress(hookProc);
    p->subscriber[ p->subscriberCount ].hwnd    = NULL;
    p->subscriberCount++;

    ret = (HANDLE)((p->id << 16) | p->subscriberCount);

    if (p->inintialized == 0 && p->pfnInitialize) {
        p->inintialized = 1;
        p->pfnInitialize(0);
    }


    //LeaveCriticalSection( &csHooks );
    return ret;
}

HANDLE HookEvent(const char *name, NWNXHOOK hookProc)
{
    HANDLE ret = HookEventOptionally(name, hookProc);

    if (!ret) {
        fprintf(stderr,
                "[PluginLink] a plugin requires hook '%s', which noone provides.\n",
                name);
        fprintf(stderr, "Backtrace:\n");
        void* callstack[32];
        int i, frames = backtrace(callstack, 32);
        char** bt = backtrace_symbols(callstack, frames);
        for (i = 0; i < frames; ++i)
            fprintf(stderr, " - %s\n", bt[i]);
        free(bt);
        abort();
    }

    return ret;
}

HANDLE HookEventMessage(const char* name, HWND hwnd, UINT message)
{
    int idx;
    THook* p;
    HANDLE ret;

    //EnterCriticalSection( &csHooks );
    if (!List_GetIndex((SortedList*)&hooks, (void*)name, &idx)) {
#ifdef _DEBUG
        //MessageBoxA(NULL,"Attempt to hook non-existant event",name,MB_OK);
#endif
        //LeaveCriticalSection(&csHooks);
        return NULL;
    }

    p = hooks.items[ idx ];
    p->subscriber = (THookSubscriber*)realloc(p->subscriber,
                    sizeof(THookSubscriber) * (p->subscriberCount + 1));
    p->subscriber[ p->subscriberCount ].pfnHook = NULL;
    p->subscriber[ p->subscriberCount ].hwnd = hwnd;
    p->subscriber[ p->subscriberCount ].message = message;
    p->subscriberCount++;

    ret = (HANDLE)((p->id << 16) | p->subscriberCount);
    //LeaveCriticalSection( &csHooks );
    return ret;
}

int UnhookEvent(HANDLE hHook)
{
    int i;
    THook* p = NULL;
    int hookId = (int)hHook >> 16;
    int subscriberId = ((int)hHook & 0xFFFF) - 1;

    //EnterCriticalSection( &csHooks );
    for (i = 0; i < hooks.count; i++) {
        if (hooks.items[i]->id == hookId) {
            p = hooks.items[i];
            break;
        }
    }

    if (p == NULL) {
        //LeaveCriticalSection( &csHooks );
        return 1;
    }

    if (subscriberId >= p->subscriberCount || subscriberId < 0) {
        //LeaveCriticalSection( &csHooks );
        return 1;
    }

    p->subscriber[subscriberId].pfnHook = NULL;
    p->subscriber[subscriberId].hwnd    = NULL;
    p->subscriber[subscriberId].hOwner  = NULL;
    while (p->subscriberCount && p->subscriber[p->subscriberCount - 1].pfnHook == NULL
            && p->subscriber[p->subscriberCount - 1].hwnd == NULL)
        p->subscriberCount--;
    if (p->subscriberCount == 0) {
        if (p->subscriber) free(p->subscriber);
        p->subscriber = NULL;
    }
    //LeaveCriticalSection( &csHooks );
    return 0;
}

void KillModuleEventHooks(HINSTANCE hInst)
{
    int i, j;

    //EnterCriticalSection(&csHooks);
    for (i = hooks.count - 1; i >= 0; i--) {
        if (hooks.items[i]->subscriberCount == 0)
            continue;

        for (j = hooks.items[i]->subscriberCount - 1; j >= 0; j--) {
            if (hooks.items[i]->subscriber[j].hOwner == hInst) {
                char szModuleName[ MAX_PATH ];
                /*GetModuleFileNameA( hooks.items[i]->subscriber[j].hOwner, szModuleName, sizeof(szModuleName));
                Netlib_Logf( NULL, "A hook %08x for event '%s' was abnormally deleted because module '%s' didn't released it",
                	hooks.items[i]->subscriber[j].pfnHook, hooks.items[i]->name, szModuleName );*/
                UnhookEvent((HANDLE)((hooks.items[i]->id << 16) + j + 1));
                if (hooks.items[i]->subscriberCount == 0)
                    break;
            }
        }
    }

    //LeaveCriticalSection(&csHooks);
}

/////////////////////SERVICES

static __inline TService* FindServiceByHash(DWORD hash)
{
    int idx;
    if (List_GetIndex((SortedList*)&services, &hash, &idx))
        return services.items[idx];
    return NULL;
}

static __inline TService* FindServiceByName(const char *name)
{
    return FindServiceByHash(NameHashFunction(name));
}

HANDLE CreateServiceFunction(const char *name, NWNXSERVICE serviceProc)
{
    DWORD hash;
    int   idx;
    TService* p;
#ifdef _DEBUG
    if (name == NULL) {
        MessageBoxA(0, "Someone tried to create a NULL'd service, see call stack for more info", "", 0);
        DebugBreak();
        return NULL;
    }
#else
    if (name == NULL) return NULL;
#endif
    hash = NameHashFunction(name);
    //EnterCriticalSection( &csServices );

    if (List_GetIndex((SortedList*)&services, &hash, &idx)) {
        //LeaveCriticalSection( &csServices );
        return NULL;
    }

    p = malloc(sizeof(*p) + strlen(name));
    strcpy(p->name, name);
    p->nameHash   = hash;
    p->pfnService = serviceProc;
    p->hOwner     = GetInstByAddress(serviceProc);
    p->isParam    = 0;
    List_Insert((SortedList*)&services, p, idx);

    //LeaveCriticalSection( &csServices );
    return (HANDLE)hash;
}

int DestroyServiceFunction(HANDLE hService)
{
    int idx;

    //EnterCriticalSection( &csServices );
    if (List_GetIndex((SortedList*)&services, &hService, &idx)) {
        free(services.items[idx]);
        List_Remove((SortedList*)&services, idx);
    }

    //LeaveCriticalSection(&csServices);
    return 0;
}

int ServiceExists(const char *name)
{
    int ret;
    if (name == NULL)
        return FALSE;

    //EnterCriticalSection( &csServices );
    ret = FindServiceByName(name) != NULL;
    //LeaveCriticalSection( &csServices );
    return ret;
}

int CallService(const char *name, uintptr_t pParam)
{
    TService *pService;
    NWNXSERVICE pfnService;
    int isParam;
    uintptr_t fnParam;

#ifdef _DEBUG
    if (name == NULL) {
        //MessageBoxA(0,"Someone tried to CallService(NULL,..) see stack trace for details","",0);
        //DebugBreak();
        return CALLSERVICE_NOTFOUND;
    }
#else
    if (name == NULL) return CALLSERVICE_NOTFOUND;
#endif

    //EnterCriticalSection(&csServices);
    pService = FindServiceByName(name);
    if (pService == NULL) {
        //LeaveCriticalSection(&csServices);
#ifdef _DEBUG
        //MessageBoxA(NULL,"Attempt to call non-existant service",name,MB_OK);
        //OutputDebugStringA("Missing service called: \t");
        //OutputDebugStringA(name);
        //OutputDebugStringA("\n");
#endif
        /*		{	MISSING_SERVICE_PARAMS params = { name, wParam, lParam };
        			int result = NotifyEventHooks(hMissingService,0,(LPARAM)&params);
        			if (result != 0)
        				return params.lParam;
        		} */
        return CALLSERVICE_NOTFOUND;
    }
    pfnService = pService->pfnService;
    isParam = pService->isParam;
    fnParam = pService->pParam;
    //LeaveCriticalSection(&csServices);
    if (isParam)
        return ((int (*)(uintptr_t, uintptr_t))pfnService)(pParam, fnParam);
    else
        return ((int (*)(uintptr_t))pfnService)(pParam);
}

void KillModuleServices(HINSTANCE hInst)
{
    int i;

    //EnterCriticalSection(&csServices);
    for (i = services.count - 1; i >= 0; i--) {
        if (services.items[i]->hOwner == hInst) {
            char szModuleName[ MAX_PATH ];
            /*GetModuleFileNameA( services.items[i]->hOwner, szModuleName, sizeof(szModuleName));
            Netlib_Logf( NULL, "A service function '%s' was abnormally deleted because module '%s' didn't released it",
            	services.items[i]->name, szModuleName );*/
            DestroyServiceFunction((HANDLE)services.items[i]->nameHash);
        }
    }

    //LeaveCriticalSection(&csServices);
}
