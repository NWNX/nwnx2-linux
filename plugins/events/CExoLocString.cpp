#include <stdlib.h>
#include "CExoLocString.h"

CExoLocStringElement *CExoLocString::GetLangEntry(dword nLocale)
{
    if (this->StrRef != -1) return NULL;
    CExoLocStringElement *pLangEntry;
    CExoLinkedListElement *pText = this->List->GetFirst();
    while (pText) {
        pLangEntry = (CExoLocStringElement *) this->List->GetAtPos(pText);
        if (pLangEntry->LangID == nLocale) return pLangEntry;
        pText = this->List->GetNext(pText);
    }
    return NULL;
}


char *CExoLocString::GetStringText(dword nLocale)
{
    if (this->StrRef != -1) return NULL;
    CExoLocStringElement *pLangEntry;
    CExoLinkedListElement *pText = this->List->GetFirst();
    while (pText) {
        pLangEntry = (CExoLocStringElement *) this->List->GetAtPos(pText);
        if (pLangEntry->LangID == nLocale) return pLangEntry->Text.Text;
        pText = this->List->GetNext(pText);
    }
    return NULL;
}
