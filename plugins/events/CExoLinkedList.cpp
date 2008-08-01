#include <stdlib.h>
#include "CExoLinkedList.h"

CExoLinkedListElement *CExoLinkedList::GetFirst()
{
	return this->ListHeader->FirstElement;
}

void *CExoLinkedList::GetAtPos(CExoLinkedListElement *Position)
{
	if(!Position) return NULL;
	return Position->Data;
}

CExoLinkedListElement *CExoLinkedList::GetNext(CExoLinkedListElement *Position)
{
	if(!Position) return NULL;
	return Position->NextElement;
}
