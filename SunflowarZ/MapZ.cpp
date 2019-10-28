#include "pch.h"
#include "MapZ.h"
/*
void MapZ::calc(CHAR_INFO bufferGame[][SCREEN_WIDTH]) {
	for (int x = 0; x < SCREEN_WIDTH; ++x) {
		for (int y = 0; y < SCREEN_HEIGHT; ++y) {
			bufferGame[y][x].Attributes = 0x00b0;
		}
	}

	for (int y = 5; y <= (SCREEN_HEIGHT - 1); ++y) {
		int a = y / 11;
		for (int x = 0; x <= y + a * a && x <= (SCREEN_WIDTH / 2); ++x) {
			bufferGame[y][x].Attributes = 0x0080;
			bufferGame[y][SCREEN_WIDTH - 1 - x].Attributes = 0x0080;
		}
	}

}
*/
class Util;

const std::vector<std::vector<std::shared_ptr<CellZ>>>& MapZ::getCellsZ() const
{
	return cellsZ;
}

MapZ::MapZ(const COORD &size) :
	size(size)
{}

std::shared_ptr<CellZ> MapZ::getCellZ(int x, int y)
{	
	return cellsZ[x][y];
}

void MapZ::fillMap()
{
	for (short i = 0; i < size.Y; ++i)
	{
		cellsZ.emplace_back();
		for (short j = 0; j < size.X; ++j)
		{
			COORD coord = { j,i };
			cellsZ[i].push_back(std::make_shared<AirCellZ>(coord));
		}
		
	}
		


	for (short y = 5; y <= (SCREEN_HEIGHT - 1); ++y) {
		short a = y / 11;
		for (short x = 0; x <= y + a * a && x <= (SCREEN_WIDTH / 2); ++x)
		{
			COORD coord = { x,y };
			cellsZ[x][y] = std::make_shared<GroundCellZ>(coord);
			cellsZ[SCREEN_WIDTH - 1 - x][y] = std::make_shared<GroundCellZ>(coord);
		}
	}
}


COORD MapZ::getSizeZ() const {
	return this->size;
}

std::shared_ptr<CellZ> MapZ::getGroundCellZ(const int& y1)
{
	std::vector<std::shared_ptr<CellZ>> suitable;

	for (int i = 1; i< cellsZ[y1].size(); ++i)
	{
		if(cellsZ[y1][i - 1]->getTypeName() == "air" && (cellsZ[y1][i]->getTypeName() == "ground"))
		{			
			suitable.push_back(cellsZ[y1][i-1]);
		}
			
	}
	if (suitable.empty())
		return std::shared_ptr<CellZ>();	
	return Util::randomElement(suitable);
}

MapZ::~MapZ()
= default;
