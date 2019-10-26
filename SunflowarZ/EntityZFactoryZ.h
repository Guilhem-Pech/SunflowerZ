#pragma once
#include "EntityZ.h"
#include <string>
#include "SunflowerZ.h"
#include <memory>

class EntityZFactoryZ
{
public:
	enum EntityType
	{
		Sunflower
	};
	static std::shared_ptr<EntityZ> NewEntity(const std::string& description, COORD coord);
};

