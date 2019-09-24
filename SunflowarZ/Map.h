#pragma once

#include <Windows.h>
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40

class Map
{
public:
	void calc(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]);
	Map(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]);
	
};
