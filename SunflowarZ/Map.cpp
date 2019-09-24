#include "pch.h"
#include "Map.h"
#include <random>


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

Map::Map(const COORD &size)
{
	const std::vector<std::vector<CellZ> > vec(size.Y, std::vector<CellZ>(size.X));
	cellsZ = vec;
}

CellZ* Map::getCellZ(const int &x, const int &y)
{
	return &cellsZ[x][y];
}

void Map::fillMap(const COORD & size)
{
	// Fill the map with air
	for (short y = 0; y < size.Y; ++y) {
		for (short x = 0; x < size.X; ++x) {
			cellsZ[y][x] = AirCellZ({x,y});
		}
	}
}

CellZ random_element(const std::vector<CellZ> &vec)
{
	std::random_device seed;
	std::mt19937 engine(seed());
	std::uniform_int_distribution<int> choose(0, vec.size() - 1);
	return vec[choose(engine)];
}

CellZ* Map::getGoundCellZ(const int& y1)
{
	std::vector<CellZ> *suitable = new std::vector<CellZ>();
	for (CellZ e : cellsZ[y1])
		if (e.getTypeName() == "ground")
			suitable->push_back(e);

	if (suitable->empty())
		return nullptr;	
	return &random_element(*suitable);
}


