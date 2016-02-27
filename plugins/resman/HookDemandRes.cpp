#include "nx_devel.h"
#include "nx_hook.h"
#include "NWNXResMan.h"

// For backtrace.
#include <execinfo.h>

extern CNWNXResMan resman;

static NwnResType lastResType;
static CResRef lastResRef;
static CExoKeyTable keytable;

int (*CExoResMan__GetKeyEntry)(CExoResMan *, CResRef const &, unsigned short, CExoKeyTable **, CKeyTableEntry **);
char *(*CExoResMan__Demand)(CExoResMan *, CRes *);

void (*CRes__ctor)(CRes *);
void (*CRes__ctor2)(CRes *, uint32_t);
void (*CRes__dtor)(CRes *, char);

void CRes__dtor_hook(CRes *res, char del)
{
    resman.Log(4, "Destructing %p (%d)\n", res, del);
    CRes__dtor(res, del);
}

void CRes__ctor_hook(CRes *res)
{
    CRes__ctor(res);
    resman.Log(4, "Creating CRes %p of vtble: %p\n", res, res->vptr);

    int nptrs;
    void *buffer[10];
    char **strings;

    nptrs = backtrace(buffer, 10);
    strings = backtrace_symbols(buffer, nptrs);
    if (strings != NULL) {
        resman.Log(4, "  Bactrace return %d addresses\n", nptrs);
        for (int j = 0; j < nptrs; j++) {
            resman.Log(4, "    %s\n", strings[j]);
        }
        free(strings);
    }
}

void CRes__ctor2_hook(CRes *res, uint32_t something)
{
    CRes__ctor2(res, something);
    resman.Log(4, "Creating CRes %p\n of type: %p", res, res->vptr);

    int nptrs;
    void *buffer[10];
    char **strings;

    nptrs = backtrace(buffer, 10);
    strings = backtrace_symbols(buffer, nptrs);
    if (strings != NULL) {
        resman.Log(4, "  Bactrace return %d addresses\n", nptrs);
        for (int j = 0; j < nptrs; j++) {
            resman.Log(4, "    %s\n", strings[j]);
        }
        free(strings);
    }
}

int CExoResMan__GetKeyEntry_hook(CExoResMan *pthis, CResRef const &resRef, unsigned short resType, CExoKeyTable **v1, CKeyTableEntry **v2)
{

    lastResRef = resRef;
    lastResType = (NwnResType)resType;
    int result = CExoResMan__GetKeyEntry(pthis, lastResRef, lastResType, v1, v2);
    if (resman.ResourceExists(resRef, (NwnResType) resType, v2)) {
        result = 1;
        *v1 = &keytable;
    }
    return result;
}

void* CExoResMan__Demand_hook(CExoResMan *pthis, CRes *cRes)
{
    void *lastRet = resman.DemandRes(pthis, cRes, lastResRef, lastResType);
    if (lastRet) {
        return lastRet;
    } else {
        return CExoResMan__Demand(pthis, cRes);
    }
}

int HookFunctions()
{
    NX_HOOK(CExoResMan__GetKeyEntry, 0x082AFF20, CExoResMan__GetKeyEntry_hook, 5);
    NX_HOOK(CExoResMan__Demand, 0x082AF408, CExoResMan__Demand_hook, 5);

    if (resman.debugCRes) {
        NX_HOOK(CRes__ctor, 0x082B35C8, CRes__ctor_hook, 6);
        NX_HOOK(CRes__ctor2, 0x082B3624, CRes__ctor2_hook, 6);
        NX_HOOK(CRes__dtor, 0x082B3668, CRes__dtor_hook, 5);
    }

    keytable.TableID = 0;
    lastResRef.m_resRef[0] = 0;
    return 1;
}
