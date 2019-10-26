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



void calcSunflowerZ(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	//TODO
}


void drawMap(SMALL_RECT rcRegion, CHAR_INFO bufferConsole[SCREEN_HEIGHT][SCREEN_WIDTH], MapZ* m)
{
	for (int i = 0; i < m->getCellsZ().size(); ++i)
	{
		for (int j = 0; j < m->getCellsZ()[i].size(); ++j)
		{
			bufferConsole[j][i].Attributes = m->getCellZ(i, j)->getAttributes();
			bufferConsole[j][i].Char.AsciiChar = m->getCellZ(i, j)->getSprite();
		}
	}
	WriteConsoleOutput(hOutput, (CHAR_INFO *)bufferConsole, dwBufferSize, dwBufferCoord, &rcRegion);
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


	EntityManagerZ::getInstance().spawnAndRegister("SunflowerZ", { 0,10 });
	EntityManagerZ::getInstance().spawnAndRegister("SunflowerZ", { 2,10 });
	EntityManagerZ::getInstance().spawnAndRegister("SunflowerZ", { 4,10 });

	for (auto element : EntityManagerZ::getInstance().getListOfEntityZ())
	{
		std::cout << element->pos2DZ.X << " " << element->pos2DZ.Y << std::endl;
	}
	
	/*
	MapZ *m = new MapZ({ SCREEN_HEIGHT,SCREEN_WIDTH });
	m->fillMap();

	for (;;) {

		drawMap(rcRegion, bufferConsole, m);
	
	}
	*/
}


