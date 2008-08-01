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

#ifndef _NX_NWN_STRUCT_CNWSFACTION_
#define _NX_NWN_STRUCT_CNWSFACTION_

struct CNWSFaction_s {
    void               *members;
    int32_t             members_len;

    uint32_t            field_08;

    uint32_t            fac_id;

    uint32_t            field_10;
    uint32_t            field_14;

    char               *fac_name;
};

#endif /* _NX_NWN_STRUCT_CNWSFACTION_ */

/* vim: set sw=4: */
