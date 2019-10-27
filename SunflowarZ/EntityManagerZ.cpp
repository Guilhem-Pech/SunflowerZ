#include "pch.h"
#include "EntityManagerZ.h"
#include "EntityZFactoryZ.h"
#include <algorithm>


std::vector<std::shared_ptr<EntityZ>> EntityManagerZ::getListOfEntitiesZ() const
{
	return listOfEntities;
}

std::vector<std::shared_ptr<EntityZ>> EntityManagerZ::getListOfPlayersEntitiesZ(owner player) const
{
	switch (player)
	{
	case player1:
		return listOfPlayers1Entities;
	case player2:
		return listOfPlayers2Entities;
	default:
		return {};
	}
}


bool EntityManagerZ::checkIfSomeoneHere(COORD coord)
{
	for (auto e : listOfEntities)
		if (e->getPos2DZ().X == coord.X && e->getPos2DZ().Y == coord.Y)
			return true;
	return false;
}


void EntityManagerZ::spawnAndRegister(const EntityZFactoryZ::EntityType description, const COORD coord, EntityManagerZ::owner owner)
{
	std::shared_ptr<EntityZ> newEntity = EntityZFactoryZ::NewEntity(description, coord);
	this->listOfEntities.push_back(newEntity);

	switch (owner)
	{
	case player1:
		listOfPlayers1Entities.push_back(newEntity);
		break;
	case player2:
		listOfPlayers2Entities.push_back(newEntity);
		break;
	default:
		break;
	}
}

void EntityManagerZ::removeEntity(std::shared_ptr<EntityZ> entity, owner thePreviousOwner)
{
	switch (thePreviousOwner)
	{
	case player1:
		listOfPlayers1Entities.erase(std::remove(listOfPlayers1Entities.begin(), listOfPlayers1Entities.end(), entity),
		                             listOfPlayers1Entities.end());
		break;
	case player2:
		listOfPlayers2Entities.erase(std::remove(listOfPlayers2Entities.begin(), listOfPlayers2Entities.end(), entity),
		                             listOfPlayers2Entities.end());
		break;
	default:
		break;
	}

	listOfEntities.erase(std::remove(listOfEntities.begin(), listOfEntities.end(), entity), listOfEntities.end());
}




std::shared_ptr<EntityZ> EntityManagerZ::spawnAndRegisterReturn(const EntityZFactoryZ::EntityType description, const COORD coord, EntityManagerZ::owner owner)
{
	std::shared_ptr<EntityZ> ent(EntityZFactoryZ::NewEntity(description, coord));
	this->listOfEntities.push_back(ent);
	
	return ent;
}


void EntityManagerZ::update()
{
	for (auto ent : listOfEntities)
	{
		ent->updateZ();
	}
}