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


void *nx_safe_calloc(size_t nmemb, size_t size)
{
    return calloc(nmemb, size);
}

void *nx_safe_malloc(size_t size)
{
    return malloc(size);
}

void *nx_safe_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

void nx_safe_free(void *ptr)
{
    free(ptr);
}

char *nx_safe_strdup(const char *str)
{
    return strdup(str);
}

/* vim: set sw=4: */
