#include "pch.h"
#include "EntityZFactoryZ.h"

EntityZ* EntityZFactoryZ::NewEntity(const std::string& description, COORD coord = {0,0})
{
	if (description == "SunflowerZ")
		return new SunflowerZ(coord);
	return nullptr;
}
