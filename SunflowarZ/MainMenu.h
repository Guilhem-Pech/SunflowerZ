#pragma once

#include <Windows.h>
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40

class MainMenu
{

private:
	COORD size{};
	COORD pos{};
public:
	MainMenu(const COORD& size, const COORD& pos);
//	void calcMenu();
	~MainMenu();
};

