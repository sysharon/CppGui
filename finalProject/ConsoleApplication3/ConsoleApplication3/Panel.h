#pragma once
#include "Control.h"


class Panel : public Control {
public:
	Panel(const int, const int);
	virtual void onKeyDown(const WORD, const CHAR) override;
	virtual void onMouseClick(const int, const int, const bool) override;
	void draw(Graphics& graphics, const int, const int, const size_t) override;
	virtual void getAllControls(vector<Control*>*) override;
	virtual bool enableFocus() override { return false; }
	virtual void addControl(Control&, const int, const int);
	static void restartFocus();
	virtual void set_layer(const size_t) override;
	virtual ~Panel() { }
	vector<Control*>& getChildrens() { return children; }
	vector<Control*>& getFocusVec() { return focusVec; }
private:
	vector < Control* > children;
	static vector < Control* > focusVec;
};