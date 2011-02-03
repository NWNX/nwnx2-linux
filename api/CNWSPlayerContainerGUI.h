#ifndef _CNWSPLAYERCONTAINERGUI_H_
#define _CNWSPLAYERCONTAINERGUI_H_
#include "nwndef.h"

class CNWSPlayerContainerGUI
{
public:
	int SetNextPage(CNWSPlayer *);
	int SetOpen(CNWSPlayer *, unsigned long, int);
	int SetPreviousPage(CNWSPlayer *);
	CNWSPlayerContainerGUI();

};
#endif
