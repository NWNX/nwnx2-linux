#ifndef _CNWCREATURESTATSUPDATE_H_
#define _CNWCREATURESTATSUPDATE_H_
#include "nwndef.h"
#include "CCombatInformation.h"

class CNWCreatureStatsUpdate
{
public:
	void ClearEffectIcons();
	void SetCombatInformation(CCombatInformation *);
	~CNWCreatureStatsUpdate();
	CNWCreatureStatsUpdate();

};
#endif
