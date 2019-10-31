#include "pch.h"
#include "CellZ.h"

void CellZ::setAttribute(WORD word)
{
	this->attributes = word;
}

CellZ::CellZ() : sprite(' '), pos({0,0}), attributes(0x00E0), taggedZ(false)
{}

CellZ::CellZ(const COORD &position, const char &sprite) : sprite(sprite),pos(position), attributes(0x00E0), taggedZ(false)
{}


void CellZ::setSprite(const char& c)
{
	CellZ::sprite = c;
}


void CellZ::setPos(const COORD &newCoordinates)
{
	this->pos = newCoordinates;
}

const COORD & CellZ::getPos() const
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
