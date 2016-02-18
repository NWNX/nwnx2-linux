#ifndef _CRESLTR_H_
#define _CRESLTR_H_
#include "nwndef.h"
#include "CRes.h"

class CResLTR  : public CRes
{
public:
    int GetEndDoubleLetterProb();
    int GetEndSingleLetterProb();
    int GetEndTripleLetterProb();
    int GetLTRHeaderPtr();
    int GetMiddleDoubleLetterProb();
    int GetMiddleSingleLetterProb();
    int GetMiddleTripleLetterProb();
    int GetStartDoubleLetterProb();
    int GetStartSingleLetterProb();
    int GetStartTripleLetterProb();
    int OnResourceFreed();
    int OnResourceServiced();
    ~CResLTR();
    CResLTR();

};
#endif
