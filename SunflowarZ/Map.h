#pragma once

#include <Windows.h>
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40

class Map
{

private:
	COORD size;
	// vector<Cell> cellsZ;
	
public:
	
	Map(COORD Size);

	// CellZ  getCellZ(int x, int y)
	// CellZ getGoundCellZ(int y1)
};
