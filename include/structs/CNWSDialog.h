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

#ifndef _NX_NWN_STRUCT_CNWSDIALOG_
#define _NX_NWN_STRUCT_CNWSDIALOG_

struct CNWSDialog_s {
    int32_t             entries_len;
    CDialogSpeak       *entries;

    int32_t             replies_len;
    CDialogReply   *replies;

    int32_t             starts_len;
    CDialogNode        *starts;

    char                script_end[16];
    char                script_abort[16];

    uint32_t           *parties;

    uint32_t            field_3C;
    uint32_t            field_40;

    uint32_t            current_node;

    uint32_t            field_48;

    uint32_t            lang;
    uint32_t            oid_with;
    uint32_t            oid_self;

    uint32_t            field_58;
    uint32_t            field_5C;
    uint32_t            field_60;
    uint32_t            field_64;

    uint32_t            oid_self_2;
    uint32_t            prevent_zoom;
};

#endif /* _NX_NWN_STRUCT_CNWSDIALOG_ */

/* vim: set sw=4: */
