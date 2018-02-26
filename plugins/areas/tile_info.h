/***************************************************************************
    tile_info.h
    this structure details the information contained in the nwn in-memory
    tile structure, i.e., one element of an area's full tile set.

    ------------------------------------------------------------------------
    Areas plugin for NWNX
    (c) 2010 virusman (virusman@virusman.ru)
    modifications 2018 by niv, xorbaxian

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along	with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#ifndef _TILE_INFO_H_
# define _TILE_INFO_H_

struct tile_info {
    /* 0x000/0 */	unsigned long	field_00;
    /* 0x004/4 */	unsigned short	field_04;
    /* 0x006/6 */	unsigned short	x;
    /* 0x008/8 */	unsigned short	field_08;
    /* 0x00A/10 */	unsigned short	y;
    /* 0x00C/12 */	unsigned long	field_0C;
    /* 0x010/16 */	unsigned long	Tile_ID;
    /* 0x014/20 */	unsigned long	Tile_Height;
    /* 0x018/24 */	unsigned long	col;
    /* 0x01C/28 */	unsigned long	row;
    /* 0x020/32 */	unsigned long	Tile_Orientation;
    /* 0x024/36 */	unsigned char	Tile_MainLight1;
    /* 0x025/37 */	unsigned char	Tile_MainLight2;
    /* 0x026/38 */	unsigned char	Tile_SrcLight1;	// for some reason, these 2 are
    /* 0x027/39 */	unsigned char	Tile_SrcLight2;	// offset by -1 [value 0 => 0xff]
    /* 0x028/40 */	unsigned char	field_28;
    /* 0x029/41 */	unsigned char	Tile_AnimLoop1;
    /* 0x02A/42 */	unsigned char	Tile_AnimLoop2;
    /* 0x02B/43 */	unsigned char	Tile_AnimLoop3;
    /* 0x02C/44 */	unsigned long	field_2C;
    /* 0x030/48 */	unsigned long	field_30;
    /* 0x034/52 */	unsigned long	field_34;
    /* 0x038/56 */	unsigned long	tile_flags;	// always & 0x08 if triggers present
    /* 0x03C/60 */	unsigned long	*trigger_list;
    /* 0x040/64 */	unsigned long	field_40;
    /* 0x044/68 */	unsigned long	field_44;
    /* 0x048/72 */	unsigned long	field_48;
    /* 0x04C/76 */	unsigned long	field_4C;
    /* 0x050/80 */	unsigned long	field_50;
    /* 0x054/84 */	unsigned long	field_54;
    /* 0x058/88 */	unsigned long	field_58;
};

typedef struct tile_info tile_info_s;

static_assert_size(tile_info_s, 0x5c);

#endif

/* vim: set ts=8 sw=4: */
