#ifndef _MS_RSAVLONG_H_
#define _MS_RSAVLONG_H_
#include "nwndef.h"

class MS_RSAVLong
{
public:
    ~MS_RSAVLong();
    MS_RSAVLong(MS_RSAVLong const &);
    MS_RSAVLong(unsigned int);
    MS_RSAVLong & operator-=(MS_RSAVLong const &);
    MS_RSAVLong & operator+=(MS_RSAVLong const &);
    MS_RSAVLong & operator=(MS_RSAVLong const &);
    int cf(MS_RSAVLong const &) const;
    void docopy();
    int is_negative() const;
    int is_zero() const;
    void shiftLeft32();
    void shiftRight32();

};
#endif
