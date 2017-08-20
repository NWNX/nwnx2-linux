#include "SortSetImpl.h"

void delsse(ssElement *ele) {
	delete ele;
}

SortSet::SortSet() {
}

SortSet::~SortSet() {
	// iterate vector and delete all ssElement pointers
	std::for_each( sortIndex.begin(), sortIndex.end(),
			 	  delsse );

	// sortIndex and keyIndex will clean up themselves
}

int
SortSet::Add(ssElement &element) {
	return Add(element.key.c_str(), element.sort.c_str(), element.value.c_str());
}

int
SortSet::Add(const char *key, const char *sort, const char *value) {

	if(key == NULL)
		return -2;
	if(sort == NULL)
		return -3;
	if(value == NULL)
		return -4;

	if(keyIndex.find(key) != keyIndex.end())
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
	if(index<0 || index>sortIndex.size())
		return NULL;
	return sortIndex[index];
}

ssElement *
SortSet::Get(const char *key) {
	if(keyIndex.find(key) == keyIndex.end())
		return NULL;
	return keyIndex[key];
}

bool
SortSet::Exists(const char *key) {
	return (keyIndex.find(key) != keyIndex.end());
}

int
SortSet::Set(int index, const char *sort, const char *value) {
	if(index<0 || index>sortIndex.size())
		return -1;
	if(sort == NULL)
		return -3;
	if(value == NULL)
		return -4;

	ssElement *sptr=sortIndex[index];
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
	if(index<0 || index>sortIndex.size())
		return -1;

	ssElement *sptr = sortIndex[index];

	keyIndex.erase(sptr->key);
	sortIndex.erase(sortIndex.begin()+index);

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
