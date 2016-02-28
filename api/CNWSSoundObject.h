#ifndef _CNWSSOUNDOBJECT_H_
#define _CNWSSOUNDOBJECT_H_
#include "nwndef.h"
#include "Vector.h"
#include "nwnstructs.h"
#include "CNWSObject.h"

class CNWSSoundObject : public CNWSObject
{
public:
    void AIUpdate();
    void AddToArea(CNWSArea *, int);
    CNWSSoundObject * AsNWSSoundObject();
    void ChangePosition(Vector);
    void ChangeVolume(int);
    void EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
    int GetContinuous();
    int GetHours();
    int GetIntervalVariance();
    int GetInterval();
    int GetIsActive();
    int GetLooping();
    int GetMaxDistance();
    int GetMinDistance();
    int GetPeopleInSoundRange();
    int GetPitchVariation();
    int GetPositional();
    int GetPriority();
    int GetRandomPosition();
    int GetRandomXRange();
    int GetRandomYRange();
    int GetRandom();
    int GetSoundList();
    int GetTimeofDay();
    int GetVolumeVariation();
    int GetVolume();
    int Load(CResGFF *, CResStruct *);
    void PackIntoMessage(CNWSMessage *);
    void Play();
    int RemoveFromArea();
    void Save(CResGFF *, CResStruct *);
    int SetContinuous(int);
    int SetHours(unsigned long);
    int SetIntervalVariance(unsigned long);
    int SetInterval(unsigned long);
    int SetIsActive(int);
    int SetLooping(int);
    int SetMaxDistance(float);
    int SetMinDistance(float);
    int SetPitchVariation(float);
    int SetPositional(int);
    int SetPriority(unsigned char);
    int SetRandomPosition(int);
    int SetRandomXRange(float);
    int SetRandomYRange(float);
    int SetRandom(int);
    int SetTimeofDay(CNWSSoundObjectTimeOfDay);
    int SetVolumeVariation(int);
    int SetVolume(int);
    void Stop();
    ~CNWSSoundObject();
    CNWSSoundObject(unsigned long);

    /* 0x1C4/452 */ unsigned long Active;
    /* 0x1C8/456 */ unsigned long Positional;
    /* 0x1CC/460 */ unsigned long Looping;
    /* 0x1D0/464 */ unsigned long Volume;
    /* 0x1D4/468 */ unsigned long VolumeVrtn;
    /* 0x1D8/472 */ unsigned long Times;
    /* 0x1DC/476 */ float PitchVariation;
    /* 0x1E0/480 */ unsigned long Hours;
    /* 0x1E4/484 */ unsigned char GeneratedType;
    /* 0x1E5/485 */ unsigned char field_1E5;
    /* 0x1E6/486 */ unsigned char field_1E6;
    /* 0x1E7/487 */ unsigned char field_1E7;
    /* 0x1E8/488 */ unsigned long RandomPosition;
    /* 0x1EC/492 */ float RandomRangeX;
    /* 0x1F0/496 */ float RandomRangeY;
    /* 0x1F4/500 */ CExoArrayList<CResRef> Sounds;
    /* 0x200/512 */ unsigned long Interval;
    /* 0x204/516 */ unsigned long IntervalVariation;
    /* 0x208/520 */ float MinDistance;
    /* 0x20C/524 */ float MaxDistance;
    /* 0x210/528 */ unsigned long Continuous;
    /* 0x214/532 */ unsigned long Random;
};

static_assert_size(CNWSSoundObject, 0x218);

#endif
