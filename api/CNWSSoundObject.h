#ifndef _CNWSSOUNDOBJECT_H_
#define _CNWSSOUNDOBJECT_H_
#include "nwndef.h"
#include "Vector.h"
#include "nwnstructs.h"

class CNWSSoundObject
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

};
#endif
