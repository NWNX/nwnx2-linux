#ifndef _CNWSPLAYERCHARSHEETGUI_H_
#define _CNWSPLAYERCHARSHEETGUI_H_
#include "nwndef.h"

class CNWSPlayerCharSheetGUI
{
public:
    unsigned long ComputeCharacterSheetUpdateRequired(CNWSPlayer *);
    void SetCreatureDisplayed(unsigned long);

    unsigned long ObjectID;
    char UpdatedList; // 1: skills, 2: feats
    char field_5;
    char field_6;
    char field_7;
    CNWCreatureStatsUpdate* CreatureStatsUpdate;
};
#endif
