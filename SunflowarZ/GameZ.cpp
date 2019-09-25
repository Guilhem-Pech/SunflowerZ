#include "pch.h"
#include "GameZ.h"


GameZ::GameZ(int numberSFZ): maxSFZ(0)
{
	this->mapZ = new MapZ({ 100,40 }); //TODO modulable
	this->collisionZ = new CollisionControllerZ(mapZ);
}


GameZ::~GameZ()
{
}
