#ifndef _CNWLEVELSTATS_H_
#define _CNWLEVELSTATS_H_
#include "nwndef.h"

class CNWLevelStats
{
public:
	int AddFeat(unsigned short);
	int ClearFeats();
	int GetSkillRankChange(unsigned short);
	int SetSkillRankChange(unsigned short, char);
	~CNWLevelStats();
	CNWLevelStats();

};
#endif
