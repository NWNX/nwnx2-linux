#ifndef _CNETLAYERPLAYERINFO_H_
#define _CNETLAYERPLAYERINFO_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoArrayList.h"

class CNetLayerPlayerInfo
{
public:
    int AddCDKey(CExoString const &, CExoString const &);
    int AllKeysAuthed(unsigned long &);
    void Initialize();
    void SetCDKey(int, CExoString const &, CExoString const &);
    int StartMstTimer(unsigned long long);
    int UpdateMstTimer(unsigned long long);
    CNetLayerPlayerInfo();

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ CExoString Account;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ unsigned long IsPlayer;
    /* 0x18/24 */ unsigned long IsDM;
    /* 0x1C/28 */ unsigned long IsSysAdmin;
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
    /* (mtype:CExoArrayList<CExoString>) */
    /* 0x58/88 */ CExoArrayList<CExoString> CDKeyArray;
    /* 0x64/100 */ unsigned long field_64;
    /* 0x68/104 */ unsigned long field_68;
    /* 0x6C/108 */ unsigned long field_6C;
    /* 0x70/112 */ unsigned long field_70;
    /* 0x74/116 */ unsigned long field_74;
};
#endif
