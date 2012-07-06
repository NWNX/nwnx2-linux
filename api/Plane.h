#ifndef _PLANE_H_
#define _PLANE_H_
#include "nwndef.h"
#include "Vector.h"
#include "nwnstructs.h"

class Plane
{
public:
	int Transform(Vector const &, Quaternion const &);

};
#endif
