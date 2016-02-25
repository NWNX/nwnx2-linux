/***************************************************************************
    NWNX FOR LINUX MAIN PROGRAM
    Copyright (C) 2003 by the APS/NWNX Linux Conversion Group
    (see README for further information)
    visit us at http://sourceforge.net/projects/apsnwnx/

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include <sys/types.h>
#include <sys/mman.h>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <dlfcn.h>
#include <dirent.h>
#include <errno.h>

using namespace std;
#include <string>
#include <map>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

//#include "typedef.h"

#include "commonheaders.h"
#include "NWNXBase.h"
#include "nx_hook.h"
//#include "modules.h"

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

static DWORD g_nwnxVersion = PLUGIN_MAKE_VERSION(2, 8, 0, 0);

//Modular engine
PLUGINLINK pluginCoreLink;
extern "C" int InitialiseModularEngine(void);
extern "C" void DestroyModularEngine(void);
//Hooks
HANDLE hPluginsLoadedEvent;
//Plugins
typedef int (* Plugin_Init)(PLUGINLINK *);
typedef PLUGININFO * (* Plugin_Info)(DWORD nwnxVersion);


typedef CNWNXBase* (*ClassObject)();
ClassObject GetClassObject;

static FILE *logFile = stdout;
static const char *logDir = NULL;
static const char *pluginDir = NULL;
static int debuglevel = 0;
static int xdbglevel = 1;
static int nwnxinitdisabled = 0;

// hashtable (ok, ok, a red-black tree)
static map<string, CNWNXBase*> Libraries;

const map<string, CNWNXBase*> & GetLoadedLibraries()
{
    return Libraries;
}

int GetCoreDebugLevel()
{
    return debuglevel;
}

void SetCoreDebugLevel(int level)
{
    debuglevel = level;
}

static unsigned char jmp_code[] = "\x68\x60\x70\x80\x90"	/* push dword 0x90807060 */
                                  "\xc3\x90\x90";		/* ret , nop , nop       */
static unsigned char ret_code_ss[0x20] asm("ret_code_ss");
static unsigned char ret_code_go[0x20] asm("ret_code_go");
static bool ObjRet = 0;
static unsigned long oRes asm("oRes");

static unsigned long o_esp asm("o_esp");
static unsigned long o_SetString, m_SetString;
static unsigned long o_GetObject;
static void (*o_SetStringFunc)(char **, char **);
static gline nwnxConfig;

// FIXME!!! hack
static char *gameObject = NULL;
static char *returnAddr = NULL;
static char *ObjReturnAddr = NULL;
static char gObjDummy[4096] = {};

// helper function prototype
static void Log(int priority, const char *pcMsg, ...);

