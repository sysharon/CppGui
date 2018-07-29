#pragma once
#include "Graphics.h"


class BorderDrawer {
public:
	virtual ~BorderDrawer() {}
	void setAssets(char[]);
	virtual void draw(const Graphics&, const int, const int, const int, const int) const = 0;
private:
	char _assets[6];
	BorderDrawer* border;
};

class NoBorder : public BorderDrawer {
public:
	NoBorder() { }
	~NoBorder() { }
	void fillBackground(const Graphics&, const int, const int, const int, const int) const;
	void draw(const Graphics&, const int, const int, const int, const int) const override;
};

class SingleBorder : public BorderDrawer {
public:
	SingleBorder();
	~SingleBorder() { }
	void draw(const Graphics&, const int, const int, const int, const int) const override;
};

class DoubleBorder : public BorderDrawer {
public:
	DoubleBorder();
	~DoubleBorder() { }
	void draw(const Graphics&, const int, const int, const int, const int) const override;
};
