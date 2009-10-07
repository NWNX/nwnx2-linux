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

#ifndef _NX_NWN_STRUCT_CSERVEREXOAPPINTERNAL_
#define _NX_NWN_STRUCT_CSERVEREXOAPPINTERNAL_

struct CServerExoAppInternal_s {
    u_int32_t                   unknown[16384];

    void                       *vtable;                 /* 10000 (AppManager +0x20) */

    u_int32_t                   field_10004;            /* 10004 */
    u_int32_t                   field_10008;            /* 10008 */
    u_int32_t                   field_1000C;            /* 1000C */
    u_int32_t                   field_10010;            /* 10010 */
    u_int32_t                   field_10014;            /* 10014 */

    CNWSMessage                *srv_client_messages;    /* 10018 */
    u_int32_t                   srv_client_update;      /* 1001C */

    nwn_objid_t                *srv_player_list;        /* 10020 */

    u_int32_t                   field_10024;            /* 10024 */
    u_int32_t                   field_10028;            /* 10028 */

    CExoArrayList_uint32       *field_1002C;            /* 1002C */

    u_int32_t                   field_10030;            /* 10030 */
    u_int32_t                   field_10034;            /* 10034 */
    u_int32_t                   field_10038;            /* 10038 */
    u_int32_t                   field_1003C;            /* 1003C */
    u_int32_t                   field_10040;            /* 10040 */
    u_int32_t                   field_10044;            /* 10044 */
    u_int32_t                   field_10048;            /* 10048 */
    u_int32_t                   field_1004C;            /* 1004C */
    u_int32_t                   field_10050;            /* 10050 */

    CExoString                 *field_10054;            /* 10054 */

    u_int32_t                   field_10058;            /* 10058 */
    u_int32_t                   field_1005C;            /* 1005C */

    CNetLayer                  *srv_network;            /* 10060 */

    CServerAIMaster            *srv_ai;                 /* 10064 */

    CWorldTimer                *srv_time_world;         /* 10068 */
    CWorldTimer                *srv_time_timestop;      /* 1006C */
    CWorldTimer                *srv_time_pause;         /* 10070 */

    CFactionManager            *srv_factions;           /* 10074 */

    u_int32_t                   field_10078;            /* 10078 */
    u_int32_t                   field_1007C;            /* 1007C */

    CGameObjectArray           *srv_objects;            /* 10080 */
    nwn_objid_t                 srv_obj_module;         /* 10084 */

    CExoLinkedList             *srv_client_list_1;      /* 10088 */
    CExoLinkedList             *srv_client_list_2;      /* 1008C */

    u_int32_t                   field_10090;            /* 10090 */
    u_int32_t                   field_10094;            /* 10094 */

    CExoLinkedList             *field_10098;            /* 10098 */
    CExoLinkedList             *field_1009C;            /* 1009C */

    u_int32_t                   field_100A0;            /* 100A0 */
    u_int32_t                   field_100A4;            /* 100A4 */
    u_int32_t                   field_100A8;            /* 100A8 */

    CExoString                 *field_100AC;            /* 100AC */

    u_int32_t                   field_100B0;            /* 100B0 */
    u_int32_t                   field_100B4;            /* 100B4 */

    CExoString                 *field_100B8;            /* 100B8 */

    u_int32_t                   field_100BC;            /* 100BC */
    u_int32_t                   field_100C0;            /* 100C0 */
    u_int32_t                   field_100C4;            /* 100C4 */
    u_int32_t                   field_100C8;            /* 100C8 */
    u_int32_t                   field_100CC;            /* 100CC */
    u_int32_t                   srv_pc_export_pending;  /* 100D0 */
    u_int32_t                   field_100D4;            /* 100D4 */
    u_int32_t                   field_100D8;            /* 100D8 */
    u_int32_t                   field_100DC;            /* 100DC */
    u_int32_t                   field_100E0;            /* 100E0 */
    u_int32_t                   field_100E4;            /* 100E4 */
    u_int32_t                   field_100E8;            /* 100E8 */
    u_int32_t                   field_100EC;            /* 100EC */

    CExoArrayList_uint32       *field_100F0;            /* 100F0 */

    CExoArrayList_ptr          *field_100FC;            /* 100FC (CExoString) */
    CExoArrayList_ptr          *field_10108;            /* 10108 (CExoString) */
    CExoArrayList_ptr          *field_10114;            /* 10114 (CExoString) */

    u_int32_t                   field_10120;            /* 10120 */
    u_int32_t                   field_10124;            /* 10124 */
    u_int32_t                   field_10128;            /* 10128 */
    u_int32_t                   field_1012C;            /* 1012C */

    CExoArrayList_ptr          *field_10130;            /* 10130 (SSubNetProfile *) */

    u_int32_t                   field_1013C;            /* 1013C */
    u_int32_t                   field_10140;            /* 10140 */
    u_int32_t                   field_10144;            /* 10144 */
    u_int32_t                   field_10148;            /* 10148 */
    u_int32_t                   field_1014C;            /* 1014C */
    u_int32_t                   field_10150;            /* 10150 */
    u_int32_t                   field_10154;            /* 10154 */
    u_int32_t                   field_10158;            /* 10158 */
};

#endif /* _NX_NWN_STRUCT_CSERVEREXOAPPINTERNAL_ */

/* vim: set sw=4: */
