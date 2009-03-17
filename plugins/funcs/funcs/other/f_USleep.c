#include "NWNXFuncs.h"
#include <unistd.h>

void Func_Sleep (CGameObject *ob, char *value) {
	unsigned int usec = atoi(value);
	if (usec < 0)
		usec = 0;

	sleep(usec);
}

/* vim: set sw=4: */
