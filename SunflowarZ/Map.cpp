#include "pch.h"
#include "Map.h"


/*
void Map::calc(CHAR_INFO buffer[][SCREEN_WIDTH]) {
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
*/

Map::Map(COORD size)
{

}

