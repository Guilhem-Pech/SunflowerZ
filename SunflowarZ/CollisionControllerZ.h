#pragma once
#include "MapZ.h"
#include "EntityManagerZ.h"

#include <vector>

class CollisionControllerZ
{
public:

	MapZ * map;

	bool isCollisionZ(COORD posZ);
	void spreadAoEZ(COORD posInitZ, int radiuZ, const std::vector<COORD>& posHitByAoEZ);

	CollisionControllerZ(MapZ *mapZ);
	~CollisionControllerZ();
};

