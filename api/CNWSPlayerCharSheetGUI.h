#ifndef _CNWSPLAYERCHARSHEETGUI_H_
#define _CNWSPLAYERCHARSHEETGUI_H_
#include "nwndef.h"
#include "CNWSPlayer.h"

class CNWSPlayerCharSheetGUI
{
public:
	unsigned long ComputeCharacterSheetUpdateRequired(CNWSPlayer *);
	void SetCreatureDisplayed(unsigned long);

};
#endif
