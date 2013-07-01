#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/time.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "NWNXRedis.h"
#include "NWNStructures.h"
#include "HookFunc.h"

extern CNWNXRedis Redis;

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */

unsigned char d_ret_code_loop[0x20];

void (*pRunScript)(void *pScriptMachine, CExoString *script_name, dword ObjID, int arg_4);
char scriptRun;
void **pVirtualMachine = (void **) 0x0832F1EC;

int (*CServerExoApp__MainLoopInner)(void *pServer);

//extern bool redis__eventsAvailable;

int CServerExoApp__MainLoopInner_hook(void *pServer) {
	int ret = CServerExoApp__MainLoopInner(pServer);

	if (Redis.eventsAvailable) {
		RunScript(Redis.pubsubscript, 0);
		Redis.eventsAvailable = false;
	}

	return ret;
}

void RunScript(char * sname, int ObjID) {
    CExoString script_name;
    script_name.Text = sname;
    script_name.Length = strlen(sname);
    scriptRun = 1;
    pRunScript(*(dword **)pVirtualMachine, &script_name, ObjID, 1);
    scriptRun = 0;
}

void d_enable_write (unsigned long location) {
    char *page;
    page = (char *) location;
    page = (char *) (((int) page + PAGESIZE - 1) & ~(PAGESIZE - 1));
    page -= PAGESIZE;

    if (mprotect (page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
	perror ("mprotect");
}

int intlen = -1;

void d_redirect (long from, long to, unsigned char *d_ret_code, long len=0) {
    // enable write to code pages
    d_enable_write (from);
    // copy orig code stub to our "ret_code"
    len = len ? len : sizeof(d_jmp_code)-1; // - trailing 0x00
    intlen = len;
    memcpy ((void *) d_ret_code, (const void *) from, len);
    // make ret code
    *(long *)(d_jmp_code + 1) = from + len;
    memcpy ((char *) d_ret_code + len, (const void *) d_jmp_code, 6);
    // make hook code
    *(long *)(d_jmp_code + 1) = to;
    memcpy ((void *) from, (const void *) d_jmp_code, 6);
}

int HookFunctions() {
	*(dword*)&pRunScript = 0x8261f94;

	//0x080A0474: inner loop
	//0x080B2050: main loop from opt
	*(dword*)&CServerExoApp__MainLoopInner = 0x080B2050;
	d_redirect((unsigned long)CServerExoApp__MainLoopInner, (unsigned long)CServerExoApp__MainLoopInner_hook, d_ret_code_loop, 9);
	*(dword*)&CServerExoApp__MainLoopInner = (dword)&d_ret_code_loop;

	return 1;
}
