#include "pch.h"
#include "AirCellZ.h"


AirCellZ::AirCellZ(const COORD& position): CellZ(position)
{
	this->attributes = 0x00B0;
}

string AirCellZ::getTypeName()
{
	return "air";	
}
