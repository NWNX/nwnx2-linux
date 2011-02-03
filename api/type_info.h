#ifndef _TYPE_INFO_H_
#define _TYPE_INFO_H_
#include "nwndef.h"

class type_info
{
public:
	~type_info();
	type_info(char const *);
	int operator==(type_info const &) const;
	int operator!=(type_info const &) const;
	int before(type_info const &) const;
	int name() const;

};
#endif
