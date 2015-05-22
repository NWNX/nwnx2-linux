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

};
#endif
