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
