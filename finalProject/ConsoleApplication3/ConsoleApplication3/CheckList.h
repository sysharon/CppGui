#pragma once
#include <map>
#include "Button.h"
#include "Scrollable.h"

class CheckList : public Panel {
public:
	CheckList(const int, const int, const vector<string>&);
	virtual ~CheckList();
	void deselctIndex(const size_t index) { valsMap[list[index]] = false; }
	void selectIndex(const size_t);
	vector<size_t> getSelectedIndices();
private:
	map< string, bool > valsMap;
	size_t size;
	vector<string> list;
};