#ifndef ___CLASS_TYPE_INFO_H_
#define ___CLASS_TYPE_INFO_H_
#include "nwndef.h"

class __class_type_info
{
public:
	~__class_type_info();
	int do_find_public_subobj(int, type_info const &, void *, void *) const;

};
#endif
