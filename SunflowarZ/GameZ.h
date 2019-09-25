#pragma once
#include <Windows.h>>
#include <vector>

#include "SunflowerZ.h"
#include "WeaponZ.h"
#include "ProjectZ.h"
#include "CollisionControllerZ.h"

typedef MapZ;

class GameZ
{
public:

	int const maxSFZ;

	MapZ * mapZ;
	std::vector<SunflowerZ*> listSFZ;
	CollisionControllerZ * collisionZ;

	GameZ();
	~GameZ();
};

