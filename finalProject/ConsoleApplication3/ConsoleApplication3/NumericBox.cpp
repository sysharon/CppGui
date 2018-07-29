#include "stdafx.h"
#include "NumericBox.h"
#include <sstream>

int checkWidth(const int width) { return width < 11 ? 11 : width; }

NumericBox::NumericBox(int width, const int min, const int max) : Panel(3, checkWidth(width)) {
	width = checkWidth(width);
	this->min = min;
	this->max = max;
	val = new Label(std::to_string(max).size(), to_string(number));
	val->setBorder(BorderType::Single);
	buttonUp = new Button(1);
	buttonUp->setBorder(BorderType::Single);
	buttonUp->SetText("+");
	buttonDown = new Button(1);
	buttonDown->setBorder(BorderType::Single);
	buttonDown->SetText("-");
	addControl(*val, getLeft() + 1, getTop() + 1);
	addControl(*buttonUp, width - (buttonDown->getWidth() + buttonUp->getWidth() + 3), getTop() + 1);
	addControl(*buttonDown, width - 2, getTop() + 1);
	auto upEvenet = [&](Control *c) {
		if (number < this->max) {
			++number;
			setValue(number);
		}
	};
	buttonUp->addListener(upEvenet, buttonUp);
	auto downEvent = [&](Control *c) {
		if (number > this->min) {
			--number;
			setValue(number);
		}
	};
	buttonDown->addListener(downEvent, buttonDown);
}

NumericBox::~NumericBox() {
	for (int i = 0; i < getChildrens().size(); i++)
		if (getChildrens()[i]) delete getChildrens()[i];
}

void NumericBox::setValue(const int val) {
	if (val >= min && val <= max) {
		number = val;
		this->val->SetText(to_string(number));
	}
}