#ifndef _CNWSEXPRESSIONLIST_H_
#define _CNWSEXPRESSIONLIST_H_
#include "nwndef.h"

class CNWSExpressionList
{
public:
    int AddNodeToHead(CNWSExpressionNode *);
    void AddNode(CNWSExpressionNode *);
    void DeleteAlternate(CNWSExpressionNode *);
    int DeleteList();
    ~CNWSExpressionList();
    CNWSExpressionList();

};
#endif
