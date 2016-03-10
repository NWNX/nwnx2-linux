#pragma once

#ifdef REALTIME_EXPORTS
#define REALTIME_API extern "C" __declspec(dllexport)
#else
#define REALTIME_API extern "C" __declspec(dllimport)
#endif

REALTIME_API NWNXBase* GetClassObject();