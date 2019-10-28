#pragma once

#include <Windows.h>
#include "GroundCellZ.h"
#include <vector>
#include <memory>

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 40

class MapZ
{

private:
	COORD size;
	std::vector<std::vector<std::shared_ptr<CellZ>>> cellsZ;
	
public:

	const std::vector<std::vector<std::shared_ptr<CellZ>>>& getCellsZ() const;
	
	MapZ(const COORD &size);

	std::shared_ptr<CellZ>  getCellZ(int x, int y);
	void fillMap();

	COORD getSizeZ() const;

	std::shared_ptr<CellZ> getGroundCellZ(const int &y1 );
	~MapZ();
};
