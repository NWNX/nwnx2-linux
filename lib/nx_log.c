/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#include "NWNXLib.h"

uint32_t nx__log_facility = 0;
static FILE *nx_log_file = NULL;

static void nx_log_varargs(uint32_t fac, uint16_t tags, const char *fmt, va_list vap)
{
    time_t t;
    struct tm tm;

    if (nx_log_file == NULL) {
        nx_log_init(NULL, 0);

        if (nx_log_file == NULL)
            nx_log_file = stderr;
    }

    t = time(NULL);
    localtime_r(&t, &tm);

    fprintf(nx_log_file, "[%04d-%02d-%02d %02d:%02d:%02d] ",
            (1900 + tm.tm_year), (1 + tm.tm_mon), tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    vfprintf(nx_log_file, fmt, vap);
    fprintf(nx_log_file, "\n");
}

void nx__log(uint32_t fac, uint16_t tags, const char *fmt, ...)
{
    va_list vap;

    va_start(vap, fmt);
    nx_log_varargs(fac, tags, fmt, vap);
    va_end(vap);
}

void nx__log_error(uint32_t fac, const char *file, int line, const char *func, const char *fmt, ...)
{
    char buf[1024];
    va_list vap;

    snprintf(buf, sizeof(buf), "[%s:%d %s] %s", file, line, func, fmt);

    va_start(vap, fmt);
    nx_log_varargs(fac, 0, buf, vap);
    va_end(vap);
}

uint32_t nx__log_init(const char *name, int facility, ...)
{
    if (nx_log_file == NULL)
        nx_log_file = fopen("logs.0/nwnx_core.txt", "a");

    if (nx_log_file != NULL)
        setlinebuf(nx_log_file);

    return 0;
}

/* vim: set sw=4: */
