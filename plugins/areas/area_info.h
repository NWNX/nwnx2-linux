/***************************************************************************
	area_info.h
	this structure details the information contained in the nwn in-memory
	area structure. it differs from CNWSArea in that this structure is
	complete, whereas CNWSArea contains data starting only from offset 0xd4.

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
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#ifndef _AREA_INFO_H_
# define _AREA_INFO_H_

struct area_info {
    /* 0x000/0 */	unsigned long object_id;
    /* 0x004/4 */	unsigned long width;
    /* 0x008/8 */	unsigned long height;
    /* 0x00C/12 */	unsigned long field_0C;
    /* 0x010/16 */	unsigned long field_10;
    /* 0x014/20 */	unsigned long field_14;
    /* 0x018/24 */	unsigned long field_18;
    /* 0x01C/28 */	unsigned long field_1C;
    /* 0x020/32 */	unsigned long field_20;
    /* 0x024/36 */	unsigned long field_24;
    /* 0x028/40 */	unsigned long field_28;
    /* 0x02C/44 */	unsigned long field_2C;
    /* 0x030/48 */	unsigned long field_30;
    /* 0x034/52 */	unsigned long field_34;
    /* 0x038/56 */	unsigned long field_38;
    /* 0x03C/60 */	unsigned long field_3C;
    /* 0x040/   */	unsigned long field_40;
    /* 0x044/   */	unsigned long field_44;
    /* 0x048/   */	unsigned long field_48;
    /* 0x04C/   */	unsigned long field_4C;
    /* 0x050/   */	unsigned long field_50;
    /* 0x054/   */	unsigned long field_54;
    /* 0x058/   */	unsigned long field_58;
    /* 0x05C/   */	unsigned long field_5C;
    /* 0x060/   */	unsigned long field_60;
    /* 0x064/   */	unsigned long field_64;
    /* 0x068/   */	unsigned long field_68;
    /* 0x06C/   */	unsigned long field_6C;
    /* 0x070/   */	unsigned long field_70;
    /* 0x074/   */	unsigned long field_74;
    /* 0x078/   */	unsigned long field_78;
    /* 0x07C/   */	unsigned long field_7C;
    /* 0x080/128 */	unsigned long field_80;
    /* 0x084/132 */	unsigned long field_84;
    /* 0x088/136 */	unsigned long field_88;
    /* 0x08C/140 */	unsigned long field_8C;
    /* 0x090/144 */	unsigned long field_90;
    /* 0x094/148 */	unsigned long field_94;
    /* 0x098/152 */	unsigned long no_rest;
    /* 0x09C/156 */	unsigned long field_9C;
    /* 0x0A0/160 */	unsigned long field_A0;
    /* 0x0A4/164 */	unsigned long area;
    /* 0x0A8/168 */	unsigned long field_A8;
    /* 0x0AC/172 */	unsigned long field_AC;
    /* 0x0B0/176 */	char resref[16];
    /* 0x0C0/192 */	unsigned long CResARE;
    /* 0x0C4/196 */	CGameObject GameObject;
    /* 0x0D4/212 */	unsigned long NumPlayers;
    /* 0x0D8/216 */	CExoArrayList<nwobjid> TrapList;
    /* 0x0E4/228 */	unsigned long ObjectByNameIndex;
    /* 0x0E8/232 */	unsigned long m_nLastHeartbeatScriptCalendarDay;
    /* 0x0EC/236 */	unsigned long m_nLastHeartbeatScriptTimeOfDay;
    /* 0x0F0/240 */	unsigned long field_F0;
    /* 0x0F4/244 */	unsigned long field_F4;
    /* 0x0F8/248 */	unsigned long field_F8;
    /* 0x0FC/252 */	CExoLocString Name;
    /* 0x104/260 */ CExoString Tag;
    /* 0x10C/268 */ char tileset[16];
    /* 0x11C/284 */	unsigned long field_11C;
    /* 0x120/288 */ CNWSTile *Tiles;
    /* 0x124/292 */ unsigned long field_124;
    /* 0x128/296 */ CExoString m_sHeartbeatScript;
    /* 0x130/304 */ unsigned long field_130;
    /* 0x134/308 */ unsigned long field_134;
    /* 0x138/    */	unsigned long field_138;
    /* 0x13C/    */	unsigned long field_13C;
    /* 0x140/    */	unsigned long field_140;
    /* 0x144/    */	unsigned long field_144;
    /* 0x148/    */	unsigned long field_148;
    /* 0x14C/332 */	int mod_spot;
    /* 0x150/336 */	int mod_listen;
    /* (mtype:CExoArrayList<unsigned long>) */
    /* 0x154/340 */ CExoArrayList<unsigned long> ObjectList;
    /* 0x160/352 */ unsigned long CurrentObjectIndex;
    /* 0x164/356 */ CExoArrayList<unsigned long> SubAreas;
    /* 0x170/368 */ unsigned long field_170;
    /* 0x174/372 */ unsigned long field_174;
    /* 0x178/376 */ unsigned long field_178;
    /* 0x17C/380 */ unsigned long field_17C;
    /* 0x180/384 */ unsigned long field_180;
    /* 0x184/388 */ unsigned long field_184;
    /* 0x188/392 */ unsigned long field_188;
    /* 0x18C/396 */ unsigned long field_18C;
    /* 0x190/400 */ unsigned long field_190;
    /* 0x194/404 */ unsigned long field_194;
    /* 0x198/408 */ CPathfindInformation* PathfindInformation;
    /* 0x19C/412 */ unsigned long SoundPathInformation;
    /* 0x1A0/416 */ unsigned long field_1A0;
    /* 0x1A4/420 */ unsigned long field_1A4;
    /* 0x1A8/424 */ unsigned long field_1A8;
    /* 0x1AC/428 */ unsigned long field_1AC;
    /* 0x1B0/432 */ unsigned long field_1B0;
    /* 0x1B4/436 */ unsigned long field_1B4;
    /* 0x1B8/440 */ unsigned long field_1B8;
    /* 0x1BC/444 */ unsigned long field_1BC;
    /* 0x1C0/448 */ nwobjid LastEntered;
    /* 0x1C4/452 */ nwobjid LastExited;
    /* 0x1C8/456 */ unsigned long CustomScriptEventId;
    /* 0x1CC/460 */ unsigned long field_1CC;
    /* 0x1D0/464 */ unsigned long field_1D0;
    /* 0x1D4/468 */ unsigned long InterAreaDFSVisited;
    /* 0x1D8/472 */ CNWSScriptVarTable VarTable;
    /* 0x1E0/480 */ unsigned long field_1E0;
    /* 0x1E4/484 */ unsigned long field_1E4;
    /* 0x1E8/488 */ unsigned long AmbientSound;
    /* 0x1EC/492 */	unsigned long field_1EC;
    /* 0x1F0/496 */ char WeatherStarted;
    /* 0x1F1/497 */ char rsvd5[3];
    /* 0x1F4/500 */	unsigned long field_1F4;
    /* 0x1F8/504 */ unsigned long m_nLastUpdateCalendarDay;
    /* 0x1FC/508 */ unsigned long m_nLastUpdateTimeOfDay;
    /* 0x200/512 */ unsigned char OverrideWeather;
    /* 0x201/513 */ unsigned char CurrentWeather;
    /* 0x202/514 */	unsigned char lighting;
    /* 0x203/515 */ unsigned char PVPSetting;
    /* 0x204/516 */ unsigned long tilecount;
    /* 0x208/520 */ unsigned long field_208;
    /* 0x20C/524 */ unsigned long LoadScreenID;
};

typedef struct area_info area_info_s;

static_assert_size(area_info_s, 0x210);

#endif

/* vim: set ts=4 sw=4: */
