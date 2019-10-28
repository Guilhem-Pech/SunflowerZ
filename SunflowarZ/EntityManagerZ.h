#pragma once
#include <vector>

#include"EntityZ.h"
#include <memory>
#include "EntityZFactoryZ.h"


class EntityZ;

class EntityManagerZ
{
private:
	std::vector<std::shared_ptr<EntityZ>> listOfEntities;

	std::vector<std::shared_ptr<EntityZ>> listOfPlayers1Entities;
	std::vector<std::shared_ptr<EntityZ>> listOfPlayers2Entities;
	
private:
	EntityManagerZ() {}

public:
	enum class owner
	{
		world, player1, player2
	};
	
	static EntityManagerZ& getInstance()
	{
		static EntityManagerZ    instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
	EntityManagerZ(EntityManagerZ const&) = delete;
	void operator=(EntityManagerZ const&) = delete;


	const std::vector<std::shared_ptr<EntityZ>> & getListOfEntitiesZ() const;
	std::vector<std::shared_ptr<EntityZ>> getListOfPlayersEntitiesZ(owner player) const;

	bool checkIfSomeoneHere(COORD coord);

	std::shared_ptr<EntityZ> spawnAndRegisterReturn(const EntityZFactoryZ::EntityType description, const COORD coord, owner owner);
	
	void spawnAndRegister(const EntityZFactoryZ::EntityType description, const COORD coord, owner owner);

	void removeEntity(std::shared_ptr<EntityZ> entity, owner thePreviousOwner = owner::world);
	
	void update();
}; 