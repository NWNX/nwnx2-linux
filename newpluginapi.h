#pragma once

#include "typedef.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_MAKE_VERSION(a,b,c,d) (((((DWORD)(a))&0xFF)<<24)|((((DWORD)(b))&0xFF)<<16)|((((DWORD)(c))&0xFF)<<8)|(((DWORD)(d))&0xFF))

typedef struct {
    int cbSize;
    char *shortName;
    DWORD version;
    char *description;
    char *author;
    char *authorEmail;
    char *copyright;
    char *homepage;
    BYTE flags;
} PLUGININFO;

#ifndef MODULES_H_
typedef int (*NWNXHOOK)(uintptr_t);
typedef int (*NWNXSERVICE)(uintptr_t);
typedef int (*NWNXSERVICEPARAM)(uintptr_t, uintptr_t);
#define CALLSERVICE_NOTFOUND ((int)0x80000000)
#endif

//see modules.h for what all this stuff is
typedef struct {
    HANDLE(*CreateHookableEvent)(const char *);
    int (*DestroyHookableEvent)(HANDLE);
    int (*NotifyEventHooks)(HANDLE, uintptr_t);
    void (*NotifyEventHooksNotAbortable)(HANDLE, uintptr_t);
    HANDLE(*HookEvent)(const char *, NWNXHOOK);
    HANDLE(*HookEventMessage)(const char *, HWND, UINT);
    int (*UnhookEvent)(HANDLE);
    HANDLE(*CreateServiceFunction)(const char *, NWNXSERVICE);
    HANDLE(*CreateTransientServiceFunction)(const char *, NWNXSERVICE);
    int (*DestroyServiceFunction)(HANDLE);
    int (*CallService)(const char *, uintptr_t);
    int (*ServiceExists)(const char *);       //v0.1.0.1+
    int (*SetHookDefaultForHookableEvent)(HANDLE, NWNXHOOK);  // v0.3.4 (2004/09/15)
    const char* (*GetCurrentEventName)();
    int (*SetHookInitializer)(HANDLE hEvent, NWNXHOOK pfnIntialize);
    HANDLE(*HookEventOptionally)(const char *, NWNXHOOK);
} PLUGINLINK;

#ifndef MODULES_H_
#ifndef NODEFINEDLINKFUNCTIONS
//relies on a global variable 'pluginLink' in the plugins
extern PLUGINLINK *pluginLink;
#define CreateHookableEvent(a)               pluginLink->CreateHookableEvent(a)
#define DestroyHookableEvent(a)              pluginLink->DestroyHookableEvent(a)
#define NotifyEventHooks(a,b)                pluginLink->NotifyEventHooks(a,b)
#define NotifyEventHooksNotAbortable(a,b)    pluginLink->NotifyEventHooksNotAbortable(a,b)
#define HookEventMessage(a,b,c)              pluginLink->HookEventMessage(a,b,c)
#define HookEvent(a,b)                       pluginLink->HookEvent(a,b)
#define HookEventOptionally(a,b)             pluginLink->HookEventOptionally(a,b)
#define UnhookEvent(a)                       pluginLink->UnhookEvent(a)
#define CreateServiceFunction(a,b)           pluginLink->CreateServiceFunction(a,b)
#define CreateTransientServiceFunction(a,b)  pluginLink->CreateTransientServiceFunction(a,b)
#define DestroyServiceFunction(a)            pluginLink->DestroyServiceFunction(a)
#define CallService(a,b)                     pluginLink->CallService(a,b)
#define ServiceExists(a)                     pluginLink->ServiceExists(a)
#define SetHookDefaultForHookableEvent(a,b)  pluginLink->SetHookDefaultForHookableEvent(a,b)
#define GetCurrentEventName()                pluginLink->GetCurrentEventName()
#define SetHookInitializer(a,b)              pluginLink->SetHookInitializer(a,b)

#endif
#endif

