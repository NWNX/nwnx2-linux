#include "typedefs.h"

#ifndef NWNXStructures_h_
#define NWNXStructures_h_

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

struct CNWObjectVarListElement
{
    CExoString sVarName;
    dword      nVarType;
    dword       nVarValue;
};

struct CNWObjectVarList
{
	CNWObjectVarListElement *VarList;
	dword                    VarCount;
};

#endif
