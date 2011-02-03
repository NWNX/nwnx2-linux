#ifndef _CVIRTUALMACHINECACHE_H_
#define _CVIRTUALMACHINECACHE_H_
#include "nwndef.h"

class CVirtualMachineCache
{
public:
	int ClearAllFiles();
	int PrecacheFile(CExoString const &);
	~CVirtualMachineCache();

};
#endif
