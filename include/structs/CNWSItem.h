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

#ifndef _NX_NWN_STRUCT_CNWSITEM_
#define _NX_NWN_STRUCT_CNWSITEM_

struct CNWSItem_s {
    uint8_t                     it_color_leather1;      /* 0000 */
    uint8_t                     it_color_leather2;      /* 0001 */
    uint8_t                     it_color_cloth1;        /* 0002 */
    uint8_t                     it_color_cloth2;        /* 0003 */
    uint8_t                     it_color_metal1;        /* 0004 */
    uint8_t                     it_color_metal2;        /* 0005 */

    uint8_t                     field_06;
    uint8_t                     field_07;

    uint32_t                    it_baseitem;

    uint32_t                    field_0C;

    CNWSObject                  obj;

    uint32_t                    field_1D4;              /* 01D4 */
    uint32_t                    field_1D8;              /* 01D8 */
    uint32_t                    field_1DC;              /* 01DC */
    uint32_t                    field_1E0;              /* 01E0 */

    uint8_t                     it_identified;          /* 01E4 */
    uint8_t                     field_1E5;
    uint8_t                     field_1E6;
    uint8_t                     field_1E7;

    uint32_t                    field_1E8;              /* 01E8 */
    uint32_t                    field_1EC;              /* 01EC */
    uint32_t                    field_1F0;              /* 01F0 */
    uint32_t                    field_1F4;              /* 01F4 */
    uint32_t                    field_1F8;              /* 01F8 */
    uint32_t                    field_1FC;              /* 01FC */
    uint32_t                    field_200;              /* 0200 */

    uint8_t                     it_charges;             /* 0204 */
    uint8_t                     field_205;
    uint8_t                     field_206;
    uint8_t                     field_207;

    uint32_t                    field_208;              /* 0208 */
    uint32_t                    field_20C;              /* 020C */

    uint32_t                    it_addcost;             /* 0210 */

    uint32_t                    field_214;              /* 0214 */

    uint8_t                     it_model_part_1;        /* 0218 */
    uint8_t                     it_model_part_2;        /* 0219 */
    uint8_t                     it_model_part_3;        /* 021A */

    uint8_t                     it_model_armor_rfoot;   /* 021B */
    uint8_t                     it_model_armor_lfoot;   /* 021C */
    uint8_t                     it_model_armor_rshin;   /* 021D */
    uint8_t                     it_model_armor_lshin;   /* 021E */
    uint8_t                     it_model_armor_lthigh;  /* 021F */
    uint8_t                     it_model_armor_rthigh;  /* 0220 */
    uint8_t                     it_model_armor_pelvis;  /* 0221 */
    uint8_t                     it_model_armor_torso;   /* 0222 */
    uint8_t                     it_model_armor_belt;    /* 0223 */
    uint8_t                     it_model_armor_neck;    /* 0224 */
    uint8_t                     it_model_armor_rfarm;   /* 0225 */
    uint8_t                     it_model_armor_lfarm;   /* 0226 */
    uint8_t                     it_model_armor_rbicep;  /* 0227 */
    uint8_t                     it_model_armor_lbicep;  /* 0228 */
    uint8_t                     it_model_armor_rshoul;  /* 0229 */
    uint8_t                     it_model_armor_lshoul;  /* 022A */
    uint8_t                     it_model_armor_rhand;   /* 022B */
    uint8_t                     it_model_armor_lhand;   /* 022C */
    uint8_t                     it_model_armor_robe;    /* 022D */
    uint8_t                     field_22E;
    uint8_t                     field_22F;

    uint32_t                    field_230;              /* 0230 */
    uint32_t                    field_234;              /* 0234 */
    uint32_t                    field_238;              /* 0238 */
    uint32_t                    field_23C;              /* 023C */
    uint32_t                    field_240;              /* 0240 */
    uint32_t                    field_244;              /* 0244 */
    uint32_t                    field_248;              /* 0248 */
    uint32_t                    field_24C;              /* 024C */
    uint32_t                    field_250;              /* 0250 */
    uint32_t                    field_254;              /* 0254 */
    uint32_t                    field_258;              /* 0258 */
    uint32_t                    field_25C;              /* 025C */
    uint32_t                    field_260;              /* 0260 */
    uint32_t                    field_264;              /* 0264 */
    uint32_t                    field_268;              /* 0268 */
    uint32_t                    field_26C;              /* 026C */
    uint32_t                    field_270;              /* 0270 */
    uint32_t                    field_274;              /* 0274 */
    uint32_t                    field_278;              /* 0278 */
    uint32_t                    field_27C;              /* 027C */
    uint32_t                    field_280;              /* 0280 */
    uint32_t                    field_284;              /* 0284 */

    uint8_t                     it_droppable;           /* 0288 */
    uint8_t                     field_289;
    uint8_t                     field_28A;
    uint8_t                     field_28B;

    uint32_t                    field_28C;              /* 028C */

    uint8_t                     it_pickpocketable;      /* 0290 */
    uint8_t                     field_290;
    uint8_t                     field_291;
    uint8_t                     field_292;

    uint32_t                    field_294;              /* 0294 */

    uint8_t                     it_stolen;              /* 0298 */
    uint8_t                     field_299;
    uint8_t                     field_29A;
    uint8_t                     field_29B;

};

#endif /* _NX_NWN_STRUCT_CNWSITEM_ */

/* vim: set sw=4: */
