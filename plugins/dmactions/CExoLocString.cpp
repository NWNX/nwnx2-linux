#include <stdlib.h>
#include <string.h>
#include "CExoLocString.h"

CExoLocStringElement_1 *CExoLocString_c::GetLangEntry(dword nLocale)
{
    if (this->StrRef != -1) return NULL;
    CExoLocStringElement_1 *pLangEntry;
    CExoLinkedListElement *pText = this->List->GetHeadPos();
    while (pText) {
        pLangEntry = (CExoLocStringElement_1 *) this->List->GetAtPos(pText);
        if (pLangEntry->LangID == nLocale) return pLangEntry;
        pText = this->List->GetNext(pText);
    }
    return NULL;
}


char *CExoLocString_c::GetStringText(dword nLocale)
{
    if (this->StrRef != -1) return NULL;
    CExoLocStringElement_1 *pLangEntry;
    CExoLinkedListElement *pText = this->List->GetHeadPos();
    while (pText) {
        pLangEntry = (CExoLocStringElement_1 *) this->List->GetAtPos(pText);
        if (pLangEntry->LangID == nLocale) return pLangEntry->Text.Text;
        pText = this->List->GetNext(pText);
    }
    return NULL;
}

int CExoLocString_c::AddString(dword nLocale, char *sString)
{
    CExoLocStringElement_1 *pCurrentData;
    CExoLocStringElement_1 *pNewEntry;
    CExoLinkedListElement *pCurrentElement;

    pCurrentElement = this->List->GetHeadPos();
    pCurrentData = (CExoLocStringElement_1 *) this->List->GetHead();
    while (pCurrentData) {
        if (pCurrentData->LangID == nLocale) {
            if (pCurrentData->Text.Text)
                delete[] pCurrentData->Text.Text;
            pCurrentData->Text.Text = sString;
            //delete[] sString;
            return 1;
        }
        pCurrentData = (CExoLocStringElement_1 *)this->List->GetNext(pCurrentElement);
    }
    pNewEntry = new CExoLocStringElement_1;
    if (!pNewEntry) {
        delete[] sString;
        return 0;
    }
    pNewEntry->LangID = nLocale;
    pNewEntry->Text.Text = sString;
    this->List->AddTail(pNewEntry);
    ++this->List->Count;
    //delete[] sString;
    return 1;
}
