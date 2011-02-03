#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include "nwndef.h"

class exception
{
public:
	~exception();
	exception();
	int what() const;

};
#endif
