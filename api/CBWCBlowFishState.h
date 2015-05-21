#ifndef _CBWCBLOWFISHSTATE_H_
#define _CBWCBLOWFISHSTATE_H_
#include "nwndef.h"
#include "CBWCBlowFishBlock.h"

class CBWCBlowFishState
{
public:
    int GetChain();
    int ResetChain();
    int SetChain(CBWCBlowFishBlock);
    ~CBWCBlowFishState();
    CBWCBlowFishState(CBWCBlowFishBlock);
    CBWCBlowFishState(CBWCBlowFishState const &);

};
#endif
