/*

Miranda IM: the free IM client for Microsoft* Windows*

Copyright 2000-2007 Miranda ICQ/IM project,
all portions of this codebase are copyrighted to the people
listed in contributors.txt.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef M_NEWPLUGINAPI_H__
#define M_NEWPLUGINAPI_H__

#include "typedef.h"

#define PLUGIN_MAKE_VERSION(a,b,c,d)   (((((DWORD)(a))&0xFF)<<24)|((((DWORD)(b))&0xFF)<<16)|((((DWORD)(c))&0xFF)<<8)|(((DWORD)(d))&0xFF))
#define MAXMODULELABELLENGTH 64

typedef struct {
	int cbSize;
	char *shortName;
	DWORD version;
	char *description; // [TRANSLATED-BY-CORE]
	char *author;
	char *authorEmail;
	char *copyright;
	char *homepage;
	BYTE flags;	   // 
} PLUGININFO;

#ifndef MODULES_H_
typedef int (*NWNXHOOK)(WPARAM,LPARAM);
typedef int (*NWNXSERVICE)(WPARAM,LPARAM);
typedef int (*NWNXSERVICEPARAM)(WPARAM,LPARAM,LPARAM);
#define CALLSERVICE_NOTFOUND      ((int)0x80000000)
#endif

//see modules.h for what all this stuff is
typedef struct {
	HANDLE (*CreateHookableEvent)(const char *);
	int (*DestroyHookableEvent)(HANDLE);
	int (*NotifyEventHooks)(HANDLE,WPARAM,LPARAM);
	HANDLE (*HookEvent)(const char *,NWNXHOOK);
	HANDLE (*HookEventMessage)(const char *,HWND,UINT);
	int (*UnhookEvent)(HANDLE);
	HANDLE (*CreateServiceFunction)(const char *,NWNXSERVICE);
	HANDLE (*CreateTransientServiceFunction)(const char *,NWNXSERVICE);
	int (*DestroyServiceFunction)(HANDLE);
	int (*CallService)(const char *,WPARAM,LPARAM);
	int (*ServiceExists)(const char *);		  //v0.1.0.1+
	int (*SetHookDefaultForHookableEvent) (HANDLE, NWNXHOOK); // v0.3.4 (2004/09/15)
} PLUGINLINK;

#ifndef MODULES_H_
#ifndef NODEFINEDLINKFUNCTIONS
//relies on a global variable 'pluginLink' in the plugins
extern PLUGINLINK *pluginLink;
#define CreateHookableEvent(a)               pluginLink->CreateHookableEvent(a)
#define DestroyHookableEvent(a)              pluginLink->DestroyHookableEvent(a)
#define NotifyEventHooks(a,b,c)              pluginLink->NotifyEventHooks(a,b,c)
#define HookEventMessage(a,b,c)              pluginLink->HookEventMessage(a,b,c)
#define HookEvent(a,b)                       pluginLink->HookEvent(a,b)
#define UnhookEvent(a)                       pluginLink->UnhookEvent(a)
#define CreateServiceFunction(a,b)           pluginLink->CreateServiceFunction(a,b)
#define CreateTransientServiceFunction(a,b)  pluginLink->CreateTransientServiceFunction(a,b)
#define DestroyServiceFunction(a)            pluginLink->DestroyServiceFunction(a)
#define CallService(a,b,c)                   pluginLink->CallService(a,b,c)
#define ServiceExists(a)                     pluginLink->ServiceExists(a)
#define SetHookDefaultForHookableEvent(a,b)  pluginLink->SetHookDefaultForHookableEvent(a,b)
#endif
#endif

#endif // M_NEWPLUGINAPI_H__
