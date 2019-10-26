#include "pch.h"
#include "EntityManagerZ.h"
#include <string>
#include "EntityZFactoryZ.h"

/*
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
*/

std::vector<std::shared_ptr<EntityZ>> EntityManagerZ::getListOfEntityZ() const
{
	return this->listOfEntityZ;
}

bool EntityManagerZ::checkIfSomeoneHere(COORD coord)
{
	for (auto e : listOfEntityZ)
		if (e->getPos2DZ().X == coord.X && e->getPos2DZ().Y == coord.Y)
			return true;
	return false;
}


void EntityManagerZ::spawnAndRegister(const std::string& description, const COORD coord)
{
	std::shared_ptr<EntityZ> ent(spawnAndRegisterReturn(description, coord));
}


std::shared_ptr<EntityZ> EntityManagerZ::spawnAndRegisterReturn(const std::string& description, const COORD coord)
{
	std::shared_ptr<EntityZ> ent(EntityZFactoryZ::NewEntity(description, coord));

	this->listOfEntityZ.push_back(ent);
	
	return ent;
}
