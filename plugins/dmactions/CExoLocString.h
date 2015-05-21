#ifndef _CEXOLOCSTRING_H_
#define _CEXOLOCSTRING_H_

#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <stdarg.h>

#include "typedefs.h"
#include "CExoLinkedList.h"

/*
struct CExoString
{
	char *Text;
	dword Length;
};
*/
struct CExoLocStringElement_1 {
    dword      LangID;
    CExoString Text;
};

/*
http://nwn.bioware.com/developers/Bioware_Aurora_LocalizedStrings_Format.pdf
*/

class CExoLocString_c
{
public:
    CExoLinkedList *List;
    dword           StrRef;

    char                   *GetStringText(dword nLocale);
    CExoLocStringElement_1 *GetLangEntry(dword nLocale);
    int                    AddString(dword nLocale, char *sString);
};

#endif
