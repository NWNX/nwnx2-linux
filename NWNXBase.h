/***************************************************************************
    NWNXBase.h: interface for the CNWNXBase class.
    Copyright (C) 2003 Ingmar Stieger (Papillon, papillon@blackdagger.com) and
	Jeroen Broekhuizen (nwnx@jengine.nl)

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

#ifndef NWNXBase_h_
#define NWNXBase_h_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gline.h"
#include "newpluginapi.h"
#include "core/core.h"

#define OBJECT_INVALID 0x7F000000

class CNWNXBase
{
public:
    CNWNXBase();
    virtual ~CNWNXBase();

    ///////////////////////////////////////////////////////////////////////////
    // Function: OnCreate
    // Description
    //	This function is called just when an instance is created.
    //	Overloading is allowed, but the base class function must be called first.
    // Parameters
    //  nwnxConfig  : parsed nwnx2.ini, a gline instance
    //	LogFile		: optionally a path and filename of the log file
    virtual bool OnCreate(gline *nwnxConfig, const char* LogFile = NULL);

    ///////////////////////////////////////////////////////////////////////////
    // Function: OnRequest (char* Request, char* Parameters)
    // Description
    //	Called when a request is pending from a NWScript.
    //	This function must be overloaded by the module.
    // Parameters
    //	Request		: the job that must be performed
    //  Parameters	: optional parameters
    virtual char* OnRequest(char *gameObject, char* Request, char* Parameters) = 0;

    ///////////////////////////////////////////////////////////////////////////
    // Function: OnRequestObject (char* Request)
    // Description
    //	Called when a request is pending from a NWScript.
    //	This function must be overloaded by the module.
    //	Request		: the job that must be performed
    virtual unsigned long OnRequestObject(char *gameObject, char* Request);

    ///////////////////////////////////////////////////////////////////////////
    // Function: OnRelease
    // Description
    //	Called just before deletion of an instance of this class.
    //	Overloading is allowed, but the base class function must be called.
    // Parameters
    //	None
    virtual bool OnRelease();

    ///////////////////////////////////////////////////////////////////////////
    // Function: Log (int debugPri, const char* pcMsg[, argument]...);
    // Description:
    //	This function formats and writes a message to the log file. It works
    //  the same way as the standard C printf function.
    //  Example: Log ("Set array item %d with value %s.", iIndex, pcValue);
    // Parameters:
    //	debugPri	: message will only be sent to the log if this argument
    //				  is >= the instance's debuglevel
    //	Msg			: the format string
    //  [argument]	: optional arguments
    void Log(int debugPri, const char* Msg, ...);

    // convenience, checks Msg and Param lengths
    // returns 0 if Param not set 1 if set
    int ParamLog(int debugPri, const char* Msg, char* Parameters);

    ///////////////////////////////////////////////////////////////////////////
    // Function: SetDebugLevel (int level);
    // Description:
    //  Helper function to alter the instance's debuglevel independent of
    //  the global level.  Returns the old debuglevel.
    // Parameters:
    //  level	: the desired level
    int SetDebugLevel(int level);

    int GetDebugLevel();

    ///////////////////////////////////////////////////////////////////////////
    // Function: BaseConf ();
    // Description:
    //  This function parses the generic config options: "debuglevel", etc.
    // Parameters:
    //  None
    void BaseConf();

protected:
    FILE* m_fFile;
    gline* nwnxConfig;
    const char * confKey;
    int debuglevel;

private:

};

#endif
