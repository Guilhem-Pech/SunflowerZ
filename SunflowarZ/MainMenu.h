#pragma once
#include <wincontypes.h>
#include <Windows.h>

class MainMenu
{

private:
	COORD size;
	COORD pos;
public:
	MainMenu(const COORD& size, const COORD& pos);
	~MainMenu();
};

