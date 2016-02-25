#pragma once

#include "typedef.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_MAKE_VERSION(a,b,c,d) (((((DWORD)(a))&0xFF)<<24)|((((DWORD)(b))&0xFF)<<16)|((((DWORD)(c))&0xFF)<<8)|(((DWORD)(d))&0xFF))

typedef struct {
    int cbSize;
    char *shortName;
    DWORD version;
    char *description;
    char *author;
    char *authorEmail;
    char *copyright;
    char *homepage;
    BYTE flags;
} PLUGININFO;
