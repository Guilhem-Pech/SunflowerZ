#include "pch.h"

#include <Windows.h>
#include <iostream>
#include "Map.h"
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40
COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
COORD dwBufferCoord = { 0, 0 };
HANDLE hOutput;



void calcSunflowerZ(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	//TODO
}


int main()
{
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };


	CHAR_INFO bufferConsole[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

	ReadConsoleOutput(hOutput, (CHAR_INFO *)bufferConsole, dwBufferSize,dwBufferCoord, &rcRegion);
	
	
	

	while (1) {
		
		Map *m = new Map({40,100});
		/*
		for (sunflower m : list)
			m->calc(bufferConsole);
		

		for (projectile p : listP)
			p->calc(bufferConsole);
		
		barreAction->calc(bufferBar);
		*/
		WriteConsoleOutput(hOutput, (CHAR_INFO *)bufferConsole, dwBufferSize, dwBufferCoord, &rcRegion);
		
	}
}