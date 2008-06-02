/***************************************************************************
    Ruby plugin for NWNX  - hooks implementation
    (c) 2007 virusman (virusman@virusman.ru)

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
#include <dlfcn.h>
#include <stdarg.h>
#include <time.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "FunctionHooks.h"
#include "NWNXRuby.h"
#include "AssemblyHelper.cpp"

extern CNWNXRuby ruby;
AssemblyHelper asmhelp;

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */

unsigned char d_ret_code_sm[0x20];
unsigned char d_ret_code_sdm[0x20];

unsigned long lastRet;
bool bReturn = 0;

dword **g_pVirtualMachine;


////////////////////////////////////////////////////////////////////
// FUNCTIONS
////////////////////////////////////////////////////////////////////

int (*CNWVirtualMachineCommands_ExecuteCommand)(void *pCommands, dword nCommandID, int arg_8);
int (*CVirtualMachine_StackPopInteger)(void *pVM, int *buf);
int (*CVirtualMachine_StackPopString)(void *pVM, CExoString *buf);
int (*CVirtualMachine_StackPopObject)(void *pVM, dword *buf);
int (*CVirtualMachine_StackPopFloat)(void *pVM, float *buf);

int (*CVirtualMachine_StackPushInteger)(void *pVM, int value);
int (*CVirtualMachine_StackPushFloat)(void *pVM, float value);
int (*CVirtualMachine_StackPushString)(void *pVM, CExoString *value);
int (*CVirtualMachine_StackPushObject)(void *pVM, dword value);

void
d_enable_write (unsigned long location)
{
	char *page;
	page = (char *) location;
	page = (char *) (((int) page + PAGESIZE - 1) & ~(PAGESIZE - 1));
	page -= PAGESIZE;

	if (mprotect (page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
		perror ("mprotect");
}

int intlen = -1;

void
d_redirect (long from, long to, unsigned char *d_ret_code, long len=0)
{
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

int StackPopInteger(int *buf)
{
	return CVirtualMachine_StackPopInteger(*g_pVirtualMachine, buf);
}

int StackPopString(char *buf)
{
	return CVirtualMachine_StackPopString(*g_pVirtualMachine, (CExoString *) &buf);
}

int StackPopObject(dword *buf)
{
	return CVirtualMachine_StackPopObject(*g_pVirtualMachine, buf);
}

int StackPopFloat(float *buf)
{
	return CVirtualMachine_StackPopFloat(*g_pVirtualMachine, buf);
}

int StackPushInteger(int value)
{
	return CVirtualMachine_StackPushInteger(*g_pVirtualMachine, value);
}

int StackPushFloat(float value)
{
	return CVirtualMachine_StackPushFloat(*g_pVirtualMachine, value);
}

int StackPushString(char *value)
{
	return CVirtualMachine_StackPushString(*g_pVirtualMachine, (CExoString *) &value);
}

int StackPushObject(dword value)
{
	return CVirtualMachine_StackPushObject(*g_pVirtualMachine, value);
}


void *GetCommandsPtr()
{
	return *(void **)(*(dword *)(g_pVirtualMachine) + 0x398);
}

void VM_ExecuteCommand(dword nCommandID)
{
	int nCurrYear;
	CNWVirtualMachineCommands_ExecuteCommand(GetCommandsPtr(), 0x7, 0); //GetCalendarYear
	CVirtualMachine_StackPopInteger(*g_pVirtualMachine, &nCurrYear);
	ruby.Log(0, "GetCalendarYear: %d\n", nCurrYear);

	CNWVirtualMachineCommands_ExecuteCommand(GetCommandsPtr(), nCommandID, 0);
	dword nObjID;
	int nRetVal;
	if(nCommandID == 0xD)
	{
		CVirtualMachine_StackPopInteger(*g_pVirtualMachine, &nRetVal);
		ruby.Log(0, "Command %d executed: %d\n", nCommandID, nRetVal);

	}
	else
	{
		CVirtualMachine_StackPopObject(*g_pVirtualMachine, &nObjID);
		ruby.Log(0, "Command %d executed: %d\n", nCommandID, nObjID);
	}
}

int HookFunctions()
{
	/*dword CExoNetInternal_StoreMessage = 
	if(CExoNetInternal_StoreMessage) d_redirect (CExoNetInternal_StoreMessage, (unsigned long)StoreMessage, d_ret_code_sm, 9);*/
	
	*(dword*)&CNWVirtualMachineCommands_ExecuteCommand = 0x082319C0;

	*(dword*)&CVirtualMachine_StackPopInteger = 0x08262988;
	*(dword*)&CVirtualMachine_StackPopString = 0x08262BA4;
	*(dword*)&CVirtualMachine_StackPopObject = 0x08262D88;
	*(dword*)&CVirtualMachine_StackPopFloat = 0x08262A64;

	*(dword*)&CVirtualMachine_StackPushInteger = 0x082642D8;
	*(dword*)&CVirtualMachine_StackPushFloat = 0x08264314;
	*(dword*)&CVirtualMachine_StackPushString = 0x082643BC;
	*(dword*)&CVirtualMachine_StackPushObject = 0x082644A0;

	InitConstants();

	ruby.Log(2, "All functions set\n");
	return true;
}

void InitConstants()
{
	*(dword*)&g_pVirtualMachine = 0x0832E1CC;
}

