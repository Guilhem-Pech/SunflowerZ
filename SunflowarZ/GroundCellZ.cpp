#include "pch.h"
#include "GroundCellZ.h"

GroundCellZ::GroundCellZ(const COORD& position, const char& sprite):CellZ(position,sprite)
{
	this->attributes = 0x0080;
}

string GroundCellZ::getTypeName()
{
	return "ground";
}
