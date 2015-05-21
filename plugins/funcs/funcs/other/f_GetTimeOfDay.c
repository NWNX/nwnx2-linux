#include "NWNXFuncs.h"
#include <sys/time.h>

void Func_GetTimeOfDay(CGameObject *ob, char *value)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    snprintf(value, strlen(value), "%ld.%ld", t.tv_sec, t.tv_usec);
}

/* vim: set sw=4: */
