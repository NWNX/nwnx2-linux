#include "NWNXmysql.h"

CNWNXmysql pmysql;

extern "C" {
CNWNXBase* GetClassObject()
{
	return &pmysql;
}
}
