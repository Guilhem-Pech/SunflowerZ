#include "pch.h"

#include <Windows.h>
#include <iostream>
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40
COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
COORD dwBufferCoord = { 0, 0 };
HANDLE hOutput;

void calcMapZ(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	for (int x = 0; x < SCREEN_WIDTH; ++x) {
		for (int y = 0; y < SCREEN_HEIGHT; ++y) {
			buffer[y][x].Attributes = 0x00b0;
		}
	}

	for (int y = 5; y <= (SCREEN_HEIGHT - 1); ++y) {
		int a = y / 11;
		for (int x = 0; x <= y + a * a && x <= (SCREEN_WIDTH / 2); ++x) {
			buffer[y][x].Attributes = 0x0080;
			buffer[y][SCREEN_WIDTH - 1 - x].Attributes = 0x0080;
		}
	}

}

void calcSunflowerZ(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	//TODO
}


int main()
{
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };


	CHAR_INFO MapZ[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

	ReadConsoleOutput(hOutput, (CHAR_INFO *)MapZ, dwBufferSize,dwBufferCoord, &rcRegion);
	
	calcMapZ(MapZ);
	

	while (1) {
		calcSunflowerZ(MapZ);
		WriteConsoleOutput(hOutput, (CHAR_INFO *)MapZ, dwBufferSize, dwBufferCoord, &rcRegion);
	}
}