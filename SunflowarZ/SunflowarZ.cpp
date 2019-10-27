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

COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
COORD dwBufferCoord = { 0, 0 };
HANDLE hOutput;

int nbOfSunflowerZByTeam = 3; // Default number of sunflowerz


void calcEntities(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH], std::vector<std::shared_ptr<EntityZ>> entityList) {
	for(auto ent : entityList)
	{
		COORD coord = ent->getPos2DZ();
		buffer[coord.X][coord.Y].Char.AsciiChar = ent->sprite2DZ;
	}
}


void calcMap(CHAR_INFO bufferConsole[SCREEN_HEIGHT][SCREEN_WIDTH], MapZ* m)
{
	for (int i = 0; i < m->getCellsZ().size(); ++i)
	{
		for (int j = 0; j < m->getCellsZ()[i].size(); ++j)
		{
			bufferConsole[j][i].Attributes = m->getCellZ(i, j)->getAttributes();
			bufferConsole[j][i].Char.AsciiChar = m->getCellZ(i, j)->getSprite();
		}
	}
}


void draw(SMALL_RECT rcRegion, CHAR_INFO bufferConsole[SCREEN_HEIGHT][SCREEN_WIDTH])
{
	WriteConsoleOutput(hOutput, (CHAR_INFO*)bufferConsole, dwBufferSize, dwBufferCoord, &rcRegion);
}


int main()
{

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	MoveWindow(consoleWindow, 40, 100, 840, 840, TRUE);
	   	
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };


	CHAR_INFO bufferConsole[SCREEN_HEIGHT][SCREEN_WIDTH] = {};

	ReadConsoleOutput(hOutput, (CHAR_INFO *)bufferConsole, dwBufferSize,dwBufferCoord, &rcRegion);

	/**
	 * Create and fill the MapZ
	 */


	MapZ *m = new MapZ({ SCREEN_HEIGHT,SCREEN_WIDTH });
	m->fillMap();
	const int sizeY = m->getSizeZ().Y-1;
	
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

	for (;;) {

		calcMap(bufferConsole, m);
		calcEntities(bufferConsole, EntityManagerZ::getInstance().getListOfEntitiesZ());
		draw(rcRegion, bufferConsole);
		
		EntityManagerZ::getInstance().update();
	}
}


