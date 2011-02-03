#ifndef _CNWSEXPRESSIONLIST_H_
#define _CNWSEXPRESSIONLIST_H_
#include "nwndef.h"

class CNWSExpressionList
{
public:
	int AddNodeToHead(CNWSExpressionNode *);
	int AddNode(CNWSExpressionNode *);
	int DeleteAlternate(CNWSExpressionNode *);
	int DeleteList();
	~CNWSExpressionList();
	CNWSExpressionList();

};
#endif
