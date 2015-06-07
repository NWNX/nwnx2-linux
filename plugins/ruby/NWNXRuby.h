/***************************************************************************
    NWNXRuby.h - Interface for the CNWNXRuby class.
    (c) 2008-2013 virusman (virusman@virusman.ru)

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

#ifndef NWNXRuby_h_
#define NWNXRuby_h_

#include "NWNXBase.h"
#include <ruby.h>

class CNWNXRuby : public CNWNXBase
{
public:
    CNWNXRuby();
    virtual ~CNWNXRuby();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
//	unsigned long OnRequestObject (char *gameObject, char* Request);
    void ExecuteCommand(char *value);
    char *Eval(char *value);
    void LogRubyError();


    bool bHooked;
    VALUE cNWScript;
    int nError;

private:

};

#endif
