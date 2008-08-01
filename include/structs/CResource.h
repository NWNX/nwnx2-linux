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

#ifndef _NX_NWN_STRUCT_CRESOURCE_
#define _NX_NWN_STRUCT_CRESOURCE_

struct CResource_s {
    uint32_t            field_00;
    uint8_t             id1;
    uint8_t             id2;
    uint8_t             id3;
    uint8_t             id4;
    uint32_t            field_08;

    void               *res_data;
    void               *res_name;
    uint32_t            res_size;
    uint32_t            res_loaded;

    uint32_t            field_1C;
    uint32_t            field_20;

    void               *res_list;
    void               *res_class;

    uint32_t            res_loaded_2;
    uint32_t            res_size_2;
    void               *res_data_2;
};

#endif /* _NX_NWN_STRUCT_CRESOURCE_ */

/* vim: set sw=4: */
