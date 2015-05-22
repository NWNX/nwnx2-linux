#ifndef _MS_RSAVLONG_VALUE_H_
#define _MS_RSAVLONG_VALUE_H_
#include "nwndef.h"

class MS_RSAVLong_value
{
public:
    MS_RSAVLong_value();
    void add(MS_RSAVLong_value &);
    unsigned int bits() const;
    int cf(MS_RSAVLong_value &) const;
    void copy(MS_RSAVLong_value &);
    void divide(MS_RSAVLong_value &, MS_RSAVLong_value &, MS_RSAVLong_value &);
    void init(unsigned int);
    int is_zero() const;
    void mul(MS_RSAVLong_value &, MS_RSAVLong_value &);
    void shl();
    void shr();
    void shr(unsigned int);
    void subtract(MS_RSAVLong_value &);
    int test(unsigned int) const;

};
#endif
