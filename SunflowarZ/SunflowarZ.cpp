#include "pch.h"
#include "SunflowerZ.h"
#include "GameZ.h"
#include "WeaponZ.h"
#include "EntityManagerZ.h"

#include <Windows.h>
#include <iostream>
#include "MapZ.h"
#include "CellZ.h"

#define _WIN32_WINNT 0x0500
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40
#define MENU_HEIGHT 10

COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
COORD dwBufferCoord = { 0, 0 };
HANDLE hOutput;

int nbOfSunflowerZByTeam = 3; // Default number of sunflowerz TODO can be moved to the game manager ?


void calcEntities(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH], const std::vector<std::shared_ptr<EntityZ>>& entityList) {
	for(const auto& ent : entityList)
	{
		COORD coord = ent->getPos2DZ();
		buffer[coord.X][coord.Y].Char.AsciiChar = ent->sprite2DZ;
	}
}


void calcMap(CHAR_INFO bufferConsole[SCREEN_HEIGHT][SCREEN_WIDTH], MapZ* m)
{
	const std::vector<std::vector<std::shared_ptr<CellZ>>> &map = m->getCellsZ();
	
	for (int i(0); i < map.size(); ++i)
	{
		
		for (int j(0); j < map[i].size(); ++j)
		{
			const std::shared_ptr<CellZ> cell(m->getCellZ(i, j));
			bufferConsole[j][i].Attributes = cell->getAttributes();
			bufferConsole[j][i].Char.AsciiChar = cell->getSprite();
		}
	}
}

void writeString(CHAR_INFO bufferConsole[MENU_HEIGHT][SCREEN_WIDTH], string text, COORD begin, WORD attribute = 0x0000)
{
	for (int i(0); i < text.size(); ++i)
	{
		bufferConsole[begin.X][begin.Y + i].Char.AsciiChar = text[i];
		bufferConsole[begin.X][begin.Y + i].Attributes = attribute;
	}
}

void calcMenu(CHAR_INFO bufferConsole[MENU_HEIGHT][SCREEN_WIDTH])
{
	for (auto i(0); i < SCREEN_WIDTH; ++i)
		for(auto j(0); j < MENU_HEIGHT; ++j){
			bufferConsole[j][i].Attributes = BACKGROUND_RED | BACKGROUND_GREEN;
	}

	writeString(bufferConsole, "SunflowarZ", { 1,1 }, BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	writeString(bufferConsole, "Current player: ", { 3,1 }, BACKGROUND_RED | BACKGROUND_GREEN );
}



void draw(SMALL_RECT rcRegion, CHAR_INFO bufferConsole[SCREEN_HEIGHT][SCREEN_WIDTH])
{
	WriteConsoleOutput(hOutput, (CHAR_INFO*)bufferConsole, dwBufferSize, dwBufferCoord, &rcRegion);
}


int main()
{
	bool inGame = true;
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	MoveWindow(consoleWindow, 40, 100, 840, 840, TRUE);
	   	
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT gameView = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };
	SMALL_RECT menuView = { 0, SCREEN_HEIGHT, SCREEN_WIDTH - 1, (SCREEN_HEIGHT - 1) + MENU_HEIGHT };


	CHAR_INFO bufferGameview[SCREEN_HEIGHT][SCREEN_WIDTH] = {};
	CHAR_INFO bufferMenuview[MENU_HEIGHT][SCREEN_WIDTH] = {};

	ReadConsoleOutput(hOutput, (CHAR_INFO *)bufferGameview, dwBufferSize,dwBufferCoord, &gameView);

	/**
	 * Create and fill the MapZ
	 */


	MapZ *m = new MapZ({ SCREEN_HEIGHT,SCREEN_WIDTH });
	m->fillMap();
	const int sizeY = m->getSizeZ().Y-1;


	// TODO Move those in the game manager ! 
	for (int i = 0; i < nbOfSunflowerZByTeam; ++i)
	{
		EntityManagerZ::getInstance().spawnAndRegister(EntityZFactoryZ::Sunflower,
		                                               m->getGroundCellZ(rand() % sizeY / 2)->getPos(),
		                                               EntityManagerZ::player1);

	}

	for (int i = 0; i < nbOfSunflowerZByTeam; ++i)
	{
		EntityManagerZ::getInstance().spawnAndRegister(EntityZFactoryZ::Sunflower,
		                                               m->getGroundCellZ((rand() % sizeY / 2) + (sizeY / 2))->getPos(),
		                                               EntityManagerZ::player2);
	}

	for (;inGame;) {

		calcMap(bufferGameview, m);
		calcEntities(bufferGameview, EntityManagerZ::getInstance().getListOfEntitiesZ());
		draw(gameView, bufferGameview);
		calcMenu(bufferMenuview);
		draw(menuView, bufferMenuview);
		EntityManagerZ::getInstance().update();
	}
	delete(m);
}


