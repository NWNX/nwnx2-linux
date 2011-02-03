#ifndef _MS_RSAVLONG_H_
#define _MS_RSAVLONG_H_
#include "nwndef.h"

class MS_RSAVLong
{
public:
	~MS_RSAVLong();
	MS_RSAVLong(MS_RSAVLong const &);
	MS_RSAVLong(unsigned int);
	int operator-=(MS_RSAVLong const &);
	int operator+=(MS_RSAVLong const &);
	int operator=(MS_RSAVLong const &);
	int cf(MS_RSAVLong const &) const;
	int docopy();
	int is_negative() const;
	int is_zero() const;
	int shiftLeft32();
	int shiftRight32();

};
#endif
