#ifndef _FLEX_UNIT_H_
#define _FLEX_UNIT_H_
#include "nwndef.h"

class flex_unit
{
public:
	~flex_unit();
	flex_unit();
	int clear();
	int fast_mul(flex_unit &, flex_unit &, unsigned int);
	int get(unsigned int) const;
	int reserve(unsigned int);
	int set(unsigned int, unsigned int);
	int shiftLeft32();
	int shiftRight32();

};
#endif
