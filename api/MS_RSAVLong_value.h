#ifndef _MS_RSAVLONG_VALUE_H_
#define _MS_RSAVLONG_VALUE_H_
#include "nwndef.h"

class MS_RSAVLong_value
{
public:
	MS_RSAVLong_value();
	int add(MS_RSAVLong_value &);
	int bits() const;
	int cf(MS_RSAVLong_value &) const;
	int copy(MS_RSAVLong_value &);
	int divide(MS_RSAVLong_value &, MS_RSAVLong_value &, MS_RSAVLong_value &);
	int init(unsigned int);
	int is_zero() const;
	int mul(MS_RSAVLong_value &, MS_RSAVLong_value &);
	int shl();
	int shr();
	int shr(unsigned int);
	int subtract(MS_RSAVLong_value &);
	int test(unsigned int) const;

};
#endif
