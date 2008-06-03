
/***************************************************************************
    NWNXStruct.h - Interface for the CNWNXStruct class.
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

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

#ifndef NWNXStruct_h_
#define NWNXStruct_h_

#include "NWNXBase.h"

#include <sys/time.h>

class CNWNXStruct:public CNWNXBase {
  public:
    CNWNXStruct();
    virtual ~ CNWNXStruct();

    bool OnCreate(gline * nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);

    // bool OnRelease ();

  protected:
    void CalcDurationBasis(char *value);
    void SetDurationBasis(char *value);

    void GetStructDuration(char *value);
    void GetStructDurationRemaining(char *value);

    void GetStructInteger(char *value);
    void SetStructInteger(char *value);

    void GetSpellId(char *value);
    void SetSpellId(char *value);

  private:
    int GetCurrentDurationTime();

    int DurationBasisMilliseconds;
    int DurationBasis2880Seconds;
    struct timeval DurationBasisTime;
};

#endif
