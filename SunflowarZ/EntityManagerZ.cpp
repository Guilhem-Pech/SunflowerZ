#include "pch.h"
#include "EntityManagerZ.h"

std::vector<EntityZ*> EntityManagerZ::listOfEntityZ;

void EntityManagerZ::registerZ(EntityZ * entZ) {
	EntityManagerZ::listOfEntityZ.push_back(entZ);
}

bool EntityManagerZ::isSomeoneHereZ(COORD pos) {
	for (auto e : EntityManagerZ::listOfEntityZ)
		if (e->getPos2DZ().X == pos.X && e->getPos2DZ().Y== pos.Y)
			return true;	
	return false;
}
