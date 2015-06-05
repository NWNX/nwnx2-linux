#ifndef _CNWSDIALOG_H_
#define _CNWSDIALOG_H_
#include "nwndef.h"
#include "CExoLocString.h"
#include "CResRef.h"

class CNWSDialog
{
public:
    void AddJournalEntry(CExoString const &, unsigned long, unsigned long);
    int CheckScript(CNWSObject *, CResRef const &);
    void Cleanup();
    int ClearDialogOwnerInObject(unsigned long);
    CNWSObject * GetSpeaker(CNWSObject *, CExoString const &);
    int GetStartEntryOneLiner(CNWSObject *, CExoLocString &, CResRef &, CResRef &);
    unsigned long GetStartEntry(CNWSObject *);
    int HandleReply(unsigned long, CNWSObject *, unsigned long, int, unsigned long);
    int IsPlayerInDialog(unsigned long);
    int LoadDialog(CResGFF *, int);
    int RemovePlayer(unsigned long);
    void RunScript(CNWSObject *, CResRef const &);
    int SendDialogEntry(CNWSObject *, unsigned long, unsigned long, int);
    int SendDialogReplies(CNWSObject *, unsigned long);
    float SetDialogDelay(CNWSObject *, CExoLocString, unsigned long, int);
    ~CNWSDialog();
    CNWSDialog();

    /* 0x0/0 */ unsigned long EntryListCount;
    /* 0x4/4 */ CDialogEntry *EntryList;
    /* 0x8/8 */ unsigned long ReplyListCount;
    /* 0xC/12 */ CDialogReply *ReplyList;
    /* 0x10/16 */ unsigned long StartingListCount;
    /* 0x14/20 */ CDialogReplyEntry *StartingList;
    /* 0x18/24 */ CResRef EndScript;
    /* 0x28/40 */ CResRef EndConverAbortScript;
    /* 0x38/56 */ void *ConvoPartiesList;
    /* 0x3C/60 */ unsigned long field_3C;
    /* 0x40/64 */ unsigned long field_40;
    /* 0x44/68 */ unsigned long CurrentNodeID;
    /* 0x48/72 */ unsigned long SelectedNodeID;
    /* 0x4C/76 */ unsigned long SpeakerLocale;
    /* 0x50/80 */ unsigned long ConversationWith;
    /* 0x54/84 */ unsigned long MeObjID;
    /* 0x58/88 */ unsigned long field_58;
    /* 0x5C/92 */ unsigned long field_5C;
    /* 0x60/96 */ unsigned long field_60;
    /* 0x64/100 */ unsigned long field_64;
    /* 0x68/104 */ unsigned long Me_again;
    /* 0x6C/108 */ unsigned long field_6C;
    /* 0x70/112 */ unsigned long PreventZoomIn;
    /* 0x74/116 */ unsigned long field_74;
};
#endif
