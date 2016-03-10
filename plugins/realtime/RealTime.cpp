#include "stdafx.h"
#include "NWNXRealTime.h"
#include "RealTime.h"

NWNXRealTime RealTime;

REALTIME_API NWNXBase* GetClassObject()
{
	return &RealTime;
}

BOOL APIENTRY DllMain (HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}