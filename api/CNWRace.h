#ifndef _CNWRACE_H_
#define _CNWRACE_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWRace
{
public:
    int GetConverNameLowerText();
    int GetConverNameText();
    int GetDefaultBiographyText();
    int GetDescriptionText();
    int GetNamePluralText();
    int GetNameText();
    int IsFirstLevelGrantedFeat(unsigned short);
    void LoadFeatsTable(CExoString);
    ~CNWRace();
    CNWRace();

};
#endif
