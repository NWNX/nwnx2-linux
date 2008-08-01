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

#ifndef _NX_NWN_STRUCT_CGAMEEFFECT_
#define _NX_NWN_STRUCT_CGAMEEFFECT_

struct CGameEffect_s {
    uint32_t            eff_id;

    uint32_t            field_04;

    uint32_t            eff_type;
    uint32_t            eff_durtype;

    uint32_t            eff_expire1;
    uint32_t            eff_expire2;

    nwn_objid_t         eff_creator;
    uint32_t            eff_spellid;

    uint32_t            eff_is_exposed;
    uint32_t            eff_is_iconshown;

    uint32_t            field_28;

    uint32_t            eff_link_id1;
    uint32_t            eff_link_id2;

    uint32_t            eff_num_integers;
    int32_t            *eff_integers;

    float               eff_floats[4];
    CExoString          eff_strings[6];
    nwn_objid_t         eff_objects[4];

    uint32_t            eff_skiponload;
};

#endif /* _NX_NWN_STRUCT_CGAMEEFFECT_ */

/* vim: set sw=4: */
