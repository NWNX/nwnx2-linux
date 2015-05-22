#include "NWNXFuncs.h"

void Func_USleep(CGameObject *ob, char *value)
{
    int usec = atoi(value);
    struct timeval tv;

    if (usec <= 0)
        return;

    tv.tv_sec  = 0;
    tv.tv_usec = usec;

    select(0, NULL, NULL, NULL, &tv);
}

/* vim: set sw=4: */
