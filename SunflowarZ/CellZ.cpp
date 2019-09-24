#include "pch.h"
#include "CellZ.h"




CellZ::CellZ(const COORD &position, const WORD &attributes, const char & sprite)
{
	this->pos = position;
	this->attributes = attributes;
	this->sprite = sprite;
}



void CellZ::setSprite(const char& c)
{
	this->sprite = c;
}

void CellZ::setAttributes(const WORD& c)
{
	this->attributes = c;
}

void CellZ::setPos(const COORD &newCoordinates)
{
	this->pos = newCoordinates;
}

COORD CellZ::getPos() const
{
	return this->pos;
}


CellZ::~CellZ()
= default;
