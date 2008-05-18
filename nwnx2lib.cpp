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

#include "gline.h"
#include "NWNXBase.h"

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

typedef CNWNXBase* (*ClassObject)();
ClassObject GetClassObject;

FILE *logFile = stdout;
char *logDir = NULL;
char logFileName[18] = {0};
int debuglevel = 0;
int xdbglevel = 1;
int nwnxinitdisabled = 0;

// hashtable (ok, ok, a red-black tree)
map<string, CNWNXBase*> Libraries;

unsigned char jmp_code[] = "\x68\x60\x70\x80\x90"	/* push dword 0x90807060 */
    "\xc3\x90\x90";		/* ret , nop , nop       */

unsigned long o_esp;
unsigned long o_SetString, m_SetString;
void (*o_SetStringFunc) (char **, char **);
gline nwnxConfig;

// FIXME!!! hack
char *gameObject = NULL;
char *returnAddr = NULL;
char gObjDummy[4096] = {};

// helper function prototype
void Log(int priority, const char *pcMsg, ...);

void
setaddr (unsigned char *buf, long addy)
{
    *(buf) = addy;
    *(buf + 1) = addy >> 8;
    *(buf + 2) = addy >> 16;
    *(buf + 3) = addy >> 24;
}

void
redirect (long from, long to)
{
    setaddr (jmp_code + 1, to);
    memcpy ((void *) from, (const void *) jmp_code, sizeof (jmp_code));
    o_SetString += 10;
}

void
PayLoad(const char **ppname, const char **ppvalue)
{
	int iValueLength;
	int iResultLength;

	char *name= (char*)*ppname;
	char *value= (char*)*ppvalue;
	char *thisRetAddr= *(char **)(o_esp+0x04);

	if (!name || !value)	// || !gameObject
		return;

	Log(5,"ret=0x%08x\n",thisRetAddr);
	Log(3,"name='%s'\n",name);
	Log(4,"value='%s'\n",value);

	if (strncmp(name, "NWNX!", 5) != 0) 	// not for us
		return;

	char* library = &name[5];
	if (!library)
	{
		Log(0, "* Library not specified.\n");
		return;
	}

	if(strncmp(library,"INIT",4)==0) {
		if(value[0]=='1') {
			// make sure this is only called _once_
			if(returnAddr == NULL) {
				// This is the return address that ExecCmdSetVar set
				returnAddr= thisRetAddr;
				Log(0,"INIT: valid ret=0x%08x\n",returnAddr);
			} else {
				Log(0,"INIT: reset ignored ret=0x%08x\n",
					thisRetAddr);
			}
			// Protect us from getting called during saves
			value[0]='0';

		} else {
			Log(1,"INIT: value!=1. No change to ret.\n");
		}
		return;
	}

	// if we're not enforcing NWNX!INIT usage, grab the context
	if(returnAddr == NULL && nwnxinitdisabled) {
		Log(0,"NWNX!INIT enforcement disabled, using 0x%08x\n",thisRetAddr);
		// This is the return address that (hopefully) ExecCmdSetVar set
		returnAddr = thisRetAddr;
	}

	// Make sure we're called by ExecCmdSetVar
	if(returnAddr == thisRetAddr) {
		// get the game object
		// * This is where CNWVirtualMachineCommands::ExecuteCommandSetVar()
		//   has left it.
		gameObject= *(char **)(o_esp+0x30);
	} else {
		gameObject= gObjDummy;
		if(!returnAddr)
			Log(0,"FAILED: NWNX!INIT has not been initialized.\n");
		else
			Log(2,"REJECTED: ret=0x%08x but we wanted ret=0x%08x!\n", 
				*(char **)(o_esp+0x04), returnAddr);
		return;
	}

	Log(5,"gobj=0x%08x\n", gameObject);

	char* function = strchr(library, '!');
	if (!function)
	{
		Log(0,"* Function not specified. library=%s\n",library);
		return;
	}

	// see if the library is already loaded
	*function = 0x0;
	CNWNXBase* pBase = NULL;
	if(Libraries.find(library)!=Libraries.end()) {
		pBase= Libraries[library];
	}
	*function = '!';

	if (pBase != NULL)
	{
		// library found, handle the request
		iValueLength = strlen(value);
		const char* pRes = pBase->OnRequest(gameObject, function + 1, value);
		if (pRes != NULL)
		{
			// copy result into nwn variable value while respecting the maximum size
			iResultLength = strlen(pRes);
			if (iValueLength < iResultLength)
			{
				strncpy(value, pRes, iValueLength);
				*(value+iValueLength) = 0x0;
			}
			else
			{
				strncpy(value, pRes, iResultLength);
				*(value+iResultLength) = 0x0;
			}
		}
	}
	else {
		Log(0, "* Library %s does not exist.\n", library);
	}
}

