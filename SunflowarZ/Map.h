#pragma once

#include <Windows.h>
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40

class Map
{
public:
	void calc(CHAR_INFO buffer[40][100]);
	Map(CHAR_INFO buffer[40][100]);
	
};
