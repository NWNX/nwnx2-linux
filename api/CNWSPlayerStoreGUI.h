#ifndef _CNWSPLAYERSTOREGUI_H_
#define _CNWSPLAYERSTOREGUI_H_
#include "nwndef.h"

class CNWSPlayerStoreGUI
{
public:
	int CloseStore(CNWSPlayer *, int);
	int OpenStore(CNWSPlayer *, unsigned long, char, char);
	CNWSPlayerStoreGUI();

};
#endif