void
LoadLibraries() {
	DIR *dp;
	struct dirent *d;
	char *dot, key[32], fname[128];
	int i,len;

	CNWNXBase *pBase;
	void *handle;

	// search the local directory for all files matching
	// the pattern: 'nwnx_*.so'
	if((dp=opendir("."))==NULL) {
		// scream and shout
		Log(0, "Unable to scan local directory: %s\n", strerror(errno));
		return;
	}
	
	for(d=readdir(dp); d!=NULL; d=readdir(dp)) {
		// does it have a '.' ?
		if((dot=strrchr(d->d_name,'.'))==NULL)
			continue;
		// is the prefix "nwnx_" ?
		if(strncmp("nwnx_",d->d_name,5)!=0)
			continue;
		// is the suffix ".so" ?
		if(strcmp(".so",dot)!=0)
			continue;

		// generate the collection key
		// is the key too long?
		if((len= dot-&(d->d_name[5]))>=32) {
			Log(0, "ERROR: %s: key too long.\n", key);
			continue;
		}
			
		strncpy(key, &(d->d_name[5]), len);
		key[len]=0;
		// upcase it
		for(i=0; i<len; i++)
			key[i]= toupper(key[i]);

		// Check nwnx2.ini to see if it's been disabled
		if(nwnxConfig.exists(key,"disabled") && 
		   toupper(nwnxConfig[key]["disabled"].c_str()[0])=='Y') {
			Log(0, "CONFIG: [%s] plugin disabled.\n", key);
			continue;
		}

		sprintf(fname,"./%s",d->d_name);

		// load the library
		if((handle = dlopen(fname, RTLD_NOW))==NULL) {
			
			Log(0, "ERROR: dlopen: %s: %s\n" ,fname, dlerror());
			continue;
		}

		// get the Class Accessor
		if((GetClassObject = (ClassObject)dlsym(handle,
												"GetClassObject"))==NULL) {
			Log(0, "ERROR: dlsym: %s: %s\n" ,fname, dlerror());
			dlclose(handle);
			continue;
		}

		// Access the static instance
		if((pBase = (*GetClassObject)()) == NULL ) {
			Log(0, "ERROR: %s: GetClassObject returned NULL.\n",key);
			dlclose(handle);
			continue;
		}

		// initialize the plugin
		pBase->SetDebugLevel(debuglevel);

		if(!pBase->OnCreate(&nwnxConfig,logDir)) {
			Log(0, "ERROR: %s: OnCreate() failed.\n",key);
			dlclose(handle);
			continue;
		}

		// Register the plugin
		Libraries[key] = pBase;

		Log(0, "%s plugin Registerred.\n",key);
	}

	closedir(dp);
}

void
my_SetString (const char **s1, const char **s2, const char **s3)
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
	asm ("movl %ebp, o_esp");
	
    // Execute payload
    PayLoad(s2,s3);

    // 1. correct frame pointer
    // 2. push s1 and s2 on stack
    // 3. push old_String + n bytes on stack
    // 4. ret

    // prolog of my_SetString
    asm ("sub $0x8,%esp");
    asm ("mov 0xffffffe8(%ebp),%ebx");
    asm ("leave");

    // execute head of original function
    asm ("push %ebp");
    asm ("mov %esp, %ebp");
    asm ("push %ebx");
    asm ("push %ebx");
    asm ("mov 0x10(%ebp), %ebx");
    asm ("push $0x1");

    // jmp back to original function
    asm ("mov o_SetString, %eax");
    asm ("push %eax");
    asm ("ret");
}

