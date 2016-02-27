#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <stdint.h>
typedef void * HANDLE;
#define FALSE 0
#define TRUE 1

typedef void * HINSTANCE;
typedef void * HWND;
typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef unsigned char	BYTE;

/* A generic type describing nwn object IDs.
 * Internally, they're the upper half of signed 32bit integers:
 *
 * 0x0 is always the module
 * 0x00000001 is always the first area
 * 0x00000002 to 0x7effffff are objects in order as they are created.
 * 0x7f000000 is a special const meaning OBJECT_INVALID
 * 0x7fffffff is the first player to log in
 * 0x7ffffffe the second player to log in; and so on.
 */
typedef unsigned long nwobjid;

#define MAX_PATH          260
#define CALLBACK
#endif
