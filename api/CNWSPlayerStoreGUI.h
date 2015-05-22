#ifndef _CNWSPLAYERSTOREGUI_H_
#define _CNWSPLAYERSTOREGUI_H_
#include "nwndef.h"

class CNWSPlayerStoreGUI
{
public:
    void CloseStore(CNWSPlayer *, int);
    void OpenStore(CNWSPlayer *, unsigned long, char, char);
    CNWSPlayerStoreGUI();

};
#endif
