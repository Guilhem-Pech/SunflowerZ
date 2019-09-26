#include "pch.h"
#include "SunflowerZ.h"
#include "GameZ.h"
#include "WeaponZ.h"

#include <Windows.h>
#include <iostream>
#include "MapZ.h"
#include "CellZ.h"

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40
COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
COORD dwBufferCoord = { 0, 0 };
HANDLE hOutput;



void calcSunflowerZ(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	//TODO
}


void draw(SMALL_RECT rcRegion, CHAR_INFO bufferConsole[SCREEN_HEIGHT][SCREEN_WIDTH], MapZ* m)
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
	
	
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };


	CHAR_INFO bufferConsole[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

	ReadConsoleOutput(hOutput, (CHAR_INFO *)bufferConsole, dwBufferSize,dwBufferCoord, &rcRegion);

	/**
	 * Create and fill the MapZ
	 */
	MapZ *m = new MapZ({ SCREEN_HEIGHT,SCREEN_WIDTH });
	m->fillMap();
	
	while (1) {

		draw(rcRegion, bufferConsole, m);
	
	}		
}


