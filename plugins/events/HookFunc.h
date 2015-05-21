/***************************************************************************
    Events plugin for NWNX - hooks interface
    (c) 2006 virusman (virusman@virusman.ru)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#if !defined(HookFunc_h_)
#define HookFunc_h_

#include "typedefs.h"
#include "CExoLocString.h"
#include "NWNStructures.h"

struct CDialogEntryReply {
    char  ConditionalScript[16];
    dword Index;
    dword DisplayInactive;
};

typedef CDialogEntryReply CDialogStartingEntry;

struct CDialogEntry {
    dword             *Speaker;
    dword              SpeakerLen;
    dword              Animation;
    dword              AnimLoop;
    CExoLocString      Text;
    CDialogEntryReply *RepliesList;
    dword              RepliesNum;
    char               Script[16];
    dword              Delay;
    char               Sound[16];
    dword              Quest;
    dword              QuestLen;
    dword              QuestEntry;
};

struct CDialogReplyEntry {
    char  ConditionalScript[16];
    dword Index;
};

struct CDialogReply {
    dword              Animation;
    dword              AnimLoop;
    CExoLocString      Text;
    CDialogReplyEntry *EntriesList;
    dword              EntriesNum;
    char               Script[16];
    dword              Delay;
    char               Sound[16];
    dword              Quest;
    dword              QuestLen;
    dword              QuestEntry;
};
/*
00000000 CNWSDialogClass struc ; (sizeof=0x74)
00000000 EntryListCount  dd ?
00000004 EntryList       dd ?                    ; offset
00000008 ReplyListCount  dd ?
0000000C ReplyList       dd ?                    ; offset
00000010 StartingListCount dd ?
00000014 StartingList    dd ?                    ; offset
00000018 EndScript       db 16 dup(?)            ; char
00000028 EndConverAbortScript db 16 dup(?)       ; char
00000038 ConvoPartiesList?? dd ?                 ; offset
0000003C field_3C        dd ?
00000040 field_40        dd ?
00000044 CurrentNodeID   dd ?
00000048 field_48        dd ?
0000004C SpeakerLocale   db ?
0000004D                 db ? ; undefined
0000004E                 db ? ; undefined
0000004F                 db ? ; undefined
00000050 ConversationWith dd ?
00000054 MeObjID         dd ?
00000058 field_58        dd ?
0000005C field_5C        dd ?
00000060 field_60        dd ?
00000064 field_64        dd ?
00000068 Me_again?       dd ?                    ; Object
0000006C field_6C        dd ?                    ; Object
00000070 PreventZoomIn   dd ?
00000074 CNWSDialogClass ends

*/

struct CNWSDialogClass {
    dword                 EntryListCount;
    CDialogEntry         *EntryList;
    dword                 ReplyListCount;
    CDialogReply         *ReplyList;
    dword                 StartingListCount;
    CDialogStartingEntry *StartingList;
    char                  EndScript[16];
    char                  EndConverAbortScript[16];
    dword                *ConvoPartiesList;
    dword                 field_3C;
    dword                 field_40;
    dword                 CurrentNodeID;
    dword                 field_48;
    dword                 SpeakerLocale;
    dword                 ConversationWith;
    dword                 MeObjID;
    dword                 field_58;
    dword                 field_5C;
    dword                 field_60;
    dword                 field_64;
    dword                 Me_again;
    dword                 field_6C;
    dword                 PreventZoomIn;

};

struct CNWSVector {
    float x;
    float y;
    float z;
};


int HookFunctions(bool enableUnsafe);

void RunScript(char * sname, int ObjID);
int GetRunScriptReturnValue();

extern char scriptRun;
extern char ActionScriptRunning;
extern char ConditionalScriptRunning;

#endif
