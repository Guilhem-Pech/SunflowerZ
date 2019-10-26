#pragma once

#include <Windows.h>
#include "GroundCellZ.h"
#include <vector>

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40

class MapZ
{

private:
	COORD size;
	std::vector<std::vector<CellZ*>> cellsZ;
	
public:

	std::vector<std::vector<CellZ*>> getCellsZ();
	MapZ(const COORD &size);

	CellZ*  getCellZ(int x, int y);
	void fillMap();

	COORD getSizeZ() const;

	CellZ* getGoundCellZ(const int &y1 );
	~MapZ();
};
