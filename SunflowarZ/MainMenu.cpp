#include "pch.h"
#include "MainMenu.h"



MainMenu::MainMenu(const COORD & size, const COORD & pos)
{
	this->size = size;
	this->pos = pos;
	
}

void MainMenu::calcMenu()
{
	SMALL_RECT rcRegion = { pos.X, pos.Y,  pos.X + size.X, pos.Y + size.Y};
	CHAR_INFO menuZ[size.X][size.Y] = { 0 };
}

MainMenu::~MainMenu()
{
}
