/***************************************************************************
    NWNXFunction.h - Interface for the CNWNXFunction class.
    Copyright (C) 2003 Ingmar Stieger (Papillon)
    email: papillon@blackdagger.com

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

#ifndef NWNXFunction_h_
#define NWNXFunction_h_

#include "NWNXBase.h"

class CNWNXFunction : public CNWNXBase
{
public:
	CNWNXFunction();
	virtual ~CNWNXFunction();

	bool OnCreate(gline *nwnxConfig, const char *LogDir=NULL);
	char* OnRequest (char* gameObject, char* Request, char* Parameters);

	// bool OnRelease ();

protected:
	void SetLockDC(char* value);
	void SetStolenFlag(char* value);
	void SetGoldPieceValue(char* value);
	void SetTag(char* value);
	void SetArmorAC(char* value);
	void GetArmorAC(char* value);
	void GetDescription(char* value);
	void SetIsPickPocketable(char* value);
	void GetIsPickPocketable(char* value);
	void SetBodyPart(char* value);
	void GetBodyPart(char* value);
	void ObjDump(char* value);

private:
	char* pGameObject;
};

#endif
