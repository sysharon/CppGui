#pragma once
#include "Button.h"
#include "Scrollable.h"

class Combox : public Scrollable {
public:
	Combox(const int, const vector<string>&);
	~Combox() { }
	void open();
	void close();
	void update() override;
private:
	Button* button;
	bool isListOpen;
};