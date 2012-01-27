#ifndef _CEXOARRAYLIST_H_
#define _CEXOARRAYLIST_H_
#include "nwndef.h"

template <class T>
class CExoArrayList
{
public:
	int AddUnique(T);
	int Add(T);
	int Allocate(int);
	int Contains(T);
	int DelIndex(int);
	int DerefContains(T);
	int IndexOf(T);
	int Insert(T, int);
	int Pack();
	int Remove(T);
	int SetSize(int);
	~CExoArrayList();
	int operator=(CExoArrayList<T> const &);
	CExoArrayList(int);
	CExoArrayList(CExoArrayList<T> const &);
	T &operator[](int) const;
	T &operator[](int);

	/* 0x0/0 */ T *Array;
	/* 0x4/4 */ unsigned long nAllocatedSize;
	/* 0x8/8 */ unsigned long nUsedSize;
};
#endif
