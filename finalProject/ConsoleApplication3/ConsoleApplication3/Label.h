#pragma once
#include "TextBox.h"

class Label : public TextBox {
public:
	Label(const int, const string);
	Label(const int);
	virtual ~Label() { }
	void SetText(const string);
	virtual void draw(Graphics&, const int, const int, const size_t) override;
	bool enableFocus() override { return false; }
	virtual void onKeyDown(const WORD, const CHAR) override { }
	virtual void onMouseClick(const int, const int, const bool) override { }
	virtual void set_cursor(Graphics&, const int, const int) override;
};