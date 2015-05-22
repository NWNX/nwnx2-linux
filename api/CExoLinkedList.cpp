#include "CExoLinkedList.h"

template <>
int CExoLinkedList<CServerAIEventNode>::AddAfter(CServerAIEventNode *, CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x080987f0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::AddBefore(CServerAIEventNode *, CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x080987a4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::AddHead(CServerAIEventNode *)
{
    asm("leave");
    asm("mov $0x08098818, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::AddTail(CServerAIEventNode *)
{
    asm("leave");
    asm("mov $0x080987cc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::Count()
{
    asm("leave");
    asm("mov $0x08098844, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x08098790, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x08098784, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::GetHead()
{
    asm("leave");
    asm("mov $0x0809882c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x080987b8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::GetPrev(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x08098804, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::GetTailPos()
{
    asm("leave");
    asm("mov $0x080987e0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::IsEmpty()
{
    asm("leave");
    asm("mov $0x0809875c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CServerAIEventNode>::RemoveHead()
{
    asm("leave");
    asm("mov $0x08098770, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::AddBefore(CNWSObjectActionNode *, CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081d65c4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::AddHead(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c86d4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::AddTail(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081d65b0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::Count()
{
    asm("leave");
    asm("mov $0x081c86e8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x0813f078, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x081139c8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::GetHead()
{
    asm("leave");
    asm("mov $0x081139b0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x081139d4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::IsEmpty()
{
    asm("leave");
    asm("mov $0x0805f20c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::RemoveHead()
{
    asm("leave");
    asm("mov $0x0805f220, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSObjectActionNode>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x0813f08c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::AddBefore(CNWSCombatRoundAction *, CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x080e57dc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::AddTail(CNWSCombatRoundAction *)
{
    asm("leave");
    asm("mov $0x080e57f0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x080e57c8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x080e577c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::GetHead()
{
    asm("leave");
    asm("mov $0x080e5788, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x080e57a0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::GetPrev(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x0813f144, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::GetTailPos()
{
    asm("leave");
    asm("mov $0x0813f134, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::IsEmpty()
{
    asm("leave");
    asm("mov $0x080e5718, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::RemoveHead()
{
    asm("leave");
    asm("mov $0x080e572c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSCombatRoundAction>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x080e57b4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSClient>::AddHead(CNWSClient *)
{
    asm("leave");
    asm("mov $0x080b1648, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSClient>::Count()
{
    asm("leave");
    asm("mov $0x080b1638, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSClient>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x0805f380, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSClient>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x0805f374, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSClient>::GetHead()
{
    asm("leave");
    asm("mov $0x08082ed8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSClient>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x0805f394, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSClient>::IsEmpty()
{
    asm("leave");
    asm("mov $0x080b1490, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSClient>::RemoveHead()
{
    asm("leave");
    asm("mov $0x080b14a4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSClient>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x080b165c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoKeyTable>::AddHead(CExoKeyTable *)
{
    asm("leave");
    asm("mov $0x082b4190, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoKeyTable>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082b4130, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoKeyTable>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082b4124, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoKeyTable>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082b4144, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoKeyTable>::GetPrev(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082b417c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoKeyTable>::GetTailPos()
{
    asm("leave");
    asm("mov $0x082b4158, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoKeyTable>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082b4168, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileKey>::AddHead(CLinuxFileKey *)
{
    asm("leave");
    asm("mov $0x082d32a0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileKey>::AddTail(CLinuxFileKey *)
{
    asm("leave");
    asm("mov $0x082d321c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileKey>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082d3280, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileKey>::GetHead()
{
    asm("leave");
    asm("mov $0x082d3268, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileKey>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082d328c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileKey>::IsEmpty()
{
    asm("leave");
    asm("mov $0x082d32c8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileKey>::RemoveHead()
{
    asm("leave");
    asm("mov $0x082d32dc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileKey>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082d32b4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerTURD>::AddHead(CNWSPlayerTURD *)
{
    asm("leave");
    asm("mov $0x081c1fd8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerTURD>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081c1d14, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerTURD>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x081c1d08, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerTURD>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x081c1d28, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerTURD>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081c1fc4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdateObject>::AddHead(CLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x0808306c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdateObject>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x0805f528, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdateObject>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x0805f51c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdateObject>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x0805f53c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdateObject>::IsEmpty()
{
    asm("leave");
    asm("mov $0x0805f1a8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdateObject>::RemoveHead()
{
    asm("leave");
    asm("mov $0x0805f1bc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdateObject>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x08083080, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdatePartyObject>::AddHead(CLastUpdatePartyObject *)
{
    asm("leave");
    asm("mov $0x08083330, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdatePartyObject>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x0808331c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdatePartyObject>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x08083310, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdatePartyObject>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x08083344, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLastUpdatePartyObject>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x08083358, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerLUOInventoryItem>::AddHead(CNWSPlayerLUOInventoryItem *)
{
    asm("leave");
    asm("mov $0x081e4b00, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerLUOInventoryItem>::Count()
{
    asm("leave");
    asm("mov $0x081e4af0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerLUOInventoryItem>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081e4924, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerLUOInventoryItem>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x081e4aac, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerLUOInventoryItem>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x081e4ac8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerLUOInventoryItem>::GetPrev(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x081e4adc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerLUOInventoryItem>::GetTailPos()
{
    asm("leave");
    asm("mov $0x081e4ab8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerLUOInventoryItem>::IsEmpty()
{
    asm("leave");
    asm("mov $0x081e4a84, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerLUOInventoryItem>::RemoveHead()
{
    asm("leave");
    asm("mov $0x081e4a98, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayerLUOInventoryItem>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081e4938, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<C2DA>::AddHead(C2DA *)
{
    asm("leave");
    asm("mov $0x080b9b4c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<C2DA>::Count()
{
    asm("leave");
    asm("mov $0x080b9b9c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<C2DA>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x080b9b24, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<C2DA>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x080b9b18, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<C2DA>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x080b9b60, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<C2DA>::IsEmpty()
{
    asm("leave");
    asm("mov $0x080b9b74, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<C2DA>::RemoveHead()
{
    asm("leave");
    asm("mov $0x080b9b88, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<C2DA>::RemoveTail()
{
    asm("leave");
    asm("mov $0x080b9bac, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<C2DA>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x080b9b38, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CRes>::AddHead(CRes *)
{
    asm("leave");
    asm("mov $0x082b41e4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CRes>::AddTail(CRes *)
{
    asm("leave");
    asm("mov $0x082b420c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CRes>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082b40fc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CRes>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082b40f0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CRes>::GetHead()
{
    asm("leave");
    asm("mov $0x082b41a4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CRes>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082b41bc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CRes>::IsEmpty()
{
    asm("leave");
    asm("mov $0x082b41d0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CRes>::RemoveHead()
{
    asm("leave");
    asm("mov $0x082b41f8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CRes>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082b4110, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::AddHead(unsigned long *)
{
    asm("leave");
    asm("mov $0x081a73bc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::AddTail(unsigned long *)
{
    asm("leave");
    asm("mov $0x080b1670, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::Count()
{
    asm("leave");
    asm("mov $0x0805ef40, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x08082ec4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x0805ef20, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x0805ef2c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::GetPrev(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x08082c34, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::GetTailPos()
{
    asm("leave");
    asm("mov $0x08082c24, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::IsEmpty()
{
    asm("leave");
    asm("mov $0x081a74d0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::RemoveHead()
{
    asm("leave");
    asm("mov $0x081a74e4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned long>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x08086480, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFString>::AddTail(CERFString *)
{
    asm("leave");
    asm("mov $0x082b829c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFString>::Count()
{
    asm("leave");
    asm("mov $0x082b82b0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFString>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082b82cc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFString>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082b82c0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFString>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082b82e0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFString>::IsEmpty()
{
    asm("leave");
    asm("mov $0x082b818c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFString>::RemoveHead()
{
    asm("leave");
    asm("mov $0x082b81a0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoString>::AddTail(CExoString *)
{
    asm("leave");
    asm("mov $0x081f5cb0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoString>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082acf78, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoString>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082acf6c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoString>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082acf8c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoString>::IsEmpty()
{
    asm("leave");
    asm("mov $0x081f5c88, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoString>::RemoveHead()
{
    asm("leave");
    asm("mov $0x081f5c9c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CExoString>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082acfa0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CKeyTableInfo>::AddTail(CKeyTableInfo *)
{
    asm("leave");
    asm("mov $0x082c51ec, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CKeyTableInfo>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082c520c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CKeyTableInfo>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082c5200, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CKeyTableInfo>::RemoveHead()
{
    asm("leave");
    asm("mov $0x082c5220, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<ExoLocString_st>::AddTail(ExoLocString_st *)
{
    asm("leave");
    asm("mov $0x082d1258, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<ExoLocString_st>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082d1220, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<ExoLocString_st>::GetHead()
{
    asm("leave");
    asm("mov $0x082d122c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<ExoLocString_st>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082d1244, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<ExoLocString_st>::IsEmpty()
{
    asm("leave");
    asm("mov $0x082d12d8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<ExoLocString_st>::RemoveHead()
{
    asm("leave");
    asm("mov $0x082d12ec, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<ExoLocString_st>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082d1300, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSDialogPlayer>::AddTail(CNWSDialogPlayer *)
{
    asm("leave");
    asm("mov $0x081d6364, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSDialogPlayer>::Count()
{
    asm("leave");
    asm("mov $0x0823e70c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSDialogPlayer>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x0823e6e8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSDialogPlayer>::GetHead()
{
    asm("leave");
    asm("mov $0x0823e6f4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSDialogPlayer>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x0823e730, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSDialogPlayer>::IsEmpty()
{
    asm("leave");
    asm("mov $0x081c86c0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSDialogPlayer>::RemoveHead()
{
    asm("leave");
    asm("mov $0x0823e6d4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSDialogPlayer>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x0823e71c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileSection>::AddTail(CLinuxFileSection *)
{
    asm("leave");
    asm("mov $0x082d3208, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileSection>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082d3248, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileSection>::GetHead()
{
    asm("leave");
    asm("mov $0x082d3230, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileSection>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082d3254, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileSection>::IsEmpty()
{
    asm("leave");
    asm("mov $0x082d3304, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileSection>::RemoveHead()
{
    asm("leave");
    asm("mov $0x082d3318, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CLinuxFileSection>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082d32f0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWAreaExpansion_st>::AddTail(NWAreaExpansion_st *)
{
    asm("leave");
    asm("mov $0x080d5c2c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWAreaExpansion_st>::IsEmpty()
{
    asm("leave");
    asm("mov $0x080d5c40, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWAreaExpansion_st>::RemoveHead()
{
    asm("leave");
    asm("mov $0x080d5c54, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleCutScene_st>::AddTail(NWModuleCutScene_st *)
{
    asm("leave");
    asm("mov $0x081c1c6c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleCutScene_st>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081c1d7c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleCutScene_st>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x081c1d70, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleCutScene_st>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x081c1d90, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleCutScene_st>::IsEmpty()
{
    asm("leave");
    asm("mov $0x081c1c08, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleCutScene_st>::RemoveHead()
{
    asm("leave");
    asm("mov $0x081c1c1c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWPlayerListItem_st>::AddTail(NWPlayerListItem_st *)
{
    asm("leave");
    asm("mov $0x081c1c94, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWPlayerListItem_st>::Count()
{
    asm("leave");
    asm("mov $0x081c1da4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWPlayerListItem_st>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081c1dc0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWPlayerListItem_st>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x081c1db4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWPlayerListItem_st>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x081c1dd4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWPlayerListItem_st>::IsEmpty()
{
    asm("leave");
    asm("mov $0x081c1be0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWPlayerListItem_st>::RemoveHead()
{
    asm("leave");
    asm("mov $0x081c1bf4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleExpansion_st>::AddTail(NWModuleExpansion_st *)
{
    asm("leave");
    asm("mov $0x081c1c58, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleExpansion_st>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081c1d48, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleExpansion_st>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x081c1d3c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleExpansion_st>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x081c1d5c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleExpansion_st>::IsEmpty()
{
    asm("leave");
    asm("mov $0x081c1c30, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<NWModuleExpansion_st>::RemoveHead()
{
    asm("leave");
    asm("mov $0x081c1c44, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFKey>::AddTail(CERFKey *)
{
    asm("leave");
    asm("mov $0x082b8204, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFKey>::Count()
{
    asm("leave");
    asm("mov $0x082b8324, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFKey>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082b8238, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFKey>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082b822c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFKey>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082b82f4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFKey>::IsEmpty()
{
    asm("leave");
    asm("mov $0x082b81b4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFKey>::RemoveHead()
{
    asm("leave");
    asm("mov $0x082b81c8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFKey>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082b8260, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFRes>::AddTail(CERFRes *)
{
    asm("leave");
    asm("mov $0x082b8218, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFRes>::Count()
{
    asm("leave");
    asm("mov $0x082b8308, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFRes>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082b824c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFRes>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082b8318, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFRes>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082b8288, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFRes>::IsEmpty()
{
    asm("leave");
    asm("mov $0x082b81dc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFRes>::RemoveHead()
{
    asm("leave");
    asm("mov $0x082b81f0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CERFRes>::Remove(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x082b8274, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CResRef>::AddTail(CResRef *)
{
    asm("leave");
    asm("mov $0x081c1c80, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CResRef>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x081c1ca8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CResRef>::GetHead()
{
    asm("leave");
    asm("mov $0x081c1cb4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CResRef>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x081c1ccc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CResRef>::IsEmpty()
{
    asm("leave");
    asm("mov $0x081c1ce0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CResRef>::RemoveHead()
{
    asm("leave");
    asm("mov $0x081c1cf4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned short>::AddTail(unsigned short *)
{
    asm("leave");
    asm("mov $0x082acde4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned short>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x082ace10, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned short>::GetHead()
{
    asm("leave");
    asm("mov $0x082acdf8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned short>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x082ace1c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned short>::IsEmpty()
{
    asm("leave");
    asm("mov $0x082acdbc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<unsigned short>::RemoveHead()
{
    asm("leave");
    asm("mov $0x082acdd0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayer>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x08050fe0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayer>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x08050fd4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayer>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x0805109c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayer *>::GetAtPos(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x0813f164, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayer *>::GetHeadPos()
{
    asm("leave");
    asm("mov $0x0813f158, %eax");
    asm("jmp *%eax");
}

template <>
int CExoLinkedList<CNWSPlayer *>::GetNext(CExoLinkedListNode *&)
{
    asm("leave");
    asm("mov $0x0813f178, %eax");
    asm("jmp *%eax");
}

