/*
 * RealTime - Linux Port of the RealTime NWNX2 plugin by Rob Lobbe
 * Copyright (C) 2016 Nela Melin (nela@tomb.org.uk)
 * 
 * RealTime - Implementation of the RealTime class (for NWNX2)
 * Copyright (C) 2007 Rob Lobbe (Gryphyn, gryphyn@thefold.org)
 *     
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */ 
#ifndef NWNX_REALTIME_H
#define NWNX_REALTIME_H

#include "NWNXLib.h"

#include <time.h>

#define SECONDS_PER_MINUTE  (60)
#define SECONDS_PER_HOUR    (60 * SECONDS_PER_MINUTE)
#define SECONDS_PER_DAY     (24 * SECONDS_PER_HOUR)
    
#ifdef __cplusplus
extern "C" {
#endif

void Func_Ticks(CGameObject *ob, char *value);
void Func_Date(CGameObject *ob, char *value);
void Func_Time(CGameObject *ob, char *value);
void Func_DateTime(CGameObject *ob, char *value);
void Func_LoadTime(CGameObject *ob, char *value);
void Func_Uptime(CGameObject *ob, char *value);
void Func_DayFull(CGameObject *ob, char *value);
void Func_DayShort(CGameObject *ob, char *value);
void Func_MonthFull(CGameObject *ob, char *value);
void Func_MonthShort(CGameObject *ob, char *value);
void Func_Year(CGameObject *ob, char *value);
void Func_Month(CGameObject *ob, char *value);
void Func_Day(CGameObject *ob, char *value);
void Func_Hour(CGameObject *ob, char *value);
void Func_Minute(CGameObject *ob, char *value);
void Func_Second(CGameObject *ob, char *value);
void Func_Millisecond(CGameObject *ob, char *value);
void Func_UpDays(CGameObject *ob, char *value);
void Func_UpHours(CGameObject *ob, char *value);
void Func_UpMinutes(CGameObject *ob, char *value);
void Func_UpSeconds(CGameObject *ob, char *value);
void Func_UpMilliseconds(CGameObject *ob, char *value);

struct timeval C_getLoadTime(void);

#ifdef __cplusplus
} /* End extern "C" */

#include "NWNXBase.h"

class CNWNXRealTime : public CNWNXBase  
{
public:
    CNWNXRealTime();
    virtual ~CNWNXRealTime();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);
    struct timeval getLoadTime();

private:
    struct timeval loadTime;
};

extern CNWNXRealTime RealTime;

#endif

#endif /* NWNX_REALTIME_H */
