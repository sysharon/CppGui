#pragma once
#include "Panel.h"
#include "Label.h"
#include "Button.h"

class NumericBox : public Panel {
public:
	NumericBox(int, const int, const int);
	virtual ~NumericBox();
	string getValue() const { return to_string(number); }
	void setValue(const int);
	Label* getLabel() const { return val; }
	void SetText(const Label&, string newText) const { val->setValue(newText); }
private:
	int min, max, number = 20;
	Label *val;
	Button *buttonUp, *buttonDown;
};