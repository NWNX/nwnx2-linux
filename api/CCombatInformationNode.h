#ifndef _CCOMBATINFORMATIONNODE_H_
#define _CCOMBATINFORMATIONNODE_H_
#include "nwndef.h"

class CCombatInformationNode
{
public:
    CCombatInformationNode();
    int operator=(CCombatInformationNode const &);
    int operator==(CCombatInformationNode &);
    int operator!=(CCombatInformationNode &);

};
#endif
