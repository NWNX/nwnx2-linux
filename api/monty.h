#ifndef _MONTY_H_
#define _MONTY_H_
#include "nwndef.h"

class monty
{
public:
	monty(MS_RSAVLong const &);
	int exp(MS_RSAVLong const &, MS_RSAVLong const &);
	int mul(MS_RSAVLong &, MS_RSAVLong const &);

};
#endif
