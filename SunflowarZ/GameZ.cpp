#include "pch.h"
#include "GameZ.h"
#include <random>


GameZ::GameZ(int numberSFZ): maxSFZ(0)
{
	this->mapZ = new MapZ({ 100,40 }); //TODO modulable
	this->collisionZ = new CollisionControllerZ(mapZ);
	for (int i = 0; i < maxSFZ; ++i) {
		COORD temp = mapZ->getGoundCellZ(rand() % mapZ->getSizeZ().X)->getPos();
		++temp.X;
		++temp.Y;
		auto* sunflowerZ = new SunflowerZ(temp);
	}
}


GameZ::~GameZ()
= default;
