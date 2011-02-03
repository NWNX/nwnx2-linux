#ifndef _CNWSEXPRESSION_H_
#define _CNWSEXPRESSION_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWSExpression
{
public:
	int ClearAlternate(CNWSExpressionNode *);
	int ClearGraph();
	int NewNode(int);
	int ParseString(CExoString);
	int TestString(CExoString const &, int);
	~CNWSExpression();
	CNWSExpression();

};
#endif
