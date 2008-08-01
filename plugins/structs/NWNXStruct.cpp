
/***************************************************************************
    NWNXStruct.cpp - Implementation of the CNWNXStruct class.
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

#include "NWNXStruct.h"
#include "HookFunc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXStruct::CNWNXStruct() {
    confKey = "STRUCTS";

    DurationBasisMilliseconds = 0;
    DurationBasis2880Seconds = 0;
}

CNWNXStruct::~CNWNXStruct() {
}

int CNWNXStruct::GetCurrentDurationTime() {
    struct timeval tv;
    int sec, msec;

    if (DurationBasisMilliseconds == 0)
        return 0;

    gettimeofday(&tv, NULL);

    sec = tv.tv_sec - DurationBasisTime.tv_sec;
    msec = (tv.tv_usec - DurationBasisTime.tv_usec) / 1000;

    msec += (sec * 1000);
    msec += DurationBasisMilliseconds;

    Log(3, "current duration time: %d\n", msec);

    return msec;
}


void CNWNXStruct::GetStructDuration(char *value) {
    float *p = (float *)GetLastStruct(0);
    float dur = p[3];

    Log(2, "last struct address: 0x%08x\n", p);

    snprintf(value, strlen(value), "%.2f", dur);
}


void CNWNXStruct::GetStructDurationRemaining(char *value) {
    int *p = (int *)GetLastStruct(0);
    int expire = p[5] + ((p[4] - DurationBasis2880Seconds) * 2880000);
    int current = GetCurrentDurationTime();
    float remaining = (expire - current) / 1000.0;

    Log(2, "last struct address: 0x%08x\n", p);
    Log(3, "struct expiry msec: %d\n", expire);

    if (current == 0)
        remaining = 0.0;

    snprintf(value, strlen(value), "%.2f", remaining);
}

void CNWNXStruct::GetStructInteger(char *value) {
    int *p = (int *)GetLastStruct(0);
    int idx;

    Log(2, "last struct address: 0x%08x\n", p);

    idx = atoi(value);

    if (idx < 0 || idx > 15) {
        snprintf(value, strlen(value), "%d", -1);
        return;
    }

    p = (int *)p[14];

    snprintf(value, strlen(value), "%d", p[idx]);
}


void CNWNXStruct::SetStructInteger(char *value) {
    int *p = (int *)GetLastStruct(0);
    int idx, val;
    char *space;

    Log(2, "last struct address: 0x%08x\n", p);

    if ((space = strchr(value, ' ')) == NULL)
        return;

    *space = '\0';
    idx = atoi(value);
    val = atoi(space + 1);
    *space = ' ';

    if (idx < 0 || idx > 15)
        return;

    p = (int *)p[14];

    p[idx] = val;
}


void CNWNXStruct::GetSpellId(char *value) {
    int *p = (int *)GetLastStruct(0);

    Log(2, "last struct address: 0x%08x\n", p);
    Log(3, "last struct spell id: %d\n", p[7]);

    snprintf(value, strlen(value), "%d", p[7]);
}


void CNWNXStruct::SetSpellId(char *value) {
    int *p = (int *)GetLastStruct(0);

    Log(2, "last struct address: 0x%08x\n", p);
    Log(3, "last struct spell id: %d\n", p[7]);

    p[7] = atoi(value);
}


void CNWNXStruct::SetDurationBasis(char *value) {
    gettimeofday(&DurationBasisTime, NULL);
}

void CNWNXStruct::CalcDurationBasis(char *value) {
    int *p = (int *)GetLastStruct(0);

    Log(2, "last struct address: 0x%08x\n", p);

    DurationBasisMilliseconds = p[5] - (atoi(value) * 1000);
    DurationBasis2880Seconds = p[4];

    Log(3, "duration basis: %d\n", DurationBasisMilliseconds);
}


bool CNWNXStruct::OnCreate(gline * config, const char *LogDir) {
    char log[128];

    sprintf(log, "%s/nwnx_structs.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    unsigned long orig_Struct = FindStructFunctionHook();

    if (!orig_Struct)
        return false;

    ActivateStructFunctionHook();

    Log(1, "found struct hook at 0x%08x\n", orig_Struct);

    return true;
}


char *CNWNXStruct::OnRequest(char *gameObject, char *Request, char *Parameters) {
    Log(1, "Request: \"%s\"\n", Request);
    Log(1, "Params:  \"%s\"\n", Parameters);


    if (strncmp(Request, "GETSPELLID", 10) == 0) {
        GetSpellId(Parameters);
        return NULL;
    }

    if (strncmp(Request, "SETSPELLID", 10) == 0) {
        SetSpellId(Parameters);
        return NULL;
    }

    if (strncmp(Request, "GETINTEGER", 10) == 0) {
        GetStructInteger(Parameters);
        return NULL;
    }

    if (strncmp(Request, "SETINTEGER", 10) == 0) {
        SetStructInteger(Parameters);
        return NULL;
    }

    if (strncmp(Request, "GETDURATIONREMAINING", 20) == 0) {
        GetStructDurationRemaining(Parameters);
        return NULL;
    }

    if (strncmp(Request, "GETDURATION", 11) == 0) {
        GetStructDuration(Parameters);
        return NULL;
    }

    if (strncmp(Request, "SETDURATIONBASIS", 16) == 0) {
        SetDurationBasis(Parameters);
        return NULL;
    }

    if (strncmp(Request, "CALCDURATIONBASIS", 17) == 0) {
        CalcDurationBasis(Parameters);
        return NULL;
    }

    return NULL;
}
