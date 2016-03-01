#ifndef _CNWSAMBIENTSOUND_H_
#define _CNWSAMBIENTSOUND_H_
#include "nwndef.h"
#include "CExoArrayList.h"

class CNWSAmbientSound
{
public:
    int GetPlayersInArea(CExoArrayList<unsigned long> *);
    int Load(CResGFF *, CResStruct *);
    void PackIntoMessage(CNWSMessage *);
    void PlayAmbientSound(int);
    void PlayBattleMusic(int);
    void PlayMusic(int);
    void Save(CResGFF *, CResStruct *);
    void SetAmbientDayTrack(int);
    void SetAmbientDayVolume(int);
    void SetAmbientNightTrack(int);
    void SetAmbientNightVolume(int);
    void SetBattleMusicTrack(int);
    void SetMusicDayTrack(int);
    void SetMusicDelay(int);
    void SetMusicNightTrack(int);
    ~CNWSAmbientSound();
    CNWSAmbientSound(unsigned long);

    /* 0x0/0 */ unsigned long Playing;
    /* 0x4/4 */ unsigned long MusicDelay;
    /* 0x8/8 */ unsigned long MusicDay;
    /* 0xC/12 */ unsigned long MusicNight;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ unsigned long MusicBattle;
    /* 0x18/24 */ unsigned long field_18;
    /* 0x1C/28 */ unsigned long AmbientSndDay;
    /* 0x20/32 */ unsigned long AmbientSndNight;
    /* 0x24/36 */ unsigned char AmbientSndDayVol;
    /* 0x25/37 */ unsigned char AmbientSndNightVol;
    /* 0x26/38 */ unsigned char field_26;
    /* 0x27/39 */ unsigned char field_27;
    /* 0x28/40 */ unsigned long field_28;
    /* 0x2C/44 */ unsigned long field_2C;

};

static_assert_size(CNWSAmbientSound, 0x30);
#endif
