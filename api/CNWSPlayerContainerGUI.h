#ifndef _CNWSPLAYERCONTAINERGUI_H_
#define _CNWSPLAYERCONTAINERGUI_H_
#include "nwndef.h"

class CNWSPlayerContainerGUI
{
public:
    void SetNextPage(CNWSPlayer *);
    void SetOpen(CNWSPlayer *, unsigned long, int);
    void SetPreviousPage(CNWSPlayer *);
    CNWSPlayerContainerGUI();

    /* 0x0/0 */ unsigned long m_oidOpen;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long m_bUpdateRequested;
};
#endif
