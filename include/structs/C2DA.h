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

#ifndef _NX_NWN_STRUCT_C2DA_
#define _NX_NWN_STRUCT_C2DA_

struct C2DA_s {
    uint32_t            field_00;

    CResource          *tda_resource;
    char                tda_name[16];
    void               *tda_class;

    uint32_t            field_1C;
    uint32_t            field_20;

    CExoString         *tda_ids;
    CExoString         *tda_cols;
    CExoString        **tda_rows;

    int32_t             tda_rows_len;
    int32_t             tda_cols_len;

    uint32_t            field_38;

 /*
  * int GetColumnID (char *column);
  * int GetRowID (unsigned int row);
  */
};

#endif /* _NX_NWN_STRUCT_C2DA_ */

/* vim: set sw=4: */