static void
d_enable_write(unsigned long location)
{
    char *page;
    page = (char *) location;
    page = (char *)(((int) page + PAGESIZE - 1) & ~(PAGESIZE - 1));
    page -= PAGESIZE;

    if (mprotect(page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
        perror("mprotect");
}

static void
d_redirect(long from, long to, unsigned char *ret_code, long len = 0)
{
    // enable write to code pages
    d_enable_write(from);
    // copy orig code stub to our "ret_code"
    len = len ? len : sizeof(jmp_code) - 1; // - trailing 0x00
    memcpy((void *) ret_code, (const void *) from, len);
    // make ret code
    *(long *)(jmp_code + 1) = from + len;
    memcpy((char *) ret_code + len, (const void *) jmp_code, 6);
    // make hook code
    *(long *)(jmp_code + 1) = to;
    memcpy((void *) from, (const void *) jmp_code, 6);
}

static void
StringPayLoad(const char **ppname, const char **ppvalue)
{
    int iValueLength;
    int iResultLength;

    char *name = (char*)*ppname;
    char *value = (char*)*ppvalue;
    char *thisRetAddr = *(char **)(o_esp + 0x04);

    if (!name || !value)	// || !gameObject
        return;

    Log(5, "ret=0x%08x\n", thisRetAddr);
    Log(3, "name='%s'\n", name);
    Log(4, "value='%s'\n", value);

    if (strncmp(name, "NWNX!", 5) != 0) 	// not for us
        return;

    char* library = &name[5];
    if (!library) {
        Log(0, "* Library not specified.\n");
        return;
    }

    if (strncmp(library, "INIT", 4) == 0) {
        if (value[0] == '1') {
            // make sure this is only called _once_
            if (returnAddr == NULL) {
                // This is the return address that ExecCmdSetVar set
                returnAddr = thisRetAddr;
                Log(0, "INIT(S): valid ret=0x%08x\n", returnAddr);
            } else {
                Log(0, "INIT(S): reset ignored ret=0x%08x\n",
                    thisRetAddr);
            }
            // Protect us from getting called during saves
            value[0] = '0';

        } else {
            Log(1, "INIT(S): value!=1. No change to ret.\n");
        }
        return;
    }

    // if we're not enforcing NWNX!INIT usage, grab the context
    if (returnAddr == NULL && nwnxinitdisabled) {
        Log(0, "NWNX!INIT enforcement disabled, using 0x%08x\n", thisRetAddr);
        // This is the return address that (hopefully) ExecCmdSetVar set
        returnAddr = thisRetAddr;
    }

    // Make sure we're called by ExecCmdSetVar
    if (returnAddr == thisRetAddr) {
        // get the game object
        // * This is where CNWVirtualMachineCommands::ExecuteCommandSetVar()
        //   has left it.
        gameObject = *(char **)(o_esp + 0x30);
    } else {
        gameObject = gObjDummy;
        if (!returnAddr)
            Log(0, "FAILED: NWNX!INIT has not been initialized.\n");
        else
            Log(2, "REJECTED: (S) ret=0x%08x but we wanted ret=0x%08x!\n",
                *(char **)(o_esp + 0x04), returnAddr);
        return;
    }

    Log(5, "gobj=0x%08x\n", gameObject);

    char* function = strchr(library, '!');
    if (!function) {
        Log(0, "* Function not specified. library=%s\n", library);
        return;
    }

    // see if the library is already loaded
    *function = 0x0;
    CNWNXBase* pBase = NULL;
    if (Libraries.find(library) != Libraries.end()) {
        pBase = Libraries[library];
    }
    *function = '!';

    if (pBase != NULL) {
        Log(3, "* Library %s found: %08lX\n", library, pBase);
        Log(4, "* OnRequest address: %08lX\n", &CNWNXBase::OnRequest);
        // library found, handle the request
        iValueLength = strlen(value);
        char* pRes = pBase->OnRequest(gameObject, function + 1, value);
        if (pRes != NULL && pRes != value) {
            if (strncmp(library, "LETO", 4) != 0 &&
                    strncmp(library, "HASHSET", 7) != 0) {
                // copy result into nwn variable value while respecting the maximum size
                // new plugins
                iResultLength = strlen(pRes);
                if (iValueLength < iResultLength) {
                    free(value);
                    *ppvalue = pRes;
                    *((unsigned long *)ppvalue + 1) = strlen(pRes);
                } else {
                    strncpy(value, pRes, iResultLength);
                    *(value + iResultLength) = 0x0;
                    free(pRes);
                }
            } else {
                // copy result into nwn variable value while respecting the maximum size
                // legacy plugins
                iResultLength = strlen(pRes);
                if (iValueLength < iResultLength) {
                    strncpy(value, pRes, iValueLength);
                    *(value + iValueLength) = 0x0;
                } else {
                    strncpy(value, pRes, iResultLength);
                    *(value + iResultLength) = 0x0;
                }

            }
        }
    } else {
        Log(0, "* Library %s does not exist.\n", library);
    }
}

static void
ObjectPayLoad(const char **ppname)
{
    char *name = (char*)*ppname;
    char *thisObjRetAddr = *(char **)(o_esp + 0x04);

    if (!name)	// || !gameObject
        return;

    Log(5, "ret=0x%08x\n", thisObjRetAddr);
    Log(3, "name='%s'\n", name);
    if (strncmp(name, "NWNX!", 5) != 0) 	// not for us
        return;

    char* library = &name[5];
    if (!library) {
        Log(0, "* Library not specified.\n");
        return;
    }

    if (strncmp(library, "INIT", 4) == 0) {
        // make sure this is only called _once_
        if (ObjReturnAddr == NULL) {
            // This is the return address that ExecCmdSetVar set
            ObjReturnAddr = thisObjRetAddr;
            Log(0, "INIT(O): valid ret=0x%08x\n", ObjReturnAddr);
        } else {
            Log(0, "INIT(O): reset ignored ret=0x%08x\n",
                thisObjRetAddr);
        }
        return;
    }

    // if we're not enforcing NWNX!INIT usage, grab the context
    if (ObjReturnAddr == NULL && nwnxinitdisabled) {
        Log(0, "NWNX!INIT enforcement disabled, using 0x%08x\n", thisObjRetAddr);
        // This is the return address that (hopefully) ExecCmdSetVar set
        ObjReturnAddr = thisObjRetAddr;
    }

    // Make sure we're called by ExecCmdSetVar
    if (ObjReturnAddr == thisObjRetAddr) {
        // get the game object
        // * This is where CNWVirtualMachineCommands::ExecuteCommandSetVar()
        //   has left it.
        gameObject = *(char **)(o_esp + 0x20);
    } else {
        gameObject = gObjDummy;
        if (!ObjReturnAddr)
            Log(0, "FAILED: NWNX!INIT(O) has not been initialized.\n");
        else
            Log(2, "REJECTED: (O) ret=0x%08x but we wanted ret=0x%08x!\n",
                *(char **)(o_esp + 0x04), ObjReturnAddr);
        return;
    }

    Log(5, "gobj=0x%08x\n", gameObject);

    char* function = strchr(library, '!');
    if (!function) {
        Log(0, "* Function not specified. library=%s\n", library);
        return;
    }

    // see if the library is already loaded
    *function = 0x0;
    CNWNXBase* pBase = NULL;
    if (Libraries.find(library) != Libraries.end()) {
        pBase = Libraries[library];
    }
    *function = '!';

    if (pBase != NULL) {
        Log(3, "* Library %s found: %08lX\n", library, pBase);
        Log(4, "* OnRequest address: %08lX\n", &CNWNXBase::OnRequestObject);
        // library found, handle the request
        oRes = pBase->OnRequestObject(gameObject, function + 1);
        ObjRet = 1;
        return;
    } else {
        Log(0, "* Library %s does not exist.\n", library);
    }
}

void
LoadLibraries()
{
    DIR *dp;
    struct dirent *d;
    char *dot, key[32], fname[128];
    int i, len;

    CNWNXBase *pBase;
    void *handle;

    // search the local directory for all files matching
    // the pattern: 'nwnx_*.so'
    if ((dp = opendir(pluginDir)) == NULL) {
        // scream and shout
        Log(0, "Unable to scan local directory: %s\n", strerror(errno));
        return;
    }

    for (d = readdir(dp); d != NULL; d = readdir(dp)) {
        // does it have a '.' ?
        if ((dot = strrchr(d->d_name, '.')) == NULL)
            continue;
        // is the prefix "nwnx_" ?
        if (strncmp("nwnx_", d->d_name, 5) != 0)
            continue;
        // is the suffix ".so" ?
        if (strcmp(".so", dot) != 0)
            continue;

        // generate the collection key
        // is the key too long?
        if ((len = dot - & (d->d_name[5])) >= 32) {
            Log(0, "ERROR: %s: key too long.\n", key);
            continue;
        }

        strncpy(key, &(d->d_name[5]), len);
        key[len] = 0;
        // upcase it
        for (i = 0; i < len; i++)
            key[i] = toupper(key[i]);

        // Check nwnx2.ini to see if it's been disabled
        if (nwnxConfig.exists(key, "disabled") &&
                toupper(nwnxConfig[key]["disabled"].c_str()[0]) == 'Y') {
            Log(0, "CONFIG: [%s] plugin disabled.\n", key);
            continue;
        }

        sprintf(fname, "%s/%s", pluginDir, d->d_name);

        // load the library
        if ((handle = dlopen(fname, RTLD_NOW)) == NULL) {

            Log(0, "ERROR: dlopen: %s: %s\n" , fname, dlerror());
            exit(1);
        }

        // get the Class Accessor
        if ((GetClassObject = (ClassObject)dlsym(handle,
                              "GetClassObject")) == NULL) {
            Log(0, "ERROR: dlsym: %s: %s\n" , fname, dlerror());
            dlclose(handle);
            exit(1);
        }

        Plugin_Info getPluginInfo = (Plugin_Info) dlsym(handle, "GetPluginInfo");
        Plugin_Init initPlugin = (Plugin_Init) dlsym(handle, "InitPlugin");
        if (getPluginInfo && initPlugin)	{
            Log(1, "%s: Supports the new plugin interface\n" , key);
            PLUGININFO * pi = 0;
            int initResult;
            pi = getPluginInfo(g_nwnxVersion);
            if (!pi) {
                Log(0, "%s: The plugin returned NULL on GetPluginInfo: skipping\n" , key);
                continue;
            }
            if ((initResult = initPlugin(&pluginCoreLink)) != 0) {
                Log(0, "%s: The plugin returned %d on InitPlugin: skipping\n" , key, initResult);
                continue;
            }
        } else {
            //Log(3, "%s: Doesn't support the new plugin interface\n" ,key);
        }

        // Access the static instance
        if ((pBase = (*GetClassObject)()) == NULL) {
            Log(0, "ERROR: %s: GetClassObject returned NULL.\n", key);
            dlclose(handle);
            exit(1);
        }

        // initialize the plugin
        pBase->SetDebugLevel(debuglevel);

        if (!pBase->OnCreate(&nwnxConfig, logDir)) {
            Log(0, "ERROR: %s: OnCreate() failed.\n", key);
            dlclose(handle);
            exit(1);
        }

        // Register the plugin
        Libraries[key] = pBase;

        Log(0, "%s plugin registered.\n", key);
        Log(3, "Address: %08lX\n", pBase);
    }

    closedir(dp);
}

void
my_SetString(const char **s1, const char **s2, const char **s3)
{
    // NOTES:
    // * The function hooked is:
    //		CNWSScriptVarTable::SetString(CExoString&,CExoString&)
    // * Since it's a class memeber function, s1 is the pointer to the
    //   class instance.
    // * Relative to the windows version the data fields seem to be
    //   shifted up 1 DWORD
    // * The server binary is VERY touchy about the stack, just don't
    //   touch it.

    // get the stack pointer
    asm("movl %ebp, o_esp");

    // Execute payload
    StringPayLoad(s2, s3);

    // 1. correct frame pointer
    // 2. push s1 and s2 on stack
    // 3. push old_String + n bytes on stack
    // 4. ret

    // prolog of my_SetString
    //asm ("sub $0x8,%esp");
    //asm ("mov 0xffffffe8(%ebp),%ebx");
    //asm ("leave");

    // jmp back to original function
    asm("leave");
    asm("mov $ret_code_ss, %eax");
    asm("jmp *%eax");
}

void
my_GetObject(const char **s1, const char **s2)
{
    // NOTES:
    // * The function hooked is:
    //		CNWSScriptVarTable::SetString(CExoString&,CExoString&)
    // * Since it's a class memeber function, s1 is the pointer to the
    //   class instance.
    // * Relative to the windows version the data fields seem to be
    //   shifted up 1 DWORD
    // * The server binary is VERY touchy about the stack, just don't
    //   touch it.

    // get the stack pointer
    asm("movl %ebp, o_esp");

    // Execute payload
    ObjectPayLoad(s2);

    // 1. correct frame pointer
    // 2. push s1 and s2 on stack
    // 3. push old_String + n bytes on stack
    // 4. ret
    asm("leave");
    if (ObjRet) {
        ObjRet = 0;
        asm("mov oRes, %eax");
        asm("ret");
    }
    asm("mov $ret_code_go, %eax");
    asm("jmp *%eax");
}

static void Configure()
{
    FILE *logfp;
    char logfqpn[256];
    const char *logfilename;

    // Directory to stuff plugin logfiles
    if (nwnxConfig.exists("LogDir", "logdir")) {
        logDir = (char*)(nwnxConfig["LogDir"]["logdir"].c_str());
    } else {
        printf("CONFIG: nwnx2.ini: [LogDir]logdir is missing!  Using current directory\n");
        logDir = ".";
    }

    // Logfilename
    if (nwnxConfig.exists("NWNX", "logfile")) {
        logfilename = (char*)(nwnxConfig["NWNX"]["logfile"].c_str());
    } else {
        logfilename = "nwnx2.txt";
    }

    if (nwnxConfig.exists("NWNX", "plugindir")) {
        pluginDir = (char*)(nwnxConfig["NWNX"]["plugindir"].c_str());
    } else {
        pluginDir = ".";
    }

    // Global debug level
    if (nwnxConfig.exists("Debug", "debuglevel")) {
        debuglevel = atoi(nwnxConfig["Debug"]["debuglevel"].c_str());
    }

    // Extender debug level
    if (nwnxConfig.exists("NWNX", "debuglevel")) {
        xdbglevel = atoi(nwnxConfig["NWNX"]["debuglevel"].c_str());
    } else {
        xdbglevel = debuglevel;
    }

    // Turn off NWNX!INIT enforcement
    if (nwnxConfig.exists("NWNX", "disablenwnxinit") &&
            toupper(nwnxConfig["NWNX"]["disablenwnxinit"].c_str()[0]) == 'Y') {
        nwnxinitdisabled = 1;
    }

    // create Fully Qualified Path Name
    sprintf(logfqpn, "%s/%s", logDir, logfilename);

    // open it for writing
    if ((logfp = fopen(logfqpn, "w")) == NULL) {
        printf("WARNING! Unable to open \"%s\" for write, using stdout\n",
               logfqpn);
    } else {
        logFile = logfp;
    }

}

// finds the address of the CNWSScriptVarTable::SetString function
static unsigned long
FindStringHook()
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr) {
        if ((ptr[0] == (char) 0x55) &&
                (ptr[1] == (char) 0x89) &&
                (ptr[2] == (char) 0xe5) &&
                (ptr[3] == (char) 0x53) &&
// Removed the comparison for ptr[4]
// The 1.64 patch compilation chose a different register to save
                (ptr[5] == (char) 0x8b) &&
                (ptr[6] == (char) 0x5d) &&
                (ptr[7] == (char) 0x10) &&
                (ptr[8] == (char) 0x6a) &&
                (ptr[9] == (char) 0x01) &&
                (ptr[10] == (char) 0x6a) && (ptr[11] == (char) 0x03))
            return (unsigned long) ptr;
        else
            ptr++;
    }
    return 0;
}

