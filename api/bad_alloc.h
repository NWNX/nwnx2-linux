#ifndef _BAD_ALLOC_H_
#define _BAD_ALLOC_H_
#include "nwndef.h"

class bad_alloc
{
public:
	~bad_alloc();
	int what() const;

};
#endif
