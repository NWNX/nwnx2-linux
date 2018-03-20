/***************************************************************************
    NWNX FOR LINUX SortSet plugin Implementation Class
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

#include "SortSetImpl.h"

void delsse(ssElement *ele) {
	delete ele;
}

SortSet::SortSet() {
}

SortSet::~SortSet() {
	// iterate vector and delete all ssElement pointers
	std::for_each(sortIndex.begin(), sortIndex.end(), delsse);

	// sortIndex and keyIndex will clean up themselves
}

int
SortSet::Add(ssElement &element) {
	return Add(element.key.c_str(), element.sort.c_str(), element.value.c_str());
}

int
SortSet::Add(const char *key, const char *sort, const char *value) {

	if (key == NULL)
		return -2;
	if (sort == NULL)
		return -3;
	if (value == NULL)
		return -4;

	if (keyIndex.find(key) != keyIndex.end())
		// collision!
		return -1;

	ssElement *sptr = new ssElement;
	sptr->key = key;
	sptr->sort = sort;
	sptr->value = value;

	sortIndex.push_back(sptr);
	keyIndex[key] = sptr;

	return 0;
}

ssElement *
SortSet::Get(int index) {
	if (index < 0 || index > sortIndex.size())
		return NULL;
	return sortIndex[index];
}

ssElement *
SortSet::Get(const char *key) {
	if (keyIndex.find(key) == keyIndex.end())
		return NULL;
	return keyIndex[key];
}

bool
SortSet::Exists(const char *key) {
	return (keyIndex.find(key) != keyIndex.end());
}

int
SortSet::Set(int index, const char *sort, const char *value) {
	if (index < 0 || index > sortIndex.size())
		return -1;
	if (sort == NULL)
		return -3;
	if (value == NULL)
		return -4;

	ssElement *sptr = sortIndex[index];
	sptr->sort = sort;
	sptr->value = value;

	return 0;
}

int
SortSet::Set(int index, ssElement &newval) {
	// key is ignored!
	return Set(index, newval.sort.c_str(), newval.value.c_str());
}

int
SortSet::Remove(int index) {
	if( index < 0 || index > sortIndex.size())
		return -1;

	ssElement *sptr = sortIndex[index];

	keyIndex.erase(sptr->key);
	sortIndex.erase(sortIndex.begin() + index);

	delete sptr;

	return 0;
}

bool
sortAlgo(const ssElement* p1, const ssElement* p2) {
	return p1->sort < p2->sort;
}

int
SortSet::Sort() {
	std::sort(sortIndex.begin(), sortIndex.end(), sortAlgo);
	return 0;
}

int
SortSet::Length() {
	return sortIndex.size();
}