// finds the address of the CNWSScriptVarTable::GetObject function
static unsigned long
FindObjectHook()
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr) {
        if ((ptr[0] == (char) 0x55) &&
                (ptr[1] == (char) 0x89) &&
                (ptr[2] == (char) 0xe5) &&
                (ptr[3] == (char) 0x53) &&
// Removed the comparison for ptr[4]
// The 1.64 patch compilation chose a different register to save
                (ptr[5] == (char) 0x6a) &&
                (ptr[6] == (char) 0x00) &&
                (ptr[7] == (char) 0x6a) &&
                (ptr[8] == (char) 0x04))
            return (unsigned long) ptr;
        else
            ptr++;
    }
    return 0;
}

//
static void Log(int priority, const char *pcMsg, ...)
{
    va_list argList;
    char acBuffer[2048];

    if (logFile && priority <= xdbglevel) {
        // build up the string
        va_start(argList, pcMsg);
        vsnprintf(acBuffer, 2047, pcMsg, argList);
        acBuffer[2047] = 0;
        va_end(argList);

        // log string in file
        fprintf(logFile, "%s", acBuffer);
        fflush(logFile);
    }

    if (priority == 0 && logFile != stdout) {
        printf("%s", acBuffer);
    }
}

void LoadCoreModule()
{
    pluginCoreLink.CallService = CallService;
    pluginCoreLink.ServiceExists = ServiceExists;
    pluginCoreLink.CreateServiceFunction = CreateServiceFunction;
    pluginCoreLink.CreateTransientServiceFunction = CreateServiceFunction;
    pluginCoreLink.DestroyServiceFunction = DestroyServiceFunction;
    pluginCoreLink.CreateHookableEvent = CreateHookableEvent;
    pluginCoreLink.DestroyHookableEvent = DestroyHookableEvent;
    pluginCoreLink.HookEvent = HookEvent;
    pluginCoreLink.UnhookEvent = UnhookEvent;
    pluginCoreLink.NotifyEventHooks = NotifyEventHooks;
    pluginCoreLink.NotifyEventHooksNotAbortable = NotifyEventHooksNotAbortable;
    pluginCoreLink.SetHookDefaultForHookableEvent = SetHookDefaultForHookableEvent;
    pluginCoreLink.GetCurrentEventName = GetCurrentEventName;
    pluginCoreLink.SetHookInitializer = SetHookInitializer;
    pluginCoreLink.HookEventOptionally = HookEventOptionally;
    //pluginCoreLink.NotifyEventHooksDirect=CallHookSubscribers;

    hPluginsLoadedEvent = CreateHookableEvent(EVENT_CORE_PLUGINSLOADED);
}

