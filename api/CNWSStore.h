#ifndef _CNWSSTORE_H_
#define _CNWSSTORE_H_
#include "nwndef.h"
#include "CNWSObject.h"
#include "CExoLocString.h"
#include "CResRef.h"
#include "CExoString.h"

class CNWSStore : public CNWSObject
{
public:
    void AIUpdate();
    int AcquireItem(CNWSItem *, int, unsigned char, unsigned char);
    void AddCustomer(CNWSPlayer *, char, char);
    int AddGold(int);
    int AddItemToInventory(CNWSItem **, unsigned char, unsigned char, unsigned char);
    void AddToArea(CNWSArea *, float, float, float, int);
    CNWSStore * AsNWSStore();
    int CalculateItemBuyPrice(CNWSItem *, unsigned long);
    int CalculateItemSellPrice(CNWSItem *, unsigned long);
    void EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
    int GetAppropriateListId(unsigned long);
    int GetBlackMarketMarkDown();
    int GetBlackMarket();
    unsigned char GetCustomerBuyRate(unsigned long, int);
    short GetCustomerSellRate(unsigned long);
    int GetCustomer(unsigned long);
    int GetGold();
    int GetIdentifyCost();
    int GetIsRestrictedBuyItem(int);
    int GetItemInInventory(CExoString *);
    int GetItemInInventory(unsigned long);
    int GetLastClosed();
    int GetLastOpened();
    int GetMarkDown();
    int GetMarkUp();
    int GetMaxBuyPrice();
    CExoLocString GetName();
    int GetRepositoryArrayIndex();
    int GetRepositoryListNumber();
    int GetRepository(unsigned char);
    int GetScriptName(int);
    int GetWillNotBuyItem(int);
    int GetWillNotBuyListSize();
    int GetWillOnlyBuyItem(int);
    int GetWillOnlyBuyListSize();
    int LoadFromTemplate(CResRef, CExoString *);
    int LoadStore(CResGFF *, CResStruct *, CExoString *);
    void RemoveCustomer(CNWSPlayer *);
    int RemoveFromArea();
    int RemoveGold(int);
    int RemoveItemFromInventory(CNWSItem *, unsigned char);
    void RemoveItem(CNWSItem *);
    int SaveStore(CResGFF *, CResStruct *);
    int SellItem(CNWSItem *, CNWSCreature *, unsigned char, unsigned char);
    int SetBlackMarketMarkDown(int);
    int SetBlackMarket(int);
    int SetGold(int);
    int SetIdentifyCost(int);
    int SetLastClosed(unsigned long);
    int SetLastOpened(unsigned long);
    int SetMarkDown(int);
    int SetMarkUp(int);
    int SetMaxBuyPrice(int);
    void SetName(CExoLocString);
    int SetRepositoryArrayIndex(unsigned short);
    int SetRepositoryListNumber(unsigned char);
    void SetScriptName(int, CExoString);
    ~CNWSStore();
    CNWSStore(unsigned long);

    /* 0x1C4/452 */ unsigned long field_1C4;
    /* 0x1C8/456 */ unsigned long field_1C8;
    /* 0x1CC/460 */ unsigned long field_1CC;
    /* 0x1D0/464 */ unsigned long field_1D0;
    /* 0x1D4/468 */ unsigned long field_1D4;
    /* 0x1D8/472 */ unsigned long field_1D8;
    /* 0x1DC/476 */ unsigned long field_1DC;
    /* 0x1E0/480 */ unsigned long field_1E0;
    /* 0x1E4/484 */ unsigned long field_1E4;
    /* 0x1E8/488 */ unsigned long field_1E8;
    /* 0x1EC/492 */ unsigned long field_1EC;
    /* 0x1F0/496 */ unsigned long field_1F0;
    /* 0x1F4/500 */ unsigned long field_1F4;
    /* 0x1F8/504 */ unsigned long field_1F8;
    /* 0x1FC/508 */ unsigned long field_1FC;
    /* 0x200/512 */ unsigned long field_200;
    /* 0x204/516 */ unsigned long field_204;
    /* 0x208/520 */ unsigned long field_208;
    /* 0x20C/524 */ unsigned long field_20C;
    /* 0x210/528 */ unsigned long field_210;
    /* 0x214/532 */ unsigned long field_214;
    /* 0x218/536 */ unsigned long field_218;
    /* 0x21C/540 */ unsigned long field_21C;
    /* 0x220/544 */ unsigned long field_220;
    /* 0x224/548 */ unsigned long field_224;
    /* 0x228/552 */ unsigned long field_228;
    /* 0x22C/556 */ unsigned long field_22C;
    /* 0x230/560 */ unsigned long field_230;
    /* 0x234/564 */ unsigned long field_234;
    /* 0x238/568 */ unsigned long field_238;
};
#endif
