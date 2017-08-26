/***************************************************************************
    NWNX FOR LINUX SortSet plugin Class
    Copyright (C) 2004 John Klar (paladin at projectplasma dot com)

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

#include <stdio.h>

#include "NWNXSortSet.h"

CNWNXSortSet::CNWNXSortSet() {
}

CNWNXSortSet::~CNWNXSortSet() {
}

bool CNWNXSortSet::OnCreate(gline *config, const char *LogDir)
{
	char log[128];
	sprintf(log, "%s/nwnx_sortset.txt", LogDir);

	// call the base class function
	if (!CNWNXBase::OnCreate(config, log))
		return false;

	// NOP - Configure no longer does anything
	if (!Configure())
		return false;

	Log(0, "NWNX SortSet V.1.0\n");
	Log(0, "(c) 2009 by John Klar (PlasmaJohn)\n");
	Log(0, "visit us at http://www.avlis.org\n\n");
	Log(0, "* Module loaded successfully.\n");

	return true;
}

char *CNWNXSortSet::GetNextArg(char *start, char *dest, int width) {
	char *pos;
	int len;
	if ((pos = strchr(start,'!')) != NULL) {
		len = pos - start;
		++pos;
	} else {
		len = strlen(start);
	}
	if (len > width)
		len = width;
	strncpy(dest, start, len);
	dest[len] = 0;

	return pos;
}

char *CNWNXSortSet::OnRequest(char *gameObject, char *SetName, char* Parameters) {
	char setkey[32], name[22], cmd[32], arg1[1024], arg2[1024], arg3[1024], *lastarg, *pos;


	arg1[0] = 0;
	arg2[0] = 0;
	arg3[0] = 0;

	// Parameters are the call "ADD!value", "GET!15", "LENGTH", etc.
	
	GetNextArg(SetName, name, 22);
	results = Parameters;

	sprintf(setkey, "%08x-%s", gameObject, name);
	
	lastarg = Parameters;
	if ((pos = GetNextArg(Parameters, cmd, 31)) != NULL) {
		lastarg = pos;
		if ((pos = GetNextArg(pos, arg1, 1024)) != NULL) {
			lastarg = pos;
			if ((pos = GetNextArg(pos, arg2, 1024)) != NULL) {
				lastarg = pos;
				if ((pos = GetNextArg(pos, arg3, 1024)) != NULL) {
					lastarg = pos;
				}
			}
		}
	}

	if (strcmp("INIT", cmd) == 0) {
		SetInit(setkey);
	} else if (strcmp("ADD", cmd) == 0) {
		Add(setkey, arg1, arg2, arg3);
	} else if (strcmp("EXISTS", cmd) == 0) {
		Exists(setkey, arg1);
	} else if (strcmp("LENGTH", cmd) == 0) {
		Length(setkey);
	} else if (strcmp("SORT", cmd) == 0) {
		Sort(setkey);
	} else if (strcmp("DESTROY", cmd) == 0) {
		Destroy(setkey);
	} else if (sets.find(setkey) == sets.end()) {
		Log(0, "[%s] Set does not exist\n", setkey);
		sprintf(Parameters, "-5 [%s] Set does not exist.", setkey);
	} else if (strcmp("SETBYIDX", cmd) == 0) {
		SetByIdx(setkey, arg1, arg2, arg3);
	} else if (strcmp("SETBYTAG", cmd) == 0) {
		SetByTag(setkey, arg1, arg2, arg3);
	} else if (strcmp("REMOVE", cmd) == 0) {
		Remove(setkey, arg1);
	} else if (strcmp("GETBYIDX", cmd) == 0) {
		GetByIdx(setkey, arg1);
	} else if (strcmp("GETBYTAG", cmd) == 0) {
		GetByTag(setkey, arg1);
	} else {
		sprintf(Parameters, "[%s] bad command", cmd);
		Log(0, "[%s] %s\n", setkey, Parameters);
	}

	return NULL;
}

bool CNWNXSortSet::Configure() {
	return true;
}

bool CNWNXSortSet::SetInit(const char *setkey) {
	sets[setkey];
	return true;
};

bool CNWNXSortSet::Length(const char *setkey) {
	sprintf(results, "%d", sets[setkey].Length());
	return true;
};

bool CNWNXSortSet::Add(const char *setkey, const char *key, const char *sort, const char *value) {
	sprintf(results, "%d", sets[setkey].Add(key, sort, value));
	return true;
};

bool CNWNXSortSet::SetByIdx(const char *setkey, const char *index, const char *sort, const char *value) {
	int idx = atol(index);
	sprintf(results, "%d", sets[setkey].Set(idx, sort, value));
	return true;
};

bool CNWNXSortSet::SetByTag(const char *setkey, const char *resref, const char *sort, const char *value) {
	ssElement *sptr = sets[setkey].Get(resref);
	if (sptr != NULL) {
		sptr->sort = sort;
		sptr->value = value;
	}
	sprintf(results, "%d", sptr == NULL ? -1 : 0);
	return true;
};

bool CNWNXSortSet::Remove(const char *setkey, const char *index) {
	int idx = atol(index);
	sprintf(results, "%d", sets[setkey].Remove(idx));
	return true;
};

bool CNWNXSortSet::Destroy(const char *setkey) {
	sets.erase(setkey);
	return true;
};

bool CNWNXSortSet::GetByIdx(const char *setkey, const char *index) {
	int idx = atol(index);

	ssElement *sptr = sets[setkey].Get(idx);

	if (sptr == NULL) {
		results[0] = 0;
		return false;
	}

	strcpy(results, sptr->value.c_str());
	return true;
};

bool CNWNXSortSet::GetByTag(const char *setkey, const char *resref) {

	ssElement *sptr = sets[setkey].Get(resref);

	if(sptr == NULL) {
		results[0] = 0;
		return false;
	}
	
	strcpy(results, sptr->value.c_str());
	return true;
};

bool CNWNXSortSet::Exists(const char *setkey, const char *resref) {
	sprintf(results, "%d", sets[setkey].Exists(resref) ? 1 : 0);
	return true;
};

bool CNWNXSortSet::Sort(const char *setkey) {
	sets[setkey].Sort();
	return true;
};

