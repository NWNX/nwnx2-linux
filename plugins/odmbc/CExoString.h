#ifndef _CExoString_h_
#define _CExoString_h_

#include <string.h>

class CExoString
{
public:
    char *Text;
    unsigned int Length;

    CExoString();
    CExoString(const char *str);
    bool operator==(const char *str);
    CExoString *operator=(char const *str);
    ~CExoString();
};

#endif

