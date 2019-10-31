#include "pch.h"
#include "CollisionControllerZ.h"
#include "ProjectZ.h" //polymorphysme/20

#include <Windows.h>


bool CollisionControllerZ::isCollisionZ(COORD posZ) {
	return EntityManagerZ::getInstance()->checkIfSomeoneHere(posZ);
}

void CollisionControllerZ::impactZ(COORD posInitZ, std::shared_ptr<ProjectZ> bulletZ){ //those who call impactZ don't know the map so they just use COORD. the CC will use the map.
	std::shared_ptr<CellZ> tempC = mapZ->getCellZ(posInitZ.X, posInitZ.Y);
	impactRecZ(tempC, bulletZ.get());
}

void CollisionControllerZ::impactRecZ(std::shared_ptr<CellZ> cellZ, ProjectZ * bulletZ) { //recurcivly call itself on the nearest CellZ while radius>1.
	if (EntityManagerZ::getInstance()->checkIfSomeoneHere(cellZ->getPos())) { //check if an entity is in that cellZ //redondant
		std::static_pointer_cast<SunflowerZ>(EntityManagerZ::getInstance()->getEntityHereCoord(cellZ->getPos()))->hurtZ(bulletZ->damageZ);
	}
	cellZ->taggedZ = true;
	if (bulletZ->radiusZ > 0) {
		--bulletZ->radiusZ; //polymorphisme/20
		std::vector<std::shared_ptr<CellZ>> tempTab = mapZ->getClosestCellZ(cellZ); //maybe use ref/ptr
		std::vector<std::shared_ptr<CellZ>>::iterator it;

		for (it = tempTab.begin(); it != tempTab.end(); ++it) {
			if (!(*it)->taggedZ)	impactRecZ(*it, bulletZ);
		}

	}
	cellZ->taggedZ = false;
}

void CollisionControllerZ::setMap(std::shared_ptr<MapZ> setMapZ) {
	this->mapZ = setMapZ;
}

bool CollisionControllerZ::isPositionValidZ(COORD posZ) {
	return (!(posZ.X<0 || posZ.X>mapZ->getSizeZ().X || posZ.Y<0 || posZ.Y>mapZ->getSizeZ().Y));
}

CollisionControllerZ::CollisionControllerZ(){}
CollisionControllerZ::~CollisionControllerZ() = default;
