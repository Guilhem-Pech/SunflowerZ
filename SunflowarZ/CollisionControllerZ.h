#pragma once
#include "MapZ.h"
#include <vector>

typedef MapZ;

class CollisionControllerZ
{
public:

	MapZ * map;

	bool isCollisionZ(COORD posZ);
	void spreadAoEZ(COORD posInitZ, int radiuZ, std::vector<COORD> posHitByAoEZ);

	CollisionControllerZ(MapZ mapZ);
	~CollisionControllerZ();
};

