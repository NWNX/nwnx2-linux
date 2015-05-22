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

#ifndef _NX_NWN_STRUCT_CNWSCREATURECLASS_
#define _NX_NWN_STRUCT_CNWSCREATURECLASS_

struct CNWSCreatureStats_ClassInfo_s {
    CExoArrayList_uint32        cl_spells_known[10];
    CExoArrayList_ptr           cl_spells_mem[10];      /* CNWSStats_Spell * */

    uint8_t                     cl_spells_bonus[10];
    uint8_t                     cl_spells_left[10];
    uint8_t                     cl_spells_max[10];

    uint8_t                     cl_class;
    uint8_t                     cl_level;

    uint8_t                     cl_negative_level;

    uint8_t                     cl_specialist;
    uint8_t                     cl_domain_1;
    uint8_t                     cl_domain_2;

    uint8_t                     unknown_2[4];
};

#endif /* _NX_NWN_STRUCT_CNWSCREATURECLASS_ */

/* vim: set sw=4: */
