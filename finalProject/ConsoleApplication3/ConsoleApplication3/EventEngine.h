#pragma once
#include "Control.h"
#include "Graphics.h"


class EventEngine {
public:
	static EventEngine& getEngine();
	void run(Control& c);
	void stop();
	static void moveFocusForword(Control& main, Control* focused);
	static void moveFocusBackword(Control& main, Control* focused);
private:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	static EventEngine* eventEngine;
	bool isEventEngineRunning;
	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};