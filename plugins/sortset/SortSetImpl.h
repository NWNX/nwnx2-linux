/***************************************************************************
    NWNX FOR LINUX SortSet plugin Implementation Interface
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

//: SortSet.h - sortable container with random and associative access
#ifndef SortSet_h_
#define SortSet_h_

// using namespace::std;

#include <vector>
#include <map>
#include <string>
#include <algorithm>
// #include <iostream>

struct ssElement {
	// ~ssElement() { cout << "ssE: deleted" << endl; };
	std::string key;
	std::string sort;
	std::string value;
};

class SortSet {
	std::vector<ssElement*> sortIndex;
	std::map<std::string, ssElement*> keyIndex;

public:
	SortSet();
	~SortSet();

	int Length();
	int Add(const char *key, const char *sort, const char *value);
	int Add(ssElement &element);
	int Set(int index, const char *sort, const char *value);
	int Set(int index, ssElement &newval);
	ssElement *Get(int index);
	ssElement *Get(const char *key);
	int Remove(int index);
	bool Exists(const char *key);
	int Sort();

protected:
	// bool SortSet::sortAlgo(const ssElement*& p1, const ssElement*& p2);

};

#endif
