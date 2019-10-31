#include "pch.h"
#include "EntityManagerZ.h"
#include "EntityZFactoryZ.h"

#include <typeinfo>
#include <algorithm>


const std::vector<std::shared_ptr<EntityZ>>& EntityManagerZ::getListOfEntitiesZ() const
{
	return listOfEntities;
}

std::vector<std::shared_ptr<EntityZ>> EntityManagerZ::getListOfPlayersEntitiesZ(owner player) const
{
	switch (player)
	{
	case owner::player1:
		return listOfPlayers1Entities;
	case owner::player2:
		return listOfPlayers2Entities;
	default:
		return {};
	}
}

std::shared_ptr<EntityZ> EntityManagerZ::getEntityHereCoord(COORD pos) const {
	for (const auto& e : listOfEntities)
		if (e->getPos2DZ().X == pos.X && e->getPos2DZ().Y == pos.Y)
			return e;
}


bool EntityManagerZ::checkIfSomeoneHere(COORD coord)
{
	for (const auto& e : listOfEntities)
		if (e->getPos2DZ().X == coord.X && e->getPos2DZ().Y == coord.Y)
			return true;
	return false;
}


void EntityManagerZ::spawnAndRegister(const EntityZFactoryZ::EntityType description, const COORD coord, EntityManagerZ::owner owner)
{
	const std::shared_ptr<EntityZ> newEntity = EntityZFactoryZ::NewEntity(description, coord);
	this->listOfEntities.push_back(newEntity);

	switch (owner)
	{
	case owner::player1:
		listOfPlayers1Entities.push_back(newEntity);
		break;
	case owner::player2:
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
	case owner::player1:
		listOfPlayers1Entities.erase(std::remove(listOfPlayers1Entities.begin(), listOfPlayers1Entities.end(), entity),
		                             listOfPlayers1Entities.end());
		break;
	case owner::player2:
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
	for (const auto& ent : listOfEntities)
	{
		COORD nextMove = ent->getNextMove2DZ();
		COORD actPos = ent->getPos2DZ();
		if (!collisionControllerZ->isPositionValidZ(actPos)) { //is the Entity is still inside the map
			ent->~EntityZ();
		}
		else if (!collisionControllerZ->isCollisionZ(nextMove)) //is the next move valid (no collisions)
		{
			if (ent->isSFZ && collisionControllerZ->mapZ->getCellZ(actPos.X, actPos.Y - 1)->getAttributes() != 0x0080)	nextMove = { actPos.X,actPos.Y - 1 }; //fall
			ent->setPos2DZ(nextMove);
		}
		else if (!ent->isSFZ) { //in case of collision for the next move, is the entity a projectil
			std::shared_ptr<EntityZ> temp;
			temp = ent;
			collisionControllerZ->impactZ(nextMove, std::static_pointer_cast<ProjectZ>(temp));
			ent->~EntityZ();
		}
		ent->updateZ();
	}
}

EntityManagerZ::EntityManagerZ() {
	this->collisionControllerZ.reset(new CollisionControllerZ());
}

EntityManagerZ::~EntityManagerZ() = default;