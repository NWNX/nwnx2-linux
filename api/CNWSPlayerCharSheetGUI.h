#ifndef _CNWSPLAYERCHARSHEETGUI_H_
#define _CNWSPLAYERCHARSHEETGUI_H_
#include "nwndef.h"

class CNWSPlayerCharSheetGUI
{
public:
	int ComputeCharacterSheetUpdateRequired(CNWSPlayer *);
	int SetCreatureDisplayed(unsigned long);

};
#endif
