#include "pch.h"
#include "MapZ.h"
#include <random>
#include <algorithm>
#include <iostream>

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

std::vector<std::vector<CellZ*>> MapZ::getCellsZ()
{
	return cellsZ;
}

MapZ::MapZ(const COORD &size) :
	size(size), cellsZ(size.Y, std::vector<CellZ*>(size.X))
{}

CellZ* MapZ::getCellZ(int x, int y)
{
	return cellsZ[x][y];
}

void MapZ::fillMap()
{
	for(short i = 0; i<cellsZ.size(); ++i)
		for (short j = 0; j < cellsZ[i].size(); ++j)
		{
			if (cellsZ[i][j]) // Delete previous cellz if any so there is no memory leak
				delete cellsZ[i][j];
			cellsZ[i][j] = new AirCellZ({ j,i });
		}


	for (int y = 5; y <= (SCREEN_HEIGHT - 1); ++y) {
		int a = y / 11;
		for (int x = 0; x <= y + a * a && x <= (SCREEN_WIDTH / 2); ++x) {
			cellsZ[x][y]->setAttribute(0x0080);
			cellsZ[SCREEN_WIDTH - 1 - x][y]->setAttribute(0x0080);
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

CellZ* MapZ::getGoundCellZ(const int& y1)
{
	std::vector<CellZ*> *suitable = new std::vector<CellZ*>();
	for (CellZ *e : cellsZ[y1])
		if (e->getTypeName() == "ground")
			suitable->push_back(e);

	if (suitable->empty())
		return nullptr;	
	return random_element(*suitable);
}

MapZ::~MapZ()
{
	for (short i = 0; i < cellsZ.size(); ++i)
		for (short j = 0; j < cellsZ[i].size(); ++j)
			if (cellsZ[i][j]) // Delete previous cellz if any so there is no memory leak
				delete cellsZ[i][j];
}
