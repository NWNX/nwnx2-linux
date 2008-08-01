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

#ifndef _NX_NWN_STRUCT_CEXOBASE_
#define _NX_NWN_STRUCT_CEXOBASE_

struct CExoBase_s {
    CExoIni            *exo_ini;                /* 0000 */
    CExoTimers         *exo_timers;             /* 0004 */
    CExoDebug          *exo_debug;              /* 0008 */
    CExoAliasList      *exo_aliases;            /* 000C */
    CExoRand           *exo_rand;               /* 0010 */
    u_int32_t           field_14;
    CExoBaseInternal   *exo_internal;           /* 0018 */
};

#endif /* _NX_NWN_STRUCT_CEXOBASE_ */

/* vim: set sw=4: */
