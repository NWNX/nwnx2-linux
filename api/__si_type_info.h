#ifndef ___SI_TYPE_INFO_H_
#define ___SI_TYPE_INFO_H_
#include "nwndef.h"

class __si_type_info
{
public:
	~__si_type_info();
	__si_type_info(char const *, __user_type_info const &);
	int do_find_public_subobj(int, type_info const &, void *, void *) const;

};
#endif
