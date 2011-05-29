/***************************************************************************
    nocharlist plugin for NWNX  - hooks implementation
    (c) 2007 Zebranky

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

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "nocharlistHooks.h"
#include "NWNXnocharlist.h"
#include "NWNStructures.h"
#include "AssemblyHelper.cpp"

extern CNWNXnocharlist nocharlist;
AssemblyHelper asmhelp;

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

int FindHookFunctions()
{
	char *pPlayModCharList = (char *) asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 14 8B 5D 08 8B 7D 0C 0F B6 75 10 6A 01 53");
	nocharlist.Log(2, "pPlayModCharList: %08lX\n", pPlayModCharList);

	if(pPlayModCharList && *pPlayModCharList == (char)0x55)
	{
		d_enable_write((dword) pPlayModCharList);
		pPlayModCharList[0x00] = (char)0xC2;
		pPlayModCharList[0x01] = (char)0x0C;
		pPlayModCharList[0x02] = (char)0x00;
		nocharlist.Log(2, "* Suppressing character list response.\n");
	}

	if(!(pPlayModCharList))
	{
		nocharlist.Log(2, "Some of the functions could not be found\n");
		return false;
	}
	nocharlist.Log(2, "All functions set\n");
	return true;
}
