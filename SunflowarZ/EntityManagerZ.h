#pragma once
#include <vector>

#include"EntityZ.h"


class EntityManagerZ
{
public:

	static std::vector<EntityZ*> listOfEntityZ;

	static void registerZ(EntityZ * entZ); //register the parameter entity into the vector.
	static bool isSomeoneHereZ(COORD pos); //true if an entity is present at that coordinate
};

