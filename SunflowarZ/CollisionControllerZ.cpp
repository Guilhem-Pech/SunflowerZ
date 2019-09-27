#include "pch.h"
#include "CollisionControllerZ.h"
#include "EntityManagerZ.h"

#include <Windows.h>


bool CollisionControllerZ::isCollisionZ(COORD posZ) {
	return EntityManagerZ::isSomeoneHereZ(posZ);
}

void CollisionControllerZ::spreadAoEZ(COORD posInitZ, int radiuZ, const std::vector<COORD>& posHitByAoEZ) {

}

CollisionControllerZ::CollisionControllerZ(MapZ *mapZ): map(mapZ)
{
}


CollisionControllerZ::~CollisionControllerZ() = default;
