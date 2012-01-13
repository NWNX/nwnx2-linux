#ifndef _VECTOR_H_
#define _VECTOR_H_
#include "nwndef.h"

class Vector
{
public:
	int Normalize();
	int operator-=(Vector const &);
	int operator+=(Vector const &);

	/* 0x0/0 */ float X;
	/* 0x4/4 */ float Y;
	/* 0x8/8 */ float Z;
};
#endif
