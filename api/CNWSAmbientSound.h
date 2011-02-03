#ifndef _CNWSAMBIENTSOUND_H_
#define _CNWSAMBIENTSOUND_H_
#include "nwndef.h"
#include "CExoArrayList.h"

class CNWSAmbientSound
{
public:
	int GetPlayersInArea(CExoArrayList<unsigned long> *);
	int Load(CResGFF *, CResStruct *);
	int PackIntoMessage(CNWSMessage *);
	int PlayAmbientSound(int);
	int PlayBattleMusic(int);
	int PlayMusic(int);
	int Save(CResGFF *, CResStruct *);
	int SetAmbientDayTrack(int);
	int SetAmbientDayVolume(int);
	int SetAmbientNightTrack(int);
	int SetAmbientNightVolume(int);
	int SetBattleMusicTrack(int);
	int SetMusicDayTrack(int);
	int SetMusicDelay(int);
	int SetMusicNightTrack(int);
	~CNWSAmbientSound();
	CNWSAmbientSound(unsigned long);

};
#endif