void
enable_write (unsigned long location)
{
    char *page;
    page = (char *) location;
    page = (char *) (((int) page + PAGESIZE - 1) & ~(PAGESIZE - 1));
    page -= PAGESIZE;

    if (mprotect (page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
	perror ("mprotect");
}

void Configure() {
	FILE *logfp;
	char *logfilename,logfqpn[256];

	// Directory to stuff plugin logfiles
	if(nwnxConfig.exists("LogDir","logdir")) {
		logDir = (char*)(nwnxConfig["LogDir"]["logdir"].c_str());
	} else {
		printf("CONFIG: nwnx2.ini: [LogDir]logdir is missing!  Using current directory\n");
		logDir = ".";
	}

	// Logfilename
	if(nwnxConfig.exists("NWNX","logfile")) {
		logfilename= (char*)(nwnxConfig["NWNX"]["logfile"].c_str());
	} else {
		logfilename= "nwnx2.txt";
	}

	// Global debug level
	if(nwnxConfig.exists("Debug","debuglevel")) {
		debuglevel = atoi(nwnxConfig["Debug"]["debuglevel"].c_str());
	}

	// Extender debug level
	if(nwnxConfig.exists("NWNX","debuglevel")) {
		xdbglevel = atoi(nwnxConfig["NWNX"]["debuglevel"].c_str());
	} else {
		xdbglevel = debuglevel;
	}

	// Turn off NWNX!INIT enforcement
	if(nwnxConfig.exists("NWNX","disablenwnxinit") &&
	   toupper(nwnxConfig["NWNX"]["disablenwnxinit"].c_str()[0])=='Y') {
		nwnxinitdisabled=1;
	}

	// create Fully Qualified Path Name
	sprintf(logfqpn,"%s/%s",logDir,logfilename);

	// open it for writing
	if((logfp=fopen(logfqpn,"w"))==NULL) {
		printf("WARNING! Unable to open \"%s\" for write, using stdout\n",
			   logfqpn);
	} else {
		logFile = logfp;
	}

}

// finds the address of the CNWSScriptVarTable::SetString function
unsigned long
FindHook ()
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr)
    {
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

// 
void Log(int priority, const char *pcMsg, ...)
{
	va_list argList;
	char acBuffer[2048];

	if (logFile && priority<=xdbglevel)
	{  
		// build up the string
		va_start(argList, pcMsg);
		vsnprintf(acBuffer, 2047, pcMsg, argList);
		acBuffer[2047]= 0;
		va_end(argList);

		// log string in file
		fprintf (logFile, acBuffer);
		fflush (logFile);
	}

	if(priority==0 && logFile != stdout)
	{
		printf(acBuffer);
	}
}

class startstop {
public:
	startstop();
	~startstop();
};

// extern "C" void
// _init ()

startstop::startstop()
{
    nwnxConfig.open("nwnx2.ini");

    printf ("\n");
    printf ("NWNX2lib: Init\n");
    o_SetString = FindHook ();

    m_SetString = (unsigned long) my_SetString;
    o_SetStringFunc = (void (*)(char **, char **)) o_SetString;

    printf ("NWNX2lib: org SetString() at %p, new SetString() at %p\n",
	    o_SetString, m_SetString);

    enable_write (o_SetString);
    redirect (o_SetString, m_SetString);

	printf("* Parsing configuration...\n");
	Configure();

	// banner
	Log(0,"NWN Extender v2.5.3-rc1\n");
	Log(1,"--------------------------------\n");
	printf("(c) 2004 by the APS/NWNX Linux Conversion Group\n");
	printf("Based on the Win32 version (c) 2003 by Ingmar Stieger (Papillon)\n");
	printf("and Jeroen Broekhuizen\n");
	printf("visit us at http://www.avlis.org\n\n");

	printf("* Loading modules...\n");
	LoadLibraries();

	// log & emit
	Log(0,"* NWNX2 activated.\n");
}

// extern "C" void
// _fini ()

startstop::~startstop()
{
    printf ("NWNX2lib: Server exiting.\n");
}

startstop __loadit;
