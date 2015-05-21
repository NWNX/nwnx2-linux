#include "CExoArrayList.h"

#include "CExoString.h"
#include "CNWSStats_SpellLikeAbility.h"
#include "CResRef.h"
template <>
int CExoArrayList<CExoString>::AddUnique(CExoString)
{
    asm("leave");
    asm("mov $0x08050ff4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CExoString>::Add(CExoString)
{
    asm("leave");
    asm("mov $0x080512cc, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CExoString>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080510b0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CExoString>::Contains(CExoString)
{
    asm("leave");
    asm("mov $0x08051248, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CExoString>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x080b18b0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CExoString>::Insert(CExoString, int)
{
    asm("leave");
    asm("mov $0x082ceb9c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CExoString>::Remove(CExoString)
{
    asm("leave");
    asm("mov $0x080b17c8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CExoString>::SetSize(int)
{
    asm("leave");
    asm("mov $0x08061cb0, %eax");
    asm("jmp *%eax");
}

template <>
CExoString & CExoArrayList<CExoString>::operator[](int) const
{
    asm("leave");
    asm("mov $0x082acf5c, %eax");
    asm("jmp *%eax");
}

template <>
CExoString & CExoArrayList<CExoString>::operator[](int)
{
    asm("leave");
    asm("mov $0x08050fc4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CLoopingVisualEffect *>::AddUnique(CLoopingVisualEffect *)
{
    asm("leave");
    asm("mov $0x08082cfc, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CLoopingVisualEffect *>::Add(CLoopingVisualEffect *)
{
    asm("leave");
    asm("mov $0x080836fc, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CLoopingVisualEffect *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08083680, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CLoopingVisualEffect *>::Contains(CLoopingVisualEffect *)
{
    asm("leave");
    asm("mov $0x080836d4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CLoopingVisualEffect *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x081d6580, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CLoopingVisualEffect *>::SetSize(int)
{
    asm("leave");
    asm("mov $0x08082cb4, %eax");
    asm("jmp *%eax");
}

template <>
CLoopingVisualEffect * & CExoArrayList<CLoopingVisualEffect *>::operator[](int)
{
    asm("leave");
    asm("mov $0x0813f0a0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<NWPlayerCharacterList_st *>::AddUnique(NWPlayerCharacterList_st *)
{
    asm("leave");
    asm("mov $0x08083010, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<NWPlayerCharacterList_st *>::Add(NWPlayerCharacterList_st *)
{
    asm("leave");
    asm("mov $0x080838ec, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<NWPlayerCharacterList_st *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08083870, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<NWPlayerCharacterList_st *>::Contains(NWPlayerCharacterList_st *)
{
    asm("leave");
    asm("mov $0x080838c4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<NWPlayerCharacterList_st *>::DerefContains(NWPlayerCharacterList_st *)
{
    asm("leave");
    asm("mov $0x08082fa8, %eax");
    asm("jmp *%eax");
}

template <>
NWPlayerCharacterList_st * & CExoArrayList<NWPlayerCharacterList_st *>::operator[](int)
{
    asm("leave");
    asm("mov $0x0808304c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned long>::AddUnique(unsigned long)
{
    asm("leave");
    asm("mov $0x08098688, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned long>::Add(unsigned long)
{
    asm("leave");
    asm("mov $0x0805eee0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned long>::Allocate(int)
{
    asm("leave");
    asm("mov $0x0805f580, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned long>::Contains(unsigned long)
{
    asm("leave");
    asm("mov $0x0805f34c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned long>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x0805f550, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned long>::IndexOf(unsigned long)
{
    asm("leave");
    asm("mov $0x080986c4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned long>::Insert(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080d5bc4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned long>::Remove(unsigned long)
{
    asm("leave");
    asm("mov $0x0805ee88, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned long>::SetSize(int)
{
    asm("leave");
    asm("mov $0x08061c68, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned long>::operator=(CExoArrayList<unsigned long> const &)
{
    asm("leave");
    asm("mov $0x081139e8, %eax");
    asm("jmp *%eax");
}

template <>
unsigned long & CExoArrayList<unsigned long>::operator[](int) const
{
    asm("leave");
    asm("mov $0x08113c90, %eax");
    asm("jmp *%eax");
}

template <>
unsigned long & CExoArrayList<unsigned long>::operator[](int)
{
    asm("leave");
    asm("mov $0x0805eff0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned short>::AddUnique(unsigned short)
{
    asm("leave");
    asm("mov $0x08165ac8, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned short>::Add(unsigned short)
{
    asm("leave");
    asm("mov $0x0805f038, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned short>::Allocate(int)
{
    asm("leave");
    asm("mov $0x0805f5d4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned short>::Contains(unsigned short)
{
    asm("leave");
    asm("mov $0x0805f010, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned short>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x0805f31c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned short>::Insert(unsigned short, int)
{
    asm("leave");
    asm("mov $0x080e5804, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned short>::Remove(unsigned short)
{
    asm("leave");
    asm("mov $0x0805f07c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned short>::SetSize(int)
{
    asm("leave");
    asm("mov $0x080bfaec, %eax");
    asm("jmp *%eax");
}

template <>
unsigned short & CExoArrayList<unsigned short>::operator[](int)
{
    asm("leave");
    asm("mov $0x0805f000, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned long long>::AddUnique(unsigned long long)
{
    asm("leave");
    asm("mov $0x080833e8, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned long long>::Add(unsigned long long)
{
    asm("leave");
    asm("mov $0x08083b0c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned long long>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08083a58, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned long long>::Contains(unsigned long long)
{
    asm("leave");
    asm("mov $0x08083ab8, %eax");
    asm("jmp *%eax");
}

template <>
unsigned long long & CExoArrayList<unsigned long long>::operator[](int)
{
    asm("leave");
    asm("mov $0x080833d8, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSTagNode>::Add(CNWSTagNode)
{
    asm("leave");
    asm("mov $0x081c1fec, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSTagNode>::Allocate(int)
{
    asm("leave");
    asm("mov $0x081c20cc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWSTagNode>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x081c1e6c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSTagNode>::Insert(CNWSTagNode, int)
{
    asm("leave");
    asm("mov $0x081c1dfc, %eax");
    asm("jmp *%eax");
}

template <>
CNWSTagNode & CExoArrayList<CNWSTagNode>::operator[](int)
{
    asm("leave");
    asm("mov $0x081c1de8, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSPVPEntry>::Add(CNWSPVPEntry)
{
    asm("leave");
    asm("mov $0x08113b34, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSPVPEntry>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08113ca0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWSPVPEntry>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08113c50, %eax");
    asm("jmp *%eax");
}

template <>
CNWSPVPEntry & CExoArrayList<CNWSPVPEntry>::operator[](int)
{
    asm("leave");
    asm("mov $0x08113b84, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSScriptVar>::Add(CNWSScriptVar)
{
    asm("leave");
    asm("mov $0x081f44f0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSScriptVar>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080d5ca8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWSScriptVar>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x081f4584, %eax");
    asm("jmp *%eax");
}

template <>
CNWSScriptVar & CExoArrayList<CNWSScriptVar>::operator[](int)
{
    asm("leave");
    asm("mov $0x0819be30, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SJournalEntry>::Add(SJournalEntry)
{
    asm("leave");
    asm("mov $0x081b263c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SJournalEntry>::Allocate(int)
{
    asm("leave");
    asm("mov $0x081b27ec, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<SJournalEntry>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x081b2a88, %eax");
    asm("jmp *%eax");
}

template <>
SJournalEntry & CExoArrayList<SJournalEntry>::operator[](int)
{
    asm("leave");
    asm("mov $0x08083448, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWItemProperty>::Add(CNWItemProperty)
{
    asm("leave");
    asm("mov $0x081a7440, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWItemProperty>::Allocate(int)
{
    asm("leave");
    asm("mov $0x081a74f8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWItemProperty>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x081a7490, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWItemProperty>::SetSize(int)
{
    asm("leave");
    asm("mov $0x081a7360, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWItemProperty>::operator=(CExoArrayList<CNWItemProperty> const &)
{
    asm("leave");
    asm("mov $0x081a73d0, %eax");
    asm("jmp *%eax");
}

template <>
CNWItemProperty & CExoArrayList<CNWItemProperty>::operator[](int) const
{
    asm("leave");
    asm("mov $0x081a7568, %eax");
    asm("jmp *%eax");
}

template <>
CNWItemProperty & CExoArrayList<CNWItemProperty>::operator[](int)
{
    asm("leave");
    asm("mov $0x081a73a8, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SGameSpyRoomEntry>::Add(SGameSpyRoomEntry)
{
    asm("leave");
    asm("mov $0x08272dc4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SGameSpyRoomEntry>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08272e20, %eax");
    asm("jmp *%eax");
}

template <>
SGameSpyRoomEntry & CExoArrayList<SGameSpyRoomEntry>::operator[](int)
{
    asm("leave");
    asm("mov $0x08272e10, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CWorldJournalEntry>::Add(CWorldJournalEntry)
{
    asm("leave");
    asm("mov $0x081c0d20, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CWorldJournalEntry>::Allocate(int)
{
    asm("leave");
    asm("mov $0x081c0df0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CWorldJournalEntry>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x081c1ec0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CWorldJournalEntry>::SetSize(int)
{
    asm("leave");
    asm("mov $0x081c1f40, %eax");
    asm("jmp *%eax");
}

template <>
CWorldJournalEntry & CExoArrayList<CWorldJournalEntry>::operator[](int)
{
    asm("leave");
    asm("mov $0x081c1eac, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSInvitationDetails>::Add(CNWSInvitationDetails)
{
    asm("leave");
    asm("mov $0x08113c00, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSInvitationDetails>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08113d10, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWSInvitationDetails>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08113af4, %eax");
    asm("jmp *%eax");
}

template <>
CNWSInvitationDetails & CExoArrayList<CNWSInvitationDetails>::operator[](int)
{
    asm("leave");
    asm("mov $0x08113ae0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSPersonalReputation>::Add(CNWSPersonalReputation)
{
    asm("leave");
    asm("mov $0x08060e9c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSPersonalReputation>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08060f34, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWSPersonalReputation>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08113a54, %eax");
    asm("jmp *%eax");
}

template <>
CNWSPersonalReputation & CExoArrayList<CNWSPersonalReputation>::operator[](int)
{
    asm("leave");
    asm("mov $0x08060f20, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNetLayerPlayerCDKeyInfo>::Add(CNetLayerPlayerCDKeyInfo)
{
    asm("leave");
    asm("mov $0x082acac4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNetLayerPlayerCDKeyInfo>::Allocate(int)
{
    asm("leave");
    asm("mov $0x082acb80, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNetLayerPlayerCDKeyInfo>::SetSize(int)
{
    asm("leave");
    asm("mov $0x082aced8, %eax");
    asm("jmp *%eax");
}

template <>
CNetLayerPlayerCDKeyInfo & CExoArrayList<CNetLayerPlayerCDKeyInfo>::operator[](int)
{
    asm("leave");
    asm("mov $0x08050e34, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSStats_SpellLikeAbility>::Add(CNWSStats_SpellLikeAbility)
{
    asm("leave");
    asm("mov $0x08165c2c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSStats_SpellLikeAbility>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08083560, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWSStats_SpellLikeAbility>::SetSize(int)
{
    asm("leave");
    asm("mov $0x08082e7c, %eax");
    asm("jmp *%eax");
}

template <>
CNWSStats_SpellLikeAbility & CExoArrayList<CNWSStats_SpellLikeAbility>::operator[](int)
{
    asm("leave");
    asm("mov $0x08165ab4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSPlayerJournalQuestUpdates>::Add(CNWSPlayerJournalQuestUpdates)
{
    asm("leave");
    asm("mov $0x081b2754, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSPlayerJournalQuestUpdates>::Allocate(int)
{
    asm("leave");
    asm("mov $0x0805f3a8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWSPlayerJournalQuestUpdates>::SetSize(int)
{
    asm("leave");
    asm("mov $0x08083478, %eax");
    asm("jmp *%eax");
}

template <>
CNWSPlayerJournalQuestUpdates & CExoArrayList<CNWSPlayerJournalQuestUpdates>::operator[](int)
{
    asm("leave");
    asm("mov $0x08083464, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<NWPlayerCharacterListClass_st>::Add(NWPlayerCharacterListClass_st)
{
    asm("leave");
    asm("mov $0x08082f5c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<NWPlayerCharacterListClass_st>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08083620, %eax");
    asm("jmp *%eax");
}

template <>
NWPlayerCharacterListClass_st & CExoArrayList<NWPlayerCharacterListClass_st>::operator[](int)
{
    asm("leave");
    asm("mov $0x0808305c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CResRef>::Add(CResRef)
{
    asm("leave");
    asm("mov $0x080b159c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CResRef>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080b1704, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CResRef>::Contains(CResRef)
{
    asm("leave");
    asm("mov $0x080b15ec, %eax");
    asm("jmp *%eax");
}

template <>
CResRef & CExoArrayList<CResRef>::operator[](int) const
{
    asm("leave");
    asm("mov $0x081e9ec0, %eax");
    asm("jmp *%eax");
}

template <>
CResRef & CExoArrayList<CResRef>::operator[](int)
{
    asm("leave");
    asm("mov $0x081e9de0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CFileInfo>::Add(CFileInfo)
{
    asm("leave");
    asm("mov $0x082ceae0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CFileInfo>::Allocate(int)
{
    asm("leave");
    asm("mov $0x081e876c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CFileInfo>::Insert(CFileInfo, int)
{
    asm("leave");
    asm("mov $0x082ce994, %eax");
    asm("jmp *%eax");
}

template <>
CFileInfo & CExoArrayList<CFileInfo>::operator[](int)
{
    asm("leave");
    asm("mov $0x081e8758, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CExoString *>::Add(CExoString *)
{
    asm("leave");
    asm("mov $0x081d6690, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CExoString *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x081d676c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CExoString *>::SetSize(int)
{
    asm("leave");
    asm("mov $0x081d66d0, %eax");
    asm("jmp *%eax");
}

template <>
CExoString * & CExoArrayList<CExoString *>::operator[](int) const
{
    asm("leave");
    asm("mov $0x08236da8, %eax");
    asm("jmp *%eax");
}

template <>
CExoString * & CExoArrayList<CExoString *>::operator[](int)
{
    asm("leave");
    asm("mov $0x081139a0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CScriptLog *>::Add(CScriptLog *)
{
    asm("leave");
    asm("mov $0x082649f4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CScriptLog *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08264ab4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CScriptLog *>::SetSize(int)
{
    asm("leave");
    asm("mov $0x082649ac, %eax");
    asm("jmp *%eax");
}

template <>
CScriptLog * & CExoArrayList<CScriptLog *>::operator[](int)
{
    asm("leave");
    asm("mov $0x0826499c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CSpell_Add *>::Add(CSpell_Add *)
{
    asm("leave");
    asm("mov $0x08082e08, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CSpell_Add *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x0808381c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CSpell_Add *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x081e4a54, %eax");
    asm("jmp *%eax");
}

template <>
CSpell_Add * & CExoArrayList<CSpell_Add *>::operator[](int)
{
    asm("leave");
    asm("mov $0x080830a4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CGameEffect *>::Add(CGameEffect *)
{
    asm("leave");
    asm("mov $0x08061028, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CGameEffect *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08061068, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CGameEffect *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08060e38, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CGameEffect *>::IndexOf(CGameEffect *)
{
    asm("leave");
    asm("mov $0x081d6624, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CGameEffect *>::Insert(CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081d65d8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CGameEffect *>::SetSize(int)
{
    asm("leave");
    asm("mov $0x081d6538, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CGameEffect *>::operator=(CExoArrayList<CGameEffect *> const &)
{
    asm("leave");
    asm("mov $0x08165a6c, %eax");
    asm("jmp *%eax");
}

template <>
CGameEffect * & CExoArrayList<CGameEffect *>::operator[](int) const
{
    asm("leave");
    asm("mov $0x0813f18c, %eax");
    asm("jmp *%eax");
}

template <>
CGameEffect * & CExoArrayList<CGameEffect *>::operator[](int)
{
    asm("leave");
    asm("mov $0x0805f234, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CGameObject *>::Add(CGameObject *)
{
    asm("leave");
    asm("mov $0x080d5c68, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CGameObject *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080bd218, %eax");
    asm("jmp *%eax");
}

template <>
CGameObject * & CExoArrayList<CGameObject *>::operator[](int)
{
    asm("leave");
    asm("mov $0x080d5e38, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSFaction *>::Add(CNWSFaction *)
{
    asm("leave");
    asm("mov $0x081d8560, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSFaction *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080bac10, %eax");
    asm("jmp *%eax");
}

template <>
CNWSFaction * & CExoArrayList<CNWSFaction *>::operator[](int)
{
    asm("leave");
    asm("mov $0x080bab7c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SMstKeyEntry *>::Add(SMstKeyEntry *)
{
    asm("leave");
    asm("mov $0x08298bac, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SMstKeyEntry *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08298d88, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<SMstKeyEntry *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08298cac, %eax");
    asm("jmp *%eax");
}

template <>
SMstKeyEntry * & CExoArrayList<SMstKeyEntry *>::operator[](int)
{
    asm("leave");
    asm("mov $0x08298b9c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWLevelStats *>::Add(CNWLevelStats *)
{
    asm("leave");
    asm("mov $0x081659b4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWLevelStats *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08165cd0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWLevelStats *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08165a04, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWLevelStats *>::Remove(CNWLevelStats *)
{
    asm("leave");
    asm("mov $0x08165b4c, %eax");
    asm("jmp *%eax");
}

template <>
CNWLevelStats * & CExoArrayList<CNWLevelStats *>::operator[](int)
{
    asm("leave");
    asm("mov $0x081659f4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CSpell_Delete *>::Add(CSpell_Delete *)
{
    asm("leave");
    asm("mov $0x08082dc8, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CSpell_Delete *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080837c8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CSpell_Delete *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x081e4a24, %eax");
    asm("jmp *%eax");
}

template <>
CSpell_Delete * & CExoArrayList<CSpell_Delete *>::operator[](int)
{
    asm("leave");
    asm("mov $0x08083094, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SCodeBaseData *>::Add(SCodeBaseData *)
{
    asm("leave");
    asm("mov $0x082db118, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SCodeBaseData *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x082db1f4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<SCodeBaseData *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x082db158, %eax");
    asm("jmp *%eax");
}

template <>
SCodeBaseData * & CExoArrayList<SCodeBaseData *>::operator[](int)
{
    asm("leave");
    asm("mov $0x082db108, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SMstNameEntry *>::Add(SMstNameEntry *)
{
    asm("leave");
    asm("mov $0x08298bec, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SMstNameEntry *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08298ddc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<SMstNameEntry *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08298d58, %eax");
    asm("jmp *%eax");
}

template <>
SMstNameEntry * & CExoArrayList<SMstNameEntry *>::operator[](int)
{
    asm("leave");
    asm("mov $0x08298d48, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSExpression *>::Add(CNWSExpression *)
{
    asm("leave");
    asm("mov $0x081d6650, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSExpression *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x081d6718, %eax");
    asm("jmp *%eax");
}

template <>
CNWSExpression * & CExoArrayList<CNWSExpression *>::operator[](int)
{
    asm("leave");
    asm("mov $0x081d6528, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CStoreCustomer *>::Add(CStoreCustomer *)
{
    asm("leave");
    asm("mov $0x08086640, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CStoreCustomer *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080866b0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CStoreCustomer *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08086680, %eax");
    asm("jmp *%eax");
}

template <>
CStoreCustomer * & CExoArrayList<CStoreCustomer *>::operator[](int)
{
    asm("leave");
    asm("mov $0x08086500, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SMstBuddyEntry *>::Add(SMstBuddyEntry *)
{
    asm("leave");
    asm("mov $0x08298c2c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SMstBuddyEntry *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08298e30, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<SMstBuddyEntry *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08298c7c, %eax");
    asm("jmp *%eax");
}

template <>
SMstBuddyEntry * & CExoArrayList<SMstBuddyEntry *>::operator[](int)
{
    asm("leave");
    asm("mov $0x08298c6c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SSubNetProfile *>::Add(SSubNetProfile *)
{
    asm("leave");
    asm("mov $0x080b1694, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SSubNetProfile *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080b185c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<SSubNetProfile *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x080b16d4, %eax");
    asm("jmp *%eax");
}

template <>
SSubNetProfile * & CExoArrayList<SSubNetProfile *>::operator[](int)
{
    asm("leave");
    asm("mov $0x080b1684, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSStats_Spell *>::Add(CNWSStats_Spell *)
{
    asm("leave");
    asm("mov $0x0816586c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSStats_Spell *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08165c7c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWSStats_Spell *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x081658ac, %eax");
    asm("jmp *%eax");
}

template <>
CNWSStats_Spell * & CExoArrayList<CNWSStats_Spell *>::operator[](int)
{
    asm("leave");
    asm("mov $0x0816585c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWCCMessageData *>::Add(CNWCCMessageData *)
{
    asm("leave");
    asm("mov $0x080f5c9c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWCCMessageData *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080e58d4, %eax");
    asm("jmp *%eax");
}

template <>
CNWCCMessageData * & CExoArrayList<CNWCCMessageData *>::operator[](int)
{
    asm("leave");
    asm("mov $0x080f5cdc, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SMstDigiDistInfo *>::Add(SMstDigiDistInfo *)
{
    asm("leave");
    asm("mov $0x08298b5c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SMstDigiDistInfo *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08298e84, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<SMstDigiDistInfo *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08298b2c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<SMstDigiDistInfo *>::Remove(SMstDigiDistInfo *)
{
    asm("leave");
    asm("mov $0x08298cdc, %eax");
    asm("jmp *%eax");
}

template <>
SMstDigiDistInfo * & CExoArrayList<SMstDigiDistInfo *>::operator[](int)
{
    asm("leave");
    asm("mov $0x08298b1c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CEffectIconObject *>::Add(CEffectIconObject *)
{
    asm("leave");
    asm("mov $0x08083520, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CEffectIconObject *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08083bb8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CEffectIconObject *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x080834f0, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CEffectIconObject *>::SetSize(int)
{
    asm("leave");
    asm("mov $0x081e4b14, %eax");
    asm("jmp *%eax");
}

template <>
CEffectIconObject * & CExoArrayList<CEffectIconObject *>::operator[](int)
{
    asm("leave");
    asm("mov $0x08083428, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CFeatUseListEntry *>::Add(CFeatUseListEntry *)
{
    asm("leave");
    asm("mov $0x080832d0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CFeatUseListEntry *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08083a04, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CFeatUseListEntry *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x080832a0, %eax");
    asm("jmp *%eax");
}

template <>
CFeatUseListEntry * & CExoArrayList<CFeatUseListEntry *>::operator[](int)
{
    asm("leave");
    asm("mov $0x08082db8, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWVisibilityNode *>::Add(CNWVisibilityNode *)
{
    asm("leave");
    asm("mov $0x08082d78, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWVisibilityNode *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08083774, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWVisibilityNode *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08082d48, %eax");
    asm("jmp *%eax");
}

template <>
CNWVisibilityNode * & CExoArrayList<CNWVisibilityNode *>::operator[](int)
{
    asm("leave");
    asm("mov $0x08082d38, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSExpressionList *>::Add(CNWSExpressionList *)
{
    asm("leave");
    asm("mov $0x08240278, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSExpressionList *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x082403e4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWSExpressionList *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x082402c8, %eax");
    asm("jmp *%eax");
}

template <>
CNWSExpressionList * & CExoArrayList<CNWSExpressionList *>::operator[](int)
{
    asm("leave");
    asm("mov $0x082402b8, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSExpressionNode *>::Add(CNWSExpressionNode *)
{
    asm("leave");
    asm("mov $0x08240364, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSExpressionNode *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08240438, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWSExpressionNode *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x082403b4, %eax");
    asm("jmp *%eax");
}

template <>
CNWSExpressionNode * & CExoArrayList<CNWSExpressionNode *>::operator[](int)
{
    asm("leave");
    asm("mov $0x082403a4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSSpellScriptData *>::Add(CNWSSpellScriptData *)
{
    asm("leave");
    asm("mov $0x080f5cfc, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSSpellScriptData *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080e5880, %eax");
    asm("jmp *%eax");
}

template <>
CNWSSpellScriptData * & CExoArrayList<CNWSSpellScriptData *>::operator[](int)
{
    asm("leave");
    asm("mov $0x080f5cec, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CVirtualMachineFile *>::Add(CVirtualMachineFile *)
{
    asm("leave");
    asm("mov $0x082648b0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CVirtualMachineFile *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08264a60, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CVirtualMachineFile *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08264900, %eax");
    asm("jmp *%eax");
}

template <>
CVirtualMachineFile * & CExoArrayList<CVirtualMachineFile *>::operator[](int)
{
    asm("leave");
    asm("mov $0x082648f0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CCombatInformationNode *>::Add(CCombatInformationNode *)
{
    asm("leave");
    asm("mov $0x080cbbb8, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CCombatInformationNode *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080cbcdc, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CCombatInformationNode *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x080cbc64, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CCombatInformationNode *>::SetSize(int)
{
    asm("leave");
    asm("mov $0x080cbc94, %eax");
    asm("jmp *%eax");
}

template <>
CCombatInformationNode * & CExoArrayList<CCombatInformationNode *>::operator[](int)
{
    asm("leave");
    asm("mov $0x08083438, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWTileSurfaceMeshAABBNode *>::Add(CNWTileSurfaceMeshAABBNode *)
{
    asm("leave");
    asm("mov $0x0809443c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWTileSurfaceMeshAABBNode *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080944d8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<CNWTileSurfaceMeshAABBNode *>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x0809447c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSItem *>::Add(CNWSItem *)
{
    asm("leave");
    asm("mov $0x080865d8, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSItem *>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08086704, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<CNWSItem *>::Insert(CNWSItem *, int)
{
    asm("leave");
    asm("mov $0x0808658c, %eax");
    asm("jmp *%eax");
}

template <>
CNWSItem * & CExoArrayList<CNWSItem *>::operator[](int)
{
    asm("leave");
    asm("mov $0x0808657c, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned char>::Add(unsigned char)
{
    asm("leave");
    asm("mov $0x080831e0, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<unsigned char>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080839b4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned char>::DelIndex(int)
{
    asm("leave");
    asm("mov $0x08165c00, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<unsigned char>::SetSize(int)
{
    asm("leave");
    asm("mov $0x08165bb8, %eax");
    asm("jmp *%eax");
}

template <>
unsigned char & CExoArrayList<unsigned char>::operator[](int)
{
    asm("leave");
    asm("mov $0x08083224, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<char>::Add(char)
{
    asm("leave");
    asm("mov $0x08083120, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<char>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08083964, %eax");
    asm("jmp *%eax");
}

template <>
char & CExoArrayList<char>::operator[](int)
{
    asm("leave");
    asm("mov $0x08083164, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<float>::Add(float)
{
    asm("leave");
    asm("mov $0x08061d34, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<float>::Allocate(int)
{
    asm("leave");
    asm("mov $0x08061d74, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<float>::Insert(float, int)
{
    asm("leave");
    asm("mov $0x08236cb8, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<float>::SetSize(int)
{
    asm("leave");
    asm("mov $0x08061c20, %eax");
    asm("jmp *%eax");
}

template <>
float & CExoArrayList<float>::operator[](int)
{
    asm("leave");
    asm("mov $0x08061d24, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<int>::Add(int)
{
    asm("leave");
    asm("mov $0x08050eb4, %eax");
    asm("jmp *%eax");
}

template <>
void CExoArrayList<int>::Allocate(int)
{
    asm("leave");
    asm("mov $0x080511f4, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<int>::Contains(int)
{
    asm("leave");
    asm("mov $0x08086618, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<int>::IndexOf(int)
{
    asm("leave");
    asm("mov $0x08050f00, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<int>::Pack()
{
    asm("leave");
    asm("mov $0x080bab8c, %eax");
    asm("jmp *%eax");
}

template <>
int CExoArrayList<int>::SetSize(int)
{
    asm("leave");
    asm("mov $0x08061bd8, %eax");
    asm("jmp *%eax");
}

template <>
int & CExoArrayList<int>::operator[](int)
{
    asm("leave");
    asm("mov $0x08050ef0, %eax");
    asm("jmp *%eax");
}

