#include "pch.h"
#include "GameZ.h"


GameZ::GameZ()
{
	this->mapZ = new MapZ();
	this->collisionZ = new CollisionControllerZ(mapZ);
}


GameZ::~GameZ()
{
}
