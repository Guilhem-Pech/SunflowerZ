#include "pch.h"
#include "CollisionControllerZ.h"
#include "EntityManagerZ.h"

#include <Windows.h>


bool CollisionControllerZ::isCollisionZ(COORD posZ) {
	return EntityManagerZ::isSomeoneHereZ(posZ);
}

void CollisionControllerZ::spreadAoEZ(COORD posInitZ, int radiuZ, std::vector<COORD> posHitByAoEZ) {

}

CollisionControllerZ::CollisionControllerZ(MapZ *mapZ){
}


CollisionControllerZ::~CollisionControllerZ(){
}
