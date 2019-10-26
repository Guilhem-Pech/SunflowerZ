#include "pch.h"
#include "EntityZFactoryZ.h"
#include <memory>
#include <memory>

std::shared_ptr<EntityZ> EntityZFactoryZ::NewEntity(const std::string& description, COORD coord = {0, 0})
{
	std::shared_ptr<EntityZ> result;
	
	if (description == "SunflowerZ")
		result = std::make_shared<SunflowerZ>(coord);
	return result;
}
