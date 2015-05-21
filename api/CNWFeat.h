#ifndef _CNWFEAT_H_
#define _CNWFEAT_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWFeat
{
public:
    int GetDescriptionText();
    CExoString GetNameText();
    ~CNWFeat();
    CNWFeat();

};
#endif
