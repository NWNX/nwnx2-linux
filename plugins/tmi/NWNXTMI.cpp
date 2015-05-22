
/***************************************************************************
    NWNXTMI.cpp - Implementation of the CNWNXTMI class.
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

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

#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/mman.h>

#include <dlfcn.h>

#include <limits.h>             /* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "NWNXTMI.h"

//////////////////////////////////////////////////////////////////////
// Hooks
//////////////////////////////////////////////////////////////////////

/* 8D F7 1D 00 00 8B 55 08  8B 42 08 40 3D FF FF 01 */
unsigned long FindTMILimit()
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;

    char *ptr = (char *)start_addr;

    while (ptr < (char *)end_addr) {
        if (ptr[0x0] == (char)0x8d &&
                ptr[0x1] == (char)0xf7 &&
                ptr[0x2] == (char)0x1d &&
                ptr[0x3] == (char)0x00 &&
                ptr[0x4] == (char)0x00 &&
                ptr[0x5] == (char)0x8b &&
                ptr[0x6] == (char)0x55 &&
                ptr[0x7] == (char)0x08 &&
                ptr[0x8] == (char)0x8b &&
                ptr[0x9] == (char)0x42 &&
                ptr[0xa] == (char)0x08 &&
                ptr[0xb] == (char)0x40 &&
                ptr[0xc] == (char)0x3d &&
                ptr[0xd] == (char)0xff &&
                ptr[0xe] == (char)0xff &&
                ptr[0xf] == (char)0x01)
            return (unsigned long)(ptr + 13);
        else
            ptr++;
    }

    return 0;
}

static void enable_write(unsigned long location)
{
    char *page;

    page = (char *)location;
    page = (char *)(((int)page + PAGESIZE - 1) & ~(PAGESIZE - 1));
    page -= PAGESIZE;

    if (mprotect(page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
        perror("mprotect");
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXTMI::CNWNXTMI()
{
    confKey = "TMI";

    orig_TMI = 0;
}

CNWNXTMI::~CNWNXTMI()
{
}

void CNWNXTMI::GetTMILimit(char *value)
{
    int lim = 0;

    lim |= *((unsigned char *)(orig_TMI + 2)) << 16;
    lim |= *((unsigned char *)(orig_TMI + 1)) << 8;
    lim |= *((unsigned char *)orig_TMI);

    snprintf(value, strlen(value), "%d", lim);
}

void CNWNXTMI::SetTMILimit(char *value)
{
    int lim = atoi(value);

    if (lim < 16383)
        lim = 16383;
    else if (lim > 8388607)
        lim = 8388607;

    *((unsigned char *)(orig_TMI + 2)) = (lim >> 16) & 0xFF;
    *((unsigned char *)(orig_TMI + 1)) = (lim >> 8) & 0xFF;
    *((unsigned char *)orig_TMI) = lim & 0xFF;
}

bool CNWNXTMI::OnCreate(gline *config, const char *LogDir)
{
    char log[128];

    sprintf(log, "%s/nwnx_tmi.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    orig_TMI = FindTMILimit();

    if (!orig_TMI)
        return false;

    enable_write(orig_TMI);

    Log(1, "found TMI limit at 0x%08x\n", orig_TMI);

    return true;
}

char *CNWNXTMI::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    Log(1, "Request: \"%s\"\n", Request);
    Log(1, "Params:  \"%s\"\n", Parameters);

    if (strncmp(Request, "GETLIMIT", 8) == 0) {
        GetTMILimit(Parameters);
        return NULL;
    }

    if (strncmp(Request, "SETLIMIT", 8) == 0) {
        SetTMILimit(Parameters);
        return NULL;
    }

    return NULL;
}
