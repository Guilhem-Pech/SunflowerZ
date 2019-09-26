#pragma once

#include <vector>

#include "SunflowerZ.h"
#include "CollisionControllerZ.h"
#include "MapZ.h"


class GameZ
{
public:

	int const maxSFZ;

	MapZ * mapZ;
	std::vector<SunflowerZ*> listSFZ;
	CollisionControllerZ * collisionZ;

	GameZ(int numberSFZ);
	~GameZ();
};

