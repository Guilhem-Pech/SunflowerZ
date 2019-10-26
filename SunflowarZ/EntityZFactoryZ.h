#pragma once
#include "EntityZ.h"
#include <string>
#include "SunflowerZ.h"

class EntityZFactoryZ
{
public:
	static EntityZ* NewEntity(const std::string& description, COORD coord);
};

