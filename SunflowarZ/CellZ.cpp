#include "pch.h"
#include "CellZ.h"




CellZ::CellZ(const COORD &position, const char &sprite)
{
	this->pos = position;
	this->sprite = sprite;
	this->attributes = 0x00E0;
}


void CellZ::setSprite(const char& c)
{
	CellZ::sprite = c;
}


void CellZ::setPos(const COORD &newCoordinates)
{
	this->pos = newCoordinates;
}

COORD CellZ::getPos() const
{
	return this->pos;
}

string CellZ::getTypeName()
{
	return "Undefined";
}
