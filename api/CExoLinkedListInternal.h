#ifndef _CEXOLINKEDLISTINTERNAL_H_
#define _CEXOLINKEDLISTINTERNAL_H_
#include "nwndef.h"

class CExoLinkedListInternal
{
public:
	int AddAfter(void *, CExoLinkedListNode *);
	int AddBefore(void *, CExoLinkedListNode *);
	int AddHead(void *);
	int AddTail(void *);
	int GetAtPos(CExoLinkedListNode *);
	int GetNext(CExoLinkedListNode *&);
	int GetPrev(CExoLinkedListNode *&);
	int RemoveHead();
	int RemoveTail();
	int Remove(CExoLinkedListNode *);
	~CExoLinkedListInternal();

	/* 0x0/0 */ void *FirstElement;
	/* 0x4/4 */ void *LastElement;
	/* 0x8/8 */ unsigned long Count;
};
#endif
