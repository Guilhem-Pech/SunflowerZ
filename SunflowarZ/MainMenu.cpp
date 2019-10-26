#include "pch.h"
#include "MainMenu.h"
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40


MainMenu::MainMenu(const COORD & size, const COORD & pos): size(size), pos(pos)
{}

//void MainMenu::calcMenu()
//{
//	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };
//	CHAR_INFO MenuBuffer[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };
//}

MainMenu::~MainMenu()
= default;
