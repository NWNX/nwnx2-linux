#ifndef SYSTEM_H__
#define SYSTEM_H__ 1

#include <stdint.h>

typedef int (*FSortFunc)(void*, void*);

typedef struct {
    void**		items;
    int			realCount;
    int			limit;
    int			increment;

    FSortFunc	sortFunc;
}
SortedList;

struct LIST_INTERFACE {
    int    cbSize;

    SortedList* (*List_Create)(int, int);
    void (*List_Destroy)(SortedList*);

    void*	(*List_Find)(SortedList*, void*);
    int	(*List_GetIndex)(SortedList*, void*, int*);
    int (*List_Insert)(SortedList*, void*, int);
    int (*List_Remove)(SortedList*, int);
    int (*List_IndexOf)(SortedList*, void*);

#if MIRANDA_VER >= 0x0600
    int (*List_InsertPtr)(SortedList* list, void* p);
    int (*List_RemovePtr)(SortedList* list, void* p);
#endif
};

/* Missing service catcher
Is being called when one calls the non-existent service.
All parameters are stored in the special structure

The event handler takes 0 as wParam and TMissingServiceParams* as lParam.

0.4.3+ addition (2006/03/27)
*/

typedef struct {
    const char* name;
    uintptr_t pParam;
}
MISSING_SERVICE_PARAMS;

#define ME_SYSTEM_MISSINGSERVICE "System/MissingService"

#endif // M_SYSTEM_H

