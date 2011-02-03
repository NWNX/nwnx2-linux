#ifndef ___USER_TYPE_INFO_H_
#define ___USER_TYPE_INFO_H_
#include "nwndef.h"

class __user_type_info
{
public:
	~__user_type_info();
	__user_type_info(char const *);
	int do_find_public_subobj(int, type_info const &, void *, void *) const;
	int dyncast(int, type_info const &, void *, type_info const &, void *) const;
	int find_public_subobj(int, type_info const &, void *, void *) const;
	int upcast(type_info const &, void *, void **) const;

};
#endif
