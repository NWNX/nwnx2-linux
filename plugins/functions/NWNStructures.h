#ifndef NWNXStructures_h_
#define NWNXStructures_h_

#include "typedefs.h"

struct CNWSAmbientSound
{
	dword Enabled;
	dword MusicDelay;
	dword MusicDay;
	dword MusicNight;
	dword field_10;
	dword MusicBattle;
	dword field_18;
	dword AmbientSndDay;
	dword AmbientSndNight;
	byte  AmbientSndDayVol;
	byte  AmbientSndNitVol;
	byte  field_26;
	byte  field_27;
	void *CNWSAmbientSoundClass;
};

struct CExoString
{
	char *Text;
	dword Length;
};

struct AddressStruct
{
	word unk;		//0x0 
	word port;		//0x2
	dword ip;		//0x4
	dword unk2;		//0x8
	dword unk3;		//0xC
}; //total 0x10


struct CServerExoApp;
struct CServerExoAppInternal;
struct CServerExoAppConfig;
struct CServerExoApp
{
  /* 0x0/0 */ unsigned long field_0;
  /* 0x4/4 */ CServerExoAppInternal *Internal;
};
struct CServerExoAppInternal
{
  /* 0x0/0 */ unsigned long field_0[16384];
  /* 0x10000/65536 */ unsigned long UseNetworking;
  /* 0x10004/65540 */ unsigned long UseGameSpy;
  /* 0x10008/65544 */ unsigned long field_10008;
  /* 0x1000C/65548 */ CServerExoAppConfig *config;
  /* 0x10010/65552 */ unsigned short State;
  /* 0x10014/65556 */ char rsvd1[2];
  /* 0x10014/65556 */ unsigned long field_10014;
  /* 0x10018/65560 */ unsigned long CNWSMessage;
  /* 0x1001C/65564 */ unsigned long field_1001C;
  /* 0x10020/65568 */ unsigned long field_10020;
  /* 0x10024/65572 */ unsigned long NotTranslatedAddresses;
  /* 0x10028/65576 */ unsigned long field_10028;
  /* 0x1002C/65580 */ unsigned long field_1002C;
  /* 0x10030/65584 */ unsigned long ShutdownServer;
  /* 0x10034/65588 */ unsigned long field_10034;
  /* 0x10038/65592 */ unsigned long field_10038;
  /* 0x1003C/65596 */ unsigned long field_1003C;
  /* 0x10040/65600 */ unsigned long field_10040;
  /* 0x10044/65604 */ unsigned long field_10044;
  /* 0x10048/65608 */ unsigned long field_10048;
  /* 0x1004C/65612 */ unsigned long field_1004C;
  /* 0x10050/65616 */ unsigned long field_10050;
  /* 0x10054/65620 */ unsigned long field_10054;
  /* 0x10058/65624 */ unsigned long field_10058;
  /* 0x1005C/65628 */ unsigned long field_1005C;
  /* 0x10060/65632 */ unsigned long CNetLayer;
  /* 0x10064/65636 */ unsigned long CServerAIMaster;
  /* 0x10068/65640 */ unsigned long WorldTimer1;
  /* 0x1006C/65644 */ unsigned long WorldTimer2;
  /* 0x10070/65648 */ unsigned long WorldTimer3;
  /* 0x10074/65652 */ unsigned long CFactionManager;
  /* 0x10078/65656 */ unsigned long CConnectionLib;
  /* 0x1007C/65660 */ unsigned long field_1007C;
  /* 0x10080/65664 */ unsigned long CGameObjectArray;
  /* 0x10084/65668 */ unsigned long field_10084;
  /* 0x10088/65672 */ void *ClientsList;
  /* 0x1008C/65676 */ unsigned long field_1008C;
  /* 0x10090/65680 */ unsigned long field_10090;
  /* 0x10094/65684 */ unsigned long field_10094;
  /* 0x10098/65688 */ unsigned long field_10098;
  /* 0x1009C/65692 */ unsigned long field_1009C;
  /* 0x100A0/65696 */ unsigned long field_100A0;
  /* 0x100A4/65700 */ unsigned long field_100A4;
  /* 0x100A8/65704 */ unsigned long StartNewModule;
  /* 0x100AC/65708 */ unsigned long ModuleName;
  /* 0x100B0/65712 */ unsigned long field_100B0;
  /* 0x100B4/65716 */ unsigned long EndGame;
  /* 0x100B8/65720 */ unsigned long field_100B8;
  /* 0x100BC/65724 */ unsigned long field_100BC;
  /* 0x100C0/65728 */ unsigned long field_100C0;
  /* 0x100C4/65732 */ unsigned long field_100C4;
  /* 0x100C8/65736 */ unsigned long field_100C8;
  /* 0x100CC/65740 */ unsigned long field_100CC;
  /* 0x100D0/65744 */ unsigned long ExportCharacters;
  /* 0x100D4/65748 */ unsigned long CharacterToExport;
  /* 0x100D8/65752 */ unsigned long field_100D8;
  /* 0x100DC/65756 */ unsigned long field_100DC;
  /* 0x100E0/65760 */ unsigned long field_100E0;
  /* 0x100E4/65764 */ unsigned long field_100E4;
  /* 0x100E8/65768 */ unsigned long field_100E8;
  /* 0x100EC/65772 */ unsigned long field_100EC;
  /* 0x100F0/65776 */ unsigned long field_100F0;
  /* 0x100F4/65780 */ unsigned long field_100F4;
  /* 0x100F8/65784 */ unsigned long field_100F8;
  /* 0x100FC/65788 */ unsigned long field_100FC;
  /* 0x10100/65792 */ unsigned long field_10100;
  /* 0x10104/65796 */ unsigned long field_10104;
  /* 0x10108/65800 */ unsigned long field_10108;
  /* 0x1010C/65804 */ unsigned long field_1010C;
  /* 0x10110/65808 */ unsigned long field_10110;
  /* 0x10114/65812 */ unsigned long field_10114;
  /* 0x10118/65816 */ unsigned long field_10118;
  /* 0x1011C/65820 */ unsigned long field_1011C;
  /* 0x10120/65824 */ unsigned long field_10120;
  /* 0x10124/65828 */ unsigned long field_10124;
  /* 0x10128/65832 */ unsigned long field_10128;
  /* 0x1012C/65836 */ unsigned long field_1012C;
  /* 0x10130/65840 */ unsigned long field_10130;
  /* 0x10134/65844 */ unsigned long field_10134;
  /* 0x10138/65848 */ unsigned long field_10138;
  /* 0x1013C/65852 */ unsigned long field_1013C;
  /* 0x10140/65856 */ unsigned long field_10140;
  /* 0x10144/65860 */ unsigned long field_10144;
  /* 0x10148/65864 */ unsigned long field_10148;
  /* 0x1014C/65868 */ unsigned long field_1014C;
  /* 0x10150/65872 */ unsigned long field_10150;
  /* 0x10154/65876 */ unsigned long field_10154;
  /* 0x10158/65880 */ unsigned long LogDots;
  /* 0x1015C/65884 */ unsigned long field_1015C;
};
struct CServerExoAppConfig
{
  /* 0x0/0 */ unsigned long field_0;
  /* 0x4/4 */ unsigned long field_4;
  /* 0x8/8 */ unsigned long field_8;
  /* 0xC/12 */ unsigned long field_C;
  /* 0x10/16 */ unsigned long field_10;
  /* 0x14/20 */ unsigned long field_14;
  /* 0x18/24 */ unsigned long field_18;
  /* 0x1C/28 */ unsigned long field_1C;
  /* 0x20/32 */ unsigned long field_20;
  /* 0x24/36 */ unsigned long field_24;
  /* 0x28/40 */ unsigned long field_28;
  /* 0x2C/44 */ unsigned long field_2C;
  /* 0x30/48 */ unsigned long field_30;
  /* 0x34/52 */ unsigned long field_34;
  /* 0x38/56 */ unsigned long field_38;
  /* 0x3C/60 */ unsigned long field_3C;
  /* 0x40/64 */ unsigned long field_40;
  /* 0x44/68 */ unsigned long field_44;
  /* 0x48/72 */ unsigned long field_48;
  /* 0x4C/76 */ unsigned long field_4C;
  /* 0x50/80 */ unsigned long field_50;
  /* 0x54/84 */ unsigned long field_54;
  /* 0x58/88 */ unsigned long field_58;
  /* 0x5C/92 */ unsigned long field_5C;
  /* 0x60/96 */ unsigned long field_60;
  /* 0x64/100 */ unsigned long field_64;
  /* 0x68/104 */ unsigned long field_68;
  /* 0x6C/108 */ unsigned long field_6C;
  /* 0x70/112 */ unsigned long field_70;
  /* 0x74/116 */ unsigned long field_74;
  /* 0x78/120 */ unsigned long field_78;
  /* 0x7C/124 */ unsigned long field_7C;
  /* 0x80/128 */ unsigned long field_80;
  /* 0x84/132 */ unsigned long field_84;
  /* 0x88/136 */ unsigned long field_88;
  /* 0x8C/140 */ unsigned long field_8C;
  /* 0x90/144 */ unsigned long field_90;
  /* 0x94/148 */ unsigned long field_94;
  /* 0x98/152 */ unsigned long field_98;
  /* 0x9C/156 */ unsigned long field_9C;
  /* 0xA0/160 */ unsigned long field_A0;
  /* 0xA4/164 */ unsigned long field_A4;
  /* 0xA8/168 */ unsigned long field_A8;
  /* 0xAC/172 */ unsigned long field_AC;
  /* 0xB0/176 */ unsigned long field_B0;
  /* 0xB4/180 */ unsigned long field_B4;
  /* 0xB8/184 */ unsigned long AllowLocalChars;
  /* 0xBC/188 */ unsigned long field_BC;
  /* 0xC0/192 */ unsigned long field_C0;
  /* 0xC4/196 */ unsigned long field_C4;
  /* 0xC8/200 */ unsigned long field_C8;
  /* 0xCC/204 */ unsigned long field_CC;
  /* 0xD0/208 */ unsigned long field_D0;
  /* 0xD4/212 */ unsigned long field_D4;
  /* 0xD8/216 */ unsigned long field_D8;
  /* 0xDC/220 */ unsigned long field_DC;
  /* 0xE0/224 */ unsigned long field_E0;
  /* 0xE4/228 */ unsigned long field_E4;
  /* 0xE8/232 */ unsigned long PauseAndPlay;
  /* 0xEC/236 */ unsigned long OneParty;
  /* 0xF0/240 */ unsigned long EnforceLegalCharacters;
  /* 0xF4/244 */ unsigned long ItemLevelRestrictions;
  /* 0xF8/248 */ unsigned long CDBannedBehavior;
  /* 0xFC/252 */ unsigned long DisallowShouting;
  /* 0x100/256 */ unsigned long ShowDMJoinedMessage;
  /* 0x104/260 */ unsigned long BackupSavedChars;
  /* 0x108/264 */ unsigned long AutoFail1;
  /* 0x10C/268 */ unsigned long ValidateSpells;
  /* 0x110/272 */ unsigned long ExamineEffects;
  /* 0x114/276 */ unsigned long ExamineCR;
  /* 0x118/280 */ unsigned long MaxHP;
  /* 0x11C/284 */ unsigned long RestoreSpellUses;
  /* 0x120/288 */ unsigned long ResetEncounterSpawns;
  /* 0x124/292 */ unsigned long HideHPGained;
  /* 0x128/296 */ unsigned long field_128;
  /* 0x12C/300 */ unsigned long field_12C;
  /* 0x130/304 */ unsigned long field_130;
  /* 0x134/308 */ unsigned long field_134;
  /* 0x138/312 */ unsigned long field_138;
  /* 0x13C/316 */ unsigned long field_13C;
  /* 0x140/320 */ unsigned long field_140;
  /* 0x144/324 */ unsigned long field_144;
  /* 0x148/328 */ unsigned long field_148;
  /* 0x14C/332 */ unsigned long VaultCharsOnly;
  /* 0x150/336 */ unsigned long SaveCharsInSaveGame;
  /* 0x154/340 */ unsigned long SuppressBaseServervault;
  /* 0x158/344 */ unsigned long GameRegion;
  /* 0x15C/348 */ unsigned long field_15C;
  /* 0x160/352 */ unsigned long field_160;
  /* 0x164/356 */ unsigned long field_164;
};


#endif
