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

#ifndef _NX_NWN_STRUCT_CNWSQUICKBARBUTTON_
#define _NX_NWN_STRUCT_CNWSQUICKBARBUTTON_

struct CNWSQuickbarButton_s {
    uint32_t            qb_objid1;      // Item on slot
    uint32_t            qb_objid2;      // Second item on same slot
    uint8_t             qb_type;
    uint8_t             qb_class;       // Class reference for spells when player is multiclass
    char                qb_resref[17];  // For DM creator dropped slots, resref to object
    CExoString          qb_label;       // Custom macro label
    CExoString          qb_command;     // Custom macro command
    CExoString          qb_label2;      // Label for DM creator dropped slots
    uint32_t            qb_id;
    uint32_t            qb_metamagic;

    uint32_t            field_3C;		/* 0x3C */
};

#endif /* _NX_NWN_STRUCT_CNWSQUICKBARBUTTON_ */

/* vim: set sw=4: */
