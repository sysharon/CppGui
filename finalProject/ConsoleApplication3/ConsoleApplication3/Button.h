#pragma once
#include "Label.h"
#include "EventEngine.h"
#include <functional>

class Button : public Label {
public:
	Button(const int width) : Label(width, "[X]") { }
	virtual ~Button() { }
	void addListener(const std::function<void(Control*)> listener, Control* c) { action = listener; this->c = c; }
	void onMouseClick(const int, const int, const bool) override { action(c); }
	bool enableFocus() override { return true; }
	void onKeyDown(const WORD code, const CHAR) override { if (code == VK_SPACE || code == VK_RETURN) action(c); }

private:
	std::function<void(Control*)> action;
	Control* c;
};