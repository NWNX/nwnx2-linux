#ifndef _CNWCREATURESTATSUPDATE_H_
#define _CNWCREATURESTATSUPDATE_H_
#include "nwndef.h"

class CNWCreatureStatsUpdate
{
public:
	int ClearEffectIcons();
	int SetCombatInformation(CCombatInformation *);
	~CNWCreatureStatsUpdate();
	CNWCreatureStatsUpdate();

};
#endif
