#pragma once
#include "MapZ.h"
#include "EntityManagerZ.h"
#include "ProjectZ.h"

#include <vector>

class CollisionControllerZ
{
public:

	std::shared_ptr<MapZ> mapZ;

	bool isCollisionZ(COORD posZ);
	void impactZ(COORD posInitZ, std::shared_ptr<ProjectZ> bulletZ);
	void impactRecZ(std::shared_ptr<CellZ> cellZ, ProjectZ * bulletZ);
	bool isPositionValidZ(COORD posZ);

	void setMap(std::shared_ptr<MapZ> mapZ);

	CollisionControllerZ();
	~CollisionControllerZ();
};

