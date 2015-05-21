#ifndef _CNWSEXPRESSION_H_
#define _CNWSEXPRESSION_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWSExpression
{
public:
    void ClearAlternate(CNWSExpressionNode *);
    int ClearGraph();
    CNWSExpressionNode * NewNode(int);
    int ParseString(CExoString);
    int TestString(CExoString const &, int);
    ~CNWSExpression();
    CNWSExpression();

};
#endif
