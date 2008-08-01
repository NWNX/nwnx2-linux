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

#ifndef _NX_NWN_STRUCT_CTLKTABLE_
#define _NX_NWN_STRUCT_CTLKTABLE_

struct CTlkTable_s {
    u_int32_t           field_00;
    u_int32_t           field_04;
    u_int32_t           field_08;
    u_int32_t           field_0C;
    u_int32_t           field_10;
    u_int32_t           field_14;
    u_int32_t           field_18;
    u_int32_t           field_1C;
    u_int32_t           field_20;
    u_int32_t           field_24;
    void               *vtable;
};

#endif /* _NX_NWN_STRUCT_CTLKTABLE_ */

/* vim: set sw=4: */