class startstop
{
public:
    startstop();
    ~startstop();
};

startstop::startstop()
{
    nwnxConfig.open("nwnx2.ini");

    printf("\n");
    printf("NWNX2lib: Init\n");
    InitialiseModularEngine();
    LoadCoreModule();
    o_SetString = FindStringHook();
    o_GetObject = FindObjectHook();

    m_SetString = (unsigned long) my_SetString;
    o_SetStringFunc = (void (*)(char **, char **)) o_SetString;

    printf("NWNX2lib: org SetString() at %lx, new SetString() at %lx\n",
           o_SetString, m_SetString);
    printf("NWNX2lib: org GetObj() at %lx, new GetObj() at %lx\n",
           o_GetObject, (unsigned long) my_GetObject);

    d_redirect(o_SetString, m_SetString, ret_code_ss, 10);
    d_redirect(o_GetObject, (unsigned long) my_GetObject, ret_code_go, 9);

    printf("* Parsing configuration...\n");
    Configure();

    // banner
    Log(0, "NWN Extender v2.8-dev\n");
    Log(1, "--------------------------------\n");
    printf("(c) 2004 by the APS/NWNX Linux Conversion Group\n");
    printf("(c) 2007-2010 by virusman and Acaos\n");
    printf("Based on the Win32 version (c) 2003 by Ingmar Stieger (Papillon)\n");
    printf("and Jeroen Broekhuizen\n");
    printf("visit us at http://www.avlis.org\n\n");

    printf("* Searching for signatures...\n");
    nwn_hook_init();

    printf("* Loading modules...\n");
    LoadLibraries();
    Core_Init(&pluginCoreLink);
    NotifyEventHooksNotAbortable(hPluginsLoadedEvent, 0);

    // log & emit
    Log(0, "* NWNX2 activated.\n");
}

startstop::~startstop()
{
    printf("NWNX2lib: Server exiting.\n");
    DestroyModularEngine();
}

startstop __loadit;
