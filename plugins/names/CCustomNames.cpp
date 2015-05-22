#include "CCustomNames.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//############################# CPlayerNames #############################

CPlayerNames::CPlayerNames()
{
    //if(data&&capacity) return;
    data = NULL;
    size = 0;
    capacity = 0;
    bEnabled = 0;
    data = (NameEntry*) malloc(sizeof(NameEntry) * ALLOC_SIZE);
    if (!data) return;
    size = 0;
    capacity = ALLOC_SIZE;
}

void CPlayerNames::Construct()
{
    //if(data&&capacity) return;
    data = NULL;
    size = 0;
    capacity = 0;
    bEnabled = 0;
    data = (NameEntry*) malloc(sizeof(NameEntry) * ALLOC_SIZE);
    if (!data) return;
    size = 0;
    capacity = ALLOC_SIZE;
}


CPlayerNames::~CPlayerNames()
{
    if (!data) return;
    for (int i = 0; i < size; i++) {
        NameEntry *pNameEntry = &data[i];
        if (pNameEntry->sCustomName) {
            free(pNameEntry->sCustomName);
            pNameEntry->sCustomName = NULL;
        }
    }
    free(data);
    data = NULL;
}

void CPlayerNames::AllocNewMemory()
{
    data = (NameEntry*) realloc(data, sizeof(NameEntry) * (capacity + ALLOC_SIZE));
    if (!data) return;
    capacity = capacity + ALLOC_SIZE;
}

void CPlayerNames::InsertCustomName(dword ObjID, char *CustomName)
{
    if (size >= capacity) this->AllocNewMemory();
    if (!data) return;
    NameEntry *pNameEntry = &data[size];
    pNameEntry->TargetObjID = ObjID;
    pNameEntry->sCustomName = CustomName;
    size++;
}

NameEntry *CPlayerNames::FindEntryByObjectID(dword ObjID)
{
    if (!data) return NULL;
    for (int i = 0; i < size; i++) {
        NameEntry *pNameEntry = &data[i];
        if (pNameEntry->TargetObjID == ObjID) return pNameEntry;
    }
    return NULL;
}

int CPlayerNames::FindNumByObjectID(dword ObjID)
{
    if (!data) return -1;
    for (int i = 0; i < size; i++) {
        NameEntry *pNameEntry = &data[i];
        if (pNameEntry->TargetObjID == ObjID) return i;
    }
    return -1;
}

void CPlayerNames::DeleteByObjectID(dword ObjID)
{
    if (!data) return;
    int nPos = this->FindNumByObjectID(ObjID);
    if (nPos == -1) return;
    NameEntry *pNameEntry = &data[nPos];
    if (pNameEntry->sCustomName) free(pNameEntry->sCustomName);
    memcpy(&data[nPos + 1], pNameEntry, (size - nPos - 1)*sizeof(NameEntry));
    size--;
}

//############################# CCustomNames #############################

CCustomNames::CCustomNames()
{
    data = NULL;
    size = 0;
    capacity = 0;
    data = (CPlayerNames*) malloc(sizeof(CPlayerNames) * ALLOC_SIZE);
    if (!data) return;
    size = 0;
    capacity = ALLOC_SIZE;
}

CCustomNames::~CCustomNames()
{
    if (!data) return;
    for (int i = 0; i < size; i++) {
        CPlayerNames *pPlayerNames = &data[i];
        pPlayerNames->~CPlayerNames();
    }
    free(data);
}

void CCustomNames::AllocNewMemory()
{
    data = (CPlayerNames*) realloc(data, sizeof(CPlayerNames) * (capacity + ALLOC_SIZE));
    if (!data) return;
    capacity = capacity + ALLOC_SIZE;
}

CPlayerNames *CCustomNames::InsertPlayer(dword ObjID, int nStyle, bool bEnabled = 0)
{
    if (size >= capacity) this->AllocNewMemory();
    if (!data) return NULL;
    CPlayerNames *pPlayerEntry = &data[size];
    pPlayerEntry->PlayerObjID = ObjID;
    pPlayerEntry->UnknownStyle = nStyle;
    pPlayerEntry->Construct();
    pPlayerEntry->bEnabled = bEnabled;
    if (!pPlayerEntry->data) return NULL;
    size++;
    return pPlayerEntry;
}

CPlayerNames *CCustomNames::FindPlayerEntry(dword ObjID)
{
    if (!data) return NULL;
    for (int i = 0; i < size; i++) {
        CPlayerNames *pPlayerEntry = &data[i];
        if (pPlayerEntry->PlayerObjID == ObjID) return pPlayerEntry;
    }
    return NULL;
}

int CCustomNames::FindPlayerID(dword ObjID)
{
    if (!data) return -1;
    for (int i = 0; i < size; i++) {
        CPlayerNames *pPlayerEntry = &data[i];
        if (pPlayerEntry->PlayerObjID == ObjID) return i;
    }
    return -1;
}

void CCustomNames::DeletePlayer(dword ObjID)
{
    if (!data) return;
    int nPos = this->FindPlayerID(ObjID);
    if (nPos == -1) return;
    CPlayerNames *pPlayerEntry = &data[nPos];
    pPlayerEntry->~CPlayerNames();
    memcpy(&data[nPos + 1], pPlayerEntry, (size - nPos - 1)*sizeof(NameEntry));
    size--;
}

void CCustomNames::InsertCustomName(dword ObjID1, dword ObjID2, char *CustomName)
{
    CPlayerNames *pPlayerEntry = this->FindPlayerEntry(ObjID1);
    if (!pPlayerEntry) return;
    NameEntry *pNameEntry = pPlayerEntry->FindEntryByObjectID(ObjID2);
    if (pNameEntry) {
        if (pNameEntry->sCustomName) delete[] pNameEntry->sCustomName;
        pNameEntry->sCustomName = CustomName;
    } else {
        pPlayerEntry->InsertCustomName(ObjID2, CustomName);
    }
}

char *CCustomNames::FindCustomName(dword ObjID1, dword ObjID2)
{
    CPlayerNames *pPlayerEntry = this->FindPlayerEntry(ObjID1);
    if (!pPlayerEntry) return NULL;
    NameEntry *pNameEntry = pPlayerEntry->FindEntryByObjectID(ObjID2);
    if (pNameEntry) {
        return pNameEntry->sCustomName;
    }
    return NULL;
}
