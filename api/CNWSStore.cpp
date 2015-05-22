#include "CNWSStore.h"

void CNWSStore::AIUpdate()
{
    asm("leave");
    asm("mov $0x08085bb8, %eax");
    asm("jmp *%eax");
}

int CNWSStore::AcquireItem(CNWSItem *, int, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08085404, %eax");
    asm("jmp *%eax");
}

void CNWSStore::AddCustomer(CNWSPlayer *, char, char)
{
    asm("leave");
    asm("mov $0x08085da0, %eax");
    asm("jmp *%eax");
}

int CNWSStore::AddGold(int)
{
    asm("leave");
    asm("mov $0x08086374, %eax");
    asm("jmp *%eax");
}

int CNWSStore::AddItemToInventory(CNWSItem **, unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08085690, %eax");
    asm("jmp *%eax");
}

void CNWSStore::AddToArea(CNWSArea *, float, float, float, int)
{
    asm("leave");
    asm("mov $0x08085b0c, %eax");
    asm("jmp *%eax");
}

CNWSStore * CNWSStore::AsNWSStore()
{
    asm("leave");
    asm("mov $0x08086144, %eax");
    asm("jmp *%eax");
}

int CNWSStore::CalculateItemBuyPrice(CNWSItem *, unsigned long)
{
    asm("leave");
    asm("mov $0x08085bc0, %eax");
    asm("jmp *%eax");
}

int CNWSStore::CalculateItemSellPrice(CNWSItem *, unsigned long)
{
    asm("leave");
    asm("mov $0x08085c60, %eax");
    asm("jmp *%eax");
}

void CNWSStore::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080852cc, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetAppropriateListId(unsigned long)
{
    asm("leave");
    asm("mov $0x08085d14, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetBlackMarketMarkDown()
{
    asm("leave");
    asm("mov $0x0808623c, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetBlackMarket()
{
    asm("leave");
    asm("mov $0x08086218, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSStore::GetCustomerBuyRate(unsigned long, int)
{
    asm("leave");
    asm("mov $0x08085f88, %eax");
    asm("jmp *%eax");
}

short CNWSStore::GetCustomerSellRate(unsigned long)
{
    asm("leave");
    asm("mov $0x08085f0c, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetCustomer(unsigned long)
{
    asm("leave");
    asm("mov $0x08085eb4, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetGold()
{
    asm("leave");
    asm("mov $0x08086328, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetIdentifyCost()
{
    asm("leave");
    asm("mov $0x08086390, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetIsRestrictedBuyItem(int)
{
    asm("leave");
    asm("mov $0x08085d40, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetItemInInventory(CExoString *)
{
    asm("leave");
    asm("mov $0x08086080, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetItemInInventory(unsigned long)
{
    asm("leave");
    asm("mov $0x08086018, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetLastClosed()
{
    asm("leave");
    asm("mov $0x080861f4, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetLastOpened()
{
    asm("leave");
    asm("mov $0x080861d0, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetMarkDown()
{
    asm("leave");
    asm("mov $0x08086260, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetMarkUp()
{
    asm("leave");
    asm("mov $0x08086284, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetMaxBuyPrice()
{
    asm("leave");
    asm("mov $0x080863b4, %eax");
    asm("jmp *%eax");
}

CExoLocString CNWSStore::GetName()
{
    asm("leave");
    asm("mov $0x08086300, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetRepositoryArrayIndex()
{
    asm("leave");
    asm("mov $0x08086438, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetRepositoryListNumber()
{
    asm("leave");
    asm("mov $0x0808645c, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetRepository(unsigned char)
{
    asm("leave");
    asm("mov $0x08086420, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetScriptName(int)
{
    asm("leave");
    asm("mov $0x080861b4, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetWillNotBuyItem(int)
{
    asm("leave");
    asm("mov $0x080863f8, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetWillNotBuyListSize()
{
    asm("leave");
    asm("mov $0x080863d8, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetWillOnlyBuyItem(int)
{
    asm("leave");
    asm("mov $0x0808640c, %eax");
    asm("jmp *%eax");
}

int CNWSStore::GetWillOnlyBuyListSize()
{
    asm("leave");
    asm("mov $0x080863e8, %eax");
    asm("jmp *%eax");
}

int CNWSStore::LoadFromTemplate(CResRef, CExoString *)
{
    asm("leave");
    asm("mov $0x08084074, %eax");
    asm("jmp *%eax");
}

int CNWSStore::LoadStore(CResGFF *, CResStruct *, CExoString *)
{
    asm("leave");
    asm("mov $0x08084230, %eax");
    asm("jmp *%eax");
}

void CNWSStore::RemoveCustomer(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08085e28, %eax");
    asm("jmp *%eax");
}

int CNWSStore::RemoveFromArea()
{
    asm("leave");
    asm("mov $0x08085b74, %eax");
    asm("jmp *%eax");
}

int CNWSStore::RemoveGold(int)
{
    asm("leave");
    asm("mov $0x0808634c, %eax");
    asm("jmp *%eax");
}

int CNWSStore::RemoveItemFromInventory(CNWSItem *, unsigned char)
{
    asm("leave");
    asm("mov $0x080859bc, %eax");
    asm("jmp *%eax");
}

void CNWSStore::RemoveItem(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08085cd8, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SaveStore(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08084db8, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SellItem(CNWSItem *, CNWSCreature *, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08085594, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetBlackMarketMarkDown(int)
{
    asm("leave");
    asm("mov $0x0808624c, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetBlackMarket(int)
{
    asm("leave");
    asm("mov $0x08086228, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetGold(int)
{
    asm("leave");
    asm("mov $0x08086338, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetIdentifyCost(int)
{
    asm("leave");
    asm("mov $0x080863a0, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetLastClosed(unsigned long)
{
    asm("leave");
    asm("mov $0x08086204, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetLastOpened(unsigned long)
{
    asm("leave");
    asm("mov $0x080861e0, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetMarkDown(int)
{
    asm("leave");
    asm("mov $0x08086270, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetMarkUp(int)
{
    asm("leave");
    asm("mov $0x08086294, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetMaxBuyPrice(int)
{
    asm("leave");
    asm("mov $0x080863c4, %eax");
    asm("jmp *%eax");
}

void CNWSStore::SetName(CExoLocString)
{
    asm("leave");
    asm("mov $0x080862a8, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetRepositoryArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x08086448, %eax");
    asm("jmp *%eax");
}

int CNWSStore::SetRepositoryListNumber(unsigned char)
{
    asm("leave");
    asm("mov $0x0808646c, %eax");
    asm("jmp *%eax");
}

void CNWSStore::SetScriptName(int, CExoString)
{
    asm("leave");
    asm("mov $0x0808614c, %eax");
    asm("jmp *%eax");
}

