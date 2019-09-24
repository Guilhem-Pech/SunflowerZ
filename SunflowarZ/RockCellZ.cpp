#include "pch.h"
#include "RockCellZ.h"

RockCellZ::RockCellZ(const COORD& position, const char& sprite): CellZ(position,sprite)
{
	this->attributes = 0x0000;
}

string RockCellZ::getTypeName()
{
	return "rock";
}
