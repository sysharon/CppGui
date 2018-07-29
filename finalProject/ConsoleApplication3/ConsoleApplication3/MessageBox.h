#pragma once
#include "Panel.h"
#include "Label.h"
#include "Button.h"

class Messagebox : public Panel {
public:
	Messagebox(const int, const int);
	virtual ~Messagebox();
	void show() override;
	void setText(string);
	void setTitle(string);

private:
	void addControl(Control&, const int, const int) override;
	bool enableFocus() override { return false; }
	void draw(Graphics& graphics, const int, const int, const size_t) override;
	Label *title, *description;
	Button *bOK, *bBack;
};
