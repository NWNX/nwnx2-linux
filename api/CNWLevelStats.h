#ifndef _CNWLEVELSTATS_H_
#define _CNWLEVELSTATS_H_
#include "nwndef.h"

class CNWLevelStats
{
public:
    void AddFeat(unsigned short);
    int ClearFeats();
    char GetSkillRankChange(unsigned short);
    void SetSkillRankChange(unsigned short, char);
    ~CNWLevelStats();
    CNWLevelStats();

};
#endif
