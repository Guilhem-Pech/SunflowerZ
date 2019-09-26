#include "pch.h"
#include "CellZ.h"

void CellZ::setAttribute(WORD word)
{
	this->attributes = word;
}

CellZ::CellZ() : pos({0,0}), sprite(' '), attributes(0x00E0)
{}

CellZ::CellZ(const COORD &position, const char &sprite) : pos(position),sprite(sprite), attributes(0x00E0)
{}


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

WORD CellZ::getAttributes() const
{
	return attributes;
}

char CellZ::getSprite() const
{
	return this->sprite;
}
