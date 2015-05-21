#include <stdlib.h>
#include <string.h>
#include "CExoLocString.h"

CExoLocStringElement *CExoLocString::GetLangEntry(dword nLocale)
{
    if (this->StrRef != -1) return NULL;
    CExoLocStringElement *pLangEntry;
    CExoLinkedListElement *pText = this->List->GetHeadPos();
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
    CExoLinkedListElement *pText = this->List->GetHeadPos();
    while (pText) {
        pLangEntry = (CExoLocStringElement *) this->List->GetAtPos(pText);
        if (pLangEntry->LangID == nLocale) return pLangEntry->Text.Text;
        pText = this->List->GetNext(pText);
    }
    return NULL;
}

int CExoLocString::AddString(dword nLocale, char *sString)
{
    CExoLocStringElement *pCurrentData;
    CExoLocStringElement *pNewEntry;
    CExoLinkedListElement *pCurrentElement;

    pCurrentElement = this->List->GetHeadPos();
    pCurrentData = (CExoLocStringElement *) this->List->GetHead();
    while (pCurrentData) {
        if (pCurrentData->LangID == nLocale) {
            if (pCurrentData->Text.Text)
                delete[] pCurrentData->Text.Text;
            pCurrentData->Text.Text = sString;
            //delete[] sString;
            return 1;
        }
        pCurrentData = (CExoLocStringElement *)this->List->GetNext(pCurrentElement);
    }
    pNewEntry = new CExoLocStringElement;
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
