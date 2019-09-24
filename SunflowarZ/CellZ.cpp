#include "pch.h"
#include "CellZ.h"




CellZ::CellZ(const COORD &position, const CellType &typeOfCellZ)
{
	this->pos = position;
	this->typeOfCellZ = typeOfCellZ;
}

void CellZ::setType(const CellType &c)
{
	this->typeOfCellZ = c;
}

bool CellZ::isType(const CellType &of) const
{
	return of == this->typeOfCellZ;
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
