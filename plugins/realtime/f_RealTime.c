/*
 * RealTime - Linux Port of the RealTime NWNX2 plugin by Rob Lobbe
 * Copyright (C) 2016 Nela Melin (nela@tomb.org.uk)
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

#include "NWNXRealTime.h"

static struct tm *now_tm(struct tm *now)
{
    time_t now_seconds;

    time(&now_seconds);

    return localtime_r(&now_seconds, now);
}

static struct tm *loadtime_tm(struct tm *loadtime)
{
    time_t loadtime_seconds = C_getLoadTime().tv_sec;

    return localtime_r(&loadtime_seconds, loadtime);
}

void Func_Ticks(CGameObject *ob, char *value)
{
    snprintf(value, strlen(value), "%lld", (long long) time(NULL));
}

void Func_Date(CGameObject *ob, char *value)
{
    struct tm now;
    strftime(value, strlen(value), "%Y-%m-%d", now_tm(&now));
}

void Func_Time(CGameObject *ob, char *value)
{
    struct tm now;
    strftime(value, strlen(value), "%H:%M:%S", now_tm(&now));
}

void Func_DateTime(CGameObject *ob, char *value)
{
    struct tm now;
    strftime(value, strlen(value), "%Y-%m-%d %H:%M:%S", now_tm(&now));
}

void Func_LoadTime(CGameObject *ob, char *value)
{
    struct tm loadtime;
    strftime(value, strlen(value), "%Y-%m-%d %H:%M:%S", loadtime_tm(&loadtime));
}

void Func_Uptime(CGameObject *ob, char *value)
{
    struct tm uptime;
    time_t uptime_seconds = time(NULL) - C_getLoadTime().tv_sec;

    strftime(value, strlen(value), "%H:%M:%S",
            gmtime_r(&uptime_seconds, &uptime));
}

void Func_DayFull(CGameObject *ob, char *value)
{
    struct tm now;
    strftime(value, strlen(value), "%A", now_tm(&now));
}

void Func_DayShort(CGameObject *ob, char *value)
{
    struct tm now;
    strftime(value, strlen(value), "%a", now_tm(&now));
}

void Func_MonthFull(CGameObject *ob, char *value)
{
    struct tm now;
    strftime(value, strlen(value), "%B", now_tm(&now));
}

void Func_MonthShort(CGameObject *ob, char *value)
{
    struct tm now;
    strftime(value, strlen(value), "%b", now_tm(&now));
}

void Func_Year(CGameObject *ob, char *value)
{
    struct tm now;
    strftime(value, strlen(value), "%Y", now_tm(&now));
}

void Func_Month(CGameObject *ob, char *value)
{
    struct tm now;
    now_tm(&now);
    snprintf(value, strlen(value), "%d", now.tm_mon + 1); //ZeroBased, so add 1
}

void Func_Day(CGameObject *ob, char *value)
{
    struct tm now;
    now_tm(&now);

    snprintf(value, strlen(value), "%d", now.tm_mday);
}

void Func_Hour(CGameObject *ob, char *value)
{
    struct tm now;
    now_tm(&now);

    snprintf(value, strlen(value), "%d", now.tm_hour);
}

void Func_Minute(CGameObject *ob, char *value)
{
    struct tm now;
    now_tm(&now);

    snprintf(value, strlen(value), "%d", now.tm_min);
}

void Func_Second(CGameObject *ob, char *value)
{
    struct tm now;
    now_tm(&now);

    snprintf(value, strlen(value), "%d", now.tm_sec);
}

void Func_Millisecond(CGameObject *ob, char *value)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);

    snprintf(value, strlen(value), "%ld", (long) tv.tv_usec / 1000);
}

void Func_UpDays(CGameObject *ob, char *value)
{
    struct tm uptime;
    time_t uptime_seconds = time(NULL) - C_getLoadTime().tv_sec;

    snprintf(value, strlen(value), "%lld",
            (long long) uptime_seconds / SECONDS_PER_DAY);
}

void Func_UpHours(CGameObject *ob, char *value)
{
    struct tm uptime;
    time_t uptime_seconds = time(NULL) - C_getLoadTime().tv_sec;

    snprintf(value, strlen(value), "%lld",
            (long long) uptime_seconds / SECONDS_PER_HOUR);
}
void Func_UpMinutes(CGameObject *ob, char *value)
{
    struct tm uptime;
    time_t uptime_seconds = time(NULL) - C_getLoadTime().tv_sec;

    snprintf(value, strlen(value), "%lld",
            (long long) uptime_seconds / SECONDS_PER_MINUTE);
}

void Func_UpSeconds(CGameObject *ob, char *value)
{
    struct tm uptime;
    time_t uptime_seconds = time(NULL) - C_getLoadTime().tv_sec;

    snprintf(value, strlen(value), "%lld", (long long int) uptime_seconds);
}

void Func_UpMilliseconds(CGameObject *ob, char *value)
{
    struct timeval now, uptime, loadtime = C_getLoadTime();
    
    gettimeofday(&now, NULL);
    timersub(&now, &loadtime, &uptime);

    snprintf(value, strlen(value), "%lld",
            ((long long int) uptime.tv_sec * 1000) + (uptime.tv_usec / 1000));
}
