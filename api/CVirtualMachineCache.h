#ifndef _CVIRTUALMACHINECACHE_H_
#define _CVIRTUALMACHINECACHE_H_
#include "nwndef.h"
#include "CExoString.h"

class CVirtualMachineCache
{
public:
	void ClearAllFiles();
	void PrecacheFile(CExoString const &);
	~CVirtualMachineCache();

};
#endif
