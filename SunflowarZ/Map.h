#pragma once

#include <Windows.h>
#include "AirCellZ.h"
#include "GroundCellZ.h"
#include "RockCellZ.h"
#include <vector>

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40

class Map
{

private:
	COORD size;
	std::vector<std::vector<CellZ*>> cellsZ;
	
public:

	std::vector<std::vector<CellZ*>> getCellsZ();
	Map(const COORD &size);

	CellZ*  getCellZ(int x, int y);
	void fillMap();

	CellZ* getGoundCellZ(const int &y1 );
};
