#include "pch.h"
#include <random>
#include "AirCellZ.h"
#include <memory>
#include <iostream>
#include "MapZ.h"

/*
void MapZ::calc(CHAR_INFO buffer[][SCREEN_WIDTH]) {
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

const std::vector<std::vector<std::shared_ptr<CellZ>>>* MapZ::getCellsZ() const
{
	return &cellsZ;
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
			cellsZ[i].push_back(std::shared_ptr<AirCellZ>(new AirCellZ({ j,i })));
		}
		
	}
		


	for (short y = 5; y <= (SCREEN_HEIGHT - 1); ++y) {
		short a = y / 11;
		for (short x = 0; x <= y + a * a && x <= (SCREEN_WIDTH / 2); ++x)
		{
			cellsZ[x][y] = std::shared_ptr<GroundCellZ>(new GroundCellZ({ x,y }));
			cellsZ[SCREEN_WIDTH - 1 - x][y] = std::shared_ptr<GroundCellZ>(new GroundCellZ({ x,y }));
		}
	}
}


COORD MapZ::getSizeZ() const {
	return this->size;
}

template<typename T>
T random_element(const std::vector<T> &vec)
{
	std::random_device seed;
	std::mt19937 engine(seed());
	const std::uniform_int_distribution<int> choose(0, vec.size() - 1);
	return vec[choose(engine)];
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
	
	return random_element(suitable);
}

MapZ::~MapZ()
= default;
