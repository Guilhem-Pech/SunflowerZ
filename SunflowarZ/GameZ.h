#pragma once

#include <vector>

#include "SunflowerZ.h"
#include "CollisionControllerZ.h"
#include "EntityManagerZ.h"
#include "MapZ.h"


class GameZ
{
public:

	int const maxSFZ;
	MapZ * mapZ;
	CollisionControllerZ * collisionZ;

	GameZ(int numberSFZ);
	~GameZ();
};

