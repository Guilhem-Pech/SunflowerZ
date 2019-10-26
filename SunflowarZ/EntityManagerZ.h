#pragma once
#include <vector>

#include"EntityZ.h"
#include <memory>
#include <string>
#include "EntityZFactoryZ.h"


class EntityManagerZ
{
private:
	std::vector<std::shared_ptr<EntityZ>> listOfEntityZ;



private:
	EntityManagerZ() {}

public:
	static EntityManagerZ& getInstance()
	{
		static EntityManagerZ    instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
	EntityManagerZ(EntityManagerZ const&) = delete;
	void operator=(EntityManagerZ const&) = delete;


	std::vector<std::shared_ptr<EntityZ>> getListOfEntityZ() const;

	bool checkIfSomeoneHere(COORD coord);

	std::shared_ptr<EntityZ> spawnAndRegisterReturn(const EntityZFactoryZ::EntityType description, const COORD coord);
	
	void spawnAndRegister(const EntityZFactoryZ::EntityType description, const COORD coord);

	void update();
}; 